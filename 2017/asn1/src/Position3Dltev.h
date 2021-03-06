/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LTEV"
 * 	found in "LTEV.asn"
 * 	`asn1c -fskeletons-copy -fnative-types -gen-PER -pdu=auto -D ./src`
 */

#ifndef	_Position3Dltev_H_
#define	_Position3Dltev_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Latitudeltev.h"
#include "Longitudeltev.h"
#include "Elevationltev.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Position3Dltev */
typedef struct Position3Dltev {
	Latitudeltev_t	 lat;
	Longitudeltev_t	 Long;
	Elevationltev_t	*elevation	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Position3Dltev_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Position3Dltev;
extern asn_SEQUENCE_specifics_t asn_SPC_Position3Dltev_specs_1;
extern asn_TYPE_member_t asn_MBR_Position3Dltev_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _Position3Dltev_H_ */
#include <asn_internal.h>
