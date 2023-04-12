#ifndef _EXITCALLBACK_H_
#define _EXITCALLBACK_H_

#include "main.h"

void MY_HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void MY_HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim);
void MY_HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
#endif