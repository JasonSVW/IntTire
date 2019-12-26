/**
  ******************************************************************************
  * @file           : hardware_api.h
  * @brief          : Header for hardware_api.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  ** 
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HARDWARE_API_H__
#define __HARDWARE_API_H__

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"
#include "main.h"
#include "fdcan.h"
#include "tim.h"
#include "ITireAppMdl.h"
#include "gpio.h"
#include "usart.h"
#include "stdio.h"

/* Private define ------------------------------------------------------------*/
/* CAN相关宏定义 -------------------------------------------------------------*/
/* 请在此处配置CAN_ID信息 */

//CAN接收MESSAGE ID列表，该处的ID均需要在FDCAN1_Config函数中配置Filter
#define CAN_ID_TIRE_PRS_SR 0x52A
#define CAN_ID_TIRE_TMPT_SR 0x52B
#define CAN_ID_VHCL_SPD_DST 0x3E9
#define CAN_ID_VHCL_OM      0x120
#define CAN_ID_TIRELIFE     0x690
//#define CAN_ID_ENG_GE_ST1 0x0C9 //
//#define CAN_ID_VHCL_ODO_ST 0x120 //（暂无配置）
//#define CAN_ID_LON_LAT_SR 0x1FC
//#define CAN_ID_12V_SYS_ST 0x12A  //0x238
//#define CAN_ID_TSM_GE_ST2 0x1F5 //
//#define CAN_ID_ENG_GE_ST2 0x3D1 //（暂无配置）
//#define CAN_ID_ENG_GE_ST3 0x3F9 //
//#define CAN_ID_ENG_GE_ST5 0x4D1 //
//#define CAN_ID_CSS_GE_ST1 0x1E9 // (暂无配置)
//#define CAN_ID_ENG_TQ_ST 0x191  //0x18E //


//CAN发送MESSAGE ID列表
#define CAN_ID_TEST_TX1_SEND 0x020
#define CAN_ID_TEST_TX2_SEND 0x030

struct TireInfo
{
  int16_t Temp;
  uint8_t TempSt;
  uint16_t Pres;
  uint8_t PrsSenLostErr;
	uint8_t PrsSt;
	uint8_t PrsLeakSt;
	uint8_t Life;
	uint8_t SlowLeakTime;
};


extern struct TireInfo AllTireInfo[4];
/* function and variables declaration ------------------------------------------------------------*/
void FDCAN1_TxMessage(uint16_t CAN_Tx_StdId, uint8_t CAN_Tx_Data[], uint32_t CAN_Tx_DLC);
void FDCAN2_TxMessage(uint16_t CAN_Tx_StdId, uint8_t CAN_Tx_Data[], uint32_t CAN_Tx_DLC);
void HardwareInit(void);
void MdlSoftwareInit(void);
void Error_Handler(void);
void sprintf2(char *strmsg, uint32_t msg);
void sprintf3(char *strmsg, uint32_t msg);
void sprintf4(char *strmsg, uint32_t msg);
void sprintf3n(char *strmsg, int32_t msg);
void sprintf4n(char *strmsg, int32_t msg);
void BLESend(struct TireInfo SendTireInfo[4]);

extern uint8_t PresCANRecvFlg;
//extern char strTrPrsLF[4];
//extern char strTrPrsLR[4];
//extern char strTrPrsRF[4];
//extern char strTrPrsRR[4];

//extern char strTrTmptLF[3];//带符号3位
//extern char strTrTmptLR[3];
//extern char strTrTmptRF[3];
//extern char strTrTmptRR[3];



//extern uint8_t BLESendFlag;

//extern uint16_t TrPrsLF_CAN;
//extern uint16_t TrPrsLR_CAN;
//extern uint16_t TrPrsRF_CAN;
//extern uint16_t TrPrsRR_CAN;

//extern uint8_t TrPrsLFV_CAN;
//extern uint8_t TrPrsLRV_CAN;
//extern uint8_t TrPrsRFV_CAN;
//extern uint8_t TrPrsRRV_CAN;

////uint32_t VclOdoMeter = 0;

//extern int16_t TrTmptLF_CAN;
//extern int16_t TrTmptLR_CAN;
//extern int16_t TrTmptRF_CAN;
//extern int16_t TrTmptRR_CAN;




#endif /* __HARDWARE_API_H__ */
/*****************************END OF FILE********************/
