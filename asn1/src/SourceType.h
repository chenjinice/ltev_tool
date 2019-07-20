/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LTEV"
 * 	found in "LTEV.asn"
 * 	`asn1c -fskeletons-copy -fnative-types -gen-PER -pdu=auto -D ./src`
 */

#ifndef	_SourceType_H_
#define	_SourceType_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SourceType {
	SourceType_unknown	= 0,
	SourceType_selfinfo	= 1,
	SourceType_v2x	= 2,
	SourceType_video	= 3,
	SourceType_microwaveRadar	= 4,
	SourceType_loop	= 5
	/*
	 * Enumeration is extensible
	 */
} e_SourceType;

/* SourceType */
typedef long	 SourceType_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_SourceType_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_SourceType;
extern const asn_INTEGER_specifics_t asn_SPC_SourceType_specs_1;
asn_struct_free_f SourceType_free;
asn_struct_print_f SourceType_print;
asn_constr_check_f SourceType_constraint;
ber_type_decoder_f SourceType_decode_ber;
der_type_encoder_f SourceType_encode_der;
xer_type_decoder_f SourceType_decode_xer;
xer_type_encoder_f SourceType_encode_xer;
oer_type_decoder_f SourceType_decode_oer;
oer_type_encoder_f SourceType_encode_oer;
per_type_decoder_f SourceType_decode_uper;
per_type_encoder_f SourceType_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _SourceType_H_ */
#include <asn_internal.h>
