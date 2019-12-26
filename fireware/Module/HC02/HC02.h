//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
//********************************************************************************
//无修改信息							  
////////////////////////////////////////////////////////////////////////////////// 	  
#ifndef __HC02_H
#define __HC02_H 	 
#include "usart.h" 			 
//#include "led.h" 
#include "string.h"	 
#include "math.h"
#include "stdarg.h"	 	 
#include "stdio.h"	 	 
#include "string.h"
#include "tim.h" 

#define USART1_MAX_RECV_LEN		400					//最大接收缓存字节数
#define USART1_MAX_SEND_LEN		400					//最大发送缓存字节数
#define USART1_RX_EN 			1					//0,不接收;1,接收.
#define HC02_KEY(n) (n?HAL_GPIO_WritePin(GPIOI,GPIO_PIN_11,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOI,GPIO_PIN_11,GPIO_PIN_RESET))	//蓝牙控制KEY信号
#define HC02_LED 	HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_4)  //蓝牙连接状态信号

extern uint8_t  USART1_RX_BUF[USART1_MAX_RECV_LEN]; 		//接收缓冲,最大USART3_MAX_RECV_LEN字节
extern uint8_t  USART1_TX_BUF[USART1_MAX_SEND_LEN]; 		//发送缓冲,最大USART3_MAX_SEND_LEN字节
extern __IO uint16_t USART1_RX_STA;   						//接收数据状态

void u1_printf(char* fmt,...);

uint8_t HC02_Init(void);
//void HC02_CFG_CMD(u8 *str);
uint8_t HC02_Get_Role(void);
uint8_t HC02_Set_Cmd(uint8_t* atstr);	

#endif  

