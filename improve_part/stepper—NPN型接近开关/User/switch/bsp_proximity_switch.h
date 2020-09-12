#ifndef __BSP_PROXIMITY_SWITCH_H
#define	__BSP_PROXIMITY_SWITCH_H

#include "stm32f1xx_hal.h"

/* 接近开关结构体 */
typedef struct{
  GPIO_TypeDef *port;            //端口号
  uint16_t pin;                  //引脚序号
  uint32_t gpio_mode;            //触发模式
  IRQn_Type IRQn;                //中断源
}ProximitySwitch_TypeDef;


//引脚定义
/*******************************************************/
#define SWITCH1_INT_GPIO_PORT                GPIOB
#define SWITCH1_INT_GPIO_CLK_ENABLE()        __HAL_RCC_GPIOB_CLK_ENABLE()
#define SWITCH1_INT_GPIO_PIN                 GPIO_PIN_11
#define SWITCH1_INT_EXTI_IRQ                 EXTI15_10_IRQn
#define SWITCH1_IRQHandler                   EXTI15_10_IRQHandler

#define SWITCH2_INT_GPIO_PORT                GPIOD
#define SWITCH2_INT_GPIO_CLK_ENABLE()        __HAL_RCC_GPIOD_CLK_ENABLE()
#define SWITCH2_INT_GPIO_PIN                 GPIO_PIN_2
#define SWITCH2_INT_EXTI_IRQ                 EXTI2_IRQn
#define SWITCH2_IRQHandler                   EXTI2_IRQHandler
/*******************************************************/


void ProximitySwitch_Config(void);

#endif /* __BSP_PROXIMITY_SWITCH_H */
