/*
 * File: ITireAppMdl.h
 *
 * Code generated for Simulink model 'ITireAppMdl'.
 *
 * Model version                  : 1.126
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Mon Dec 23 22:25:23 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: STMicroelectronics->STM32 32-bit Cortex-M
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. Traceability
 *    3. Safety precaution
 *    4. Polyspace
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ITireAppMdl_h_
#define RTW_HEADER_ITireAppMdl_h_
#include <string.h>
#ifndef ITireAppMdl_COMMON_INCLUDES_
# define ITireAppMdl_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ITireAppMdl_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  uint16_T LFPress1MinArray[60];       /* '<Root>/High_Low_PrsERR' */
  uint16_T RFPress1MinArray[60];       /* '<Root>/High_Low_PrsERR' */
  uint16_T LRPress1MinArray[60];       /* '<Root>/High_Low_PrsERR' */
  uint16_T RRPress1MinArray[60];       /* '<Root>/High_Low_PrsERR' */
  uint16_T TireRFPrsLostCount;         /* '<Root>/SensorLostERR' */
  uint16_T TireLFPrsLostCount;         /* '<Root>/SensorLostERR' */
  uint16_T TireLRPrsLostCount;         /* '<Root>/SensorLostERR' */
  uint16_T TireRRPrsLostCount;         /* '<Root>/SensorLostERR' */
  uint16_T TireLFPrsRef;               /* '<Root>/High_Low_PrsERR' */
  uint16_T TireLRPrsRef;               /* '<Root>/High_Low_PrsERR' */
  uint16_T TireRFPrsRef;               /* '<Root>/High_Low_PrsERR' */
  uint16_T TireRRPrsRef;               /* '<Root>/High_Low_PrsERR' */
  uint16_T TireLFPrsSlowCounts;        /* '<Root>/High_Low_PrsERR' */
  uint16_T TireLRPrsSlowCounts;        /* '<Root>/High_Low_PrsERR' */
  uint16_T TireRRPrsSlowCounts;        /* '<Root>/High_Low_PrsERR' */
  uint16_T TireRFPrsSlowCounts;        /* '<Root>/High_Low_PrsERR' */
  uint8_T LFPressV1MinArray[60];       /* '<Root>/High_Low_PrsERR' */
  uint8_T LRPressV1MinArray[60];       /* '<Root>/High_Low_PrsERR' */
  uint8_T RFPressV1MinArray[60];       /* '<Root>/High_Low_PrsERR' */
  uint8_T RRPressV1MinArray[60];       /* '<Root>/High_Low_PrsERR' */
  uint8_T LFTireTempStaus_m;           /* '<Root>/TireTempStatus' */
  uint8_T LRTireTempStaus_l;           /* '<Root>/TireTempStatus' */
  uint8_T RFTireTempStaus_e;           /* '<Root>/TireTempStatus' */
  uint8_T RRTireTempStaus_h;           /* '<Root>/TireTempStatus' */
  uint8_T LFTirPreSenLostErr_m;        /* '<Root>/SensorLostERR' */
  uint8_T LFTirPreSenLostErrV_e;       /* '<Root>/SensorLostERR' */
  uint8_T LRTirPreSenLostErr_d;        /* '<Root>/SensorLostERR' */
  uint8_T RFTirPreSenLostErr_h;        /* '<Root>/SensorLostERR' */
  uint8_T RRTirPreSenLostErr_l;        /* '<Root>/SensorLostERR' */
  uint8_T LRTirPreSenLostErrV_l;       /* '<Root>/SensorLostERR' */
  uint8_T RFTirPreSenLostErrV_e;       /* '<Root>/SensorLostERR' */
  uint8_T RRTirPreSenLostErrV_e;       /* '<Root>/SensorLostERR' */
  uint8_T RFTirePreStaus_b;            /* '<Root>/High_Low_PrsERR' */
  uint8_T LFTirePreStaus_l;            /* '<Root>/High_Low_PrsERR' */
  uint8_T LRTirePreStaus_p;            /* '<Root>/High_Low_PrsERR' */
  uint8_T RRTirePreStaus_o;            /* '<Root>/High_Low_PrsERR' */
  uint8_T LFTireLeakStaus_c;           /* '<Root>/High_Low_PrsERR' */
  uint8_T LRTireLeakStaus_l;           /* '<Root>/High_Low_PrsERR' */
  uint8_T RFTireLeakStaus_p;           /* '<Root>/High_Low_PrsERR' */
  uint8_T RRTireLeakStaus_c;           /* '<Root>/High_Low_PrsERR' */
  uint8_T Time1SCount;                 /* '<Root>/High_Low_PrsERR' */
} DW_ITireAppMdl_T;

/* Block signals and states (auto storage) */
extern DW_ITireAppMdl_T ITireAppMdl_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern uint8_T EngRunAtv;              /* '<Root>/EngRunAtv' */
extern uint8_T AccActPosV;             /* '<Root>/AccActPosV' */
extern uint8_T AccActPos;              /* '<Root>/AccActPos' */
extern uint8_T ThrPosV;                /* '<Root>/ThrPosV' */
extern uint8_T ThrPos;                 /* '<Root>/ThrPos' */
extern uint8_T BrkPdlPos;              /* '<Root>/BrkPdlPos' */
extern uint8_T StrWhAngV;              /* '<Root>/StrWhAngV' */
extern int16_T StrWhAng;               /* '<Root>/StrWhAng' */
extern uint8_T StrWhAngGrdV;           /* '<Root>/StrWhAngGrdV' */
extern int16_T StrWhAngGrd;            /* '<Root>/StrWhAngGrd' */
extern uint8_T CmpsOctHding;           /* '<Root>/CmpsOctHding' */
extern uint16_T CmpsCrhding;           /* '<Root>/CmpsCrhding' */
extern uint8_T OtsAirTmpV;             /* '<Root>/OtsAirTmpV' */
extern real_T OtsAirTmp;               /* '<Root>/OtsAirTmp' */
extern uint8_T VehOdoV;                /* '<Root>/VehOdoV' */
extern uint32_T VehOdo;                /* '<Root>/VehOdo' */
extern uint16_T CldrYr_154;            /* '<Root>/CldrYr_154' */
extern uint8_T CldrMth_154;            /* '<Root>/CldrMth_154' */
extern uint8_T HrsV;                   /* '<Root>/HrsV' */
extern uint8_T Hrs;                    /* '<Root>/Hrs' */
extern uint8_T MinsV;                  /* '<Root>/MinsV' */
extern uint8_T CldrDay_154;            /* '<Root>/CldrDay_154' */
extern uint8_T Mins;                   /* '<Root>/Mins' */
extern uint8_T SecV;                   /* '<Root>/SecV' */
extern uint8_T Sec;                    /* '<Root>/Sec' */
extern uint8_T PsngSysLatV;            /* '<Root>/PsngSysLatV' */
extern int32_T PsngSysLat;             /* '<Root>/PsngSysLat' */
extern uint8_T PsngSysLongV;           /* '<Root>/PsngSysLongV' */
extern int32_T PsngSysLong;            /* '<Root>/PsngSysLong' */
extern uint8_T VSELatAccV;             /* '<Root>/VSELatAccV' */
extern real_T VSELatAcc;               /* '<Root>/VSELatAcc' */
extern uint8_T VehDynYawRateV;         /* '<Root>/VehDynYawRateV' */
extern real_T VehDynYawRate;           /* '<Root>/VehDynYawRate' */
extern uint8_T ABSAtv;                 /* '<Root>/ABSAtv' */
extern uint8_T ABSFld;                 /* '<Root>/ABSFld' */
extern uint8_T TCSysAtv;               /* '<Root>/TCSysAtv' */
extern uint8_T TCSysEnbld;             /* '<Root>/TCSysEnbld' */
extern uint8_T VSEAct;                 /* '<Root>/VSEAct' */
extern real_T LonAccSnsVal;            /* '<Root>/LonAccSnsVal' */
extern real_T LatAccSnsVal;            /* '<Root>/LatAccSnsVal' */
extern uint8_T EngActStdyStTorqV;      /* '<Root>/EngActStdyStTorqV' */
extern real_T EngActStdyStTorq;        /* '<Root>/EngActStdyStTorq' */
extern uint8_T AutoTransComndGear;     /* '<Root>/AutoTransComndGear' */
extern uint8_T WSWprAct;               /* '<Root>/WSWprAct' */
extern uint8_T RnSnsOffIO;             /* '<Root>/RnSnsOffIO' */
extern uint8_T RnSnsActIO;             /* '<Root>/RnSnsActIO' */
extern uint8_T TurnWprIntIO;           /* '<Root>/TurnWprIntIO' */
extern uint8_T DrvEconMdCmd;           /* '<Root>/DrvEconMdCmd' */
extern uint8_T DrvSprtMdCmd;           /* '<Root>/DrvSprtMdCmd' */
extern uint8_T DrvTwHaulMdCmd;         /* '<Root>/DrvTwHaulMdCmd' */
extern uint8_T DrvWntrMdCmd;           /* '<Root>/DrvWntrMdCmd' */
extern uint8_T DrvHldMdCmnd;           /* '<Root>/DrvHldMdCmnd' */
extern uint8_T DrvMntnMdCmnd;          /* '<Root>/DrvMntnMdCmnd' */
extern uint8_T TireLFTmpV;             /* '<Root>/TireLFTmpV' */
extern int16_T TireLFTmp;              /* '<Root>/TireLFTmp' */
extern uint8_T TireLRTmpV;             /* '<Root>/TireLRTmpV' */
extern int16_T TireLRTmp;              /* '<Root>/TireLRTmp' */
extern uint8_T TireRFTmpV;             /* '<Root>/TireRFTmpV' */
extern int16_T TireRFTmp;              /* '<Root>/TireRFTmp' */
extern uint8_T TireRRTmpV;             /* '<Root>/TireRRTmpV' */
extern int16_T TireRRTmp;              /* '<Root>/TireRRTmp' */
extern uint8_T TireRFPrsV;             /* '<Root>/TireRFPrsV' */
extern uint16_T TireLFPrs;             /* '<Root>/TireLFPrs' */
extern uint8_T TireRRPrsV;             /* '<Root>/TireRRPrsV' */
extern uint8_T TireLRPrsV;             /* '<Root>/TireLRPrsV' */
extern uint16_T TireLRPrs;             /* '<Root>/TireLRPrs' */
extern uint16_T TireRFPrs;             /* '<Root>/TireRFPrs' */
extern uint16_T TireRRPrs;             /* '<Root>/TireRRPrs' */
extern real_T VehSpdAvgNDrvn;          /* '<Root>/VehSpdAvgNDrvn' */
extern uint8_T VehSpdAvgNDrvnV;        /* '<Root>/VehSpdAvgNDrvnV' */
extern uint8_T TireLFPrsV;             /* '<Root>/TireLFPrsV' */
extern uint8_T LFTireTempStaus;        /* '<Root>/TireTempStatus' */
extern uint8_T LRTireTempStaus;        /* '<Root>/TireTempStatus' */
extern uint8_T RFTireTempStaus;        /* '<Root>/TireTempStatus' */
extern uint8_T RRTireTempStaus;        /* '<Root>/TireTempStatus' */
extern uint8_T LFTirPreSenLostErr;     /* '<Root>/SensorLostERR' */
extern uint8_T LFTirPreSenLostErrV;    /* '<Root>/SensorLostERR' */
extern uint8_T LRTirPreSenLostErr;     /* '<Root>/SensorLostERR' */
extern uint8_T RFTirPreSenLostErr;     /* '<Root>/SensorLostERR' */
extern uint8_T RRTirPreSenLostErr;     /* '<Root>/SensorLostERR' */
extern uint8_T LRTirPreSenLostErrV;    /* '<Root>/SensorLostERR' */
extern uint8_T RFTirPreSenLostErrV;    /* '<Root>/SensorLostERR' */
extern uint8_T RRTirPreSenLostErrV;    /* '<Root>/SensorLostERR' */
extern uint8_T TireSlowLifeLF;         /* '<Root>/High_Low_PrsERR' */
extern uint8_T TireSlowLifeLR;         /* '<Root>/High_Low_PrsERR' */
extern uint8_T TireSlowLifeRF;         /* '<Root>/High_Low_PrsERR' */
extern uint8_T TireSlowLifeRR;         /* '<Root>/High_Low_PrsERR' */
extern uint8_T RFTirePreStaus;         /* '<Root>/High_Low_PrsERR' */
extern uint8_T LFTirePreStaus;         /* '<Root>/High_Low_PrsERR' */
extern uint8_T LRTirePreStaus;         /* '<Root>/High_Low_PrsERR' */
extern uint8_T RRTirePreStaus;         /* '<Root>/High_Low_PrsERR' */
extern uint8_T LFTireLeakStaus;        /* '<Root>/High_Low_PrsERR' */
extern uint8_T LRTireLeakStaus;        /* '<Root>/High_Low_PrsERR' */
extern uint8_T RFTireLeakStaus;        /* '<Root>/High_Low_PrsERR' */
extern uint8_T RRTireLeakStaus;        /* '<Root>/High_Low_PrsERR' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real_T pTireHighPreDWLimit;     /* Variable: pTireHighPreDWLimit
                                        * Referenced by: '<Root>/High_Low_PrsERR'
                                        */
extern real_T pTireHighPreUpLimit;     /* Variable: pTireHighPreUpLimit
                                        * Referenced by: '<Root>/High_Low_PrsERR'
                                        */
extern real_T pTireLowPreDWLimit;      /* Variable: pTireLowPreDWLimit
                                        * Referenced by: '<Root>/High_Low_PrsERR'
                                        */
extern real_T pTireLowPreUpLimit;      /* Variable: pTireLowPreUpLimit
                                        * Referenced by: '<Root>/High_Low_PrsERR'
                                        */
extern real_T pTirePrsLostCountTh;     /* Variable: pTirePrsLostCountTh
                                        * Referenced by: '<Root>/SensorLostERR'
                                        */

/* Model entry point functions */
extern void ITireAppMdl_initialize(void);
extern void ITireAppMdl_step(void);
extern void ITireAppMdl_terminate(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ITireAppMdl'
 * '<S1>'   : 'ITireAppMdl/High_Low_PrsERR'
 * '<S2>'   : 'ITireAppMdl/SensorLostERR'
 * '<S3>'   : 'ITireAppMdl/TireTempStatus'
 */

/*-
 * Requirements for '<Root>': ITireAppMdl
 */
#endif                                 /* RTW_HEADER_ITireAppMdl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
