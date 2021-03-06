/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LTEV"
 * 	found in "LTEV.asn"
 * 	`asn1c -fskeletons-copy -fnative-types -gen-PER -pdu=auto -D ./src`
 */

#include "FullPositionVectorltev.h"

asn_TYPE_member_t asn_MBR_FullPositionVectorltev_1[] = {
	{ ATF_POINTER, 1, offsetof(struct FullPositionVectorltev, utcTime),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DDateTimeltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"utcTime"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct FullPositionVectorltev, pos),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Position3Dltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"pos"
		},
	{ ATF_POINTER, 7, offsetof(struct FullPositionVectorltev, heading),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Headingltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"heading"
		},
	{ ATF_POINTER, 6, offsetof(struct FullPositionVectorltev, transmission),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TransmissionStateltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"transmission"
		},
	{ ATF_POINTER, 5, offsetof(struct FullPositionVectorltev, speed),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Speedltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"speed"
		},
	{ ATF_POINTER, 4, offsetof(struct FullPositionVectorltev, posAccuracy),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PositionConfidenceSetltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"posAccuracy"
		},
	{ ATF_POINTER, 3, offsetof(struct FullPositionVectorltev, timeConfidence),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TimeConfidenceltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"timeConfidence"
		},
	{ ATF_POINTER, 2, offsetof(struct FullPositionVectorltev, posConfidence),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PositionConfidenceSetltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"posConfidence"
		},
	{ ATF_POINTER, 1, offsetof(struct FullPositionVectorltev, motionCfd),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MotionConfidenceSet,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"motionCfd"
		},
};
static const int asn_MAP_FullPositionVectorltev_oms_1[] = { 0, 2, 3, 4, 5, 6, 7, 8 };
static const ber_tlv_tag_t asn_DEF_FullPositionVectorltev_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_FullPositionVectorltev_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* utcTime */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* pos */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* heading */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* transmission */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* speed */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* posAccuracy */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* timeConfidence */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* posConfidence */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 } /* motionCfd */
};
asn_SEQUENCE_specifics_t asn_SPC_FullPositionVectorltev_specs_1 = {
	sizeof(struct FullPositionVectorltev),
	offsetof(struct FullPositionVectorltev, _asn_ctx),
	asn_MAP_FullPositionVectorltev_tag2el_1,
	9,	/* Count of tags in the map */
	asn_MAP_FullPositionVectorltev_oms_1,	/* Optional members */
	8, 0,	/* Root/Additions */
	9,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_FullPositionVectorltev = {
	"FullPositionVectorltev",
	"FullPositionVectorltev",
	&asn_OP_SEQUENCE,
	asn_DEF_FullPositionVectorltev_tags_1,
	sizeof(asn_DEF_FullPositionVectorltev_tags_1)
		/sizeof(asn_DEF_FullPositionVectorltev_tags_1[0]), /* 1 */
	asn_DEF_FullPositionVectorltev_tags_1,	/* Same as above */
	sizeof(asn_DEF_FullPositionVectorltev_tags_1)
		/sizeof(asn_DEF_FullPositionVectorltev_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_FullPositionVectorltev_1,
	9,	/* Elements count */
	&asn_SPC_FullPositionVectorltev_specs_1	/* Additional specs */
};

