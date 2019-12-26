/**
  ******************************************************************************
  * File Name          : HC02.c
  * Description        : HC02蓝牙模块驱动配置函数
  ******************************************************************************
  * @attention
  * 该程序中使用USART1和蓝牙进行数据交互
  *
  ******************************************************************************
  */	

/* Includes ------------------------------------------------------------------*/
#include "HC02.h"

//串口发送缓存区 	
__align(8) uint8_t USART1_TX_BUF[USART1_MAX_SEND_LEN]; 	//发送缓冲,最大USART1_MAX_SEND_LEN字节
//串口接收缓存区 	
uint8_t USART1_RX_BUF[USART1_MAX_RECV_LEN]; 				//接收缓冲,最大USART1_MAX_RECV_LEN个字节.


//通过判断接收连续2个字符之间的时间差不大于10ms来决定是不是一次连续的数据.
//如果2个字符接收间隔超过10ms,则认为不是1次连续数据.也就是超过10ms没有接收到
//任何数据,则表示此次接收完毕.
//接收到的数据状态
//[15]:0,没有接收到数据;1,接收到了一批数据.
//[14:0]:接收到的数据长度
__IO uint16_t USART1_RX_STA=0;   	 //接收状态寄存器
void USART1_IRQHandler(void)
{
	uint8_t res;
	if((__HAL_UART_GET_FLAG(&huart1,UART_FLAG_RXNE)!=RESET))  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
	{
        HAL_UART_Receive(&huart1,&res,1,1000); 
		if((USART1_RX_STA&(1<<15))==0)//接收完的一批数据,还没有被处理,则不再接收其他数据
		{ 
			if(USART1_RX_STA<USART1_MAX_RECV_LEN)	//还可以接收数据
			{
                __HAL_TIM_SET_COUNTER(&htim1,0);	//计数器清空			
				if(USART1_RX_STA==0) 				//使能定时器7的中断 
				{
                    __HAL_TIM_ENABLE(&htim1); //使能定时器7
				}
				USART1_RX_BUF[USART1_RX_STA++]=res;	//记录接收到的值	 
			}else 
			{
				USART1_RX_STA|=1<<15;				//强制标记接收完成
			} 
		}
    }         													 
}   


//串口3,printf 函数
//确保一次发送数据不超过USART1_MAX_SEND_LEN字节
void u1_printf(char* fmt,...)  
{  
	uint16_t i,j;
	va_list ap;
	va_start(ap,fmt);
	vsprintf((char*)USART1_TX_BUF,fmt,ap);
	va_end(ap);
	i=strlen((const char*)USART1_TX_BUF);//此次发送数据的长度
	for(j=0;j<i;j++)//循环发送数据
	{
		while((USART1->ISR&0X40)==0);//循环发送,直到发送完毕   
		USART1->TDR=USART1_TX_BUF[j];  
	}
}


//初始化ATK-HC02模块
//返回值:0,成功;1,失败.
uint8_t HC02_Init(void)
{
	uint8_t retry=10,t;	  		 
	uint8_t temp=1;
	while(retry--)
	{
		HC02_KEY(1);					//KEY置高,进入AT模式
		//delay_ms(10);
		HAL_Delay(10);
		u1_printf("AT\r\n");			//发送AT测试指令
		HC02_KEY(0);					//KEY拉低,退出AT模式
		for(t=0;t<10;t++) 				//最长等待50ms,来接收HC02模块的回应
		{
			if(USART1_RX_STA&0X8000)break;
			//delay_ms(5);
			HAL_Delay(5);
		}		
		if(USART1_RX_STA&0X8000)	//接收到一次数据了
		{
			temp=USART1_RX_STA&0X7FFF;	//得到数据长度
			USART1_RX_STA=0;			 
			if(temp==4&&USART1_RX_BUF[0]=='O'&&USART1_RX_BUF[1]=='K')
			{
				temp=0;//接收到OK响应
				break;
			}
		}			    		
	}		    
	if(retry==0)temp=1;	//检测失败
	return temp;	 
}

//获取ATK-HC02模块的角色
//返回值:0,从机;1,主机;0XFF,获取失败.							  
uint8_t HC02_Get_Role(void)
{	 		    
	uint8_t retry=0X0F;
	uint8_t temp,t;
	while(retry--)
	{
		HC02_KEY(1);				//KEY置高,进入AT模式
		//delay_ms(10);
		HAL_Delay(10);
		u1_printf("AT+ROLE?\r\n");	//查询角色
		for(t=0;t<20;t++) 			//最长等待200ms,来接收HC02模块的回应
		{
			//delay_ms(10);
			HAL_Delay(10);
			if(USART1_RX_STA&0X8000)break;
		}		
		HC02_KEY(0);				//KEY拉低,退出AT模式
		if(USART1_RX_STA&0X8000)	//接收到一次数据了
		{
			temp=USART1_RX_STA&0X7FFF;	//得到数据长度
			USART1_RX_STA=0;			 
			if(temp==13&&USART1_RX_BUF[0]=='+')//接收到正确的应答了
			{
				temp=USART1_RX_BUF[6]-'0';//得到主从模式值
				break;
			}
		}		
	}
	if(retry==0)temp=0XFF;//查询失败.
	return temp;
} 							   
//ATK-HC02设置命令
//此函数用于设置ATK-HC02,适用于仅返回OK应答的AT指令
//atstr:AT指令串.比如:"AT+RESET"/"AT+UART=9600,0,0"/"AT+ROLE=0"等字符串
//返回值:0,设置成功;其他,设置失败.							  
uint8_t HC02_Set_Cmd(uint8_t* atstr)
{	 		    
	uint8_t retry=0X0F;
	uint8_t temp,t;
	while(retry--)
	{
		HC02_KEY(1);				//KEY置高,进入AT模式
		//delay_ms(10);
		HAL_Delay(10);
		u1_printf("%s\r\n",atstr);	//发送AT字符串
		HC02_KEY(0);				//KEY拉低,退出AT模式
		for(t=0;t<20;t++) 			//最长等待100ms,来接收HC02模块的回应
		{
			if(USART1_RX_STA&0X8000)break;
			//delay_ms(5);
			HAL_Delay(5);
		}		
		if(USART1_RX_STA&0X8000)	//接收到一次数据了
		{
			temp=USART1_RX_STA&0X7FFF;	//得到数据长度
			USART1_RX_STA=0;			 
			if(temp==4&&USART1_RX_BUF[0]=='O')//接收到正确的应答了
			{			
				temp=0;
				break;			 
			}
		}		
	}
	if(retry==0)temp=0XFF;//设置失败.
	return temp;
} 


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  USART1_RX_STA|=1<<15;	                                    //标记接收完成
  __HAL_TIM_DISABLE(htim);                           //关闭定时器1
}
