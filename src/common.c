#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include "common.h"
#include "MessageFrame.h"


#define POINTTYPE_COUNT 7
static int s_bits[POINTTYPE_COUNT] = {24,28,32,36,44,48,64};
static int s_lng_max[POINTTYPE_COUNT] = {2047,8191,32767,131071,2097151,8388607,LNG_MAX};
static int s_lat_max[POINTTYPE_COUNT] = {2047,8191,32767,131071,2097151,8388607,LAT_MAX};



// 打印消息前缀
void get_pre(char *pre,char *name,int level)
{
    int i;
    char *format = "│ ";
    char *format_last = "├ ";
    pre[0] = 0;
    for(i=0;i<level;i++){
        if(i== level-1)sprintf(pre+strlen(pre),"%s",format_last);
        else sprintf(pre+strlen(pre),"%s",format);
    }
    sprintf(pre+strlen(pre),"%s",name);
}

// 判断整数是否在范围内
int check_int(int num ,int min,int max,char *pre,char *name)
{
    if( (num < min) || (num > max) ){
        printf("%s.%s error : value = %d, must be (%d ~ %d)\n",pre,name,num,min,max);
        return -1;
    }else{
        return 0;
    }
}

// 判断浮点数是否在范围内
int check_double(double num ,double min,double max,char *pre,char *name)
{
    if( (num < min) || (num > max) ){
        printf("%s.%s error : value = %lf, must be (%.2lf ~ %.2lf)\n",pre,name,num,min,max);
        return -1;
    }else{
        return 0;
    }
}


// 获取文件大小
int get_file_size(char *path)
{
    int ret = -1;
    struct stat statbuff;

    if(stat(path, &statbuff) < 0){
        printf("%s : get file status fail , %s\n",path,strerror(errno));
        return ret;
    }
    return statbuff.st_size;
}


/*
 * 读取文件内容，并保存到 buffer,
 * 如果读取成功，buffer需要手动释放
 * 返回值： 读取到的数据大小
 */
int read_file(char *path,uint8_t **buffer)
{
    int ret = -1;
    int filesize,fd;
    *buffer = NULL;

    filesize = get_file_size(path);
    if(filesize < 0)return ret;

    fd = open(path,O_RDONLY);
    if(fd == -1){
        printf("open %s failed\n",path);
        return ret;
    }

    *buffer = (uint8_t*)malloc(filesize);
    int len = read(fd,*buffer,filesize);
    close(fd);
    if(len != filesize){
        printf("read %s error : len = %d,filesize = %d\n",path,len,filesize);
        free(*buffer);
        *buffer = NULL;
        return ret;
    }
    return filesize;
}


//  把buffer内容保存到文件中
void write_file(char *path, uint8_t *buffer, int length)
{
    int fd = open(path,O_WRONLY|O_CREAT|O_TRUNC,0666);
    if(fd == -1){
        printf("open %s failed\n",path);
        return;
    }
    int ret = write(fd,buffer,length);
    if(ret != length){
        printf("write to %s \e[31;40mfail\e[0m : ret = %d,length = %d\n",path,ret,length);
    }else{
        printf("write to %s \e[32;40mOK\e[0m\n",path);
    }
    close(fd);
}

/*
 * 从文件读取数据，并用cJSON解析,
 * 解析成功的话，需要调用 cJSON_Delete 函数释放
 */
cJSON *read_json(char *path)
{
    cJSON *json = NULL;

    uint8_t *buffer;
    read_file(path,&buffer);
    if(!buffer)return;

    json = cJSON_Parse((char *)buffer);
    free(buffer);

    if (!json) {
        printf("%s : json parse error : [%s]\n",path,cJSON_GetErrorPtr());
    }
    return json;
}


// asn编码 MessageFrame_t 类型数据，并将编码结果保存到文件
void encode(char *path, MessageFrame_t *msg)
{
    uint8_t buffer[BUFF_SIZE];
    asn_enc_rval_t rval  = uper_encode_to_buffer(&asn_DEF_MessageFrame, NULL, msg, buffer, BUFF_SIZE);
    printf("encode size = %d , buffer_size = %d\n",rval.encoded,BUFF_SIZE);
    if (rval.encoded == -1)
    {
        printf( "encode \e[31;40mfail\e[0m : error = %s\n",(char *)rval.failed_type->name);
        return;
    }
    if (rval.encoded > BUFF_SIZE) {
        printf("encode \e[31;40mfail\e[0m : size(%d) > buffer_size(%d) \n",rval.encoded,BUFF_SIZE);
        return;
    }
    printf("encode \e[32;40mOK\e[0m \n");
    write_file(path,buffer,rval.encoded);
}



// -------------- roadpoint------------------------------------
PositionOffsetLL_PR get_point_type(int lng, int lat, int bits)
{
    PositionOffsetLL_PR ret = PositionOffsetLL_PR_NOTHING;
    int lng_abs = abs(lng),lat_abs = abs(lat),i;
    int lng_indx = -1,lat_index = -1,index = -1;

    if(lng_abs > LNG_MAX )return ret;
    if(lat_abs > LAT_MAX)return ret;

    if(bits != 64){
        for(i=0;i<POINTTYPE_COUNT;i++){
            if(lng_abs <= s_lng_max[i]){lng_indx = i;break;}
        }
        for(i=0;i<POINTTYPE_COUNT;i++){
            if(lat_abs <= s_lat_max[i]){lat_index = i;break;}
        }
        index = lng_indx > lat_index ? lng_indx : lat_index;
    }else{
        index = POINTTYPE_COUNT-1;
    }
    return index + 1;
}

void get_type_str(PositionOffsetLL_PR type, char *str)
{
    if( (type > PositionOffsetLL_PR_NOTHING) && (type < PositionOffsetLL_PR_position_LatLon) ) {
        sprintf(str,"LL%d:%d:%d",type,s_bits[type-1],s_lng_max[type-1]);
    }else if(type == PositionOffsetLL_PR_position_LatLon){
        sprintf(str,"LatLon:64:lng:180*1e7,lat:90*1e7");
    }else{
        sprintf(str,"????");
    }
}

void set_point(PositionOffsetLLV_t *point, long lng, long lat, PositionOffsetLL_PR type)
{
    point->offsetLL.present = type;
    switch (type) {
        case PositionOffsetLL_PR_position_LL1:
            point->offsetLL.choice.position_LL1.lon = lng;
            point->offsetLL.choice.position_LL1.lat = lat;
            break;
        case PositionOffsetLL_PR_position_LL2:
            point->offsetLL.choice.position_LL2.lon = lng;
            point->offsetLL.choice.position_LL2.lat = lat;
            break;
        case PositionOffsetLL_PR_position_LL3:
            point->offsetLL.choice.position_LL3.lon = lng;
            point->offsetLL.choice.position_LL3.lat = lat;
            break;
        case PositionOffsetLL_PR_position_LL4:
            point->offsetLL.choice.position_LL4.lon = lng;
            point->offsetLL.choice.position_LL4.lat = lat;
            break;
        case PositionOffsetLL_PR_position_LL5:
            point->offsetLL.choice.position_LL5.lon = lng;
            point->offsetLL.choice.position_LL5.lat = lat;
            break;
        case PositionOffsetLL_PR_position_LL6:
            point->offsetLL.choice.position_LL6.lon = lng;
            point->offsetLL.choice.position_LL6.lat = lat;
            break;
        case PositionOffsetLL_PR_position_LatLon:
            point->offsetLL.choice.position_LatLon.lon = lng;
            point->offsetLL.choice.position_LatLon.lat = lat;
            break;
    }
}

void get_point(PositionOffsetLLV_t *point, long *lng, long *lat)
{
    switch (point->offsetLL.present) {
        case PositionOffsetLL_PR_position_LL1:
            *lng = point->offsetLL.choice.position_LL1.lon;
            *lat = point->offsetLL.choice.position_LL1.lat;
            break;
        case PositionOffsetLL_PR_position_LL2:
            *lng = point->offsetLL.choice.position_LL2.lon;
            *lat = point->offsetLL.choice.position_LL2.lat;
            break;
        case PositionOffsetLL_PR_position_LL3:
            *lng = point->offsetLL.choice.position_LL3.lon;
            *lat = point->offsetLL.choice.position_LL3.lat;
            break;
        case PositionOffsetLL_PR_position_LL4:
            *lng = point->offsetLL.choice.position_LL4.lon;
            *lat = point->offsetLL.choice.position_LL4.lat;
            break;
        case PositionOffsetLL_PR_position_LL5:
            *lng = point->offsetLL.choice.position_LL5.lon;
            *lat = point->offsetLL.choice.position_LL5.lat;
            break;
        case PositionOffsetLL_PR_position_LL6:
            *lng = point->offsetLL.choice.position_LL6.lon;
            *lat = point->offsetLL.choice.position_LL6.lat;
            break;
        case PositionOffsetLL_PR_position_LatLon:
            *lng = point->offsetLL.choice.position_LatLon.lon;
            *lat = point->offsetLL.choice.position_LatLon.lat;
            break;
        default :
            *lng = 0;
            *lat = 0;
            break;
    }
}








