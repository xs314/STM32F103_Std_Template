/******************* *******************
 * �ļ���  ��led.c
 * ����    ��led Ӧ�ú�����
 *
 * ʵ��ƽ̨��MINI STM32������ ����STM32F103C8T6
 * Ӳ�����ӣ�-----------------
 *          |   PC13 - LED1   |
 *          |      |
 *          |                 |
 *           -----------------
 * ��汾  ��ST3.0.0

*********************************************************/
#include "led.h"

/***************  ����LED�õ���I/O�� *******************/
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
