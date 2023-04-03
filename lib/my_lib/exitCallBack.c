#include "exitCallBack.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  switch(GPIO_Pin)
  {
    case FEED_BUTTON_Pin: 
      // do_someting_A(); 
      break;
    case RESET_BUTTON_Pin:
      // do_someting_B(); 
      break;
    default : break; 
  }
}