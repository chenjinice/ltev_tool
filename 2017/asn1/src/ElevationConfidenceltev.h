/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LTEV"
 * 	found in "LTEV.asn"
 * 	`asn1c -fskeletons-copy -fnative-types -gen-PER -pdu=auto -D ./src`
 */

#ifndef	_ElevationConfidenceltev_H_
#define	_ElevationConfidenceltev_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ElevationConfidenceltev {
	ElevationConfidenceltev_unavailable	= 0,
	ElevationConfidenceltev_elev_500_00	= 1,
	ElevationConfidenceltev_elev_200_00	= 2,
	ElevationConfidenceltev_elev_100_00	= 3,
	ElevationConfidenceltev_elev_050_00	= 4,
	ElevationConfidenceltev_elev_020_00	= 5,
	ElevationConfidenceltev_elev_010_00	= 6,
	ElevationConfidenceltev_elev_005_00	= 7,
	ElevationConfidenceltev_elev_002_00	= 8,
	ElevationConfidenceltev_elev_001_00	= 9,
	ElevationConfidenceltev_elev_000_50	= 10,
	ElevationConfidenceltev_elev_000_20	= 11,
	ElevationConfidenceltev_elev_000_10	= 12,
	ElevationConfidenceltev_elev_000_05	= 13,
	ElevationConfidenceltev_elev_000_02	= 14,
	ElevationConfidenceltev_elev_000_01	= 15
} e_ElevationConfidenceltev;

/* ElevationConfidenceltev */
typedef long	 ElevationConfidenceltev_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ElevationConfidenceltev_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ElevationConfidenceltev;
extern const asn_INTEGER_specifics_t asn_SPC_ElevationConfidenceltev_specs_1;
asn_struct_free_f ElevationConfidenceltev_free;
asn_struct_print_f ElevationConfidenceltev_print;
asn_constr_check_f ElevationConfidenceltev_constraint;
ber_type_decoder_f ElevationConfidenceltev_decode_ber;
der_type_encoder_f ElevationConfidenceltev_encode_der;
xer_type_decoder_f ElevationConfidenceltev_decode_xer;
xer_type_encoder_f ElevationConfidenceltev_encode_xer;
oer_type_decoder_f ElevationConfidenceltev_decode_oer;
oer_type_encoder_f ElevationConfidenceltev_encode_oer;
per_type_decoder_f ElevationConfidenceltev_decode_uper;
per_type_encoder_f ElevationConfidenceltev_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _ElevationConfidenceltev_H_ */
#include <asn_internal.h>
