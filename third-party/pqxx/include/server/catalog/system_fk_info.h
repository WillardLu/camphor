/*-------------------------------------------------------------------------
 *
 * system_fk_info.h
 *    Data about the foreign-key relationships in the system catalogs
 *
 * Portions Copyright (c) 1996-2023, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * NOTES
 *  ******************************
 *  *** DO NOT EDIT THIS FILE! ***
 *  ******************************
 *
 *  It has been GENERATED by src/backend/catalog/genbki.pl
 *
 *-------------------------------------------------------------------------
 */
#ifndef SYSTEM_FK_INFO_H
#define SYSTEM_FK_INFO_H

typedef struct SysFKRelationship
{
	Oid			fk_table;		/* referencing catalog */
	Oid			pk_table;		/* referenced catalog */
	const char *fk_columns;		/* referencing column name(s) */
	const char *pk_columns;		/* referenced column name(s) */
	bool		is_array;		/* if true, last fk_column is an array */
	bool		is_opt;			/* if true, fk_column can be zero */
} SysFKRelationship;

static const SysFKRelationship sys_fk_relationships[] = {
	{ /* pg_proc */ 1255, /* pg_namespace */ 2615, "{pronamespace}", "{oid}", false, false},
	{ /* pg_proc */ 1255, /* pg_authid */ 1260, "{proowner}", "{oid}", false, false},
	{ /* pg_proc */ 1255, /* pg_language */ 2612, "{prolang}", "{oid}", false, false},
	{ /* pg_proc */ 1255, /* pg_type */ 1247, "{provariadic}", "{oid}", false, true},
	{ /* pg_proc */ 1255, /* pg_proc */ 1255, "{prosupport}", "{oid}", false, true},
	{ /* pg_proc */ 1255, /* pg_type */ 1247, "{prorettype}", "{oid}", false, false},
	{ /* pg_proc */ 1255, /* pg_type */ 1247, "{proargtypes}", "{oid}", true, false},
	{ /* pg_proc */ 1255, /* pg_type */ 1247, "{proallargtypes}", "{oid}", true, false},
	{ /* pg_proc */ 1255, /* pg_type */ 1247, "{protrftypes}", "{oid}", true, false},
	{ /* pg_type */ 1247, /* pg_namespace */ 2615, "{typnamespace}", "{oid}", false, false},
	{ /* pg_type */ 1247, /* pg_authid */ 1260, "{typowner}", "{oid}", false, false},
	{ /* pg_type */ 1247, /* pg_class */ 1259, "{typrelid}", "{oid}", false, true},
	{ /* pg_type */ 1247, /* pg_proc */ 1255, "{typsubscript}", "{oid}", false, true},
	{ /* pg_type */ 1247, /* pg_type */ 1247, "{typelem}", "{oid}", false, true},
	{ /* pg_type */ 1247, /* pg_type */ 1247, "{typarray}", "{oid}", false, true},
	{ /* pg_type */ 1247, /* pg_proc */ 1255, "{typinput}", "{oid}", false, false},
	{ /* pg_type */ 1247, /* pg_proc */ 1255, "{typoutput}", "{oid}", false, false},
	{ /* pg_type */ 1247, /* pg_proc */ 1255, "{typreceive}", "{oid}", false, true},
	{ /* pg_type */ 1247, /* pg_proc */ 1255, "{typsend}", "{oid}", false, true},
	{ /* pg_type */ 1247, /* pg_proc */ 1255, "{typmodin}", "{oid}", false, true},
	{ /* pg_type */ 1247, /* pg_proc */ 1255, "{typmodout}", "{oid}", false, true},
	{ /* pg_type */ 1247, /* pg_proc */ 1255, "{typanalyze}", "{oid}", false, true},
	{ /* pg_type */ 1247, /* pg_type */ 1247, "{typbasetype}", "{oid}", false, true},
	{ /* pg_type */ 1247, /* pg_collation */ 3456, "{typcollation}", "{oid}", false, true},
	{ /* pg_attribute */ 1249, /* pg_class */ 1259, "{attrelid}", "{oid}", false, false},
	{ /* pg_attribute */ 1249, /* pg_type */ 1247, "{atttypid}", "{oid}", false, true},
	{ /* pg_attribute */ 1249, /* pg_collation */ 3456, "{attcollation}", "{oid}", false, true},
	{ /* pg_class */ 1259, /* pg_namespace */ 2615, "{relnamespace}", "{oid}", false, false},
	{ /* pg_class */ 1259, /* pg_type */ 1247, "{reltype}", "{oid}", false, true},
	{ /* pg_class */ 1259, /* pg_type */ 1247, "{reloftype}", "{oid}", false, true},
	{ /* pg_class */ 1259, /* pg_authid */ 1260, "{relowner}", "{oid}", false, false},
	{ /* pg_class */ 1259, /* pg_am */ 2601, "{relam}", "{oid}", false, true},
	{ /* pg_class */ 1259, /* pg_tablespace */ 1213, "{reltablespace}", "{oid}", false, true},
	{ /* pg_class */ 1259, /* pg_class */ 1259, "{reltoastrelid}", "{oid}", false, true},
	{ /* pg_class */ 1259, /* pg_class */ 1259, "{relrewrite}", "{oid}", false, true},
	{ /* pg_attrdef */ 2604, /* pg_class */ 1259, "{adrelid}", "{oid}", false, false},
	{ /* pg_attrdef */ 2604, /* pg_attribute */ 1249, "{adrelid, adnum}", "{attrelid, attnum}", false, false},
	{ /* pg_constraint */ 2606, /* pg_namespace */ 2615, "{connamespace}", "{oid}", false, false},
	{ /* pg_constraint */ 2606, /* pg_class */ 1259, "{conrelid}", "{oid}", false, true},
	{ /* pg_constraint */ 2606, /* pg_type */ 1247, "{contypid}", "{oid}", false, true},
	{ /* pg_constraint */ 2606, /* pg_class */ 1259, "{conindid}", "{oid}", false, true},
	{ /* pg_constraint */ 2606, /* pg_constraint */ 2606, "{conparentid}", "{oid}", false, true},
	{ /* pg_constraint */ 2606, /* pg_class */ 1259, "{confrelid}", "{oid}", false, true},
	{ /* pg_constraint */ 2606, /* pg_operator */ 2617, "{conpfeqop}", "{oid}", true, false},
	{ /* pg_constraint */ 2606, /* pg_operator */ 2617, "{conppeqop}", "{oid}", true, false},
	{ /* pg_constraint */ 2606, /* pg_operator */ 2617, "{conffeqop}", "{oid}", true, false},
	{ /* pg_constraint */ 2606, /* pg_operator */ 2617, "{conexclop}", "{oid}", true, false},
	{ /* pg_constraint */ 2606, /* pg_attribute */ 1249, "{conrelid, conkey}", "{attrelid, attnum}", true, true},
	{ /* pg_constraint */ 2606, /* pg_attribute */ 1249, "{confrelid, confkey}", "{attrelid, attnum}", true, false},
	{ /* pg_inherits */ 2611, /* pg_class */ 1259, "{inhrelid}", "{oid}", false, false},
	{ /* pg_inherits */ 2611, /* pg_class */ 1259, "{inhparent}", "{oid}", false, false},
	{ /* pg_index */ 2610, /* pg_class */ 1259, "{indexrelid}", "{oid}", false, false},
	{ /* pg_index */ 2610, /* pg_class */ 1259, "{indrelid}", "{oid}", false, false},
	{ /* pg_index */ 2610, /* pg_collation */ 3456, "{indcollation}", "{oid}", true, true},
	{ /* pg_index */ 2610, /* pg_opclass */ 2616, "{indclass}", "{oid}", true, false},
	{ /* pg_index */ 2610, /* pg_attribute */ 1249, "{indrelid, indkey}", "{attrelid, attnum}", true, true},
	{ /* pg_operator */ 2617, /* pg_namespace */ 2615, "{oprnamespace}", "{oid}", false, false},
	{ /* pg_operator */ 2617, /* pg_authid */ 1260, "{oprowner}", "{oid}", false, false},
	{ /* pg_operator */ 2617, /* pg_type */ 1247, "{oprleft}", "{oid}", false, true},
	{ /* pg_operator */ 2617, /* pg_type */ 1247, "{oprright}", "{oid}", false, false},
	{ /* pg_operator */ 2617, /* pg_type */ 1247, "{oprresult}", "{oid}", false, true},
	{ /* pg_operator */ 2617, /* pg_operator */ 2617, "{oprcom}", "{oid}", false, true},
	{ /* pg_operator */ 2617, /* pg_operator */ 2617, "{oprnegate}", "{oid}", false, true},
	{ /* pg_operator */ 2617, /* pg_proc */ 1255, "{oprcode}", "{oid}", false, true},
	{ /* pg_operator */ 2617, /* pg_proc */ 1255, "{oprrest}", "{oid}", false, true},
	{ /* pg_operator */ 2617, /* pg_proc */ 1255, "{oprjoin}", "{oid}", false, true},
	{ /* pg_opfamily */ 2753, /* pg_am */ 2601, "{opfmethod}", "{oid}", false, false},
	{ /* pg_opfamily */ 2753, /* pg_namespace */ 2615, "{opfnamespace}", "{oid}", false, false},
	{ /* pg_opfamily */ 2753, /* pg_authid */ 1260, "{opfowner}", "{oid}", false, false},
	{ /* pg_opclass */ 2616, /* pg_am */ 2601, "{opcmethod}", "{oid}", false, false},
	{ /* pg_opclass */ 2616, /* pg_namespace */ 2615, "{opcnamespace}", "{oid}", false, false},
	{ /* pg_opclass */ 2616, /* pg_authid */ 1260, "{opcowner}", "{oid}", false, false},
	{ /* pg_opclass */ 2616, /* pg_opfamily */ 2753, "{opcfamily}", "{oid}", false, false},
	{ /* pg_opclass */ 2616, /* pg_type */ 1247, "{opcintype}", "{oid}", false, false},
	{ /* pg_opclass */ 2616, /* pg_type */ 1247, "{opckeytype}", "{oid}", false, true},
	{ /* pg_am */ 2601, /* pg_proc */ 1255, "{amhandler}", "{oid}", false, false},
	{ /* pg_amop */ 2602, /* pg_opfamily */ 2753, "{amopfamily}", "{oid}", false, false},
	{ /* pg_amop */ 2602, /* pg_type */ 1247, "{amoplefttype}", "{oid}", false, false},
	{ /* pg_amop */ 2602, /* pg_type */ 1247, "{amoprighttype}", "{oid}", false, false},
	{ /* pg_amop */ 2602, /* pg_operator */ 2617, "{amopopr}", "{oid}", false, false},
	{ /* pg_amop */ 2602, /* pg_am */ 2601, "{amopmethod}", "{oid}", false, false},
	{ /* pg_amop */ 2602, /* pg_opfamily */ 2753, "{amopsortfamily}", "{oid}", false, true},
	{ /* pg_amproc */ 2603, /* pg_opfamily */ 2753, "{amprocfamily}", "{oid}", false, false},
	{ /* pg_amproc */ 2603, /* pg_type */ 1247, "{amproclefttype}", "{oid}", false, false},
	{ /* pg_amproc */ 2603, /* pg_type */ 1247, "{amprocrighttype}", "{oid}", false, false},
	{ /* pg_amproc */ 2603, /* pg_proc */ 1255, "{amproc}", "{oid}", false, false},
	{ /* pg_language */ 2612, /* pg_authid */ 1260, "{lanowner}", "{oid}", false, false},
	{ /* pg_language */ 2612, /* pg_proc */ 1255, "{lanplcallfoid}", "{oid}", false, true},
	{ /* pg_language */ 2612, /* pg_proc */ 1255, "{laninline}", "{oid}", false, true},
	{ /* pg_language */ 2612, /* pg_proc */ 1255, "{lanvalidator}", "{oid}", false, true},
	{ /* pg_largeobject_metadata */ 2995, /* pg_authid */ 1260, "{lomowner}", "{oid}", false, false},
	{ /* pg_largeobject */ 2613, /* pg_largeobject_metadata */ 2995, "{loid}", "{oid}", false, false},
	{ /* pg_aggregate */ 2600, /* pg_proc */ 1255, "{aggfnoid}", "{oid}", false, false},
	{ /* pg_aggregate */ 2600, /* pg_proc */ 1255, "{aggtransfn}", "{oid}", false, false},
	{ /* pg_aggregate */ 2600, /* pg_proc */ 1255, "{aggfinalfn}", "{oid}", false, true},
	{ /* pg_aggregate */ 2600, /* pg_proc */ 1255, "{aggcombinefn}", "{oid}", false, true},
	{ /* pg_aggregate */ 2600, /* pg_proc */ 1255, "{aggserialfn}", "{oid}", false, true},
	{ /* pg_aggregate */ 2600, /* pg_proc */ 1255, "{aggdeserialfn}", "{oid}", false, true},
	{ /* pg_aggregate */ 2600, /* pg_proc */ 1255, "{aggmtransfn}", "{oid}", false, true},
	{ /* pg_aggregate */ 2600, /* pg_proc */ 1255, "{aggminvtransfn}", "{oid}", false, true},
	{ /* pg_aggregate */ 2600, /* pg_proc */ 1255, "{aggmfinalfn}", "{oid}", false, true},
	{ /* pg_aggregate */ 2600, /* pg_operator */ 2617, "{aggsortop}", "{oid}", false, true},
	{ /* pg_aggregate */ 2600, /* pg_type */ 1247, "{aggtranstype}", "{oid}", false, false},
	{ /* pg_aggregate */ 2600, /* pg_type */ 1247, "{aggmtranstype}", "{oid}", false, true},
	{ /* pg_statistic */ 2619, /* pg_class */ 1259, "{starelid}", "{oid}", false, false},
	{ /* pg_statistic */ 2619, /* pg_operator */ 2617, "{staop1}", "{oid}", false, true},
	{ /* pg_statistic */ 2619, /* pg_operator */ 2617, "{staop2}", "{oid}", false, true},
	{ /* pg_statistic */ 2619, /* pg_operator */ 2617, "{staop3}", "{oid}", false, true},
	{ /* pg_statistic */ 2619, /* pg_operator */ 2617, "{staop4}", "{oid}", false, true},
	{ /* pg_statistic */ 2619, /* pg_operator */ 2617, "{staop5}", "{oid}", false, true},
	{ /* pg_statistic */ 2619, /* pg_collation */ 3456, "{stacoll1}", "{oid}", false, true},
	{ /* pg_statistic */ 2619, /* pg_collation */ 3456, "{stacoll2}", "{oid}", false, true},
	{ /* pg_statistic */ 2619, /* pg_collation */ 3456, "{stacoll3}", "{oid}", false, true},
	{ /* pg_statistic */ 2619, /* pg_collation */ 3456, "{stacoll4}", "{oid}", false, true},
	{ /* pg_statistic */ 2619, /* pg_collation */ 3456, "{stacoll5}", "{oid}", false, true},
	{ /* pg_statistic */ 2619, /* pg_attribute */ 1249, "{starelid, staattnum}", "{attrelid, attnum}", false, false},
	{ /* pg_statistic_ext */ 3381, /* pg_class */ 1259, "{stxrelid}", "{oid}", false, false},
	{ /* pg_statistic_ext */ 3381, /* pg_namespace */ 2615, "{stxnamespace}", "{oid}", false, false},
	{ /* pg_statistic_ext */ 3381, /* pg_authid */ 1260, "{stxowner}", "{oid}", false, false},
	{ /* pg_statistic_ext */ 3381, /* pg_attribute */ 1249, "{stxrelid, stxkeys}", "{attrelid, attnum}", true, false},
	{ /* pg_statistic_ext_data */ 3429, /* pg_statistic_ext */ 3381, "{stxoid}", "{oid}", false, false},
	{ /* pg_rewrite */ 2618, /* pg_class */ 1259, "{ev_class}", "{oid}", false, false},
	{ /* pg_trigger */ 2620, /* pg_class */ 1259, "{tgrelid}", "{oid}", false, false},
	{ /* pg_trigger */ 2620, /* pg_trigger */ 2620, "{tgparentid}", "{oid}", false, true},
	{ /* pg_trigger */ 2620, /* pg_proc */ 1255, "{tgfoid}", "{oid}", false, false},
	{ /* pg_trigger */ 2620, /* pg_class */ 1259, "{tgconstrrelid}", "{oid}", false, true},
	{ /* pg_trigger */ 2620, /* pg_class */ 1259, "{tgconstrindid}", "{oid}", false, true},
	{ /* pg_trigger */ 2620, /* pg_constraint */ 2606, "{tgconstraint}", "{oid}", false, true},
	{ /* pg_trigger */ 2620, /* pg_attribute */ 1249, "{tgrelid, tgattr}", "{attrelid, attnum}", true, false},
	{ /* pg_event_trigger */ 3466, /* pg_authid */ 1260, "{evtowner}", "{oid}", false, false},
	{ /* pg_event_trigger */ 3466, /* pg_proc */ 1255, "{evtfoid}", "{oid}", false, false},
	{ /* pg_description */ 2609, /* pg_class */ 1259, "{classoid}", "{oid}", false, false},
	{ /* pg_cast */ 2605, /* pg_type */ 1247, "{castsource}", "{oid}", false, false},
	{ /* pg_cast */ 2605, /* pg_type */ 1247, "{casttarget}", "{oid}", false, false},
	{ /* pg_cast */ 2605, /* pg_proc */ 1255, "{castfunc}", "{oid}", false, true},
	{ /* pg_enum */ 3501, /* pg_type */ 1247, "{enumtypid}", "{oid}", false, false},
	{ /* pg_namespace */ 2615, /* pg_authid */ 1260, "{nspowner}", "{oid}", false, false},
	{ /* pg_conversion */ 2607, /* pg_namespace */ 2615, "{connamespace}", "{oid}", false, false},
	{ /* pg_conversion */ 2607, /* pg_authid */ 1260, "{conowner}", "{oid}", false, false},
	{ /* pg_conversion */ 2607, /* pg_proc */ 1255, "{conproc}", "{oid}", false, false},
	{ /* pg_depend */ 2608, /* pg_class */ 1259, "{classid}", "{oid}", false, false},
	{ /* pg_depend */ 2608, /* pg_class */ 1259, "{refclassid}", "{oid}", false, false},
	{ /* pg_database */ 1262, /* pg_authid */ 1260, "{datdba}", "{oid}", false, false},
	{ /* pg_database */ 1262, /* pg_tablespace */ 1213, "{dattablespace}", "{oid}", false, false},
	{ /* pg_db_role_setting */ 2964, /* pg_database */ 1262, "{setdatabase}", "{oid}", false, true},
	{ /* pg_db_role_setting */ 2964, /* pg_authid */ 1260, "{setrole}", "{oid}", false, true},
	{ /* pg_tablespace */ 1213, /* pg_authid */ 1260, "{spcowner}", "{oid}", false, false},
	{ /* pg_auth_members */ 1261, /* pg_authid */ 1260, "{roleid}", "{oid}", false, false},
	{ /* pg_auth_members */ 1261, /* pg_authid */ 1260, "{member}", "{oid}", false, false},
	{ /* pg_auth_members */ 1261, /* pg_authid */ 1260, "{grantor}", "{oid}", false, false},
	{ /* pg_shdepend */ 1214, /* pg_database */ 1262, "{dbid}", "{oid}", false, true},
	{ /* pg_shdepend */ 1214, /* pg_class */ 1259, "{classid}", "{oid}", false, false},
	{ /* pg_shdepend */ 1214, /* pg_class */ 1259, "{refclassid}", "{oid}", false, false},
	{ /* pg_shdescription */ 2396, /* pg_class */ 1259, "{classoid}", "{oid}", false, false},
	{ /* pg_ts_config */ 3602, /* pg_namespace */ 2615, "{cfgnamespace}", "{oid}", false, false},
	{ /* pg_ts_config */ 3602, /* pg_authid */ 1260, "{cfgowner}", "{oid}", false, false},
	{ /* pg_ts_config */ 3602, /* pg_ts_parser */ 3601, "{cfgparser}", "{oid}", false, false},
	{ /* pg_ts_config_map */ 3603, /* pg_ts_config */ 3602, "{mapcfg}", "{oid}", false, false},
	{ /* pg_ts_config_map */ 3603, /* pg_ts_dict */ 3600, "{mapdict}", "{oid}", false, false},
	{ /* pg_ts_dict */ 3600, /* pg_namespace */ 2615, "{dictnamespace}", "{oid}", false, false},
	{ /* pg_ts_dict */ 3600, /* pg_authid */ 1260, "{dictowner}", "{oid}", false, false},
	{ /* pg_ts_dict */ 3600, /* pg_ts_template */ 3764, "{dicttemplate}", "{oid}", false, false},
	{ /* pg_ts_parser */ 3601, /* pg_namespace */ 2615, "{prsnamespace}", "{oid}", false, false},
	{ /* pg_ts_parser */ 3601, /* pg_proc */ 1255, "{prsstart}", "{oid}", false, false},
	{ /* pg_ts_parser */ 3601, /* pg_proc */ 1255, "{prstoken}", "{oid}", false, false},
	{ /* pg_ts_parser */ 3601, /* pg_proc */ 1255, "{prsend}", "{oid}", false, false},
	{ /* pg_ts_parser */ 3601, /* pg_proc */ 1255, "{prsheadline}", "{oid}", false, true},
	{ /* pg_ts_parser */ 3601, /* pg_proc */ 1255, "{prslextype}", "{oid}", false, false},
	{ /* pg_ts_template */ 3764, /* pg_namespace */ 2615, "{tmplnamespace}", "{oid}", false, false},
	{ /* pg_ts_template */ 3764, /* pg_proc */ 1255, "{tmplinit}", "{oid}", false, true},
	{ /* pg_ts_template */ 3764, /* pg_proc */ 1255, "{tmpllexize}", "{oid}", false, false},
	{ /* pg_extension */ 3079, /* pg_authid */ 1260, "{extowner}", "{oid}", false, false},
	{ /* pg_extension */ 3079, /* pg_namespace */ 2615, "{extnamespace}", "{oid}", false, false},
	{ /* pg_extension */ 3079, /* pg_class */ 1259, "{extconfig}", "{oid}", true, false},
	{ /* pg_foreign_data_wrapper */ 2328, /* pg_authid */ 1260, "{fdwowner}", "{oid}", false, false},
	{ /* pg_foreign_data_wrapper */ 2328, /* pg_proc */ 1255, "{fdwhandler}", "{oid}", false, true},
	{ /* pg_foreign_data_wrapper */ 2328, /* pg_proc */ 1255, "{fdwvalidator}", "{oid}", false, true},
	{ /* pg_foreign_server */ 1417, /* pg_authid */ 1260, "{srvowner}", "{oid}", false, false},
	{ /* pg_foreign_server */ 1417, /* pg_foreign_data_wrapper */ 2328, "{srvfdw}", "{oid}", false, false},
	{ /* pg_user_mapping */ 1418, /* pg_authid */ 1260, "{umuser}", "{oid}", false, true},
	{ /* pg_user_mapping */ 1418, /* pg_foreign_server */ 1417, "{umserver}", "{oid}", false, false},
	{ /* pg_foreign_table */ 3118, /* pg_class */ 1259, "{ftrelid}", "{oid}", false, false},
	{ /* pg_foreign_table */ 3118, /* pg_foreign_server */ 1417, "{ftserver}", "{oid}", false, false},
	{ /* pg_policy */ 3256, /* pg_class */ 1259, "{polrelid}", "{oid}", false, false},
	{ /* pg_policy */ 3256, /* pg_authid */ 1260, "{polroles}", "{oid}", true, true},
	{ /* pg_default_acl */ 826, /* pg_authid */ 1260, "{defaclrole}", "{oid}", false, false},
	{ /* pg_default_acl */ 826, /* pg_namespace */ 2615, "{defaclnamespace}", "{oid}", false, true},
	{ /* pg_init_privs */ 3394, /* pg_class */ 1259, "{classoid}", "{oid}", false, false},
	{ /* pg_seclabel */ 3596, /* pg_class */ 1259, "{classoid}", "{oid}", false, false},
	{ /* pg_shseclabel */ 3592, /* pg_class */ 1259, "{classoid}", "{oid}", false, false},
	{ /* pg_collation */ 3456, /* pg_namespace */ 2615, "{collnamespace}", "{oid}", false, false},
	{ /* pg_collation */ 3456, /* pg_authid */ 1260, "{collowner}", "{oid}", false, false},
	{ /* pg_partitioned_table */ 3350, /* pg_class */ 1259, "{partrelid}", "{oid}", false, false},
	{ /* pg_partitioned_table */ 3350, /* pg_class */ 1259, "{partdefid}", "{oid}", false, true},
	{ /* pg_partitioned_table */ 3350, /* pg_opclass */ 2616, "{partclass}", "{oid}", true, false},
	{ /* pg_partitioned_table */ 3350, /* pg_collation */ 3456, "{partcollation}", "{oid}", true, true},
	{ /* pg_partitioned_table */ 3350, /* pg_attribute */ 1249, "{partrelid, partattrs}", "{attrelid, attnum}", true, true},
	{ /* pg_range */ 3541, /* pg_type */ 1247, "{rngtypid}", "{oid}", false, false},
	{ /* pg_range */ 3541, /* pg_type */ 1247, "{rngsubtype}", "{oid}", false, false},
	{ /* pg_range */ 3541, /* pg_type */ 1247, "{rngmultitypid}", "{oid}", false, false},
	{ /* pg_range */ 3541, /* pg_collation */ 3456, "{rngcollation}", "{oid}", false, true},
	{ /* pg_range */ 3541, /* pg_opclass */ 2616, "{rngsubopc}", "{oid}", false, false},
	{ /* pg_range */ 3541, /* pg_proc */ 1255, "{rngcanonical}", "{oid}", false, true},
	{ /* pg_range */ 3541, /* pg_proc */ 1255, "{rngsubdiff}", "{oid}", false, true},
	{ /* pg_transform */ 3576, /* pg_type */ 1247, "{trftype}", "{oid}", false, false},
	{ /* pg_transform */ 3576, /* pg_language */ 2612, "{trflang}", "{oid}", false, false},
	{ /* pg_transform */ 3576, /* pg_proc */ 1255, "{trffromsql}", "{oid}", false, true},
	{ /* pg_transform */ 3576, /* pg_proc */ 1255, "{trftosql}", "{oid}", false, true},
	{ /* pg_sequence */ 2224, /* pg_class */ 1259, "{seqrelid}", "{oid}", false, false},
	{ /* pg_sequence */ 2224, /* pg_type */ 1247, "{seqtypid}", "{oid}", false, false},
	{ /* pg_publication */ 6104, /* pg_authid */ 1260, "{pubowner}", "{oid}", false, false},
	{ /* pg_publication_namespace */ 6237, /* pg_publication */ 6104, "{pnpubid}", "{oid}", false, false},
	{ /* pg_publication_namespace */ 6237, /* pg_namespace */ 2615, "{pnnspid}", "{oid}", false, false},
	{ /* pg_publication_rel */ 6106, /* pg_publication */ 6104, "{prpubid}", "{oid}", false, false},
	{ /* pg_publication_rel */ 6106, /* pg_class */ 1259, "{prrelid}", "{oid}", false, false},
	{ /* pg_subscription */ 6100, /* pg_database */ 1262, "{subdbid}", "{oid}", false, false},
	{ /* pg_subscription */ 6100, /* pg_authid */ 1260, "{subowner}", "{oid}", false, false},
	{ /* pg_subscription_rel */ 6102, /* pg_subscription */ 6100, "{srsubid}", "{oid}", false, false},
	{ /* pg_subscription_rel */ 6102, /* pg_class */ 1259, "{srrelid}", "{oid}", false, false},
};

#endif							/* SYSTEM_FK_INFO_H */
