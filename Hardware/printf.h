#ifndef __PRINTF_H
#define __PRINTF_H

#include "stm32h7xx_hal.h"

void UART_SendFloats(float *data, uint8_t count, uint8_t decimal_places);


#endif 

