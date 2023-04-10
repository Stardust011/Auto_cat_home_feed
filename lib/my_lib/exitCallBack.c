#include "exitCallBack.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  switch (GPIO_Pin)
  {
  case FEED_BUTTON_Pin:
    // do_someting_A();
    break;
  case RESET_BUTTON_Pin:
    // do_someting_B();
    break;
  default:
    break;
  }
}

// 定义脉冲数量
int count_LITTER = 0;
int count_FEED = 0;

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
  if (htim == &htim1)
  {
    if (htim->Instance == TIM1)
    {
      // 猫砂清洁;
      // 匀速转动
    }
    if (htim->Instance == TIM2)
    {
      // 饲料投喂;
    }
  }
  if (htim == &htim2)
  {
    if (htim->Instance == TIM1)
    {
      // do A;
    }
    if (htim->Instance == TIM2)
    {
      // do B;
    }
  }
}