/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LTEV"
 * 	found in "LTEV.asn"
 * 	`asn1c -fskeletons-copy -fnative-types -gen-PER -pdu=auto -D ./src`
 */

#ifndef	_Position_LLmD_64b_H_
#define	_Position_LLmD_64b_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Longitudeltev.h"
#include "Latitudeltev.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Position-LLmD-64b */
typedef struct Position_LLmD_64b {
	Longitudeltev_t	 lon;
	Latitudeltev_t	 lat;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Position_LLmD_64b_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Position_LLmD_64b;
extern asn_SEQUENCE_specifics_t asn_SPC_Position_LLmD_64b_specs_1;
extern asn_TYPE_member_t asn_MBR_Position_LLmD_64b_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _Position_LLmD_64b_H_ */
#include <asn_internal.h>
