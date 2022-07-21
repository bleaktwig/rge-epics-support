/* Generated with snc from norace.i */

/* Program "noraceTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 9 "../raceCommon.st"
	string x;
# line 13 "../raceCommon.st"
	string y;
	struct UserVar_race1 {
		struct {
			string z;
		} UserVar_wait;
	} UserVar_race1;
	struct UserVar_race3 {
		struct {
			string z;
		} UserVar_wait;
	} UserVar_race3;
	struct UserVar_stop {
		int seconds;
	} UserVar_stop;
};

/* C code definitions */
# line 7 "../raceCommon.st"
#include "../testSupport.h"

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
		"",
		"",
		{
			{
				""
			}
		},
		{
			{
				""
			}
		},
		{
# line 136 "../raceCommon.st"
			10,
		}
	};
	*pVar = pVarInit;
}

/* Program entry func */
static void G_prog_entry(SS_ID ssId, struct UserVar *pVar)
{
# line 21 "../raceCommon.st"
	seq_test_init(10);
# line 22 "../raceCommon.st"
	testDiag("This test will run for %d seconds...", 10);
}

/****** Code for state "init" in state set "race1" ******/

/* Delay function for state "init" in state set "race1" */
static void D_race1_0_init(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "init" in state set "race1" */
static seqBool E_race1_0_init(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
	if (TRUE)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "race1" */
static void A_race1_0_init(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 28 "../raceCommon.st"
			pVar->x[0] = 0;
		}
		return;
	}
}

/****** Code for state "wait" in state set "race1" ******/

/* Delay function for state "wait" in state set "race1" */
static void D_race1_0_wait(SS_ID ssId, struct UserVar *pVar)
{
# line 35 "../raceCommon.st"
	seq_delayInit(ssId, 0, (0.001));
}

/* Event function for state "wait" in state set "race1" */
static seqBool E_race1_0_wait(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 35 "../raceCommon.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
# line 52 "../raceCommon.st"
	if ((pVar->x[0] && pVar->x[1] && pVar->x[0] != pVar->x[1]) || (pVar->y[0] && pVar->y[1] && pVar->y[0] != pVar->y[1]) || (pVar->UserVar_race1.UserVar_wait.z[0] && pVar->UserVar_race1.UserVar_wait.z[1] && pVar->UserVar_race1.UserVar_wait.z[0] != pVar->UserVar_race1.UserVar_wait.z[1]))
	{
		*pNextState = 1;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait" in state set "race1" */
static void A_race1_0_wait(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 36 "../raceCommon.st"
			int j;

# line 37 "../raceCommon.st"
			for (j = 0; j < 1000; j++)
			{
# line 38 "../raceCommon.st"
				int i;
# line 39 "../raceCommon.st"
				for (i = 0; i < MAX_STRING_SIZE; i++)
				{
# line 41 "../raceCommon.st"
					if (!pVar->x[i])
						break;
# line 42 "../raceCommon.st"
					if (pVar->x[i] != pVar->x[0])
					{
# line 44 "../raceCommon.st"
						testFail("x[0]=%c!=%c=x[%d]", pVar->x[0], pVar->x[i], i);
						break;
					}
				}
			}
		}
		return;
	case 1:
		{
# line 54 "../raceCommon.st"
			testFail("%c/%c", pVar->x[0], pVar->x[1]);
		}
		return;
	}
}

/****** Code for state "init" in state set "race2" ******/

/* Delay function for state "init" in state set "race2" */
static void D_race2_1_init(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "init" in state set "race2" */
static seqBool E_race2_1_init(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
	if (TRUE)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "race2" */
static void A_race2_1_init(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 62 "../raceCommon.st"
			pVar->x[0] = 0;
		}
		return;
	}
}

/****** Code for state "wait" in state set "race2" ******/

/* Delay function for state "wait" in state set "race2" */
static void D_race2_1_wait(SS_ID ssId, struct UserVar *pVar)
{
# line 66 "../raceCommon.st"
	seq_delayInit(ssId, 0, (0.001));
# line 81 "../raceCommon.st"
	seq_delayInit(ssId, 1, (0.002));
}

/* Event function for state "wait" in state set "race2" */
static seqBool E_race2_1_wait(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 66 "../raceCommon.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
# line 81 "../raceCommon.st"
	if (seq_delay(ssId, 1))
	{
		*pNextState = 1;
		*pTransNum = 1;
		return TRUE;
	}
# line 96 "../raceCommon.st"
	if (pVar->x[0] && pVar->x[1] && pVar->x[0] != pVar->x[1])
	{
		*pNextState = 1;
		*pTransNum = 2;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait" in state set "race2" */
static void A_race2_1_wait(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 67 "../raceCommon.st"
			int j;

# line 68 "../raceCommon.st"
			for (j = 0; j < 1000; j++)
			{
# line 69 "../raceCommon.st"
				int i;
# line 70 "../raceCommon.st"
				for (i = 0; i < MAX_STRING_SIZE; i++)
				{
# line 72 "../raceCommon.st"
					if (!pVar->x[i])
						break;
# line 73 "../raceCommon.st"
					if (pVar->x[i] != pVar->x[0])
					{
# line 75 "../raceCommon.st"
						testFail("x[0]=%c!=%c=x[%d]", pVar->x[0], pVar->x[i], i);
						break;
					}
				}
			}
		}
		return;
	case 1:
		{
# line 82 "../raceCommon.st"
			int j;

# line 83 "../raceCommon.st"
			for (j = 0; j < 1000; j++)
			{
# line 84 "../raceCommon.st"
				int i;
# line 85 "../raceCommon.st"
				for (i = 0; i < MAX_STRING_SIZE; i++)
				{
# line 87 "../raceCommon.st"
					if (!pVar->x[i])
						break;
# line 88 "../raceCommon.st"
					if (pVar->x[i] != pVar->x[0])
					{
# line 90 "../raceCommon.st"
						testFail("x[0]=%c!=%c=x[%d]", pVar->x[0], pVar->x[i], i);
						break;
					}
				}
			}
		}
		return;
	case 2:
		{
# line 98 "../raceCommon.st"
			testFail("x[0]=%c!=%c=x[1]", pVar->x[0], pVar->x[1]);
		}
		return;
	}
}

/****** Code for state "init" in state set "race3" ******/

/* Delay function for state "init" in state set "race3" */
static void D_race3_2_init(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "init" in state set "race3" */
static seqBool E_race3_2_init(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
	if (TRUE)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "race3" */
static void A_race3_2_init(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 106 "../raceCommon.st"
			pVar->x[0] = 0;
		}
		return;
	}
}

/****** Code for state "wait" in state set "race3" ******/

/* Delay function for state "wait" in state set "race3" */
static void D_race3_2_wait(SS_ID ssId, struct UserVar *pVar)
{
# line 113 "../raceCommon.st"
	seq_delayInit(ssId, 0, (0.001));
}

/* Event function for state "wait" in state set "race3" */
static seqBool E_race3_2_wait(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 113 "../raceCommon.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
# line 128 "../raceCommon.st"
	if (pVar->x[0] && pVar->x[1] && pVar->x[0] != pVar->x[1])
	{
		*pNextState = 1;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait" in state set "race3" */
static void A_race3_2_wait(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 114 "../raceCommon.st"
			int j;

# line 115 "../raceCommon.st"
			for (j = 0; j < 1000; j++)
			{
# line 116 "../raceCommon.st"
				int i;
# line 117 "../raceCommon.st"
				for (i = 0; i < MAX_STRING_SIZE; i++)
				{
# line 119 "../raceCommon.st"
					if (!pVar->x[i])
						break;
# line 120 "../raceCommon.st"
					if (pVar->x[i] != pVar->x[0])
					{
# line 122 "../raceCommon.st"
						testFail("x[0]=%c!=%c=x[%d]", pVar->x[0], pVar->x[i], i);
						break;
					}
				}
			}
		}
		return;
	case 1:
		{
# line 130 "../raceCommon.st"
			testFail("x[0]=%c!=%c=x[1]", pVar->x[0], pVar->x[1]);
		}
		return;
	}
}

/****** Code for state "count" in state set "stop" ******/

/* Delay function for state "count" in state set "stop" */
static void D_stop_3_count(SS_ID ssId, struct UserVar *pVar)
{
# line 140 "../raceCommon.st"
	seq_delayInit(ssId, 0, (1.0));
}

/* Event function for state "count" in state set "stop" */
static seqBool E_stop_3_count(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 138 "../raceCommon.st"
	if (pVar->UserVar_stop.seconds == 0)
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
# line 140 "../raceCommon.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "count" in state set "stop" */
static void A_stop_3_count(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 141 "../raceCommon.st"
			pVar->UserVar_stop.seconds -= 1;
# line 142 "../raceCommon.st"
			testPass("%d seconds left", pVar->UserVar_stop.seconds);
		}
		return;
	}
}

/* Program exit func */
static void G_prog_exit(SS_ID ssId, struct UserVar *pVar)
{
# line 148 "../raceCommon.st"
	seq_test_done();
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"x", offsetof(struct UserVar, x), "x", "string", 1, 1, 0, 1, 0, 0},
	{"", offsetof(struct UserVar, y), "y", "string", 1, 2, 0, 0, 0, 0},
	{"", offsetof(struct UserVar, UserVar_race1.UserVar_wait.z), "z", "string", 1, 3, 0, 0, 0, 0},
	{"", offsetof(struct UserVar, UserVar_race3.UserVar_wait.z), "z", "string", 1, 4, 0, 0, 0, 0}
};

/* Event masks for state set "race1" */
static const seqMask	EM_race1_0_init[] = {
	0x00000000,
};
static const seqMask	EM_race1_0_wait[] = {
	0x0000000e,
};

/* State table for state set "race1" */
static seqState G_race1_states[] = {
	{
	/* state name */        "init",
	/* action function */   A_race1_0_init,
	/* event function */    E_race1_0_init,
	/* delay function */    D_race1_0_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_race1_0_init,
	/* state options */     (0)
	},
	{
	/* state name */        "wait",
	/* action function */   A_race1_0_wait,
	/* event function */    E_race1_0_wait,
	/* delay function */    D_race1_0_wait,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_race1_0_wait,
	/* state options */     (0)
	},
};

/* Event masks for state set "race2" */
static const seqMask	EM_race2_1_init[] = {
	0x00000000,
};
static const seqMask	EM_race2_1_wait[] = {
	0x00000002,
};

/* State table for state set "race2" */
static seqState G_race2_states[] = {
	{
	/* state name */        "init",
	/* action function */   A_race2_1_init,
	/* event function */    E_race2_1_init,
	/* delay function */    D_race2_1_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_race2_1_init,
	/* state options */     (0)
	},
	{
	/* state name */        "wait",
	/* action function */   A_race2_1_wait,
	/* event function */    E_race2_1_wait,
	/* delay function */    D_race2_1_wait,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_race2_1_wait,
	/* state options */     (0)
	},
};

/* Event masks for state set "race3" */
static const seqMask	EM_race3_2_init[] = {
	0x00000000,
};
static const seqMask	EM_race3_2_wait[] = {
	0x00000002,
};

/* State table for state set "race3" */
static seqState G_race3_states[] = {
	{
	/* state name */        "init",
	/* action function */   A_race3_2_init,
	/* event function */    E_race3_2_init,
	/* delay function */    D_race3_2_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_race3_2_init,
	/* state options */     (0)
	},
	{
	/* state name */        "wait",
	/* action function */   A_race3_2_wait,
	/* event function */    E_race3_2_wait,
	/* delay function */    D_race3_2_wait,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_race3_2_wait,
	/* state options */     (0)
	},
};

/* Event masks for state set "stop" */
static const seqMask	EM_stop_3_count[] = {
	0x00000000,
};

/* State table for state set "stop" */
static seqState G_stop_states[] = {
	{
	/* state name */        "count",
	/* action function */   A_stop_3_count,
	/* event function */    E_stop_3_count,
	/* delay function */    D_stop_3_count,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_stop_3_count,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "race1",
	/* states */            G_race1_states,
	/* number of states */  2,
	/* number of delays */  1
	},

	{
	/* state set name */    "race2",
	/* states */            G_race2_states,
	/* number of states */  2,
	/* number of delays */  2
	},

	{
	/* state set name */    "race3",
	/* states */            G_race3_states,
	/* number of states */  2,
	/* number of delays */  1
	},

	{
	/* state set name */    "stop",
	/* states */            G_stop_states,
	/* number of states */  1,
	/* number of delays */  1
	},
};

/* Program table (global) */
seqProgram noraceTest = {
	/* magic number */      2001021,
	/* program name */      "noraceTest",
	/* channels */          G_channels,
	/* num. channels */     4,
	/* state sets */        G_state_sets,
	/* num. state sets */   4,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT | OPT_SAFE | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        G_prog_entry,
	/* exit func */         G_prog_exit,
	/* num. queues */       0
};

#define PROG_NAME noraceTest
#include "seqMain.c"
