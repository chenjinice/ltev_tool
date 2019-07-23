#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include "encode_rsi.h"
#include "common.h"


// 检查 rsi 的 json 文件数据是否符合要求
static int check_rsi_json(cJSON *json)
{
    int ret = -1;
    cJSON *lon = cJSON_GetObjectItem(json,"lon");
    cJSON *lat = cJSON_GetObjectItem(json,"lat");
    cJSON *alertType = cJSON_GetObjectItem(json,"alertType");
    if(lon == NULL){printf("error : no lon\n");return ret;}
    if(lat == NULL){printf("error : no lat\n");return ret;}
    if(alertType == NULL){printf("error : no alertType\n");return ret;}
    printf("lon = %d \n",lon->valueint);
    printf("lat = %d \n",lat->valueint);
    printf("alertType = %d\n",alertType->valueint);
    return 0;
}


// 从文件读取 rsi 的 json 数据， 并用asn编码保存到文件
void encode_rsi(char *json_file, char *uper_file)
{
    int i;
    MessageFrame_t *msgframe = NULL;
    cJSON *json = read_json(json_file);
    if(!json)return;

    // 检查 json 数据是否符合要求
    printf("———————— check rsi json start ————————\n");
    int ret = check_rsi_json(json);
    if(ret == 0)printf("———————— check rsi json \e[32;40mOK\e[0m ————————\n");
    else{printf("———————— check rsi json \e[31;40mFAIL\e[0m ————————\n");return;}

    int lon = cJSON_GetObjectItem(json,"lon")->valueint;
    int lat = cJSON_GetObjectItem(json,"lat")->valueint;
    int alertType = cJSON_GetObjectItem(json,"alertType")->valueint;
    int rsu_id = 0;

    msgframe = (MessageFrame_t*)malloc(sizeof(MessageFrame_t));
    memset(msgframe,0,sizeof(MessageFrame_t));
    msgframe->present = MessageFrame_PR_rsiFrame;

    RSI_t *rsi = &msgframe->choice.rsiFrame;
    rsi->msgCnt = 0;
    rsi->id.buf = malloc(8);
    memcpy(rsi->id.buf,&rsu_id,sizeof(rsu_id));
    rsi->id.size = 8;
    rsi->rsiId = 0;
    rsi->refPos.lat = lat;       // 纬度
    rsi->refPos.Long = lon;      // 经度
    rsi->alertType = alertType;  // 警告类型
    rsi->alertRadius = 0;

    for(i = 0;i<2;i++)
    {
        struct PositionOffsetLLV* ptemp_alertPath;
        ptemp_alertPath  =calloc(sizeof(struct PositionOffsetLLV),1);
        memset(ptemp_alertPath,0,sizeof(struct PositionOffsetLLV));
        ptemp_alertPath->offsetLL.present = PositionOffsetLL_PR_position_LL1;
        ptemp_alertPath->offsetLL.choice.position_LL1.lat = 0;
        ptemp_alertPath->offsetLL.choice.position_LL1.lon = 0;
        ASN_SET_ADD(&rsi->alertPath.list,ptemp_alertPath);
    }

    encode(uper_file,msgframe);

    cJSON_Delete(json);
    ASN_STRUCT_FREE(asn_DEF_MessageFrame, msgframe);
}


// 打印 rsi 数据
void print_rsi(MessageFrame_t *msg)
{
    RSI_t rsi = msg->choice.rsiFrame;
    printf("lon = %ld \n",rsi.refPos.Long);
    printf("lat = %ld \n",rsi.refPos.lat);
    printf("alertType = %ld\n",rsi.alertType);
}




