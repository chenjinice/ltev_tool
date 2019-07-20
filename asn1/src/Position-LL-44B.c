/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LTEV"
 * 	found in "LTEV.asn"
 * 	`asn1c -fskeletons-copy -fnative-types -gen-PER -pdu=auto -D ./src`
 */

#include "Position-LL-44B.h"

asn_TYPE_member_t asn_MBR_Position_LL_44B_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct Position_LL_44B, lon),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OffsetLL_B22,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"lon"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Position_LL_44B, lat),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OffsetLL_B22,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"lat"
		},
};
static const ber_tlv_tag_t asn_DEF_Position_LL_44B_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_Position_LL_44B_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* lon */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* lat */
};
asn_SEQUENCE_specifics_t asn_SPC_Position_LL_44B_specs_1 = {
	sizeof(struct Position_LL_44B),
	offsetof(struct Position_LL_44B, _asn_ctx),
	asn_MAP_Position_LL_44B_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_Position_LL_44B = {
	"Position-LL-44B",
	"Position-LL-44B",
	&asn_OP_SEQUENCE,
	asn_DEF_Position_LL_44B_tags_1,
	sizeof(asn_DEF_Position_LL_44B_tags_1)
		/sizeof(asn_DEF_Position_LL_44B_tags_1[0]), /* 1 */
	asn_DEF_Position_LL_44B_tags_1,	/* Same as above */
	sizeof(asn_DEF_Position_LL_44B_tags_1)
		/sizeof(asn_DEF_Position_LL_44B_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_Position_LL_44B_1,
	2,	/* Elements count */
	&asn_SPC_Position_LL_44B_specs_1	/* Additional specs */
};

