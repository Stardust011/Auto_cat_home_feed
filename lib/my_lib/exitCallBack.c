#include "exitCallBack.h"
#include <mylib.h>
#include <stdlib.h>
#include "config.h"

int count_FEED = FEED;
char message[5];

void MY_HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  switch (GPIO_Pin)
  {
  case FEED_BUTTON_Pin:
    count_FEED = start_feed();
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 19);
    ssd1306_WriteString("Feeding.", Font_11x18, White);
    ssd1306_UpdateScreen();

    break;
  case RESET_BUTTON_Pin:
    count_FEED = start_add_feed();
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 19);
    ssd1306_WriteString("Loading.", Font_11x18, White);
    ssd1306_UpdateScreen();

    break;
  default:
    break;
  }
}



void MY_HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
  // TIM1 关闭
  if (htim == &htim1)
  {
    if (htim->Instance == TIM1)
    {
    }
    if (htim->Instance == TIM2)
    {
    }
  }


  if (htim == &htim3)
  {
    count_FEED--;
    if (count_FEED == 0)
    {
      stop_feed_all();
      ssd1306_Fill(Black);
      ssd1306_SetCursor(0, 19);
      ssd1306_WriteString("Ready.", Font_11x18, White);
      ssd1306_UpdateScreen();
    }
  }
}

static char flag = 1;
int count = 100;
void MY_HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim == &htim2)
  {
    count--;
    if (count == 0)
    {
      if (flag == 0)
      {
        HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
      }
      else
      {
        HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
      }
      HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, flag);
      flag = !flag;
      count = 100;
    }
    
  }
}