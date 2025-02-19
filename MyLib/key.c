#include "key.h"
#include "delay.h"
void Key_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE); // 开启按键端口PB的时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 开启按键端口PA的时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // 端口配置为上拉输入
    GPIO_Init(GPIOE, &GPIO_InitStructure);        // 初始化端口
}

/* 检测是否有按键按下 */
u8 Key_Scan(GPIO_TypeDef *GPIOx, u16 GPIO_Pin)
{
    /*检测是否有按键按下 */
    if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
    {
        /*延时消抖*/
        Delay_ms(10);
        if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
        {
            /*等待按键释放 */
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
