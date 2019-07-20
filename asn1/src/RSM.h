/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LTEV"
 * 	found in "LTEV.asn"
 * 	`asn1c -fskeletons-copy -fnative-types -gen-PER -pdu=auto -D ./src`
 */

#ifndef	_RSM_H_
#define	_RSM_H_


#include <asn_application.h>

/* Including external dependencies */
#include "MsgCountltev.h"
#include <OCTET_STRING.h>
#include "Position3Dltev.h"
#include "ParticipantList.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RSM */
typedef struct RSM {
	MsgCountltev_t	 msgCnt;
	OCTET_STRING_t	 id;
	Position3Dltev_t	 refPos;
	ParticipantList_t	 participants;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RSM_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RSM;
extern asn_SEQUENCE_specifics_t asn_SPC_RSM_specs_1;
extern asn_TYPE_member_t asn_MBR_RSM_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _RSM_H_ */
#include <asn_internal.h>
