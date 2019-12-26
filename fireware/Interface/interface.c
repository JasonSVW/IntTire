/**
  ******************************************************************************
  * File Name          : hardware_api.c
  * Description        : 与硬件直接相关的处理接口程序
  ******************************************************************************
  ** 
	** CAN操作的接口函数，包括CAN的Filter配置，CAN接收，CAN发送，CAN标定程序
	** 提供对频率输入信号的采集和预处理
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "interface.h"



/* Private variables ---------------------------------------------------------*/
/*USART数据解析定义---------------------------------------------------------*/  
char HC_Cmd[20]={0};
char msgHead[] = "AABBFF";
char msgEnd[] = "FFBBAA";
char msg1[] = "021";
char msg2[] = "3000";
uint8_t BLESendFlag = 0;
uint8_t PresCANRecvFlg = 0;
	
//char messageid4[] = "ID4";
//double Message4=4123.32;
//char stringmsg4[10];

//char hugemessage[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

uint8_t *data2send ;

/*CAN数据解析定义---------------------------------------------------------*/     
FDCAN_RxHeaderTypeDef RxHeader;
uint8_t               CANTxData[8]={0,1,2,3,4,5,6,7};
uint8_t               CANRxData[8];


uint16_t TrPrsLF_CAN = 240;
uint16_t TrPrsLR_CAN = 240;
uint16_t TrPrsRF_CAN = 240;
uint16_t TrPrsRR_CAN = 240;

uint8_t TrPrsLFV_CAN = 0;
uint8_t TrPrsLRV_CAN = 0;
uint8_t TrPrsRFV_CAN = 0;
uint8_t TrPrsRRV_CAN = 0;

//uint32_t VclOdoMeter = 0;

int16_t TrTmptLF_CAN = 25;
int16_t TrTmptLR_CAN = 25;
int16_t TrTmptRF_CAN = 25;
int16_t TrTmptRR_CAN = 25;

uint8_t TrTmptLFV_CAN = 0;
uint8_t TrTmptLRV_CAN = 0;
uint8_t TrTmptRFV_CAN = 0;
uint8_t TrTmptRRV_CAN = 0;

uint8_t TrLifeLF_CAN = 100;
uint8_t TrLifeLR_CAN = 100;
uint8_t TrLifeRF_CAN = 100;
uint8_t TrLifeRR_CAN = 100;

//uint8_t TrLifeLF = 100;
//uint8_t TrLifeLR = 100;
//uint8_t TrLifeRF = 100;
//uint8_t TrLifeRR = 100;

double VehSpdAvgNDrvn_CAN = 0;
uint8_t VehSpdAvgNDrvnV_CAN = 0;
double VehOdo_CAN = 0;
uint16_t VehOdo_Send = 0;


struct TireInfo AllTireInfo[4]={{68,0,240,0,0,0,100,255},{68,0,240,0,0,0,100,255},{68,0,240,0,0,0,100,255},{68,0,240,0,0,0,100,255}}; //LF,LR,RF,RR

char strTrPrs[4]={'0','0','0','0'};//无符号4位
char strTrTmpt[3]={'0','0','0'};//无符号3位
char strTrStatus[4]={'0','0','0','0'};//无符号4位
char strTrLife[3]={'0','0','0'};//无符号3位
char strTrLeakTime[3]={'0','0','0'};//无符号3位
char strVehOdo[3]={'0','0','0'};//无符号3位






/* Private function prototypes -----------------------------------------------*/
/**
  * @brief 字符处理函数
  * @param None
  * @retval None
  */

void sprintf2(char *strmsg, uint32_t msg)
{
	if(msg<10)
	{
		sprintf(strmsg, "0%d", msg);
	}
	else if(msg<100)
	{
		sprintf(strmsg, "%d", msg);
	}
	else
	{
		sprintf(strmsg, "00");
	}
}
void sprintf3(char *strmsg, uint32_t msg)
{
	if(msg<10)
	{
		sprintf(strmsg, "00%d", msg);
	}
	else if(msg<100)
	{
		sprintf(strmsg, "0%d", msg);
	}
	else if(msg<1000)
	{
		sprintf(strmsg, "%d", msg);
	}
	else
	{
		sprintf(strmsg, "000");
	}
}	
void sprintf4(char *strmsg, uint32_t msg)
{
	if(msg<10)
	{
		sprintf(strmsg, "000%d", msg);
	}
	else if(msg<100)
	{
		sprintf(strmsg, "00%d", msg);
	}
	else if(msg<1000)
	{
		sprintf(strmsg, "0%d", msg);
	}
	else if(msg<10000)
	{
		sprintf(strmsg, "%d", msg);
	}
	else
	{
		sprintf(strmsg, "0000");
	}
}	


/**
  * @brief 应用程序初始化
  * @param None
  * @retval None
  */
	
void MdlSoftwareInit(void)
{
	BLESendFlag = 0;
	PresCANRecvFlg = 0;
	ITireAppMdl_initialize();
}

/**
  * @brief 应用程序单步执行+CAN数据输出
  * @param None
  * @retval None
  */
	
void MdlSoftwareStep(void)
{
	BLESendFlag = 1;
	TireLFTmpV=TrTmptLFV_CAN;
	TireLFTmp=TrTmptLF_CAN;
	TireLRTmpV=TrTmptLRV_CAN;
	TireLRTmp=TrTmptLR_CAN;
	TireRFTmpV=TrTmptRFV_CAN;
	TireRFTmp=TrTmptRF_CAN;
	TireRRTmpV=TrTmptRRV_CAN;
	TireRRTmp=TrTmptRR_CAN;
		
	TireLFPrsV=TrPrsLFV_CAN;
	TireLFPrs=TrPrsLF_CAN;
	TireLRPrsV=TrPrsLRV_CAN;
	TireLRPrs=TrPrsLR_CAN;
	TireRFPrsV=TrPrsRFV_CAN;
	TireRFPrs=TrPrsRF_CAN;
	TireRRPrsV=TrPrsRRV_CAN;
	TireRRPrs=TrPrsRR_CAN;
	
//	TrLifeLF=TrLifeLF_CAN;
//	TrLifeLR=TrLifeLR_CAN;
//	TrLifeRF=TrLifeRF_CAN;
//	TrLifeRR=TrLifeRR_CAN;
		
	VehSpdAvgNDrvn = VehSpdAvgNDrvn_CAN;
	VehSpdAvgNDrvnV = VehSpdAvgNDrvnV_CAN;
	VehOdo_Send = (uint16_t)(VehOdo_CAN/1000);                        //0.1万公里
	BLESendFlag = 0;
	
	ITireAppMdl_step();
	
	AllTireInfo[0].Temp = TireLFTmp+20;  //上位机需要-20
	AllTireInfo[1].Temp = TireLRTmp+20;
	AllTireInfo[2].Temp = TireRFTmp+20;
	AllTireInfo[3].Temp = TireRRTmp+20;
	
	AllTireInfo[0].TempSt = LFTireTempStaus;
	AllTireInfo[1].TempSt = LRTireTempStaus;
	AllTireInfo[2].TempSt = RFTireTempStaus;
	AllTireInfo[3].TempSt = RRTireTempStaus;
	
	AllTireInfo[0].Pres = TireLFPrs;
	AllTireInfo[1].Pres = TireLRPrs;
	AllTireInfo[2].Pres = TireRFPrs;
	AllTireInfo[3].Pres = TireRRPrs;
	
	AllTireInfo[0].PrsSenLostErr = LFTirPreSenLostErr;
	AllTireInfo[1].PrsSenLostErr = LRTirPreSenLostErr;
	AllTireInfo[2].PrsSenLostErr = RFTirPreSenLostErr;
	AllTireInfo[3].PrsSenLostErr = RRTirPreSenLostErr;
	
	AllTireInfo[0].PrsSt = LFTirePreStaus;
	AllTireInfo[1].PrsSt = LRTirePreStaus;
	AllTireInfo[2].PrsSt = RFTirePreStaus;
	AllTireInfo[3].PrsSt = RRTirePreStaus;
	
	AllTireInfo[0].PrsLeakSt = LFTireLeakStaus;
	AllTireInfo[1].PrsLeakSt = LRTireLeakStaus;
	AllTireInfo[2].PrsLeakSt = RFTireLeakStaus;
	AllTireInfo[3].PrsLeakSt = RRTireLeakStaus;
	
	AllTireInfo[0].Life = TrLifeLF_CAN;
	AllTireInfo[1].Life = TrLifeLR_CAN;
	AllTireInfo[2].Life = TrLifeRF_CAN;
	AllTireInfo[3].Life = TrLifeRR_CAN;
	
	AllTireInfo[0].SlowLeakTime = TireSlowLifeLF;
	AllTireInfo[1].SlowLeakTime = TireSlowLifeLR;
	AllTireInfo[2].SlowLeakTime = TireSlowLifeRF;
	AllTireInfo[3].SlowLeakTime = TireSlowLifeRR;
	
	//BLESend(AllTireInfo);
	
	HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);
	//IFAppMdl_step(); //单步执行函数接口实例
	
//	//数据发送函数处理
//	CANTxData[0] = 1;
//	CANTxData[0] = 2;
//	//参数1为ID号，参数2为发送数据的名称，参数3为发送字节数，注意格式
//	FDCAN1_TxMessage(CAN_ID_TEST_TX1_SEND,CANTxData,FDCAN_DLC_BYTES_2);
}
/**
  * @brief CAN滤波器配置
  * @param None
  * @retval None
  */
void CANFilterConfig(void)
{
	FDCAN_FilterTypeDef sFilterConfig;
	
	/*Filter0配置模板开始*/
  /* Configure Rx filter 0*/
  sFilterConfig.IdType = FDCAN_STANDARD_ID;
  sFilterConfig.FilterIndex = 0;
  sFilterConfig.FilterType = FDCAN_FILTER_DUAL;//FDCAN_FILTER_MASK;//双ID列表模式
  sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
  sFilterConfig.FilterID1 = CAN_ID_TIRE_PRS_SR;      //第一个可通过Filter的ID号
  sFilterConfig.FilterID2 = CAN_ID_TIRE_TMPT_SR;      //第二个可通过Filter的ID号
  if (HAL_FDCAN_ConfigFilter(&hfdcan1, &sFilterConfig) != HAL_OK)
  {
    Error_Handler();
  }
	/*Filter0配置模板结束*/
	/*Filter1配置模板开始*/
  /* Configure Rx filter 1*/
  sFilterConfig.IdType = FDCAN_STANDARD_ID;
  sFilterConfig.FilterIndex = 1;
  sFilterConfig.FilterType = FDCAN_FILTER_DUAL;//FDCAN_FILTER_MASK;//双ID列表模式
  sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
  sFilterConfig.FilterID1 = CAN_ID_VHCL_SPD_DST;      //第一个可通过Filter的ID号
  sFilterConfig.FilterID2 = CAN_ID_TIRELIFE;//CAN_ID_VHCL_OM;      //第二个可通过Filter的ID号
  if (HAL_FDCAN_ConfigFilter(&hfdcan1, &sFilterConfig) != HAL_OK)
  {
    Error_Handler();
  }
	/*Filter1配置模板结束*/
//	
  if (HAL_FDCAN_ConfigFilter(&hfdcan1, &sFilterConfig) != HAL_OK)
  {
    Error_Handler();
  }
	/*Filter6配置模板结束*/
}
/**
  * @brief CAN 中断接收数据处理
  * @param None
  * @retval None
  */
void CANRecvDataProc(void)
{
	/*CAN 接收信息处理函数段*/
	//if语句中判断数据的ID和长度，
	//下面为两个具体ID的处理实例，供参考，实际使用屏蔽掉
	if (BLESendFlag == 0)
	{
		if(RxHeader.Identifier == CAN_ID_TIRE_PRS_SR)				//CANID==0x52A
		{
			TrPrsLF_CAN = CANRxData[2]*4;
			TrPrsLR_CAN = CANRxData[3]*4;
			TrPrsRF_CAN = CANRxData[4]*4;
			TrPrsRR_CAN = CANRxData[5]*4;
			
			TrPrsLFV_CAN = (CANRxData[0]&0x01);
			TrPrsLRV_CAN = (CANRxData[1]&0x01);
			TrPrsRFV_CAN = (CANRxData[0]&0x02)>>1;
			TrPrsRRV_CAN = (CANRxData[1]&0x02)>>1;
			
			PresCANRecvFlg = 1;
			
		}
		else if(RxHeader.Identifier == CAN_ID_TIRE_TMPT_SR)				//CANID==0x52B
		{
			TrTmptLF_CAN = (CANRxData[2]&0x7F)-20;
			TrTmptLFV_CAN = (CANRxData[2]&0x80)>>7;
			TrTmptLR_CAN = (CANRxData[3]&0x7F)-20;
			TrTmptLRV_CAN = (CANRxData[3]&0x80)>>7;
			TrTmptRF_CAN = (CANRxData[0]&0x7F)-20;
			TrTmptRFV_CAN = (CANRxData[0]&0x80)>>7;
			TrTmptRR_CAN = (CANRxData[1]&0x7F)-20;
			TrTmptRRV_CAN = (CANRxData[1]&0x80)>>7;
			
		}

		else if(RxHeader.Identifier == CAN_ID_VHCL_SPD_DST)				//CANID==0x3E9
		{

			VehSpdAvgNDrvn_CAN = ((uint16_t)((CANRxData[4]&0x7F)<<8)+CANRxData[5])*0.015625;
			VehSpdAvgNDrvnV_CAN = (CANRxData[4]&0x80)>>7;
		}
		
		else if(RxHeader.Identifier == CAN_ID_TIRELIFE)				//CANID==0x690
		{

			TrLifeLF_CAN = CANRxData[0];
			TrLifeLR_CAN = CANRxData[1];
			TrLifeRF_CAN = CANRxData[2];
			TrLifeRR_CAN = CANRxData[3];
		}
		
//		else if (RxHeader.Identifier == CAN_ID_VHCL_OM)
//		{
//			VehOdo_CAN = (double)((uint32_t)(CANRxData[0]<<24)+(uint32_t)(CANRxData[1]<<16)+(uint32_t)(CANRxData[2]<<8)+(uint32_t)CANRxData[3])*0.015625;
//		}

		else
		{
			Error_Handler();
		}
	}
}
	
/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */	
static void Error_Handler(void)
{
//  while (1)                                        //暂不对错误进行任何处理
//  {
//		HAL_GPIO_TogglePin(LED4_GPIO_Port,LED4_Pin);
//		//HAL_Delay(1000);
//  }
}


/**
  ******************************************************************************
  * CAN外设接口程序
  ******************************************************************************
  */

/**
  * @brief  Configures the FDCAN1 Classic Filter and start CAN mode, recieve mode is interrupt.
  * @param  None
  * @retval None
  */
static void FDCAN1_Config(void)
{
  //局部Filter设置函数接口
	CANFilterConfig();
  /* Configure global filter to reject all non-matching frames */
  HAL_FDCAN_ConfigGlobalFilter(&hfdcan1, FDCAN_REJECT, FDCAN_REJECT, FDCAN_REJECT_REMOTE, FDCAN_REJECT_REMOTE);

  /* Start the FDCAN module */
  if (HAL_FDCAN_Start(&hfdcan1) != HAL_OK)
  {
    /* Start Error */
    Error_Handler();
  }

  if (HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK)
  {
    /* Notification Error */
    Error_Handler();
  }

}
/**
  * @brief  Configures the FDCAN2 Classic Filter and start CAN mode, recieve mode is interrupt.
  * @param  None
  * @retval None
  */
static void FDCAN2_Config(void)
{
  FDCAN_FilterTypeDef sFilterConfig;
  /* Configure Rx filter */
  sFilterConfig.IdType = FDCAN_STANDARD_ID;
  sFilterConfig.FilterIndex = 1;
  sFilterConfig.FilterType = FDCAN_FILTER_DUAL;//FDCAN_FILTER_MASK;
  sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
//  sFilterConfig.FilterID1 = CAN_ID_TEST_RX2_RECV1;
//  sFilterConfig.FilterID2 = CAN_ID_TEST_RX2_RECV2;
  if (HAL_FDCAN_ConfigFilter(&hfdcan2, &sFilterConfig) != HAL_OK)
  {
    /* Filter configuration Error */
    Error_Handler();
  }

  /* Configure global filter to reject all non-matching frames */
  HAL_FDCAN_ConfigGlobalFilter(&hfdcan2, FDCAN_REJECT, FDCAN_REJECT, FDCAN_REJECT_REMOTE, FDCAN_REJECT_REMOTE);

  /* Start the FDCAN module */
  if (HAL_FDCAN_Start(&hfdcan2) != HAL_OK)
  {
    /* Start Error */
    Error_Handler();
  }

  if (HAL_FDCAN_ActivateNotification(&hfdcan2, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK)
  {
    /* Notification Error */
    Error_Handler();
  }

}


/* FDCAN1_数据发送API 程序*/
/**
  * @brief FDCAN1数据发送函数
  * @param None
  * @retval None
  */
	
void FDCAN1_TxMessage(uint16_t CAN_Tx_StdId, uint8_t CAN_Tx_Data[], uint32_t CAN_Tx_DLC)
{
	uint32_t Tx1freelevel = 0U;	
	FDCAN_TxHeaderTypeDef   TxHeader1;
	  /* Prepare Tx Header */
		TxHeader1.Identifier = CAN_Tx_StdId;
		TxHeader1.IdType = FDCAN_STANDARD_ID;
		TxHeader1.TxFrameType = FDCAN_DATA_FRAME;
		TxHeader1.DataLength = CAN_Tx_DLC;//FDCAN_DLC_BYTES_2;
		TxHeader1.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
		TxHeader1.BitRateSwitch = FDCAN_BRS_OFF;
		TxHeader1.FDFormat = FDCAN_CLASSIC_CAN;
		TxHeader1.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
		TxHeader1.MessageMarker = 0;
	  while (0 == Tx1freelevel)
		{
			Tx1freelevel = HAL_FDCAN_GetTxFifoFreeLevel(&hfdcan1);
		}
		if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader1, CAN_Tx_Data) != HAL_OK)
		{
			/* Transmission request Error */
			Error_Handler();
		}
		//HAL_GPIO_TogglePin(LED3_GPIO_Port,LED3_Pin);
}

/* FDCAN2_数据发送API 程序*/
/**
  * @brief FDCAN2数据发送函数
  * @param None
  * @retval None
  */
	
void FDCAN2_TxMessage(uint16_t CAN_Tx_StdId, uint8_t CAN_Tx_Data[], uint32_t CAN_Tx_DLC)
{
	uint32_t Tx2freelevel = 0U;		
	FDCAN_TxHeaderTypeDef   TxHeader2;
	  /* Prepare Tx Header */
		TxHeader2.Identifier = CAN_Tx_StdId;
		TxHeader2.IdType = FDCAN_STANDARD_ID;
		TxHeader2.TxFrameType = FDCAN_DATA_FRAME;
		TxHeader2.DataLength = CAN_Tx_DLC;//FDCAN_DLC_BYTES_2;
		TxHeader2.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
		TxHeader2.BitRateSwitch = FDCAN_BRS_OFF;
		TxHeader2.FDFormat = FDCAN_CLASSIC_CAN;
		TxHeader2.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
		TxHeader2.MessageMarker = 0;
	  /* Prepare Tx Header */
	  while (0 == Tx2freelevel)
		{
			Tx2freelevel = HAL_FDCAN_GetTxFifoFreeLevel(&hfdcan2);
		}
		if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &TxHeader2, CAN_Tx_Data) != HAL_OK)
		{
			/* Transmission request Error */
			Error_Handler();
		}
}
/* CAN接收中断处理函数*/
/**
  * @brief  Transmission  complete callback in non blocking mode
  * @param  hcan: pointer to a CAN_HandleTypeDef structure that contains
  *         the configuration information for the specified CAN.
  * @retval None
  */
void	HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
  /* Get RX message */
  if ((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET)
  {
		HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &RxHeader, CANRxData);
		if(hfdcan==&hfdcan1)
		{
			/*CAN 接收信息处理函数段*/
			CANRecvDataProc();
//			if((RxHeader.Identifier == CAN_ID_TEST_RX1_RECV1) && (RxHeader.DataLength ==FDCAN_DLC_BYTES_2))				//CANID==0x1F1
//			{
//				HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);
//			}
		}

		else
		{
			 /* Reception Error */
			Error_Handler();
		}
		HAL_FDCAN_ActivateNotification(hfdcan, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0);
	}

	
}

/* TIM1定时中断处理函数*/
/**
  * @brief  Transmission  complete callback in non blocking mode
  * @param  hcan: pointer to a CAN_HandleTypeDef structure that contains
  *         the configuration information for the specified CAN.
  * @retval None
  */

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == htim1.Instance)
	{
		//单步执行需要进行的处理
		if (PresCANRecvFlg==1)
		{
			MdlSoftwareStep();
		}
	}

}

/* 串口发送数据函数*/
/**
  * @brief  Transmission  complete callback in non blocking mode
  * @param  hcan: pointer to a CAN_HandleTypeDef structure that contains
  *         the configuration information for the specified CAN.
  * @retval None
  */
void BLESend(struct TireInfo SendTireInfo[4])
{
	uint8_t i = 0;
	uint16_t TireStatus = 0;
	
	//BLESendFlag = 1;

	//头包         6
	data2send = (uint8_t *)msgHead;
	HAL_UART_Transmit(&huart1, data2send, 6, 0xFFFF);
		
	
  for(i=0;i<4;i++)
	{
		//轮胎状态
		TireStatus = (uint16_t)(SendTireInfo[i].TempSt *1000) + (uint16_t)(SendTireInfo[i].PrsSenLostErr *100) + (uint16_t)(SendTireInfo[i].PrsSt *10) + (uint16_t)(SendTireInfo[i].PrsLeakSt);
		sprintf4(strTrStatus,TireStatus);
		data2send = (uint8_t *)strTrStatus;
	  HAL_UART_Transmit(&huart1, data2send, 4, 0xFFFF);
		
		//轮胎胎温
		sprintf3(strTrTmpt,SendTireInfo[i].Temp);
		data2send = (uint8_t *)strTrTmpt;
	  HAL_UART_Transmit(&huart1, data2send, 3, 0xFFFF);
		
		//轮胎胎压
		sprintf4(strTrPrs,SendTireInfo[i].Pres);
		data2send = (uint8_t *)strTrPrs;
		HAL_UART_Transmit(&huart1, data2send, 4, 0xFFFF);		
		
		//轮胎寿命
		sprintf3(strTrLife,SendTireInfo[i].Life);
		data2send = (uint8_t *)strTrLife;
		HAL_UART_Transmit(&huart1, data2send, 3, 0xFFFF);	
		
		//慢漏剩余时间
		sprintf3(strTrLeakTime,SendTireInfo[i].SlowLeakTime);
		data2send = (uint8_t *)strTrLeakTime;
		HAL_UART_Transmit(&huart1, data2send, 3, 0xFFFF);	
	}
//    sprintf3(strVehOdo,VehOdo_Send);
//    data2send = (uint8_t *)strVehOdo;
//		HAL_UART_Transmit(&huart1, data2send, 3, 0xFFFF);		
    
	
	//尾包          6
	data2send = (uint8_t *)msgEnd;
	HAL_UART_Transmit(&huart1, data2send, 6, 0xFFFF);
	//BLESendFlag = 0;
}
/* 串口接收数据中断函数*/
/**
  * @brief  Transmission  complete callback in non blocking mode
  * @param  hcan: pointer to a CAN_HandleTypeDef structure that contains
  *         the configuration information for the specified CAN.
  * @retval None
  */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
{
  if(UartHandle == &huart1)
	{
		HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED4_GPIO_Port,LED4_Pin,GPIO_PIN_RESET);
		if(HC_Cmd[0]=='1')
		{
			HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_SET);
		}
		else if(HC_Cmd[0]=='2')
		{
			HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,GPIO_PIN_SET);
		}
		else if(HC_Cmd[0]=='3')
		{
			HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin,GPIO_PIN_SET);
		}
		else if(HC_Cmd[0]=='4')
		{
			HAL_GPIO_WritePin(LED4_GPIO_Port,LED4_Pin,GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED4_GPIO_Port,LED4_Pin,GPIO_PIN_SET);
		}
	}
	  while (HAL_UART_Receive_IT(&huart1,(uint8_t *)HC_Cmd, 1)!=HAL_OK)
		{
//			HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);
//			HAL_GPIO_TogglePin(LED2_GPIO_Port,LED2_Pin);
//			HAL_Delay(1000);
		}
}


/* 中断服务开启程序，在main.c调用，并使能各中断程序，用以接收数据和运行主程序*/
/**
  * @brief  中断使能函数 
  * @param  None
  * @retval None
  */
void HardwareInit(void)
{
  
	MdlSoftwareInit();
	while (HAL_UART_Receive_IT(&huart1,(uint8_t *)HC_Cmd, 1)!=HAL_OK)
	{
		HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);
		HAL_GPIO_TogglePin(LED2_GPIO_Port,LED2_Pin);
		HAL_Delay(1000);
	}
	
	FDCAN1_Config();         //开启CAN数据接收中断服务	
	//FDCAN2_Config();         //开启CAN数据接收中断服务	
	HAL_TIM_Base_Start(&htim1);
	HAL_TIM_Base_Start_IT(&htim1);

}




/*****************************END OF FILE***********************/
