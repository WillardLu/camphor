/*-------------------------------------------------------------------------
 *
 * pg_subscription_rel_d.h
 *    Macro definitions for pg_subscription_rel
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
#ifndef PG_SUBSCRIPTION_REL_D_H
#define PG_SUBSCRIPTION_REL_D_H

#define SubscriptionRelRelationId 6102
#define SubscriptionRelSrrelidSrsubidIndexId 6117

#define Anum_pg_subscription_rel_srsubid 1
#define Anum_pg_subscription_rel_srrelid 2
#define Anum_pg_subscription_rel_srsubstate 3
#define Anum_pg_subscription_rel_srsublsn 4

#define Natts_pg_subscription_rel 4


/* ----------------
 *		substate constants
 * ----------------
 */
#define SUBREL_STATE_INIT		'i' /* initializing (sublsn NULL) */
#define SUBREL_STATE_DATASYNC	'd' /* data is being synchronized (sublsn
									 * NULL) */
#define SUBREL_STATE_FINISHEDCOPY 'f'	/* tablesync copy phase is completed
										 * (sublsn NULL) */
#define SUBREL_STATE_SYNCDONE	's' /* synchronization finished in front of
									 * apply (sublsn set) */
#define SUBREL_STATE_READY		'r' /* ready (sublsn set) */

/* These are never stored in the catalog, we only use them for IPC. */
#define SUBREL_STATE_UNKNOWN	'\0'	/* unknown state */
#define SUBREL_STATE_SYNCWAIT	'w' /* waiting for sync */
#define SUBREL_STATE_CATCHUP	'c' /* catching up with apply */


#endif							/* PG_SUBSCRIPTION_REL_D_H */
