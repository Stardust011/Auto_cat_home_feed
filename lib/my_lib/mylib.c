#include "mylib.h"
#include "config.h"

void show_start_screen(void)
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("Welcome", Font_11x18, White);
    ssd1306_SetCursor(0, 19);
    ssd1306_WriteString("By Stardusts", Font_11x18, White);
    ssd1306_UpdateScreen();
}

void show_ready_screen(void)
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 19);
    ssd1306_WriteString("System On", Font_11x18, White);
    ssd1306_UpdateScreen();
}

void set_feed_speed(int speed)
{
    TIM3->PSC = speed;
}

void start_clean(void)
{
    // 开启TIM1-CH1 PWM
    HAL_GPIO_WritePin(LITTER_EM_C_GPIO_Port, LITTER_EM_C_Pin, ClockWise);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
}

int start_feed(void)
{
    HAL_GPIO_WritePin(ROTATION_GPIO_Port, ROTATION_Pin, ClockWise);
    // 开启TIM3-CH1 PWM
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start_IT(&htim3, TIM_CHANNEL_1);
    // 开启TIM2中断
    HAL_TIM_Base_Start_IT(&htim2);
    return 100; // 脉冲数
}

void stop_feed(void)
{
    HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
    HAL_TIM_PWM_Stop_IT(&htim3, TIM_CHANNEL_1);
    HAL_TIM_Base_Start_IT(&htim2);
}

int start_add_feed(void)
{
    HAL_GPIO_WritePin(ROTATION_GPIO_Port, ROTATION_Pin, CounterClockWise);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start_IT(&htim3, TIM_CHANNEL_1);
    return 100000; // 脉冲数
}

// 输出接收字符
void show_buffer(uint8_t Buffer[1])
{
    // static char str[4] = {};
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(Buffer, Font_11x18, White);
    ssd1306_UpdateScreen();
}

// int转换为16进制
void int_to_hex(int num, char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char temp[10] = {0};
    while (num)
    {
        temp[i++] = num % 16;
        num /= 16;
    }
    for (j = i - 1; j >= 0; j--)
    {
        if (temp[j] >= 10)
        {
            str[k++] = temp[j] + 55;
        }
        else
        {
            str[k++] = temp[j] + 48;
        }
    }
}

void off_all_led()
{
    HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, GPIO_PIN_RESET);
}