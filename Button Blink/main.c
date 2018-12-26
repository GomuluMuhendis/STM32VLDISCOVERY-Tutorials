#include <stm32f10x.h>                  // Device header
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

int main()
{
  GPIO_InitTypeDef GPIO_InitStructure;
  uint8_t input_button;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

  //Led Configuration
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Pin   =  GPIO_Pin_8 | GPIO_Pin_9 ;
  GPIO_InitStructure.GPIO_Speed   =  GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  //Button Configuration
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IPD;
  GPIO_InitStructure.GPIO_Pin   =  GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Speed   =  GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);


 while(1)
 {
  input_button = GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0);
  if(input_button)
  {
   GPIO_SetBits(GPIOC, GPIO_Pin_9);
   GPIO_ResetBits(GPIOC, GPIO_Pin_8);
  }
  else
  {
   GPIO_ResetBits(GPIOC, GPIO_Pin_9);
   GPIO_SetBits(GPIOC, GPIO_Pin_8);
  } 

 }

}
