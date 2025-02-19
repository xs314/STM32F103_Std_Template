#include "key.h"
#include "delay.h"
void Key_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE); // ���������˿�PB��ʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // ���������˿�PA��ʱ��
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // �˿�����Ϊ��������
    GPIO_Init(GPIOE, &GPIO_InitStructure);        // ��ʼ���˿�
}

/* ����Ƿ��а������� */
u8 Key_Scan(GPIO_TypeDef *GPIOx, u16 GPIO_Pin)
{
    /*����Ƿ��а������� */
    if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
    {
        /*��ʱ����*/
        Delay_ms(10);
        if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
        {
            /*�ȴ������ͷ� */
            while (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
                ;
            return KEY_ON;
        }
        else
            return KEY_OFF;
    }
    else
        return KEY_OFF;
}
