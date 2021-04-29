/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LTEV"
 * 	found in "LTEV.asn"
 * 	`asn1c -fskeletons-copy -fnative-types -gen-PER -pdu=auto -D ./src`
 */

#include "VehicleSizeltev.h"

asn_TYPE_member_t asn_MBR_VehicleSizeltev_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct VehicleSizeltev, width),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_VehicleWidthltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"width"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct VehicleSizeltev, vehicleLength),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_VehicleLengthltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"vehicleLength"
		},
	{ ATF_POINTER, 1, offsetof(struct VehicleSizeltev, vehicleHeight),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_VehicleHeightltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"vehicleHeight"
		},
};
static const int asn_MAP_VehicleSizeltev_oms_1[] = { 2 };
static const ber_tlv_tag_t asn_DEF_VehicleSizeltev_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_VehicleSizeltev_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* width */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* vehicleLength */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* vehicleHeight */
};
asn_SEQUENCE_specifics_t asn_SPC_VehicleSizeltev_specs_1 = {
	sizeof(struct VehicleSizeltev),
	offsetof(struct VehicleSizeltev, _asn_ctx),
	asn_MAP_VehicleSizeltev_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_VehicleSizeltev_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_VehicleSizeltev = {
	"VehicleSizeltev",
	"VehicleSizeltev",
	&asn_OP_SEQUENCE,
	asn_DEF_VehicleSizeltev_tags_1,
	sizeof(asn_DEF_VehicleSizeltev_tags_1)
		/sizeof(asn_DEF_VehicleSizeltev_tags_1[0]), /* 1 */
	asn_DEF_VehicleSizeltev_tags_1,	/* Same as above */
	sizeof(asn_DEF_VehicleSizeltev_tags_1)
		/sizeof(asn_DEF_VehicleSizeltev_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_VehicleSizeltev_1,
	3,	/* Elements count */
	&asn_SPC_VehicleSizeltev_specs_1	/* Additional specs */
};
