/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LTEV"
 * 	found in "LTEV.asn"
 * 	`asn1c -fskeletons-copy -fnative-types -gen-PER -pdu=auto -D ./src`
 */

#ifndef	_DDateTimeltev_H_
#define	_DDateTimeltev_H_


#include <asn_application.h>

/* Including external dependencies */
#include "DYearltev.h"
#include "DMonthltev.h"
#include "DDayltev.h"
#include "DHourltev.h"
#include "DMinuteltev.h"
#include "DSecondltev.h"
#include "DTimeOffset.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* DDateTimeltev */
typedef struct DDateTimeltev {
	DYearltev_t	*year	/* OPTIONAL */;
	DMonthltev_t	*month	/* OPTIONAL */;
	DDayltev_t	*day	/* OPTIONAL */;
	DHourltev_t	*hour	/* OPTIONAL */;
	DMinuteltev_t	*minute	/* OPTIONAL */;
	DSecondltev_t	*second	/* OPTIONAL */;
	DTimeOffset_t	*offset	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DDateTimeltev_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DDateTimeltev;
extern asn_SEQUENCE_specifics_t asn_SPC_DDateTimeltev_specs_1;
extern asn_TYPE_member_t asn_MBR_DDateTimeltev_1[7];

#ifdef __cplusplus
}
#endif

#endif	/* _DDateTimeltev_H_ */
#include <asn_internal.h>
