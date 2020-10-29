#ifndef __BSP_MOTOR_TIM_H
#define	__BSP_MOTOR_TIM_H

#include "stm32f1xx_hal.h"
#include ".\bldcm_control\bsp_bldcm_control.h"

/*****************************����ӿ�1�궨��*******************************************/
/* ������ƶ�ʱ�� */
#define MOTOR1_TIM           				      TIM8
#define MOTOR1_TIM_CLK_ENABLE()  			    __HAL_RCC_TIM8_CLK_ENABLE()
extern TIM_HandleTypeDef  motor1_htimx_bldcm;

/* �ۼ� TIM_Period�������һ�����»����ж�		
	����ʱ����0������4799����Ϊ4800�Σ�Ϊһ����ʱ���� */
#define MOTOR1_PWM_PERIOD_COUNT     (4800)

#define MOTOR1_PWM_MAX_PERIOD_COUNT    (MOTOR1_PWM_PERIOD_COUNT - 100)

/* �߼����ƶ�ʱ��ʱ��ԴTIMxCLK = HCLK = 72MHz 
	 �趨��ʱ��Ƶ��Ϊ=TIMxCLK/(PWM_PRESCALER_COUNT)/PWM_PERIOD_COUNT = 15KHz*/
#define MOTOR1_PWM_PRESCALER_COUNT     (1)

/* TIM1ͨ��1������� */
#define MOTOR1_OCPWM1_PIN           		    GPIO_PIN_6
#define MOTOR1_OCPWM1_GPIO_PORT     		    GPIOC
#define MOTOR1_OCPWM1_GPIO_CLK_ENABLE() 	  __HAL_RCC_GPIOC_CLK_ENABLE()

/* TIM1ͨ��2������� */
#define MOTOR1_OCPWM2_PIN           		    GPIO_PIN_7
#define MOTOR1_OCPWM2_GPIO_PORT     		    GPIOC
#define MOTOR1_OCPWM2_GPIO_CLK_ENABLE() 	  __HAL_RCC_GPIOC_CLK_ENABLE()

/* TIM1ͨ��3������� */
#define MOTOR1_OCPWM3_PIN           		    GPIO_PIN_8
#define MOTOR1_OCPWM3_GPIO_PORT     		    GPIOC
#define MOTOR1_OCPWM3_GPIO_CLK_ENABLE() 	  __HAL_RCC_GPIOC_CLK_ENABLE()

/* TIM1ͨ��1����������� */
#define MOTOR1_OCNPWM1_PIN            		  GPIO_PIN_7
#define MOTOR1_OCNPWM1_GPIO_PORT      		  GPIOA
#define MOTOR1_OCNPWM1_GPIO_CLK_ENABLE()	  __HAL_RCC_GPIOA_CLK_ENABLE()

/* TIM1ͨ��2����������� */
#define MOTOR1_OCNPWM2_PIN            		  GPIO_PIN_0
#define MOTOR1_OCNPWM2_GPIO_PORT      		  GPIOB
#define MOTOR1_OCNPWM2_GPIO_CLK_ENABLE()	  __HAL_RCC_GPIOB_CLK_ENABLE()

/* TIM1ͨ��3����������� */
#define MOTOR1_OCNPWM3_PIN            		  GPIO_PIN_1
#define MOTOR1_OCNPWM3_GPIO_PORT      		  GPIOB
#define MOTOR1_OCNPWM3_GPIO_CLK_ENABLE()	  __HAL_RCC_GPIOB_CLK_ENABLE()

#define MOTOR1_TIM_COM_TS_ITRx              TIM_TS_ITR1    // �ڲ���������(TIM8->ITR1->TIM2)

/* ������������ʱ�� */
#define MOTOR1_HALL_TIM           				  TIM2
#define MOTOR1_HALL_TIM_CLK_ENABLE()  			__HAL_RCC_TIM2_CLK_ENABLE()

extern TIM_HandleTypeDef motor1_htimx_hall;

/* �ۼ� TIM_Period�������һ�����»����ж�		
	����ʱ����0������65535����Ϊ65535�Σ�Ϊһ����ʱ���� */
#define MOTOR1_HALL_PERIOD_COUNT     (0xFFFF)

/* �߼����ƶ�ʱ��ʱ��ԴTIMxCLK = HCLK = 72MHz
	 �趨��ʱ��Ƶ��Ϊ = TIMxCLK / (PWM_PRESCALER_COUNT) / PWM_PERIOD_COUNT = 9.98Hz
   ���� T = 100ms */
#define MOTOR1_HALL_PRESCALER_COUNT     (110)

/* TIM4 ͨ�� 1 ���� */
#define MOTOR1_HALL_INPUTU_PIN           		    GPIO_PIN_15
#define MOTOR1_HALL_INPUTU_GPIO_PORT     		    GPIOA
#define MOTOR1_HALL_INPUTU_GPIO_CLK_ENABLE() 	  __HAL_RCC_GPIOA_CLK_ENABLE()

/* TIM4 ͨ�� 2 ���� */
#define MOTOR1_HALL_INPUTV_PIN           		    GPIO_PIN_3
#define MOTOR1_HALL_INPUTV_GPIO_PORT     		    GPIOB
#define MOTOR1_HALL_INPUTV_GPIO_CLK_ENABLE() 	  __HAL_RCC_GPIOB_CLK_ENABLE()

/* TIM4 ͨ�� 3 ���� */
#define MOTOR1_HALL_INPUTW_PIN           		    GPIO_PIN_10
#define MOTOR1_HALL_INPUTW_GPIO_PORT     		    GPIOB
#define MOTOR1_HALL_INPUTW_GPIO_CLK_ENABLE() 	  __HAL_RCC_GPIOB_CLK_ENABLE()

#define MOTOR1_HALL_TIM_IRQn                    TIM2_IRQn
#define MOTOR1_HALL_TIM_IRQHandler              TIM2_IRQHandler


/***************************************************************************************/

/*****************************����ӿ�2�궨��*******************************************/
/* ������ƶ�ʱ�� */
#define MOTOR2_TIM           				      TIM1
#define MOTOR2_TIM_CLK_ENABLE()  			    __HAL_RCC_TIM1_CLK_ENABLE()
extern TIM_HandleTypeDef  motor2_htimx_bldcm;

/* �ۼ� TIM_Period�������һ�����»����ж�		
	����ʱ����0������4799����Ϊ4799�Σ�Ϊһ����ʱ���� */
#define MOTOR2_PWM_PERIOD_COUNT     (4800)

#define MOTOR2_PWM_MAX_PERIOD_COUNT    (MOTOR2_PWM_PERIOD_COUNT - 100)

/* �߼����ƶ�ʱ��ʱ��ԴTIMxCLK = HCLK = 72MHz 
	 �趨��ʱ��Ƶ��Ϊ=TIMxCLK/(PWM_PRESCALER_COUNT)/PWM_PERIOD_COUNT = 15KHz*/
#define MOTOR2_PWM_PRESCALER_COUNT     (1)

/* TIM8ͨ��1������� */
#define MOTOR2_OCPWM1_PIN           		    GPIO_PIN_9
#define MOTOR2_OCPWM1_GPIO_PORT     		    GPIOE
#define MOTOR2_OCPWM1_GPIO_CLK_ENABLE() 	  __HAL_RCC_GPIOE_CLK_ENABLE()

/* TIM8ͨ��2������� */
#define MOTOR2_OCPWM2_PIN           		    GPIO_PIN_11
#define MOTOR2_OCPWM2_GPIO_PORT     		    GPIOE
#define MOTOR2_OCPWM2_GPIO_CLK_ENABLE() 	  __HAL_RCC_GPIOE_CLK_ENABLE()

/* TIM8ͨ��3������� */
#define MOTOR2_OCPWM3_PIN           		    GPIO_PIN_13
#define MOTOR2_OCPWM3_GPIO_PORT     		    GPIOE
#define MOTOR2_OCPWM3_GPIO_CLK_ENABLE() 	  __HAL_RCC_GPIOE_CLK_ENABLE()

/* TIM8ͨ��1����������� */
#define MOTOR2_OCNPWM1_PIN            		  GPIO_PIN_8
#define MOTOR2_OCNPWM1_GPIO_PORT      		  GPIOE
#define MOTOR2_OCNPWM1_GPIO_CLK_ENABLE()	  __HAL_RCC_GPIOE_CLK_ENABLE()

/* TIM8ͨ��2����������� */
#define MOTOR2_OCNPWM2_PIN            		  GPIO_PIN_10
#define MOTOR2_OCNPWM2_GPIO_PORT      		  GPIOE
#define MOTOR2_OCNPWM2_GPIO_CLK_ENABLE()	  __HAL_RCC_GPIOE_CLK_ENABLE()

/* TIM8ͨ��3����������� */
#define MOTOR2_OCNPWM3_PIN            		  GPIO_PIN_12
#define MOTOR2_OCNPWM3_GPIO_PORT      		  GPIOE
#define MOTOR2_OCNPWM3_GPIO_CLK_ENABLE()	  __HAL_RCC_GPIOE_CLK_ENABLE()

#define MOTOR2_TIM_COM_TS_ITRx              TIM_TS_ITR3    // �ڲ���������(TIM1->ITR3->TIM4)

/* ������������ʱ�� */
#define MOTOR2_HALL_TIM           				  TIM4
#define MOTOR2_HALL_TIM_CLK_ENABLE()  			__HAL_RCC_TIM4_CLK_ENABLE()

extern TIM_HandleTypeDef motor2_htimx_hall;

/* �ۼ� TIM_Period�������һ�����»����ж�		
	����ʱ����0������65535����Ϊ65535�Σ�Ϊһ����ʱ���� */
#define MOTOR2_HALL_PERIOD_COUNT     (0xFFFF)

/* �߼����ƶ�ʱ��ʱ��ԴTIMxCLK = HCLK = 72MHz
	 �趨��ʱ��Ƶ��Ϊ = TIMxCLK / (PWM_PRESCALER_COUNT ) / PWM_PERIOD_COUNT = 9.98Hz
   ���� T = 100ms */
#define MOTOR2_HALL_PRESCALER_COUNT     (110)

/* TIM2 ͨ�� 1 ���� */
#define MOTOR2_HALL_INPUTU_PIN           		    GPIO_PIN_12
#define MOTOR2_HALL_INPUTU_GPIO_PORT     		    GPIOD
#define MOTOR2_HALL_INPUTU_GPIO_CLK_ENABLE() 	  __HAL_RCC_GPIOD_CLK_ENABLE()

/* TIM2 ͨ�� 2 ���� */
#define MOTOR2_HALL_INPUTV_PIN           		    GPIO_PIN_13
#define MOTOR2_HALL_INPUTV_GPIO_PORT     		    GPIOD
#define MOTOR2_HALL_INPUTV_GPIO_CLK_ENABLE() 	  __HAL_RCC_GPIOD_CLK_ENABLE()

/* TIM2 ͨ�� 3 ���� */
#define MOTOR2_HALL_INPUTW_PIN           		    GPIO_PIN_14
#define MOTOR2_HALL_INPUTW_GPIO_PORT     		    GPIOD
#define MOTOR2_HALL_INPUTW_GPIO_CLK_ENABLE() 	  __HAL_RCC_GPIOD_CLK_ENABLE()

#define MOTOR2_HALL_TIM_IRQn                    TIM4_IRQn
#define MOTOR2_HALL_TIM_IRQHandler              TIM4_IRQHandler


/***************************************************************************************/

extern TIM_HandleTypeDef motor1_TIM_TimeBaseStructure;
extern TIM_HandleTypeDef motor2_TIM_TimeBaseStructure;

void TIMx_Configuration(void);

void stop_motor1_pwm_output(void);
void set_motor1_pwm_pulse(uint16_t pulse);

void hall_motor1_enable(void);
void hall_motor1_disable(void);
void hall_motor1_tim_config(void);

void stop_motor2_pwm_output(void);
void set_motor2_pwm_pulse(uint16_t pulse);

void hall_motor2_enable(void);
void hall_motor2_disable(void);
void hall_motor2_tim_config(void);

#endif /* __BSP_MOTOR_TIM_H */

