/******************* *******************
 * 文件名  ：led.c
 * 描述    ：led 应用函数库
 *
 * 实验平台：MINI STM32开发板 基于STM32F103C8T6
 * 硬件连接：-----------------
 *          |   PC13 - LED1   |
 *          |      |
 *          |                 |
 *           -----------------
 * 库版本  ：ST3.0.0

*********************************************************/
#include "led.h"

/***************  配置LED用到的I/O口 *******************/
void LED_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE); 
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOE, &GPIO_InitStructure); 
    GPIO_SetBits(GPIOE, GPIO_Pin_5);      
}
