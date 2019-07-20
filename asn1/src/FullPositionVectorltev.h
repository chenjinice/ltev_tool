/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LTEV"
 * 	found in "LTEV.asn"
 * 	`asn1c -fskeletons-copy -fnative-types -gen-PER -pdu=auto -D ./src`
 */

#ifndef	_FullPositionVectorltev_H_
#define	_FullPositionVectorltev_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Position3Dltev.h"
#include "Headingltev.h"
#include "TransmissionStateltev.h"
#include "Speedltev.h"
#include "TimeConfidenceltev.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct DDateTimeltev;
struct PositionConfidenceSetltev;
struct MotionConfidenceSet;

/* FullPositionVectorltev */
typedef struct FullPositionVectorltev {
	struct DDateTimeltev	*utcTime	/* OPTIONAL */;
	Position3Dltev_t	 pos;
	Headingltev_t	*heading	/* OPTIONAL */;
	TransmissionStateltev_t	*transmission	/* OPTIONAL */;
	Speedltev_t	*speed	/* OPTIONAL */;
	struct PositionConfidenceSetltev	*posAccuracy	/* OPTIONAL */;
	TimeConfidenceltev_t	*timeConfidence	/* OPTIONAL */;
	struct PositionConfidenceSetltev	*posConfidence	/* OPTIONAL */;
	struct MotionConfidenceSet	*motionCfd	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} FullPositionVectorltev_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_FullPositionVectorltev;
extern asn_SEQUENCE_specifics_t asn_SPC_FullPositionVectorltev_specs_1;
extern asn_TYPE_member_t asn_MBR_FullPositionVectorltev_1[9];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "DDateTimeltev.h"
#include "PositionConfidenceSetltev.h"
#include "MotionConfidenceSet.h"

#endif	/* _FullPositionVectorltev_H_ */
#include <asn_internal.h>
