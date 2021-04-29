/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LTEV"
 * 	found in "LTEV.asn"
 * 	`asn1c -fskeletons-copy -fnative-types -gen-PER -pdu=auto -D ./src`
 */

#ifndef	_NodeListltev_H_
#define	_NodeListltev_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct Node;

/* NodeListltev */
typedef struct NodeListltev {
	A_SEQUENCE_OF(struct Node) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NodeListltev_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NodeListltev;
extern asn_SET_OF_specifics_t asn_SPC_NodeListltev_specs_1;
extern asn_TYPE_member_t asn_MBR_NodeListltev_1[1];
extern asn_per_constraints_t asn_PER_type_NodeListltev_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "Node.h"

#endif	/* _NodeListltev_H_ */
#include <asn_internal.h>