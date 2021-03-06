/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LTEV"
 * 	found in "LTEV.asn"
 * 	`asn1c -fskeletons-copy -fnative-types -gen-PER -pdu=auto -D ./src`
 */

#include "IntersectionStateltev.h"

asn_TYPE_member_t asn_MBR_IntersectionStateltev_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct IntersectionStateltev, intersectionId),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NodeReferenceID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"intersectionId"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct IntersectionStateltev, status),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_IntersectionStatusObjectltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"status"
		},
	{ ATF_POINTER, 2, offsetof(struct IntersectionStateltev, moy),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MinuteOfTheYearltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"moy"
		},
	{ ATF_POINTER, 1, offsetof(struct IntersectionStateltev, timeStamp),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DSecondltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"timeStamp"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct IntersectionStateltev, phases),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PhaseList,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"phases"
		},
};
static const int asn_MAP_IntersectionStateltev_oms_1[] = { 2, 3 };
static const ber_tlv_tag_t asn_DEF_IntersectionStateltev_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_IntersectionStateltev_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* intersectionId */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* status */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* moy */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* timeStamp */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* phases */
};
asn_SEQUENCE_specifics_t asn_SPC_IntersectionStateltev_specs_1 = {
	sizeof(struct IntersectionStateltev),
	offsetof(struct IntersectionStateltev, _asn_ctx),
	asn_MAP_IntersectionStateltev_tag2el_1,
	5,	/* Count of tags in the map */
	asn_MAP_IntersectionStateltev_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_IntersectionStateltev = {
	"IntersectionStateltev",
	"IntersectionStateltev",
	&asn_OP_SEQUENCE,
	asn_DEF_IntersectionStateltev_tags_1,
	sizeof(asn_DEF_IntersectionStateltev_tags_1)
		/sizeof(asn_DEF_IntersectionStateltev_tags_1[0]), /* 1 */
	asn_DEF_IntersectionStateltev_tags_1,	/* Same as above */
	sizeof(asn_DEF_IntersectionStateltev_tags_1)
		/sizeof(asn_DEF_IntersectionStateltev_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_IntersectionStateltev_1,
	5,	/* Elements count */
	&asn_SPC_IntersectionStateltev_specs_1	/* Additional specs */
};

