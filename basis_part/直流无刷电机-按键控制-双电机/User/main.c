/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2020-xx-xx
  * @brief   直流有刷减速电机-按键控制-双电机
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 F103-拂晓 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdlib.h>
#include ".\bldcm_control\bsp_bldcm_control.h"
#include "./led/bsp_led.h"
#include "./key/bsp_key.h" 
#include "./usart/bsp_debug_usart.h"

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void) 
{
  __IO uint16_t MOTOR1_ChannelPulse = MOTOR1_PWM_MAX_PERIOD_COUNT/5;
	__IO uint16_t MOTOR2_ChannelPulse = MOTOR2_PWM_MAX_PERIOD_COUNT/5;
	
	uint8_t i = 0;
	uint8_t j = 0;
	
  uint8_t motor1_en_flag = 0;
  uint8_t motor2_en_flag = 0;

	/* 初始化系统时钟为72MHz */
	SystemClock_Config();
  
	/* 开启复用寄存器时钟 */
	__HAL_RCC_AFIO_CLK_ENABLE();
	__HAL_RCC_PWR_CLK_ENABLE();
	
	/* 电机霍尔一个通道使用PB3，与JTAG复用禁用JTAG否则不正常*/
	__HAL_AFIO_REMAP_SWJ_NOJTAG();
	
	/* 初始化按键GPIO */
	Key_GPIO_Config();

  /* LED 灯初始化 */
  LED_GPIO_Config();
  
  /* 调试串口初始化 */
  DEBUG_USART_Config();
  
  printf("野火直流无刷双电机按键控制例程\r\n");

  /* 电机初始化 */
  bldcm_init();

	while(1)
	{
    /* 扫描KEY1 */
    if( Key_Scan(KEY1_GPIO_PORT, KEY1_PIN) == KEY_ON)
    {
      /* 使能电机 */
			if(!motor1_en_flag)
			{
			    set_motor1_bldcm_speed(MOTOR1_ChannelPulse);
					set_motor1_bldcm_enable();				
			}
			else
			{
					set_motor1_bldcm_disable();
			}
			motor1_en_flag = !motor1_en_flag;
    }
    
    /* 扫描KEY2 */
    if( Key_Scan(KEY2_GPIO_PORT, KEY2_PIN) == KEY_ON)
    {
      /* 使能电机 */
			if(!motor2_en_flag)
			{
			    set_motor2_bldcm_speed(MOTOR2_ChannelPulse);
					set_motor2_bldcm_enable();
			}
			else
			{
					set_motor2_bldcm_disable();
			}
			motor2_en_flag = !motor2_en_flag;
    }
    /* 扫描KEY3 */
    if( Key_Scan(KEY3_GPIO_PORT, KEY3_PIN) == KEY_ON)
    {
      /* 增大占空比 */
      MOTOR1_ChannelPulse += MOTOR1_PWM_MAX_PERIOD_COUNT/10;
      
      if(MOTOR1_ChannelPulse > MOTOR1_PWM_MAX_PERIOD_COUNT)
        MOTOR1_ChannelPulse = MOTOR1_PWM_MAX_PERIOD_COUNT;
      
      set_motor1_bldcm_speed(MOTOR1_ChannelPulse);
			
			MOTOR2_ChannelPulse += MOTOR2_PWM_MAX_PERIOD_COUNT/10;
      
      if(MOTOR2_ChannelPulse > MOTOR2_PWM_MAX_PERIOD_COUNT)
        MOTOR2_ChannelPulse = MOTOR2_PWM_MAX_PERIOD_COUNT;
      
      set_motor2_bldcm_speed(MOTOR2_ChannelPulse);
    }
    
    /* 扫描KEY4 */
    if( Key_Scan(KEY4_GPIO_PORT, KEY4_PIN) == KEY_ON)
    {
      if(MOTOR1_ChannelPulse < MOTOR1_PWM_MAX_PERIOD_COUNT/10)
        MOTOR1_ChannelPulse = 0;
      else
        MOTOR1_ChannelPulse -= MOTOR1_PWM_MAX_PERIOD_COUNT/10;

      set_motor1_bldcm_speed(MOTOR1_ChannelPulse);
			
      if(MOTOR2_ChannelPulse < MOTOR2_PWM_MAX_PERIOD_COUNT/10)
        MOTOR2_ChannelPulse = 0;
      else
        MOTOR2_ChannelPulse -= MOTOR2_PWM_MAX_PERIOD_COUNT/10;

      set_motor2_bldcm_speed(MOTOR2_ChannelPulse);
    }
	}
}



/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 72000000
  *            HCLK(Hz)                       = 72000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 2
  *            APB2 Prescaler                 = 1
  *            HSE Frequency(Hz)              = 8000000
  *            HSE PREDIV1                    = 2
  *            PLLMUL                         = 9
  *            Flash Latency(WS)              = 0
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef clkinitstruct = {0};
  RCC_OscInitTypeDef oscinitstruct = {0};
  
  /* Enable HSE Oscillator and activate PLL with HSE as source */
  oscinitstruct.OscillatorType  = RCC_OSCILLATORTYPE_HSE;
  oscinitstruct.HSEState        = RCC_HSE_ON;
  oscinitstruct.HSEPredivValue  = RCC_HSE_PREDIV_DIV1;
  oscinitstruct.PLL.PLLState    = RCC_PLL_ON;
  oscinitstruct.PLL.PLLSource   = RCC_PLLSOURCE_HSE;
  oscinitstruct.PLL.PLLMUL      = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&oscinitstruct)!= HAL_OK)
  {
    /* Initialization Error */
    while(1); 
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  clkinitstruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  clkinitstruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  clkinitstruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  clkinitstruct.APB2CLKDivider = RCC_HCLK_DIV1;
  clkinitstruct.APB1CLKDivider = RCC_HCLK_DIV2;  
  if (HAL_RCC_ClockConfig(&clkinitstruct, FLASH_LATENCY_2)!= HAL_OK)
  {
    /* Initialization Error */
    while(1); 
  }
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
