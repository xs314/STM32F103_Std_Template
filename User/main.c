#include "stm32f10x.h"
#include "key.h"
#include "led.h"

int main(void)
{
    SystemInit();      // 配置系统时钟为72M
    LED_GPIO_Config(); // LED 端口初始化
    Key_GPIO_Config(); // 按键端口初始化

    while (1)
    {
        if (Key_Scan(GPIOE, GPIO_Pin_3) == KEY_ON) // 判断KEY1是否按下
        {
            GPIO_WriteBit(GPIOE, GPIO_Pin_5, (BitAction)((1 - GPIO_ReadOutputDataBit(GPIOE, GPIO_Pin_5)))); // LED1翻转
        }
    }
}
