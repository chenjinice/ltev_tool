/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LTEV"
 * 	found in "LTEV.asn"
 * 	`asn1c -fskeletons-copy -fnative-types -gen-PER -pdu=auto`
 */

#ifndef	_LaneAttributes_TrackedVehicle_H_
#define	_LaneAttributes_TrackedVehicle_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BIT_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum LaneAttributes_TrackedVehicle {
	LaneAttributes_TrackedVehicle_spec_RevocableLane	= 0,
	LaneAttributes_TrackedVehicle_spec_commuterRailRoadTrack	= 1,
	LaneAttributes_TrackedVehicle_spec_lightRailRoadTrack	= 2,
	LaneAttributes_TrackedVehicle_spec_heavyRailRoadTrack	= 3,
	LaneAttributes_TrackedVehicle_spec_otherRailType	= 4
} e_LaneAttributes_TrackedVehicle;

/* LaneAttributes-TrackedVehicle */
typedef BIT_STRING_t	 LaneAttributes_TrackedVehicle_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_LaneAttributes_TrackedVehicle_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_LaneAttributes_TrackedVehicle;
asn_struct_free_f LaneAttributes_TrackedVehicle_free;
asn_struct_print_f LaneAttributes_TrackedVehicle_print;
asn_constr_check_f LaneAttributes_TrackedVehicle_constraint;
ber_type_decoder_f LaneAttributes_TrackedVehicle_decode_ber;
der_type_encoder_f LaneAttributes_TrackedVehicle_encode_der;
xer_type_decoder_f LaneAttributes_TrackedVehicle_decode_xer;
xer_type_encoder_f LaneAttributes_TrackedVehicle_encode_xer;
oer_type_decoder_f LaneAttributes_TrackedVehicle_decode_oer;
oer_type_encoder_f LaneAttributes_TrackedVehicle_encode_oer;
per_type_decoder_f LaneAttributes_TrackedVehicle_decode_uper;
per_type_encoder_f LaneAttributes_TrackedVehicle_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _LaneAttributes_TrackedVehicle_H_ */
#include <asn_internal.h>
