/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LTEV"
 * 	found in "LTEV.asn"
 * 	`asn1c -fskeletons-copy -fnative-types -gen-PER -pdu=auto`
 */

#include "BSM.h"

static int
memb_id_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = st->size;
	
	if((size == 8)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_plateNo_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = st->size;
	
	if((size >= 4 && size <= 16)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_oer_constraints_t asn_OER_memb_id_constr_3 CC_NOTUSED = {
	{ 0, 0 },
	8	/* (SIZE(8..8)) */};
static asn_per_constraints_t asn_PER_memb_id_constr_3 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 0,  0,  8,  8 }	/* (SIZE(8..8)) */,
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_plateNo_constr_4 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(4..16)) */};
static asn_per_constraints_t asn_PER_memb_plateNo_constr_4 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 4,  4,  4,  16 }	/* (SIZE(4..16)) */,
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_BSM_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct BSM, msgCnt),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MsgCountltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"msgCnt"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BSM, id),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		0,
		{ &asn_OER_memb_id_constr_3, &asn_PER_memb_id_constr_3,  memb_id_constraint_1 },
		0, 0, /* No default value */
		"id"
		},
	{ ATF_POINTER, 1, offsetof(struct BSM, plateNo),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		0,
		{ &asn_OER_memb_plateNo_constr_4, &asn_PER_memb_plateNo_constr_4,  memb_plateNo_constraint_1 },
		0, 0, /* No default value */
		"plateNo"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BSM, secMark),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DSecondltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"secMark"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BSM, pos),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Position3Dltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"pos"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BSM, accuracy),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PositionConfidenceSetltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"accuracy"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BSM, transmission),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TransmissionStateltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"transmission"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BSM, speed),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Speedltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"speed"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BSM, heading),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Headingltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"heading"
		},
	{ ATF_POINTER, 2, offsetof(struct BSM, angle),
		(ASN_TAG_CLASS_CONTEXT | (9 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SteeringWheelAngleltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"angle"
		},
	{ ATF_POINTER, 1, offsetof(struct BSM, motionCfd),
		(ASN_TAG_CLASS_CONTEXT | (10 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MotionConfidenceSet,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"motionCfd"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BSM, accelSet),
		(ASN_TAG_CLASS_CONTEXT | (11 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_AccelerationSet4Wayltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"accelSet"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BSM, brakes),
		(ASN_TAG_CLASS_CONTEXT | (12 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BrakeSystemStatusltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"brakes"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BSM, size),
		(ASN_TAG_CLASS_CONTEXT | (13 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_VehicleSizeltev,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"size"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BSM, vehicleClass),
		(ASN_TAG_CLASS_CONTEXT | (14 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_VehicleClassification,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"vehicleClass"
		},
	{ ATF_POINTER, 1, offsetof(struct BSM, safetyExt),
		(ASN_TAG_CLASS_CONTEXT | (15 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_VehicleSafetyExtensions,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"safetyExt"
		},
};
static const int asn_MAP_BSM_oms_1[] = { 2, 9, 10, 15 };
static const ber_tlv_tag_t asn_DEF_BSM_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_BSM_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* msgCnt */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* id */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* plateNo */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* secMark */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* pos */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* accuracy */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* transmission */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* speed */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 }, /* heading */
    { (ASN_TAG_CLASS_CONTEXT | (9 << 2)), 9, 0, 0 }, /* angle */
    { (ASN_TAG_CLASS_CONTEXT | (10 << 2)), 10, 0, 0 }, /* motionCfd */
    { (ASN_TAG_CLASS_CONTEXT | (11 << 2)), 11, 0, 0 }, /* accelSet */
    { (ASN_TAG_CLASS_CONTEXT | (12 << 2)), 12, 0, 0 }, /* brakes */
    { (ASN_TAG_CLASS_CONTEXT | (13 << 2)), 13, 0, 0 }, /* size */
    { (ASN_TAG_CLASS_CONTEXT | (14 << 2)), 14, 0, 0 }, /* vehicleClass */
    { (ASN_TAG_CLASS_CONTEXT | (15 << 2)), 15, 0, 0 } /* safetyExt */
};
asn_SEQUENCE_specifics_t asn_SPC_BSM_specs_1 = {
	sizeof(struct BSM),
	offsetof(struct BSM, _asn_ctx),
	asn_MAP_BSM_tag2el_1,
	16,	/* Count of tags in the map */
	asn_MAP_BSM_oms_1,	/* Optional members */
	4, 0,	/* Root/Additions */
	16,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_BSM = {
	"BSM",
	"BSM",
	&asn_OP_SEQUENCE,
	asn_DEF_BSM_tags_1,
	sizeof(asn_DEF_BSM_tags_1)
		/sizeof(asn_DEF_BSM_tags_1[0]), /* 1 */
	asn_DEF_BSM_tags_1,	/* Same as above */
	sizeof(asn_DEF_BSM_tags_1)
		/sizeof(asn_DEF_BSM_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_BSM_1,
	16,	/* Elements count */
	&asn_SPC_BSM_specs_1	/* Additional specs */
};

