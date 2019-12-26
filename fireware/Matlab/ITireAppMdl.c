/*
 * File: ITireAppMdl.c
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

#include "ITireAppMdl.h"

/* Exported block signals */
uint8_T EngRunAtv;                     /* '<Root>/EngRunAtv' */
uint8_T AccActPosV;                    /* '<Root>/AccActPosV' */
uint8_T AccActPos;                     /* '<Root>/AccActPos' */
uint8_T ThrPosV;                       /* '<Root>/ThrPosV' */
uint8_T ThrPos;                        /* '<Root>/ThrPos' */
uint8_T BrkPdlPos;                     /* '<Root>/BrkPdlPos' */
uint8_T StrWhAngV;                     /* '<Root>/StrWhAngV' */
int16_T StrWhAng;                      /* '<Root>/StrWhAng' */
uint8_T StrWhAngGrdV;                  /* '<Root>/StrWhAngGrdV' */
int16_T StrWhAngGrd;                   /* '<Root>/StrWhAngGrd' */
uint8_T CmpsOctHding;                  /* '<Root>/CmpsOctHding' */
uint16_T CmpsCrhding;                  /* '<Root>/CmpsCrhding' */
uint8_T OtsAirTmpV;                    /* '<Root>/OtsAirTmpV' */
real_T OtsAirTmp;                      /* '<Root>/OtsAirTmp' */
uint8_T VehOdoV;                       /* '<Root>/VehOdoV' */
uint32_T VehOdo;                       /* '<Root>/VehOdo' */
uint16_T CldrYr_154;                   /* '<Root>/CldrYr_154' */
uint8_T CldrMth_154;                   /* '<Root>/CldrMth_154' */
uint8_T HrsV;                          /* '<Root>/HrsV' */
uint8_T Hrs;                           /* '<Root>/Hrs' */
uint8_T MinsV;                         /* '<Root>/MinsV' */
uint8_T CldrDay_154;                   /* '<Root>/CldrDay_154' */
uint8_T Mins;                          /* '<Root>/Mins' */
uint8_T SecV;                          /* '<Root>/SecV' */
uint8_T Sec;                           /* '<Root>/Sec' */
uint8_T PsngSysLatV;                   /* '<Root>/PsngSysLatV' */
int32_T PsngSysLat;                    /* '<Root>/PsngSysLat' */
uint8_T PsngSysLongV;                  /* '<Root>/PsngSysLongV' */
int32_T PsngSysLong;                   /* '<Root>/PsngSysLong' */
uint8_T VSELatAccV;                    /* '<Root>/VSELatAccV' */
real_T VSELatAcc;                      /* '<Root>/VSELatAcc' */
uint8_T VehDynYawRateV;                /* '<Root>/VehDynYawRateV' */
real_T VehDynYawRate;                  /* '<Root>/VehDynYawRate' */
uint8_T ABSAtv;                        /* '<Root>/ABSAtv' */
uint8_T ABSFld;                        /* '<Root>/ABSFld' */
uint8_T TCSysAtv;                      /* '<Root>/TCSysAtv' */
uint8_T TCSysEnbld;                    /* '<Root>/TCSysEnbld' */
uint8_T VSEAct;                        /* '<Root>/VSEAct' */
real_T LonAccSnsVal;                   /* '<Root>/LonAccSnsVal' */
real_T LatAccSnsVal;                   /* '<Root>/LatAccSnsVal' */
uint8_T EngActStdyStTorqV;             /* '<Root>/EngActStdyStTorqV' */
real_T EngActStdyStTorq;               /* '<Root>/EngActStdyStTorq' */
uint8_T AutoTransComndGear;            /* '<Root>/AutoTransComndGear' */
uint8_T WSWprAct;                      /* '<Root>/WSWprAct' */
uint8_T RnSnsOffIO;                    /* '<Root>/RnSnsOffIO' */
uint8_T RnSnsActIO;                    /* '<Root>/RnSnsActIO' */
uint8_T TurnWprIntIO;                  /* '<Root>/TurnWprIntIO' */
uint8_T DrvEconMdCmd;                  /* '<Root>/DrvEconMdCmd' */
uint8_T DrvSprtMdCmd;                  /* '<Root>/DrvSprtMdCmd' */
uint8_T DrvTwHaulMdCmd;                /* '<Root>/DrvTwHaulMdCmd' */
uint8_T DrvWntrMdCmd;                  /* '<Root>/DrvWntrMdCmd' */
uint8_T DrvHldMdCmnd;                  /* '<Root>/DrvHldMdCmnd' */
uint8_T DrvMntnMdCmnd;                 /* '<Root>/DrvMntnMdCmnd' */
uint8_T TireLFTmpV;                    /* '<Root>/TireLFTmpV' */
int16_T TireLFTmp;                     /* '<Root>/TireLFTmp' */
uint8_T TireLRTmpV;                    /* '<Root>/TireLRTmpV' */
int16_T TireLRTmp;                     /* '<Root>/TireLRTmp' */
uint8_T TireRFTmpV;                    /* '<Root>/TireRFTmpV' */
int16_T TireRFTmp;                     /* '<Root>/TireRFTmp' */
uint8_T TireRRTmpV;                    /* '<Root>/TireRRTmpV' */
int16_T TireRRTmp;                     /* '<Root>/TireRRTmp' */
uint8_T TireRFPrsV;                    /* '<Root>/TireRFPrsV' */
uint16_T TireLFPrs;                    /* '<Root>/TireLFPrs' */
uint8_T TireRRPrsV;                    /* '<Root>/TireRRPrsV' */
uint8_T TireLRPrsV;                    /* '<Root>/TireLRPrsV' */
uint16_T TireLRPrs;                    /* '<Root>/TireLRPrs' */
uint16_T TireRFPrs;                    /* '<Root>/TireRFPrs' */
uint16_T TireRRPrs;                    /* '<Root>/TireRRPrs' */
real_T VehSpdAvgNDrvn;                 /* '<Root>/VehSpdAvgNDrvn' */
uint8_T VehSpdAvgNDrvnV;               /* '<Root>/VehSpdAvgNDrvnV' */
uint8_T TireLFPrsV;                    /* '<Root>/TireLFPrsV' */
uint8_T LFTireTempStaus;               /* '<Root>/TireTempStatus' */
uint8_T LRTireTempStaus;               /* '<Root>/TireTempStatus' */
uint8_T RFTireTempStaus;               /* '<Root>/TireTempStatus' */
uint8_T RRTireTempStaus;               /* '<Root>/TireTempStatus' */
uint8_T LFTirPreSenLostErr;            /* '<Root>/SensorLostERR' */
uint8_T LFTirPreSenLostErrV;           /* '<Root>/SensorLostERR' */
uint8_T LRTirPreSenLostErr;            /* '<Root>/SensorLostERR' */
uint8_T RFTirPreSenLostErr;            /* '<Root>/SensorLostERR' */
uint8_T RRTirPreSenLostErr;            /* '<Root>/SensorLostERR' */
uint8_T LRTirPreSenLostErrV;           /* '<Root>/SensorLostERR' */
uint8_T RFTirPreSenLostErrV;           /* '<Root>/SensorLostERR' */
uint8_T RRTirPreSenLostErrV;           /* '<Root>/SensorLostERR' */
uint8_T TireSlowLifeLF;                /* '<Root>/High_Low_PrsERR' */
uint8_T TireSlowLifeLR;                /* '<Root>/High_Low_PrsERR' */
uint8_T TireSlowLifeRF;                /* '<Root>/High_Low_PrsERR' */
uint8_T TireSlowLifeRR;                /* '<Root>/High_Low_PrsERR' */
uint8_T RFTirePreStaus;                /* '<Root>/High_Low_PrsERR' */
uint8_T LFTirePreStaus;                /* '<Root>/High_Low_PrsERR' */
uint8_T LRTirePreStaus;                /* '<Root>/High_Low_PrsERR' */
uint8_T RRTirePreStaus;                /* '<Root>/High_Low_PrsERR' */
uint8_T LFTireLeakStaus;               /* '<Root>/High_Low_PrsERR' */
uint8_T LRTireLeakStaus;               /* '<Root>/High_Low_PrsERR' */
uint8_T RFTireLeakStaus;               /* '<Root>/High_Low_PrsERR' */
uint8_T RRTireLeakStaus;               /* '<Root>/High_Low_PrsERR' */

/* Exported block parameters */
real_T pTireHighPreDWLimit = 335.0;    /* Variable: pTireHighPreDWLimit
                                        * Referenced by: '<Root>/High_Low_PrsERR'
                                        */
real_T pTireHighPreUpLimit = 350.0;    /* Variable: pTireHighPreUpLimit
                                        * Referenced by: '<Root>/High_Low_PrsERR'
                                        */
real_T pTireLowPreDWLimit = 180.0;     /* Variable: pTireLowPreDWLimit
                                        * Referenced by: '<Root>/High_Low_PrsERR'
                                        */
real_T pTireLowPreUpLimit = 195.0;     /* Variable: pTireLowPreUpLimit
                                        * Referenced by: '<Root>/High_Low_PrsERR'
                                        */
real_T pTirePrsLostCountTh = 5400.0;   /* Variable: pTirePrsLostCountTh
                                        * Referenced by: '<Root>/SensorLostERR'
                                        */

/* Block signals and states (auto storage) */
DW_ITireAppMdl_T ITireAppMdl_DW;

/* Model step function */
void ITireAppMdl_step(void)
{
  uint8_T i;
  uint16_T tmp;
  real_T tmp_0;
  int32_T tmp_1;
  int32_T exitg1;

  /* Chart: '<Root>/SensorLostERR' incorporates:
   *  Inport: '<Root>/TireLFPrsV'
   *  Inport: '<Root>/TireLRPrsV'
   *  Inport: '<Root>/TireRFPrsV'
   *  Inport: '<Root>/TireRRPrsV'
   *  Inport: '<Root>/VehSpdAvgNDrvn'
   *  Inport: '<Root>/VehSpdAvgNDrvnV'
   */
  /* Gateway: SensorLostERR */
  /* During: SensorLostERR */
  /* Entry Internal: SensorLostERR */
  /* Transition: '<S2>:17' */
  if ((VehSpdAvgNDrvn < 37.0) || (((int32_T)VehSpdAvgNDrvnV) == 1)) {
    /* Transition: '<S2>:19' */
    ITireAppMdl_DW.LFTirPreSenLostErrV_e = 1U;
    ITireAppMdl_DW.LRTirPreSenLostErrV_l = 1U;
    ITireAppMdl_DW.RFTirPreSenLostErrV_e = 1U;
    ITireAppMdl_DW.RRTirPreSenLostErrV_e = 1U;
  } else {
    /* Transition: '<S2>:23' */
    ITireAppMdl_DW.LFTirPreSenLostErrV_e = 0U;
    ITireAppMdl_DW.LRTirPreSenLostErrV_l = 0U;
    ITireAppMdl_DW.RFTirPreSenLostErrV_e = 0U;
    ITireAppMdl_DW.RRTirPreSenLostErrV_e = 0U;
    if (((int32_T)TireRFPrsV) == 1) {
      /* Transition: '<S2>:25' */
      tmp_1 = ((int32_T)ITireAppMdl_DW.TireRFPrsLostCount) + 1;
      if (tmp_1 > 65535) {
        tmp_1 = 65535;
      }

      ITireAppMdl_DW.TireRFPrsLostCount = (uint16_T)tmp_1;
    } else {
      /* Transition: '<S2>:27' */
      ITireAppMdl_DW.TireRFPrsLostCount = 0U;

      /* Transition: '<S2>:29' */
      /* Transition: '<S2>:30' */
    }

    /* Transition: '<S2>:34' */
    if (((int32_T)TireLFPrsV) == 1) {
      /* Transition: '<S2>:115' */
      tmp_1 = ((int32_T)ITireAppMdl_DW.TireLFPrsLostCount) + 1;
      if (tmp_1 > 65535) {
        tmp_1 = 65535;
      }

      ITireAppMdl_DW.TireLFPrsLostCount = (uint16_T)tmp_1;
    } else {
      /* Transition: '<S2>:119' */
      ITireAppMdl_DW.TireLFPrsLostCount = 0U;

      /* Transition: '<S2>:121' */
      /* Transition: '<S2>:122' */
    }

    /* Transition: '<S2>:56' */
    if (((int32_T)TireLRPrsV) == 1) {
      /* Transition: '<S2>:128' */
      tmp_1 = ((int32_T)ITireAppMdl_DW.TireLRPrsLostCount) + 1;
      if (tmp_1 > 65535) {
        tmp_1 = 65535;
      }

      ITireAppMdl_DW.TireLRPrsLostCount = (uint16_T)tmp_1;
    } else {
      /* Transition: '<S2>:131' */
      ITireAppMdl_DW.TireLRPrsLostCount = 0U;

      /* Transition: '<S2>:132' */
      /* Transition: '<S2>:133' */
    }

    /* Transition: '<S2>:72' */
    if (((int32_T)TireRRPrsV) == 1) {
      /* Transition: '<S2>:117' */
      tmp_1 = ((int32_T)ITireAppMdl_DW.TireRRPrsLostCount) + 1;
      if (tmp_1 > 65535) {
        tmp_1 = 65535;
      }

      ITireAppMdl_DW.TireRRPrsLostCount = (uint16_T)tmp_1;
    } else {
      /* Transition: '<S2>:136' */
      ITireAppMdl_DW.TireRRPrsLostCount = 0U;

      /* Transition: '<S2>:137' */
      /* Transition: '<S2>:138' */
    }

    /* Transition: '<S2>:74' */
    if (((real_T)ITireAppMdl_DW.TireRFPrsLostCount) > pTirePrsLostCountTh) {
      /* Transition: '<S2>:76' */
      ITireAppMdl_DW.RFTirPreSenLostErr_h = 1U;
      tmp_0 = pTirePrsLostCountTh;
      if (tmp_0 < 65536.0) {
        if (tmp_0 >= 0.0) {
          tmp = (uint16_T)tmp_0;
        } else {
          tmp = 0U;
        }
      } else {
        tmp = MAX_uint16_T;
      }

      ITireAppMdl_DW.TireRFPrsLostCount = tmp;
    } else {
      /* Transition: '<S2>:78' */
      ITireAppMdl_DW.RFTirPreSenLostErr_h = 0U;

      /* Transition: '<S2>:80' */
      /* Transition: '<S2>:81' */
    }

    /* Transition: '<S2>:83' */
    if (((real_T)ITireAppMdl_DW.TireLFPrsLostCount) > pTirePrsLostCountTh) {
      /* Transition: '<S2>:89' */
      ITireAppMdl_DW.LFTirPreSenLostErr_m = 1U;
      tmp_0 = pTirePrsLostCountTh;
      if (tmp_0 < 65536.0) {
        if (tmp_0 >= 0.0) {
          tmp = (uint16_T)tmp_0;
        } else {
          tmp = 0U;
        }
      } else {
        tmp = MAX_uint16_T;
      }

      ITireAppMdl_DW.TireLFPrsLostCount = tmp;
    } else {
      /* Transition: '<S2>:85' */
      ITireAppMdl_DW.LFTirPreSenLostErr_m = 0U;

      /* Transition: '<S2>:86' */
      /* Transition: '<S2>:87' */
    }

    /* Transition: '<S2>:94' */
    if (((real_T)ITireAppMdl_DW.TireLRPrsLostCount) > pTirePrsLostCountTh) {
      /* Transition: '<S2>:91' */
      ITireAppMdl_DW.LRTirPreSenLostErr_d = 1U;
      tmp_0 = pTirePrsLostCountTh;
      if (tmp_0 < 65536.0) {
        if (tmp_0 >= 0.0) {
          tmp = (uint16_T)tmp_0;
        } else {
          tmp = 0U;
        }
      } else {
        tmp = MAX_uint16_T;
      }

      ITireAppMdl_DW.TireLRPrsLostCount = tmp;
    } else {
      /* Transition: '<S2>:97' */
      ITireAppMdl_DW.LRTirPreSenLostErr_d = 0U;

      /* Transition: '<S2>:95' */
      /* Transition: '<S2>:96' */
    }

    /* Transition: '<S2>:104' */
    if (((real_T)ITireAppMdl_DW.TireRRPrsLostCount) > pTirePrsLostCountTh) {
      /* Transition: '<S2>:100' */
      ITireAppMdl_DW.RRTirPreSenLostErr_l = 1U;
      tmp_0 = pTirePrsLostCountTh;
      if (tmp_0 < 65536.0) {
        if (tmp_0 >= 0.0) {
          tmp = (uint16_T)tmp_0;
        } else {
          tmp = 0U;
        }
      } else {
        tmp = MAX_uint16_T;
      }

      ITireAppMdl_DW.TireRRPrsLostCount = tmp;
    } else {
      /* Transition: '<S2>:101' */
      ITireAppMdl_DW.RRTirPreSenLostErr_l = 0U;

      /* Transition: '<S2>:108' */
      /* Transition: '<S2>:105' */
    }

    /* Transition: '<S2>:110' */
    /* Transition: '<S2>:111' */
  }

  /* SignalConversion: '<S2>/TmpBlkForSigObjICAt SFunction Outport2' incorporates:
   *  Chart: '<Root>/SensorLostERR'
   */
  LFTirPreSenLostErr = ITireAppMdl_DW.LFTirPreSenLostErr_m;

  /* SignalConversion: '<S2>/TmpBlkForSigObjICAt SFunction Outport3' incorporates:
   *  Chart: '<Root>/SensorLostERR'
   */
  LFTirPreSenLostErrV = ITireAppMdl_DW.LFTirPreSenLostErrV_e;

  /* SignalConversion: '<S2>/TmpBlkForSigObjICAt SFunction Outport4' incorporates:
   *  Chart: '<Root>/SensorLostERR'
   */
  LRTirPreSenLostErr = ITireAppMdl_DW.LRTirPreSenLostErr_d;

  /* SignalConversion: '<S2>/TmpBlkForSigObjICAt SFunction Outport5' incorporates:
   *  Chart: '<Root>/SensorLostERR'
   */
  RFTirPreSenLostErr = ITireAppMdl_DW.RFTirPreSenLostErr_h;

  /* SignalConversion: '<S2>/TmpBlkForSigObjICAt SFunction Outport6' incorporates:
   *  Chart: '<Root>/SensorLostERR'
   */
  RRTirPreSenLostErr = ITireAppMdl_DW.RRTirPreSenLostErr_l;

  /* SignalConversion: '<S2>/TmpBlkForSigObjICAt SFunction Outport7' incorporates:
   *  Chart: '<Root>/SensorLostERR'
   */
  LRTirPreSenLostErrV = ITireAppMdl_DW.LRTirPreSenLostErrV_l;

  /* SignalConversion: '<S2>/TmpBlkForSigObjICAt SFunction Outport8' incorporates:
   *  Chart: '<Root>/SensorLostERR'
   */
  RFTirPreSenLostErrV = ITireAppMdl_DW.RFTirPreSenLostErrV_e;

  /* SignalConversion: '<S2>/TmpBlkForSigObjICAt SFunction Outport9' incorporates:
   *  Chart: '<Root>/SensorLostERR'
   */
  RRTirPreSenLostErrV = ITireAppMdl_DW.RRTirPreSenLostErrV_e;

  /* Chart: '<Root>/High_Low_PrsERR' incorporates:
   *  Inport: '<Root>/TireLFPrs'
   *  Inport: '<Root>/TireLFPrsV'
   *  Inport: '<Root>/TireLRPrs'
   *  Inport: '<Root>/TireLRPrsV'
   *  Inport: '<Root>/TireRFPrs'
   *  Inport: '<Root>/TireRFPrsV'
   *  Inport: '<Root>/TireRRPrs'
   *  Inport: '<Root>/TireRRPrsV'
   */
  /* Gateway: High_Low_PrsERR */
  /* During: High_Low_PrsERR */
  /* Entry Internal: High_Low_PrsERR */
  /* Transition: '<S1>:915' */
  if (TireLFPrs > ITireAppMdl_DW.TireLFPrsRef) {
    /* Transition: '<S1>:812' */
    /* Transition: '<S1>:810' */
    ITireAppMdl_DW.TireLFPrsRef = TireLFPrs;
    ITireAppMdl_DW.TireLFPrsSlowCounts = 0U;

    /* Transition: '<S1>:816' */
  } else {
    /* Transition: '<S1>:808' */
  }

  /* Transition: '<S1>:811' */
  if (TireLRPrs > ITireAppMdl_DW.TireLRPrsRef) {
    /* Transition: '<S1>:804' */
    /* Transition: '<S1>:799' */
    ITireAppMdl_DW.TireLRPrsRef = TireLRPrs;
    ITireAppMdl_DW.TireLRPrsSlowCounts = 0U;

    /* Transition: '<S1>:805' */
  } else {
    /* Transition: '<S1>:803' */
  }

  /* Transition: '<S1>:806' */
  if (TireRFPrs > ITireAppMdl_DW.TireRFPrsRef) {
    /* Transition: '<S1>:790' */
    /* Transition: '<S1>:791' */
    ITireAppMdl_DW.TireRFPrsRef = TireRFPrs;
    ITireAppMdl_DW.TireRFPrsSlowCounts = 0U;

    /* Transition: '<S1>:797' */
  } else {
    /* Transition: '<S1>:796' */
  }

  /* Transition: '<S1>:794' */
  if (TireRRPrs > ITireAppMdl_DW.TireRRPrsRef) {
    /* Transition: '<S1>:786' */
    /* Transition: '<S1>:788' */
    ITireAppMdl_DW.TireRRPrsRef = TireRRPrs;
    ITireAppMdl_DW.TireRRPrsSlowCounts = 0U;

    /* Transition: '<S1>:789' */
  } else {
    /* Transition: '<S1>:784' */
  }

  /* Transition: '<S1>:782' */
  if (((int32_T)TireRFPrsV) == 0) {
    /* Transition: '<S1>:173' */
    if (((real_T)TireRFPrs) > pTireLowPreUpLimit) {
      /* Transition: '<S1>:161' */
      /* Transition: '<S1>:177' */
      ITireAppMdl_DW.RFTirePreStaus_b = 0U;

      /* Transition: '<S1>:178' */
    } else {
      /* Transition: '<S1>:159' */
    }

    /* Transition: '<S1>:214' */
    if (((real_T)TireRFPrs) < pTireHighPreDWLimit) {
      /* Transition: '<S1>:207' */
      /* Transition: '<S1>:206' */
      ITireAppMdl_DW.RFTirePreStaus_b = 0U;

      /* Transition: '<S1>:212' */
    } else {
      /* Transition: '<S1>:211' */
    }

    /* Transition: '<S1>:217' */
    if (((real_T)TireRFPrs) < pTireLowPreDWLimit) {
      /* Transition: '<S1>:219' */
      /* Transition: '<S1>:218' */
      ITireAppMdl_DW.RFTirePreStaus_b = 2U;

      /* Transition: '<S1>:224' */
    } else {
      /* Transition: '<S1>:223' */
    }

    /* Transition: '<S1>:230' */
    if (((real_T)TireRFPrs) > pTireHighPreUpLimit) {
      /* Transition: '<S1>:228' */
      /* Transition: '<S1>:227' */
      ITireAppMdl_DW.RFTirePreStaus_b = 1U;

      /* Transition: '<S1>:234' */
    } else {
      /* Transition: '<S1>:229' */
    }

    /* Transition: '<S1>:235' */
  } else {
    /* Transition: '<S1>:151' */
    ITireAppMdl_DW.RFTirePreStaus_b = 3U;
  }

  /* Transition: '<S1>:277' */
  if (((int32_T)TireLFPrsV) == 0) {
    /* Transition: '<S1>:243' */
    if (((real_T)TireLFPrs) > pTireLowPreUpLimit) {
      /* Transition: '<S1>:239' */
      /* Transition: '<S1>:236' */
      ITireAppMdl_DW.LFTirePreStaus_l = 0U;

      /* Transition: '<S1>:255' */
    } else {
      /* Transition: '<S1>:246' */
    }

    /* Transition: '<S1>:238' */
    if (((real_T)TireLFPrs) < pTireHighPreDWLimit) {
      /* Transition: '<S1>:248' */
      /* Transition: '<S1>:247' */
      ITireAppMdl_DW.LFTirePreStaus_l = 0U;

      /* Transition: '<S1>:253' */
    } else {
      /* Transition: '<S1>:252' */
    }

    /* Transition: '<S1>:262' */
    if (((real_T)TireLFPrs) < pTireLowPreDWLimit) {
      /* Transition: '<S1>:260' */
      /* Transition: '<S1>:259' */
      ITireAppMdl_DW.LFTirePreStaus_l = 2U;

      /* Transition: '<S1>:266' */
    } else {
      /* Transition: '<S1>:261' */
    }

    /* Transition: '<S1>:270' */
    if (((real_T)TireLFPrs) > pTireHighPreUpLimit) {
      /* Transition: '<S1>:271' */
      /* Transition: '<S1>:268' */
      ITireAppMdl_DW.LFTirePreStaus_l = 1U;

      /* Transition: '<S1>:275' */
    } else {
      /* Transition: '<S1>:269' */
    }

    /* Transition: '<S1>:257' */
  } else {
    /* Transition: '<S1>:244' */
    ITireAppMdl_DW.LFTirePreStaus_l = 3U;
  }

  /* Transition: '<S1>:319' */
  if (((int32_T)TireLRPrsV) == 0) {
    /* Transition: '<S1>:286' */
    if (((real_T)TireLRPrs) > pTireLowPreUpLimit) {
      /* Transition: '<S1>:283' */
      /* Transition: '<S1>:282' */
      ITireAppMdl_DW.LRTirePreStaus_p = 0U;

      /* Transition: '<S1>:296' */
    } else {
      /* Transition: '<S1>:288' */
    }

    /* Transition: '<S1>:287' */
    if (((real_T)TireLRPrs) < pTireHighPreDWLimit) {
      /* Transition: '<S1>:290' */
      /* Transition: '<S1>:294' */
      ITireAppMdl_DW.LRTirePreStaus_p = 0U;

      /* Transition: '<S1>:292' */
    } else {
      /* Transition: '<S1>:297' */
    }

    /* Transition: '<S1>:304' */
    if (((real_T)TireLRPrs) < pTireLowPreDWLimit) {
      /* Transition: '<S1>:301' */
      /* Transition: '<S1>:302' */
      ITireAppMdl_DW.LRTirePreStaus_p = 2U;

      /* Transition: '<S1>:311' */
    } else {
      /* Transition: '<S1>:303' */
    }

    /* Transition: '<S1>:314' */
    if (((real_T)TireLRPrs) > pTireHighPreUpLimit) {
      /* Transition: '<S1>:305' */
      /* Transition: '<S1>:308' */
      ITireAppMdl_DW.LRTirePreStaus_p = 1U;

      /* Transition: '<S1>:317' */
    } else {
      /* Transition: '<S1>:310' */
    }

    /* Transition: '<S1>:299' */
  } else {
    /* Transition: '<S1>:281' */
    ITireAppMdl_DW.LRTirePreStaus_p = 3U;
  }

  /* Transition: '<S1>:361' */
  if (((int32_T)TireRRPrsV) == 0) {
    /* Transition: '<S1>:328' */
    if (((real_T)TireRRPrs) > pTireLowPreUpLimit) {
      /* Transition: '<S1>:325' */
      /* Transition: '<S1>:323' */
      ITireAppMdl_DW.RRTirePreStaus_o = 0U;

      /* Transition: '<S1>:335' */
    } else {
      /* Transition: '<S1>:333' */
    }

    /* Transition: '<S1>:329' */
    if (((real_T)TireRRPrs) < pTireHighPreDWLimit) {
      /* Transition: '<S1>:330' */
      /* Transition: '<S1>:339' */
      ITireAppMdl_DW.RRTirePreStaus_o = 0U;

      /* Transition: '<S1>:332' */
    } else {
      /* Transition: '<S1>:336' */
    }

    /* Transition: '<S1>:345' */
    if (((real_T)TireRRPrs) < pTireLowPreDWLimit) {
      /* Transition: '<S1>:343' */
      /* Transition: '<S1>:344' */
      ITireAppMdl_DW.RRTirePreStaus_o = 2U;

      /* Transition: '<S1>:357' */
    } else {
      /* Transition: '<S1>:346' */
    }

    /* Transition: '<S1>:350' */
    if (((real_T)TireRRPrs) > pTireHighPreUpLimit) {
      /* Transition: '<S1>:353' */
      /* Transition: '<S1>:354' */
      ITireAppMdl_DW.RRTirePreStaus_o = 1U;

      /* Transition: '<S1>:359' */
    } else {
      /* Transition: '<S1>:351' */
    }

    /* Transition: '<S1>:341' */
  } else {
    /* Transition: '<S1>:324' */
    ITireAppMdl_DW.LRTirePreStaus_p = 3U;
  }

  /* Transition: '<S1>:363' */
  /* Transition: '<S1>:691' */
  /* Transition: '<S1>:546' */
  tmp_1 = ((int32_T)ITireAppMdl_DW.Time1SCount) + 1;
  if (tmp_1 > 255) {
    tmp_1 = 255;
  }

  ITireAppMdl_DW.Time1SCount = (uint8_T)tmp_1;
  if (((int32_T)ITireAppMdl_DW.Time1SCount) >= 60) {
    /* Transition: '<S1>:548' */
    /* Transition: '<S1>:550' */
    ITireAppMdl_DW.Time1SCount = 0U;
    i = 59U;
    do {
      /* Transition: '<S1>:558' */
      /* Transition: '<S1>:560' */
      ITireAppMdl_DW.LFPress1MinArray[i] = ITireAppMdl_DW.LFPress1MinArray
        [((int32_T)i) - 1];
      ITireAppMdl_DW.LFPressV1MinArray[i] = ITireAppMdl_DW.LFPressV1MinArray
        [((int32_T)i) - 1];
      i = (uint8_T)((int32_T)(((int32_T)i) - 1));

      /* Transition: '<S1>:563' */
      /* Transition: '<S1>:564' */
    } while (((int32_T)i) >= 1);

    /* Transition: '<S1>:567' */
    ITireAppMdl_DW.LFPress1MinArray[0] = TireLFPrs;
    ITireAppMdl_DW.LFPressV1MinArray[0] = TireLFPrsV;
    i = 1U;
    if (((int32_T)TireLFPrsV) == 0) {
      /* Transition: '<S1>:572' */
      do {
        exitg1 = 0;

        /* Transition: '<S1>:707' */
        if (((((int32_T)ITireAppMdl_DW.LFPress1MinArray[i]) - ((int32_T)
               ITireAppMdl_DW.LFPress1MinArray[0])) > 20) && (((real_T)TireLFPrs)
             > pTireLowPreDWLimit)) {
          /* Transition: '<S1>:694' */
          /* Transition: '<S1>:580' */
          ITireAppMdl_DW.LFTireLeakStaus_c = 1U;
          ITireAppMdl_DW.TireLFPrsRef = TireLFPrs;
          ITireAppMdl_DW.TireLFPrsSlowCounts = 0U;

          /* Transition: '<S1>:705' */
          exitg1 = 1;
        } else {
          /* Transition: '<S1>:709' */
          i = (uint8_T)((int32_T)(((int32_T)i) + 1));
          if (((int32_T)i) <= 59) {
            /* Transition: '<S1>:716' */
            /* Transition: '<S1>:718' */
          } else {
            /* Transition: '<S1>:717' */
            ITireAppMdl_DW.LFTireLeakStaus_c = 0U;
            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);

      /* Transition: '<S1>:583' */
    } else {
      /* Transition: '<S1>:574' */
      ITireAppMdl_DW.LFTireLeakStaus_c = 3U;
    }

    /* Transition: '<S1>:588' */
    i = 59U;
    do {
      /* Transition: '<S1>:623' */
      /* Transition: '<S1>:612' */
      ITireAppMdl_DW.LRPress1MinArray[i] = ITireAppMdl_DW.LRPress1MinArray
        [((int32_T)i) - 1];
      ITireAppMdl_DW.LRPressV1MinArray[i] = ITireAppMdl_DW.LRPressV1MinArray
        [((int32_T)i) - 1];
      i = (uint8_T)((int32_T)(((int32_T)i) - 1));

      /* Transition: '<S1>:606' */
      /* Transition: '<S1>:603' */
    } while (((int32_T)i) >= 1);

    /* Transition: '<S1>:607' */
    ITireAppMdl_DW.LRPress1MinArray[0] = TireLRPrs;
    ITireAppMdl_DW.LRPressV1MinArray[0] = TireLRPrsV;
    i = 1U;
    if (((int32_T)TireLRPrsV) == 0) {
      /* Transition: '<S1>:610' */
      do {
        exitg1 = 0;

        /* Transition: '<S1>:728' */
        if (((((int32_T)ITireAppMdl_DW.LRPress1MinArray[i]) - ((int32_T)
               ITireAppMdl_DW.LRPress1MinArray[0])) > 20) && (((real_T)TireLRPrs)
             > pTireLowPreDWLimit)) {
          /* Transition: '<S1>:723' */
          /* Transition: '<S1>:719' */
          ITireAppMdl_DW.LRTireLeakStaus_l = 1U;
          ITireAppMdl_DW.TireLRPrsRef = TireLRPrs;
          ITireAppMdl_DW.TireLRPrsSlowCounts = 0U;

          /* Transition: '<S1>:726' */
          exitg1 = 1;
        } else {
          /* Transition: '<S1>:729' */
          i = (uint8_T)((int32_T)(((int32_T)i) + 1));
          if (((int32_T)i) <= 59) {
            /* Transition: '<S1>:731' */
            /* Transition: '<S1>:733' */
          } else {
            /* Transition: '<S1>:730' */
            ITireAppMdl_DW.LRTireLeakStaus_l = 0U;
            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);

      /* Transition: '<S1>:720' */
    } else {
      /* Transition: '<S1>:616' */
      ITireAppMdl_DW.LRTireLeakStaus_l = 3U;
    }

    /* Transition: '<S1>:622' */
    i = 59U;
    do {
      /* Transition: '<S1>:649' */
      /* Transition: '<S1>:638' */
      ITireAppMdl_DW.RFPress1MinArray[i] = ITireAppMdl_DW.RFPress1MinArray
        [((int32_T)i) - 1];
      ITireAppMdl_DW.RFPressV1MinArray[i] = ITireAppMdl_DW.RFPressV1MinArray
        [((int32_T)i) - 1];
      i = (uint8_T)((int32_T)(((int32_T)i) - 1));

      /* Transition: '<S1>:632' */
      /* Transition: '<S1>:629' */
    } while (((int32_T)i) >= 1);

    /* Transition: '<S1>:633' */
    ITireAppMdl_DW.RFPress1MinArray[0] = TireRFPrs;
    ITireAppMdl_DW.RFPressV1MinArray[0] = TireRFPrsV;
    i = 1U;
    if (((int32_T)TireRFPrsV) == 0) {
      /* Transition: '<S1>:636' */
      do {
        exitg1 = 0;

        /* Transition: '<S1>:743' */
        if (((((int32_T)ITireAppMdl_DW.RFPress1MinArray[i]) - ((int32_T)
               ITireAppMdl_DW.RFPress1MinArray[0])) > 20) && (((real_T)TireRFPrs)
             > pTireLowPreDWLimit)) {
          /* Transition: '<S1>:740' */
          /* Transition: '<S1>:738' */
          ITireAppMdl_DW.RFTireLeakStaus_p = 1U;
          ITireAppMdl_DW.TireRFPrsRef = TireRFPrs;
          ITireAppMdl_DW.TireRFPrsSlowCounts = 0U;

          /* Transition: '<S1>:741' */
          exitg1 = 1;
        } else {
          /* Transition: '<S1>:745' */
          i = (uint8_T)((int32_T)(((int32_T)i) + 1));
          if (((int32_T)i) <= 59) {
            /* Transition: '<S1>:750' */
            /* Transition: '<S1>:748' */
          } else {
            /* Transition: '<S1>:747' */
            ITireAppMdl_DW.RFTireLeakStaus_p = 0U;
            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);

      /* Transition: '<S1>:737' */
    } else {
      /* Transition: '<S1>:642' */
      ITireAppMdl_DW.RFTireLeakStaus_p = 3U;
    }

    /* Transition: '<S1>:648' */
    i = 59U;
    do {
      /* Transition: '<S1>:675' */
      /* Transition: '<S1>:664' */
      ITireAppMdl_DW.RRPress1MinArray[i] = ITireAppMdl_DW.RRPress1MinArray
        [((int32_T)i) - 1];
      ITireAppMdl_DW.RRPressV1MinArray[i] = ITireAppMdl_DW.RRPressV1MinArray
        [((int32_T)i) - 1];
      i = (uint8_T)((int32_T)(((int32_T)i) - 1));

      /* Transition: '<S1>:658' */
      /* Transition: '<S1>:655' */
    } while (((int32_T)i) >= 1);

    /* Transition: '<S1>:659' */
    ITireAppMdl_DW.RRPress1MinArray[0] = TireRRPrs;
    ITireAppMdl_DW.RRPressV1MinArray[0] = TireRRPrsV;
    if (((int32_T)TireRRPrsV) == 0) {
      /* Transition: '<S1>:662' */
      do {
        exitg1 = 0;

        /* Transition: '<S1>:763' */
        if (((((int32_T)ITireAppMdl_DW.RRPress1MinArray[i]) - ((int32_T)
               ITireAppMdl_DW.RRPress1MinArray[0])) > 20) && (((real_T)TireRRPrs)
             > pTireLowPreDWLimit)) {
          /* Transition: '<S1>:758' */
          /* Transition: '<S1>:754' */
          ITireAppMdl_DW.RRTireLeakStaus_c = 1U;
          ITireAppMdl_DW.TireRRPrsRef = TireRRPrs;
          ITireAppMdl_DW.TireRRPrsSlowCounts = 0U;

          /* Transition: '<S1>:755' */
          exitg1 = 1;
        } else {
          /* Transition: '<S1>:766' */
          i = (uint8_T)((int32_T)(((int32_T)i) + 1));
          if (((int32_T)i) <= 59) {
            /* Transition: '<S1>:761' */
            /* Transition: '<S1>:762' */
          } else {
            /* Transition: '<S1>:764' */
            ITireAppMdl_DW.RRTireLeakStaus_c = 0U;
            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);

      /* Transition: '<S1>:756' */
    } else {
      /* Transition: '<S1>:668' */
      ITireAppMdl_DW.RRTireLeakStaus_c = 3U;
    }

    /* Transition: '<S1>:674' */
    if ((TireLFPrs <= ITireAppMdl_DW.TireLFPrsRef) && (((int32_T)
          ITireAppMdl_DW.LFTireLeakStaus_c) == 0)) {
      /* Transition: '<S1>:819' */
      /* Transition: '<S1>:821' */
      tmp_1 = ((int32_T)ITireAppMdl_DW.TireLFPrsSlowCounts) + 1;
      if (tmp_1 > 65535) {
        tmp_1 = 65535;
      }

      ITireAppMdl_DW.TireLFPrsSlowCounts = (uint16_T)tmp_1;
      if (((((int32_T)ITireAppMdl_DW.TireLFPrsSlowCounts) < 36000) &&
           ((((int32_T)ITireAppMdl_DW.TireLFPrsRef) - ((int32_T)TireLFPrs)) > 25))
          && (((real_T)TireLFPrs) > pTireLowPreDWLimit)) {
        /* Transition: '<S1>:825' */
        /* Transition: '<S1>:830' */
        ITireAppMdl_DW.LFTireLeakStaus_c = 2U;
        tmp_0 = ((((real_T)ITireAppMdl_DW.TireLFPrsRef) - pTireLowPreDWLimit) /
                 ((real_T)((int32_T)(((int32_T)ITireAppMdl_DW.TireLFPrsRef) -
                    ((int32_T)TireLFPrs))))) * ((real_T)((uint32_T)(((uint32_T)
          ITireAppMdl_DW.TireLFPrsSlowCounts) / 600U)));
        if (tmp_0 < 256.0) {
          if (tmp_0 >= 0.0) {
            i = (uint8_T)tmp_0;
          } else {
            i = 0U;
          }
        } else {
          i = MAX_uint8_T;
        }

        TireSlowLifeLF = i;

        /* Transition: '<S1>:833' */
        /* Transition: '<S1>:840' */
      } else {
        /* Transition: '<S1>:827' */
        ITireAppMdl_DW.LFTireLeakStaus_c = 0U;
        if (((int32_T)ITireAppMdl_DW.TireLFPrsSlowCounts) >= 36000) {
          /* Transition: '<S1>:829' */
          /* Transition: '<S1>:834' */
          ITireAppMdl_DW.TireLFPrsSlowCounts = 0U;
          ITireAppMdl_DW.TireLFPrsRef = TireLFPrs;

          /* Transition: '<S1>:840' */
        } else {
          /* Transition: '<S1>:841' */
        }
      }

      /* Transition: '<S1>:842' */
    } else {
      /* Transition: '<S1>:838' */
    }

    /* Transition: '<S1>:844' */
    if ((TireLRPrs <= ITireAppMdl_DW.TireLRPrsRef) && (((int32_T)
          ITireAppMdl_DW.LRTireLeakStaus_l) == 0)) {
      /* Transition: '<S1>:851' */
      /* Transition: '<S1>:849' */
      tmp_1 = ((int32_T)ITireAppMdl_DW.TireLRPrsSlowCounts) + 1;
      if (tmp_1 > 65535) {
        tmp_1 = 65535;
      }

      ITireAppMdl_DW.TireLRPrsSlowCounts = (uint16_T)tmp_1;
      if (((((int32_T)ITireAppMdl_DW.TireLRPrsSlowCounts) < 36000) &&
           ((((int32_T)ITireAppMdl_DW.TireLRPrsRef) - ((int32_T)TireLRPrs)) > 25))
          && (((real_T)TireLRPrs) > pTireLowPreDWLimit)) {
        /* Transition: '<S1>:855' */
        /* Transition: '<S1>:859' */
        ITireAppMdl_DW.LRTireLeakStaus_l = 2U;
        tmp_0 = ((((real_T)ITireAppMdl_DW.TireLRPrsRef) - pTireLowPreDWLimit) /
                 ((real_T)((int32_T)(((int32_T)ITireAppMdl_DW.TireLRPrsRef) -
                    ((int32_T)TireLRPrs))))) * ((real_T)((uint32_T)(((uint32_T)
          ITireAppMdl_DW.TireLRPrsSlowCounts) / 600U)));
        if (tmp_0 < 256.0) {
          if (tmp_0 >= 0.0) {
            i = (uint8_T)tmp_0;
          } else {
            i = 0U;
          }
        } else {
          i = MAX_uint8_T;
        }

        TireSlowLifeLR = i;

        /* Transition: '<S1>:864' */
        /* Transition: '<S1>:861' */
      } else {
        /* Transition: '<S1>:854' */
        ITireAppMdl_DW.LRTireLeakStaus_l = 0U;
        if (((int32_T)ITireAppMdl_DW.TireLRPrsSlowCounts) >= 36000) {
          /* Transition: '<S1>:860' */
          /* Transition: '<S1>:856' */
          ITireAppMdl_DW.TireLRPrsSlowCounts = 0U;
          ITireAppMdl_DW.TireLRPrsRef = TireLFPrs;

          /* Transition: '<S1>:861' */
        } else {
          /* Transition: '<S1>:863' */
        }
      }

      /* Transition: '<S1>:845' */
    } else {
      /* Transition: '<S1>:858' */
    }

    /* Transition: '<S1>:867' */
    if ((TireRFPrs <= ITireAppMdl_DW.TireRFPrsRef) && (((int32_T)
          ITireAppMdl_DW.RFTireLeakStaus_p) == 0)) {
      /* Transition: '<S1>:879' */
      /* Transition: '<S1>:877' */
      tmp_1 = ((int32_T)ITireAppMdl_DW.TireRFPrsSlowCounts) + 1;
      if (tmp_1 > 65535) {
        tmp_1 = 65535;
      }

      ITireAppMdl_DW.TireRFPrsSlowCounts = (uint16_T)tmp_1;
      if (((((int32_T)ITireAppMdl_DW.TireRFPrsSlowCounts) < 36000) &&
           ((((int32_T)ITireAppMdl_DW.TireRFPrsRef) - ((int32_T)TireRFPrs)) > 25))
          && (((real_T)TireRFPrs) > pTireLowPreDWLimit)) {
        /* Transition: '<S1>:886' */
        /* Transition: '<S1>:883' */
        ITireAppMdl_DW.RFTireLeakStaus_p = 2U;
        tmp_0 = ((((real_T)ITireAppMdl_DW.TireRFPrsRef) - pTireLowPreDWLimit) /
                 ((real_T)((int32_T)(((int32_T)ITireAppMdl_DW.TireRFPrsRef) -
                    ((int32_T)TireRFPrs))))) * ((real_T)((uint32_T)(((uint32_T)
          ITireAppMdl_DW.TireRFPrsSlowCounts) / 600U)));
        if (tmp_0 < 256.0) {
          if (tmp_0 >= 0.0) {
            i = (uint8_T)tmp_0;
          } else {
            i = 0U;
          }
        } else {
          i = MAX_uint8_T;
        }

        TireSlowLifeRF = i;

        /* Transition: '<S1>:888' */
        /* Transition: '<S1>:874' */
      } else {
        /* Transition: '<S1>:881' */
        ITireAppMdl_DW.RFTireLeakStaus_p = 0U;
        if (((int32_T)ITireAppMdl_DW.TireRFPrsSlowCounts) >= 36000) {
          /* Transition: '<S1>:880' */
          /* Transition: '<S1>:876' */
          ITireAppMdl_DW.TireRFPrsSlowCounts = 0U;
          ITireAppMdl_DW.TireRFPrsRef = TireLFPrs;

          /* Transition: '<S1>:874' */
        } else {
          /* Transition: '<S1>:885' */
        }
      }

      /* Transition: '<S1>:871' */
    } else {
      /* Transition: '<S1>:884' */
    }

    /* Transition: '<S1>:890' */
    if ((TireRRPrs <= ITireAppMdl_DW.TireRRPrsRef) && (((int32_T)
          ITireAppMdl_DW.RRTireLeakStaus_c) == 0)) {
      /* Transition: '<S1>:905' */
      /* Transition: '<S1>:900' */
      tmp_1 = ((int32_T)ITireAppMdl_DW.TireRRPrsSlowCounts) + 1;
      if (tmp_1 > 65535) {
        tmp_1 = 65535;
      }

      ITireAppMdl_DW.TireRRPrsSlowCounts = (uint16_T)tmp_1;
      if (((((int32_T)ITireAppMdl_DW.TireRRPrsSlowCounts) < 36000) &&
           ((((int32_T)ITireAppMdl_DW.TireRRPrsRef) - ((int32_T)TireRRPrs)) > 25))
          && (((real_T)TireRRPrs) > pTireLowPreDWLimit)) {
        /* Transition: '<S1>:911' */
        /* Transition: '<S1>:909' */
        ITireAppMdl_DW.RRTireLeakStaus_c = 2U;
        tmp_0 = ((((real_T)ITireAppMdl_DW.TireRRPrsRef) - pTireLowPreDWLimit) /
                 ((real_T)((int32_T)(((int32_T)ITireAppMdl_DW.TireRRPrsRef) -
                    ((int32_T)TireRRPrs))))) * ((real_T)((uint32_T)(((uint32_T)
          ITireAppMdl_DW.TireRRPrsSlowCounts) / 600U)));
        if (tmp_0 < 256.0) {
          if (tmp_0 >= 0.0) {
            i = (uint8_T)tmp_0;
          } else {
            i = 0U;
          }
        } else {
          i = MAX_uint8_T;
        }

        TireSlowLifeRR = i;

        /* Transition: '<S1>:906' */
        /* Transition: '<S1>:891' */
      } else {
        /* Transition: '<S1>:903' */
        ITireAppMdl_DW.RRTireLeakStaus_c = 0U;
        if (((int32_T)ITireAppMdl_DW.TireRRPrsSlowCounts) >= 36000) {
          /* Transition: '<S1>:902' */
          /* Transition: '<S1>:899' */
          ITireAppMdl_DW.TireRRPrsSlowCounts = 0U;
          ITireAppMdl_DW.TireRRPrsRef = TireLFPrs;

          /* Transition: '<S1>:891' */
        } else {
          /* Transition: '<S1>:908' */
        }
      }

      /* Transition: '<S1>:892' */
    } else {
      /* Transition: '<S1>:907' */
    }

    /* Transition: '<S1>:912' */
  } else {
    /* Transition: '<S1>:553' */
  }

  /* SignalConversion: '<S1>/TmpBlkForSigObjICAt SFunction Outport2' incorporates:
   *  Chart: '<Root>/High_Low_PrsERR'
   */
  RFTirePreStaus = ITireAppMdl_DW.RFTirePreStaus_b;

  /* SignalConversion: '<S1>/TmpBlkForSigObjICAt SFunction Outport3' incorporates:
   *  Chart: '<Root>/High_Low_PrsERR'
   */
  LFTirePreStaus = ITireAppMdl_DW.LFTirePreStaus_l;

  /* SignalConversion: '<S1>/TmpBlkForSigObjICAt SFunction Outport4' incorporates:
   *  Chart: '<Root>/High_Low_PrsERR'
   */
  LRTirePreStaus = ITireAppMdl_DW.LRTirePreStaus_p;

  /* SignalConversion: '<S1>/TmpBlkForSigObjICAt SFunction Outport5' incorporates:
   *  Chart: '<Root>/High_Low_PrsERR'
   */
  RRTirePreStaus = ITireAppMdl_DW.RRTirePreStaus_o;

  /* SignalConversion: '<S1>/TmpBlkForSigObjICAt SFunction Outport6' incorporates:
   *  Chart: '<Root>/High_Low_PrsERR'
   */
  LFTireLeakStaus = ITireAppMdl_DW.LFTireLeakStaus_c;

  /* SignalConversion: '<S1>/TmpBlkForSigObjICAt SFunction Outport7' incorporates:
   *  Chart: '<Root>/High_Low_PrsERR'
   */
  LRTireLeakStaus = ITireAppMdl_DW.LRTireLeakStaus_l;

  /* SignalConversion: '<S1>/TmpBlkForSigObjICAt SFunction Outport8' incorporates:
   *  Chart: '<Root>/High_Low_PrsERR'
   */
  RFTireLeakStaus = ITireAppMdl_DW.RFTireLeakStaus_p;

  /* SignalConversion: '<S1>/TmpBlkForSigObjICAt SFunction Outport9' incorporates:
   *  Chart: '<Root>/High_Low_PrsERR'
   */
  RRTireLeakStaus = ITireAppMdl_DW.RRTireLeakStaus_c;

  /* Chart: '<Root>/TireTempStatus' incorporates:
   *  Inport: '<Root>/TireLFTmp'
   *  Inport: '<Root>/TireLFTmpV'
   *  Inport: '<Root>/TireLRTmp'
   *  Inport: '<Root>/TireLRTmpV'
   *  Inport: '<Root>/TireRFTmp'
   *  Inport: '<Root>/TireRFTmpV'
   *  Inport: '<Root>/TireRRTmp'
   *  Inport: '<Root>/TireRRTmpV'
   */
  /* Gateway: TireTempStatus */
  /* During: TireTempStatus */
  /* Entry Internal: TireTempStatus */
  /* Transition: '<S3>:14' */
  if (((int32_T)TireLFTmpV) == 0) {
    /* Transition: '<S3>:20' */
    if (TireLFTmp > 70) {
      /* Transition: '<S3>:23' */
      /* Transition: '<S3>:26' */
      ITireAppMdl_DW.LFTireTempStaus_m = 1U;

      /* Transition: '<S3>:27' */
    } else {
      /* Transition: '<S3>:28' */
      ITireAppMdl_DW.LFTireTempStaus_m = 0U;
    }

    /* Transition: '<S3>:29' */
  } else {
    /* Transition: '<S3>:18' */
    ITireAppMdl_DW.LFTireTempStaus_m = 3U;
  }

  /* Transition: '<S3>:44' */
  if (((int32_T)TireLRTmpV) == 0) {
    /* Transition: '<S3>:34' */
    if (TireLRTmp > 70) {
      /* Transition: '<S3>:32' */
      /* Transition: '<S3>:40' */
      ITireAppMdl_DW.LRTireTempStaus_l = 1U;

      /* Transition: '<S3>:39' */
    } else {
      /* Transition: '<S3>:35' */
      ITireAppMdl_DW.LRTireTempStaus_l = 0U;
    }

    /* Transition: '<S3>:41' */
  } else {
    /* Transition: '<S3>:38' */
    ITireAppMdl_DW.LRTireTempStaus_l = 3U;
  }

  /* Transition: '<S3>:59' */
  if (((int32_T)TireRFTmpV) == 0) {
    /* Transition: '<S3>:52' */
    if (TireRFTmp > 70) {
      /* Transition: '<S3>:53' */
      /* Transition: '<S3>:50' */
      ITireAppMdl_DW.RFTireTempStaus_e = 1U;

      /* Transition: '<S3>:54' */
    } else {
      /* Transition: '<S3>:57' */
      ITireAppMdl_DW.RFTireTempStaus_e = 0U;
    }

    /* Transition: '<S3>:49' */
  } else {
    /* Transition: '<S3>:47' */
    ITireAppMdl_DW.RFTireTempStaus_e = 3U;
  }

  /* Transition: '<S3>:74' */
  if (((int32_T)TireRRTmpV) == 0) {
    /* Transition: '<S3>:62' */
    if (TireRRTmp > 70) {
      /* Transition: '<S3>:63' */
      /* Transition: '<S3>:68' */
      ITireAppMdl_DW.RRTireTempStaus_h = 1U;

      /* Transition: '<S3>:64' */
    } else {
      /* Transition: '<S3>:71' */
      ITireAppMdl_DW.RRTireTempStaus_h = 0U;
    }

    /* Transition: '<S3>:69' */
  } else {
    /* Transition: '<S3>:65' */
    ITireAppMdl_DW.RRTireTempStaus_h = 3U;
  }

  /* SignalConversion: '<S3>/TmpBlkForSigObjICAt SFunction Outport2' incorporates:
   *  Chart: '<Root>/TireTempStatus'
   */
  /* Transition: '<S3>:76' */
  LFTireTempStaus = ITireAppMdl_DW.LFTireTempStaus_m;

  /* SignalConversion: '<S3>/TmpBlkForSigObjICAt SFunction Outport3' incorporates:
   *  Chart: '<Root>/TireTempStatus'
   */
  LRTireTempStaus = ITireAppMdl_DW.LRTireTempStaus_l;

  /* SignalConversion: '<S3>/TmpBlkForSigObjICAt SFunction Outport4' incorporates:
   *  Chart: '<Root>/TireTempStatus'
   */
  RFTireTempStaus = ITireAppMdl_DW.RFTireTempStaus_e;

  /* SignalConversion: '<S3>/TmpBlkForSigObjICAt SFunction Outport5' incorporates:
   *  Chart: '<Root>/TireTempStatus'
   */
  RRTireTempStaus = ITireAppMdl_DW.RRTireTempStaus_h;
}

/* Model initialize function */
void ITireAppMdl_initialize(void)
{
  /* Registration code */

  /* block I/O */

  /* exported global signals */
  LFTireTempStaus = ((uint8_T)0U);
  LRTireTempStaus = ((uint8_T)0U);
  RFTireTempStaus = ((uint8_T)0U);
  RRTireTempStaus = ((uint8_T)0U);
  LFTirPreSenLostErr = ((uint8_T)0U);
  LFTirPreSenLostErrV = ((uint8_T)0U);
  LRTirPreSenLostErr = ((uint8_T)0U);
  RFTirPreSenLostErr = ((uint8_T)0U);
  RRTirPreSenLostErr = ((uint8_T)0U);
  LRTirPreSenLostErrV = ((uint8_T)0U);
  RFTirPreSenLostErrV = ((uint8_T)0U);
  RRTirPreSenLostErrV = ((uint8_T)0U);
  TireSlowLifeLF = 0U;
  TireSlowLifeLR = 0U;
  TireSlowLifeRF = 0U;
  TireSlowLifeRR = 0U;
  RFTirePreStaus = ((uint8_T)0U);
  LFTirePreStaus = ((uint8_T)0U);
  LRTirePreStaus = ((uint8_T)0U);
  RRTirePreStaus = ((uint8_T)0U);
  LFTireLeakStaus = ((uint8_T)0U);
  LRTireLeakStaus = ((uint8_T)0U);
  RFTireLeakStaus = ((uint8_T)0U);
  RRTireLeakStaus = ((uint8_T)0U);

  /* states (dwork) */
  (void) memset((void *)&ITireAppMdl_DW, 0,
                sizeof(DW_ITireAppMdl_T));

  /* external inputs */
  EngRunAtv = 0U;
  AccActPosV = 0U;
  AccActPos = 0U;
  ThrPosV = 0U;
  ThrPos = 0U;
  BrkPdlPos = 0U;
  StrWhAngV = 0U;
  StrWhAng = 0;
  StrWhAngGrdV = 0U;
  StrWhAngGrd = 0;
  CmpsOctHding = 0U;
  CmpsCrhding = 0U;
  OtsAirTmpV = 0U;
  OtsAirTmp = 0.0;
  VehOdoV = 0U;
  VehOdo = 0U;
  CldrYr_154 = 0U;
  CldrMth_154 = 0U;
  HrsV = 0U;
  Hrs = 0U;
  MinsV = 0U;
  CldrDay_154 = 0U;
  Mins = 0U;
  SecV = 0U;
  Sec = 0U;
  PsngSysLatV = 0U;
  PsngSysLat = 0;
  PsngSysLongV = 0U;
  PsngSysLong = 0;
  VSELatAccV = 0U;
  VSELatAcc = 0.0;
  VehDynYawRateV = 0U;
  VehDynYawRate = 0.0;
  ABSAtv = 0U;
  ABSFld = 0U;
  TCSysAtv = 0U;
  TCSysEnbld = 0U;
  VSEAct = 0U;
  LonAccSnsVal = 0.0;
  LatAccSnsVal = 0.0;
  EngActStdyStTorqV = 0U;
  EngActStdyStTorq = 0.0;
  AutoTransComndGear = 0U;
  WSWprAct = 0U;
  RnSnsOffIO = 0U;
  RnSnsActIO = 0U;
  TurnWprIntIO = 0U;
  DrvEconMdCmd = 0U;
  DrvSprtMdCmd = 0U;
  DrvTwHaulMdCmd = 0U;
  DrvWntrMdCmd = 0U;
  DrvHldMdCmnd = 0U;
  DrvMntnMdCmnd = 0U;
  TireLFTmpV = 0U;
  TireLFTmp = 0;
  TireLRTmpV = 0U;
  TireLRTmp = 0;
  TireRFTmpV = 0U;
  TireRFTmp = 0;
  TireRRTmpV = 0U;
  TireRRTmp = 0;
  TireRFPrsV = 0U;
  TireLFPrs = 0U;
  TireRRPrsV = 0U;
  TireLRPrsV = 0U;
  TireLRPrs = 0U;
  TireRFPrs = 0U;
  TireRRPrs = 0U;
  VehSpdAvgNDrvn = 0.0;
  VehSpdAvgNDrvnV = 0U;
  TireLFPrsV = 0U;

  {
    int32_T i;

    /* SystemInitialize for Chart: '<Root>/SensorLostERR' */
    ITireAppMdl_DW.TireRFPrsLostCount = 0U;
    ITireAppMdl_DW.TireLFPrsLostCount = 0U;
    ITireAppMdl_DW.TireLRPrsLostCount = 0U;
    ITireAppMdl_DW.TireRRPrsLostCount = 0U;
    ITireAppMdl_DW.LFTirPreSenLostErr_m = 0U;
    ITireAppMdl_DW.LFTirPreSenLostErrV_e = 0U;
    ITireAppMdl_DW.LRTirPreSenLostErr_d = 0U;
    ITireAppMdl_DW.RFTirPreSenLostErr_h = 0U;
    ITireAppMdl_DW.RRTirPreSenLostErr_l = 0U;
    ITireAppMdl_DW.LRTirPreSenLostErrV_l = 0U;
    ITireAppMdl_DW.RFTirPreSenLostErrV_e = 0U;
    ITireAppMdl_DW.RRTirPreSenLostErrV_e = 0U;

    /* SystemInitialize for Chart: '<Root>/High_Low_PrsERR' */
    ITireAppMdl_DW.Time1SCount = 10U;
    memset(&ITireAppMdl_DW.LFPress1MinArray[0], 0, 60U * (sizeof(uint16_T)));
    memset(&ITireAppMdl_DW.RFPress1MinArray[0], 0, 60U * (sizeof(uint16_T)));
    memset(&ITireAppMdl_DW.LRPress1MinArray[0], 0, 60U * (sizeof(uint16_T)));
    memset(&ITireAppMdl_DW.RRPress1MinArray[0], 0, 60U * (sizeof(uint16_T)));
    for (i = 0; i < 60; i++) {
      ITireAppMdl_DW.LFPressV1MinArray[i] = 0U;
      ITireAppMdl_DW.LRPressV1MinArray[i] = 0U;
      ITireAppMdl_DW.RFPressV1MinArray[i] = 0U;
      ITireAppMdl_DW.RRPressV1MinArray[i] = 0U;
    }

    ITireAppMdl_DW.TireLFPrsRef = 0U;
    ITireAppMdl_DW.TireLRPrsRef = 0U;
    ITireAppMdl_DW.TireRFPrsRef = 0U;
    ITireAppMdl_DW.TireRRPrsRef = 0U;
    ITireAppMdl_DW.TireLFPrsSlowCounts = 0U;
    ITireAppMdl_DW.TireLRPrsSlowCounts = 0U;
    ITireAppMdl_DW.TireRRPrsSlowCounts = 0U;
    ITireAppMdl_DW.TireRFPrsSlowCounts = 0U;
    ITireAppMdl_DW.RFTirePreStaus_b = 0U;
    ITireAppMdl_DW.LFTirePreStaus_l = 0U;
    ITireAppMdl_DW.LRTirePreStaus_p = 0U;
    ITireAppMdl_DW.RRTirePreStaus_o = 0U;
    ITireAppMdl_DW.LFTireLeakStaus_c = 0U;
    ITireAppMdl_DW.LRTireLeakStaus_l = 0U;
    ITireAppMdl_DW.RFTireLeakStaus_p = 0U;
    ITireAppMdl_DW.RRTireLeakStaus_c = 0U;
    TireSlowLifeLF = 0U;
    TireSlowLifeLR = 0U;
    TireSlowLifeRF = 0U;
    TireSlowLifeRR = 0U;

    /* End of SystemInitialize for Chart: '<Root>/High_Low_PrsERR' */

    /* SystemInitialize for Chart: '<Root>/TireTempStatus' */
    ITireAppMdl_DW.LFTireTempStaus_m = 0U;
    ITireAppMdl_DW.LRTireTempStaus_l = 0U;
    ITireAppMdl_DW.RFTireTempStaus_e = 0U;
    ITireAppMdl_DW.RRTireTempStaus_h = 0U;
  }
}

/* Model terminate function */
void ITireAppMdl_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
