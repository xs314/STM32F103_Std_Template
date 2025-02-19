#include "stm32f10x.h"
#include "key.h"
#include "led.h"

int main(void)
{
    SystemInit();      // ����ϵͳʱ��Ϊ72M
    LED_GPIO_Config(); // LED �˿ڳ�ʼ��
    Key_GPIO_Config(); // �����˿ڳ�ʼ��

    while (1)
    {
        if (Key_Scan(GPIOE, GPIO_Pin_3) == KEY_ON) // �ж�KEY1�Ƿ���
        {
            GPIO_WriteBit(GPIOE, GPIO_Pin_5, (BitAction)((1 - GPIO_ReadOutputDataBit(GPIOE, GPIO_Pin_5)))); // LED1��ת
        }
    }
}
