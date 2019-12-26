/**
  ******************************************************************************
  * File Name          : HC02.c
  * Description        : HC02����ģ���������ú���
  ******************************************************************************
  * @attention
  * �ó�����ʹ��USART1�������������ݽ���
  *
  ******************************************************************************
  */	

/* Includes ------------------------------------------------------------------*/
#include "HC02.h"

//���ڷ��ͻ����� 	
__align(8) uint8_t USART1_TX_BUF[USART1_MAX_SEND_LEN]; 	//���ͻ���,���USART1_MAX_SEND_LEN�ֽ�
//���ڽ��ջ����� 	
uint8_t USART1_RX_BUF[USART1_MAX_RECV_LEN]; 				//���ջ���,���USART1_MAX_RECV_LEN���ֽ�.


//ͨ���жϽ�������2���ַ�֮���ʱ������10ms�������ǲ���һ������������.
//���2���ַ����ռ������10ms,����Ϊ����1����������.Ҳ���ǳ���10msû�н��յ�
//�κ�����,���ʾ�˴ν������.
//���յ�������״̬
//[15]:0,û�н��յ�����;1,���յ���һ������.
//[14:0]:���յ������ݳ���
__IO uint16_t USART1_RX_STA=0;   	 //����״̬�Ĵ���
void USART1_IRQHandler(void)
{
	uint8_t res;
	if((__HAL_UART_GET_FLAG(&huart1,UART_FLAG_RXNE)!=RESET))  //�����ж�(���յ������ݱ�����0x0d 0x0a��β)
	{
        HAL_UART_Receive(&huart1,&res,1,1000); 
		if((USART1_RX_STA&(1<<15))==0)//�������һ������,��û�б�����,���ٽ�����������
		{ 
			if(USART1_RX_STA<USART1_MAX_RECV_LEN)	//�����Խ�������
			{
                __HAL_TIM_SET_COUNTER(&htim1,0);	//���������			
				if(USART1_RX_STA==0) 				//ʹ�ܶ�ʱ��7���ж� 
				{
                    __HAL_TIM_ENABLE(&htim1); //ʹ�ܶ�ʱ��7
				}
				USART1_RX_BUF[USART1_RX_STA++]=res;	//��¼���յ���ֵ	 
			}else 
			{
				USART1_RX_STA|=1<<15;				//ǿ�Ʊ�ǽ������
			} 
		}
    }         													 
}   


//����3,printf ����
//ȷ��һ�η������ݲ�����USART1_MAX_SEND_LEN�ֽ�
void u1_printf(char* fmt,...)  
{  
	uint16_t i,j;
	va_list ap;
	va_start(ap,fmt);
	vsprintf((char*)USART1_TX_BUF,fmt,ap);
	va_end(ap);
	i=strlen((const char*)USART1_TX_BUF);//�˴η������ݵĳ���
	for(j=0;j<i;j++)//ѭ����������
	{
		while((USART1->ISR&0X40)==0);//ѭ������,ֱ���������   
		USART1->TDR=USART1_TX_BUF[j];  
	}
}


//��ʼ��ATK-HC02ģ��
//����ֵ:0,�ɹ�;1,ʧ��.
uint8_t HC02_Init(void)
{
	uint8_t retry=10,t;	  		 
	uint8_t temp=1;
	while(retry--)
	{
		HC02_KEY(1);					//KEY�ø�,����ATģʽ
		//delay_ms(10);
		HAL_Delay(10);
		u1_printf("AT\r\n");			//����AT����ָ��
		HC02_KEY(0);					//KEY����,�˳�ATģʽ
		for(t=0;t<10;t++) 				//��ȴ�50ms,������HC02ģ��Ļ�Ӧ
		{
			if(USART1_RX_STA&0X8000)break;
			//delay_ms(5);
			HAL_Delay(5);
		}		
		if(USART1_RX_STA&0X8000)	//���յ�һ��������
		{
			temp=USART1_RX_STA&0X7FFF;	//�õ����ݳ���
			USART1_RX_STA=0;			 
			if(temp==4&&USART1_RX_BUF[0]=='O'&&USART1_RX_BUF[1]=='K')
			{
				temp=0;//���յ�OK��Ӧ
				break;
			}
		}			    		
	}		    
	if(retry==0)temp=1;	//���ʧ��
	return temp;	 
}

//��ȡATK-HC02ģ��Ľ�ɫ
//����ֵ:0,�ӻ�;1,����;0XFF,��ȡʧ��.							  
uint8_t HC02_Get_Role(void)
{	 		    
	uint8_t retry=0X0F;
	uint8_t temp,t;
	while(retry--)
	{
		HC02_KEY(1);				//KEY�ø�,����ATģʽ
		//delay_ms(10);
		HAL_Delay(10);
		u1_printf("AT+ROLE?\r\n");	//��ѯ��ɫ
		for(t=0;t<20;t++) 			//��ȴ�200ms,������HC02ģ��Ļ�Ӧ
		{
			//delay_ms(10);
			HAL_Delay(10);
			if(USART1_RX_STA&0X8000)break;
		}		
		HC02_KEY(0);				//KEY����,�˳�ATģʽ
		if(USART1_RX_STA&0X8000)	//���յ�һ��������
		{
			temp=USART1_RX_STA&0X7FFF;	//�õ����ݳ���
			USART1_RX_STA=0;			 
			if(temp==13&&USART1_RX_BUF[0]=='+')//���յ���ȷ��Ӧ����
			{
				temp=USART1_RX_BUF[6]-'0';//�õ�����ģʽֵ
				break;
			}
		}		
	}
	if(retry==0)temp=0XFF;//��ѯʧ��.
	return temp;
} 							   
//ATK-HC02��������
//�˺�����������ATK-HC02,�����ڽ�����OKӦ���ATָ��
//atstr:ATָ�.����:"AT+RESET"/"AT+UART=9600,0,0"/"AT+ROLE=0"���ַ���
//����ֵ:0,���óɹ�;����,����ʧ��.							  
uint8_t HC02_Set_Cmd(uint8_t* atstr)
{	 		    
	uint8_t retry=0X0F;
	uint8_t temp,t;
	while(retry--)
	{
		HC02_KEY(1);				//KEY�ø�,����ATģʽ
		//delay_ms(10);
		HAL_Delay(10);
		u1_printf("%s\r\n",atstr);	//����AT�ַ���
		HC02_KEY(0);				//KEY����,�˳�ATģʽ
		for(t=0;t<20;t++) 			//��ȴ�100ms,������HC02ģ��Ļ�Ӧ
		{
			if(USART1_RX_STA&0X8000)break;
			//delay_ms(5);
			HAL_Delay(5);
		}		
		if(USART1_RX_STA&0X8000)	//���յ�һ��������
		{
			temp=USART1_RX_STA&0X7FFF;	//�õ����ݳ���
			USART1_RX_STA=0;			 
			if(temp==4&&USART1_RX_BUF[0]=='O')//���յ���ȷ��Ӧ����
			{			
				temp=0;
				break;			 
			}
		}		
	}
	if(retry==0)temp=0XFF;//����ʧ��.
	return temp;
} 


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  USART1_RX_STA|=1<<15;	                                    //��ǽ������
  __HAL_TIM_DISABLE(htim);                           //�رն�ʱ��1
}
