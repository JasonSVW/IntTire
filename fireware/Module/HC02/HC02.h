//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
//********************************************************************************
//���޸���Ϣ							  
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

#define USART1_MAX_RECV_LEN		400					//�����ջ����ֽ���
#define USART1_MAX_SEND_LEN		400					//����ͻ����ֽ���
#define USART1_RX_EN 			1					//0,������;1,����.
#define HC02_KEY(n) (n?HAL_GPIO_WritePin(GPIOI,GPIO_PIN_11,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOI,GPIO_PIN_11,GPIO_PIN_RESET))	//��������KEY�ź�
#define HC02_LED 	HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_4)  //��������״̬�ź�

extern uint8_t  USART1_RX_BUF[USART1_MAX_RECV_LEN]; 		//���ջ���,���USART3_MAX_RECV_LEN�ֽ�
extern uint8_t  USART1_TX_BUF[USART1_MAX_SEND_LEN]; 		//���ͻ���,���USART3_MAX_SEND_LEN�ֽ�
extern __IO uint16_t USART1_RX_STA;   						//��������״̬

void u1_printf(char* fmt,...);

uint8_t HC02_Init(void);
//void HC02_CFG_CMD(u8 *str);
uint8_t HC02_Get_Role(void);
uint8_t HC02_Set_Cmd(uint8_t* atstr);	

#endif  

