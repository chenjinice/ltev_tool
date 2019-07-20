/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LTEV"
 * 	found in "LTEV.asn"
 * 	`asn1c -fskeletons-copy -fnative-types -gen-PER -pdu=auto`
 */

#ifndef	_PhaseList_H_
#define	_PhaseList_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct Phase;

/* PhaseList */
typedef struct PhaseList {
	A_SEQUENCE_OF(struct Phase) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PhaseList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PhaseList;
extern asn_SET_OF_specifics_t asn_SPC_PhaseList_specs_1;
extern asn_TYPE_member_t asn_MBR_PhaseList_1[1];
extern asn_per_constraints_t asn_PER_type_PhaseList_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "Phase.h"

#endif	/* _PhaseList_H_ */
#include <asn_internal.h>
