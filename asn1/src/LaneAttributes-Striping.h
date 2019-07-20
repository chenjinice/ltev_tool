/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LTEV"
 * 	found in "LTEV.asn"
 * 	`asn1c -fskeletons-copy -fnative-types -gen-PER -pdu=auto -D ./src`
 */

#ifndef	_LaneAttributes_Striping_H_
#define	_LaneAttributes_Striping_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BIT_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum LaneAttributes_Striping {
	LaneAttributes_Striping_stripeToConnectingLanesRevocableLane	= 0,
	LaneAttributes_Striping_stripeDrawOnLeft	= 1,
	LaneAttributes_Striping_stripeDrawOnRight	= 2,
	LaneAttributes_Striping_stripeToConnectingLanesLeft	= 3,
	LaneAttributes_Striping_stripeToConnectingLanesRight	= 4,
	LaneAttributes_Striping_stripeToConnectingLanesAhead	= 5
} e_LaneAttributes_Striping;

/* LaneAttributes-Striping */
typedef BIT_STRING_t	 LaneAttributes_Striping_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_LaneAttributes_Striping_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_LaneAttributes_Striping;
asn_struct_free_f LaneAttributes_Striping_free;
asn_struct_print_f LaneAttributes_Striping_print;
asn_constr_check_f LaneAttributes_Striping_constraint;
ber_type_decoder_f LaneAttributes_Striping_decode_ber;
der_type_encoder_f LaneAttributes_Striping_encode_der;
xer_type_decoder_f LaneAttributes_Striping_decode_xer;
xer_type_encoder_f LaneAttributes_Striping_encode_xer;
oer_type_decoder_f LaneAttributes_Striping_decode_oer;
oer_type_encoder_f LaneAttributes_Striping_encode_oer;
per_type_decoder_f LaneAttributes_Striping_decode_uper;
per_type_encoder_f LaneAttributes_Striping_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _LaneAttributes_Striping_H_ */
#include <asn_internal.h>
