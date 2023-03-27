/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r17.3.0/38413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER`
 */

#include "NGAP_LoggingInterval.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
asn_per_constraints_t asn_PER_type_NGAP_LoggingInterval_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  4,  4,  0,  10 }	/* (0..10,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static const asn_INTEGER_enum_map_t asn_MAP_NGAP_LoggingInterval_value2enum_1[] = {
	{ 0,	5,	"ms320" },
	{ 1,	5,	"ms640" },
	{ 2,	6,	"ms1280" },
	{ 3,	6,	"ms2560" },
	{ 4,	6,	"ms5120" },
	{ 5,	7,	"ms10240" },
	{ 6,	7,	"ms20480" },
	{ 7,	7,	"ms30720" },
	{ 8,	7,	"ms40960" },
	{ 9,	7,	"ms61440" },
	{ 10,	8,	"infinity" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_NGAP_LoggingInterval_enum2value_1[] = {
	10,	/* infinity(10) */
	5,	/* ms10240(5) */
	2,	/* ms1280(2) */
	6,	/* ms20480(6) */
	3,	/* ms2560(3) */
	7,	/* ms30720(7) */
	0,	/* ms320(0) */
	8,	/* ms40960(8) */
	4,	/* ms5120(4) */
	9,	/* ms61440(9) */
	1	/* ms640(1) */
	/* This list is extensible */
};
const asn_INTEGER_specifics_t asn_SPC_NGAP_LoggingInterval_specs_1 = {
	asn_MAP_NGAP_LoggingInterval_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_NGAP_LoggingInterval_enum2value_1,	/* N => "tag"; sorted by N */
	11,	/* Number of elements in the maps */
	12,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_NGAP_LoggingInterval_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_NGAP_LoggingInterval = {
	"LoggingInterval",
	"LoggingInterval",
	&asn_OP_NativeEnumerated,
	asn_DEF_NGAP_LoggingInterval_tags_1,
	sizeof(asn_DEF_NGAP_LoggingInterval_tags_1)
		/sizeof(asn_DEF_NGAP_LoggingInterval_tags_1[0]), /* 1 */
	asn_DEF_NGAP_LoggingInterval_tags_1,	/* Same as above */
	sizeof(asn_DEF_NGAP_LoggingInterval_tags_1)
		/sizeof(asn_DEF_NGAP_LoggingInterval_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_NGAP_LoggingInterval_constr_1,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_NGAP_LoggingInterval_specs_1	/* Additional specs */
};
