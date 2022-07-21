/* Generated with snc from sncExOpt.i */

/* Program "snctest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
# line 6 "../sncExOpt.st"
static	float v = 0;


/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
}

/****** Code for state "low" in state set "ss1" ******/

/* Entry function for state "low" in state set "ss1" */
static void I_ss1_0_low(SS_ID ssId, struct UserVar *pVar)
{
# line 17 "../sncExOpt.st"
	printf("Will do this on entry");
# line 18 "../sncExOpt.st"
	printf("Another thing to do on entry");
}

/* Delay function for state "low" in state set "ss1" */
static void D_ss1_0_low(SS_ID ssId, struct UserVar *pVar)
{
# line 24 "../sncExOpt.st"
	seq_delayInit(ssId, 0, (.1));
}

/* Event function for state "low" in state set "ss1" */
static seqBool E_ss1_0_low(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 20 "../sncExOpt.st"
	if (v > 5.0)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
# line 24 "../sncExOpt.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "low" in state set "ss1" */
static void A_ss1_0_low(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 22 "../sncExOpt.st"
			printf("now changing to high\n");
		}
		return;
	case 1:
		{
		}
		return;
	}
}

/****** Code for state "high" in state set "ss1" ******/

/* Delay function for state "high" in state set "ss1" */
static void D_ss1_0_high(SS_ID ssId, struct UserVar *pVar)
{
# line 36 "../sncExOpt.st"
	seq_delayInit(ssId, 0, (.1));
}

/* Event function for state "high" in state set "ss1" */
static seqBool E_ss1_0_high(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 32 "../sncExOpt.st"
	if (v <= 5.0)
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
# line 36 "../sncExOpt.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 1;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "high" in state set "ss1" */
static void A_ss1_0_high(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 34 "../sncExOpt.st"
			printf("changing to low\n");
		}
		return;
	case 1:
		{
		}
		return;
	}
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"{user}:xxxExample", (size_t)&v, "v", "float", 1, 1, 0, 1, 0, 0}
};

/* Event masks for state set "ss1" */
static const seqMask	EM_ss1_0_low[] = {
	0x00000002,
};
static const seqMask	EM_ss1_0_high[] = {
	0x00000002,
};

/* State table for state set "ss1" */
static seqState G_ss1_states[] = {
	{
	/* state name */        "low",
	/* action function */   A_ss1_0_low,
	/* event function */    E_ss1_0_low,
	/* delay function */    D_ss1_0_low,
	/* entry function */    I_ss1_0_low,
	/* exit function */     0,
	/* event mask array */  EM_ss1_0_low,
	/* state options */     (0)
	},
	{
	/* state name */        "high",
	/* action function */   A_ss1_0_high,
	/* event function */    E_ss1_0_high,
	/* delay function */    D_ss1_0_high,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_ss1_0_high,
	/* state options */     (0 | OPT_NORESETTIMERS)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "ss1",
	/* states */            G_ss1_states,
	/* number of states */  2,
	/* number of delays */  1
	},
};

/* Program table (global) */
seqProgram snctest = {
	/* magic number */      2001021,
	/* program name */      "snctest",
	/* channels */          G_channels,
	/* num. channels */     1,
	/* state sets */        G_state_sets,
	/* num. state sets */   1,
	/* user var size */     0,
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        NULL,
	/* exit func */         NULL,
	/* num. queues */       0
};

#define PROG_NAME snctest
#include "seqMain.c"

/* Register sequencer commands and program */
#include "epicsExport.h"
static void snctestRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&snctest);
}
epicsExportRegistrar(snctestRegistrar);
