#ifndef SRC_MUTEXCTRL_H_
#define SRC_MUTEXCTRL_H_

#include "cmsis_os.h"
#include "stm32l4xx_hal.h"

void init_mutex_and_buffer(void);
void load_and_print_buffer(char val, UART_HandleTypeDef * uart_ptr);

#endif
