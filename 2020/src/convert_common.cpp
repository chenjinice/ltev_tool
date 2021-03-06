#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/stat.h>
#include <errno.h>
#include "common.h"
#include "convert_common.h"


#define POINTTYPE_COUNT 7
static int s_bits[POINTTYPE_COUNT] = {24,28,32,36,44,48,64};
static int s_max[POINTTYPE_COUNT] = {2047,8191,32767,131071,2097151,8388607,LNG_MAX};


// -------------- point------------------------------------

PositionOffsetLL_PR getOffsetLL(long ref_lng, long ref_lat, long lng, long lat, long *lng_offset, long *lat_offset, char **log)
{
    static char str[100];
    memset(str,0,sizeof(str));

    PositionOffsetLL_PR present = PositionOffsetLL_PR_position_LatLon;
    int64_t lng_tmp = (int64_t)lng - (int64_t)ref_lng;
    int     lat_tmp = lat - ref_lat;
    if(lng_tmp > LNG_MAX) {lng_tmp -= LNG_MAX;lng_tmp -= LNG_MAX;}
    if(lng_tmp < -LNG_MAX){lng_tmp += LNG_MAX;lng_tmp += LNG_MAX;}

    int lng_abs = abs(lng_tmp),lat_abs = abs(lat_tmp),i;
    int lng_indx = -1,lat_index = -1;
    int abs_max = lng_abs > lat_abs ? lng_abs : lat_abs;
    for(i=0;i<POINTTYPE_COUNT;i++){
        if(abs_max <= s_max[i]){present = (PositionOffsetLL_PR)(i+1);break;}
    }

    if( present < PositionOffsetLL_PR_position_LatLon ) {
        *lng_offset = (int)lng_tmp;
        *lat_offset = lat_tmp;
        sprintf(str,"LL%d:%d:%d",present,s_bits[present-1],s_max[present-1]);
    }else if(present == PositionOffsetLL_PR_position_LatLon){
        *lng_offset = lng;
        *lat_offset = lat;
        sprintf(str,"LatLon:64");
    }

    if(log)*log = str;
    return present;
}

void setOffsetLL(PositionOffsetLLV_t *point, long lng, long lat, PositionOffsetLL_PR type)
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

char *getPoint(PositionOffsetLLV_t *point, long *lng, long *lat)
{
    int type = point->offsetLL.present;
    static char str[100] = {0};
    memset(str,0,sizeof(str));

    switch (type) {
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

    if( (type > PositionOffsetLL_PR_NOTHING) && (type < PositionOffsetLL_PR_position_LatLon) ) {
        sprintf(str,"LL%d:%d:%d",type,s_bits[type-1],s_max[type-1]);
    }else if(type == PositionOffsetLL_PR_position_LatLon){
        sprintf(str,"LatLon:64");
    }else{
        sprintf(str,"????");
    }
    return str;
}

// 判断字符串长度是否在允许范围内
int jsonStrLenRange(cJSON *json,int min,int max,char *pre,char *keyname)
{
    int ret = -1 ;
    char *value = nullptr;
    if(json == nullptr){
        myerr("%s error, no %s\n",pre,keyname);
        return ret;
    }
    value = json->valuestring;
    int len = strlen(value);
    if( (len < min) || (len > max) ){
        myerr("%s error , str len = %d , must be %d~%d\n",pre,strlen(value),min,max);
        return  ret;
    }
    return 0;
}

// 判断整数是否在范围内
int jsonIntRange(cJSON *json, int min, int max, char *pre,char *keyname)
{
    int ret = -1, value;
    if(json == nullptr){
        myerr("%s error, no %s\n",pre,keyname);
        return ret;
    }
    value = json->valueint;
    if( (value < min) || (value > max) ){
        myerr("%s error , %s value = %d , must be %d~%d\n",pre,json->string,value,min,max);
        return ret;
    }
    return 0;
}

// 判断浮点数是否在范围内
int jsonDoubleRange(cJSON *json, double min, double max, char *pre, char *keyname)
{
    int ret = -1;
    double value;
    if(json == nullptr){
        myerr("%s error, no %s\n",pre,keyname);
        return ret;
    }
    value = json->valuedouble;
    if( (value < min) || (value > max) ){
        myerr("%s error , %s value = %lf , must be %lf~%lf\n",pre,json->string,value,min,max);
        return ret;
    }
    return 0;
}

// 判断数组元素个数是否在范围内
int jsonArrayRange(cJSON *json, int min, int max, char *pre,char *keyname)
{
    int ret = -1 , count;
    if(json == nullptr){
        myerr("%s error, no %s\n",pre,keyname);
        return ret;
    }
    count = cJSON_GetArraySize(json);
    if( (count < min) || (count > max) ){
        myerr("%s error , %s count = %d , must be %d~%d\n",pre,json->string,count,min,max);
        return ret;
    }
    return 0;
}

// 判断json元素是否存在
int jsonExists(cJSON *json , char *pre, char *keyname){
    int ret = -1;
    if(json == nullptr){
        myerr("%s error, no %s\n",pre,keyname);
    }else{
        ret = 0;
    }
    return ret;
}

//检查json数据是否符合 refPos 的要求
int refPosJsonCheck(cJSON *json,int level,char *keyname,long *lng_value,long *lat_value)
{
    int ret = -1;
    char *pre = getPreSuf(level,keyname);
    if(jsonExists(json,pre,keyname)!=0)return ret;

    char *key_lng = (char *)"lng", *key_lat = (char *)"lat";
    cJSON *lng = cJSON_GetObjectItem(json,key_lng);
    cJSON *lat = cJSON_GetObjectItem(json,key_lat);
    if(jsonIntRange(lng,-LNG_MAX,LNG_MAX,pre,key_lng)!=0)return ret;
    if(jsonIntRange(lat,-LAT_MAX,LAT_MAX,pre,key_lat)!=0)return ret;
    mylog("%s : lng=%d,lat=%d\n",pre,lng->valueint,lat->valueint);
    *lng_value = lng->valueint;
    *lat_value = lat->valueint;
    return 0;
}

//检查json数据是否符合 nodeID的要求
int nodeRefIDJsonCheck(cJSON *json,int level,char *keyname)
{
    int ret = -1,region_int = 0;
    char *pre = getPreSuf(level,keyname);

    if(jsonExists(json,pre,keyname)!=0)return ret;

    char *key_id = (char *)"id", *key_region = (char *)"region";
    cJSON *id = cJSON_GetObjectItem(json,key_id);
    cJSON *region = cJSON_GetObjectItem(json,key_region);
    if(jsonIntRange(id,NODEID_MIN,NODEID_MAX,pre,key_id)!=0)return ret;
    if(region){
        if(jsonIntRange(region,0,U16_MAX,pre,key_region)!=0)return ret;
        region_int = region->valueint;
    }
    mylog("%s : id=%d",pre,id->valueint);
    if(region)mylog(",region*=%d",region_int);
    mylog("\n");
    return 0;
}

// 添加 refPos
void addRefPos(Position3D_t *pos,cJSON *json,long *lng_value,long *lat_value)
{
    int lng = cJSON_GetObjectItem(json,"lng")->valueint;
    int lat = cJSON_GetObjectItem(json,"lat")->valueint;
    pos->Long = lng;
    pos->lat  = lat;
    *lng_value = lng;
    *lat_value = lat;
}

// 添加 NodeReferenceID
void addNodeRefId(NodeReferenceID_t *nodeId,cJSON *json)
{
    int id_value = 0;
    cJSON *region = nullptr;
    if(json){
        id_value = cJSON_GetObjectItem(json,"id")->valueint;
        region = cJSON_GetObjectItem(json,"region");
    }
    nodeId->id = id_value;
    if(region){
        nodeId->region = (RoadRegulatorID_t*)calloc(1,sizeof(RoadRegulatorID_t));
        *nodeId->region = region->valueint;
    }
}

// 添加IA5String
IA5String_t *addIA5String(cJSON *json)
{
    IA5String_t *p = nullptr;
    if(json){
        p            = new IA5String_t();
        char * value = json->valuestring;
        int len      = strlen(value);
        p->buf       = new uint8_t[len]();
        p->size      = len;
        memcpy(p->buf,value,len);
    }
    return p;
}

void printNodeRefId(NodeReferenceID_t *nodeid ,int level,char *name)
{
    char *pre = getPreSuf(level,name);
    mylog("%s : id=%ld",pre,nodeid->id);
    if(nodeid->region)mylog(",region*=%ld",*nodeid->region);
    mylog("\n");
}


