/*
 * MutexCtrl.h
 *
 *  Created on: Feb 9, 2025
 *      Author: Jon Sumner
 */

#ifndef SRC_MUTEXCTRL_H_
#define SRC_MUTEXCTRL_H_

#include "cmsis_os.h"
#include "stm32l4xx_hal.h"

void init_mutex(void);
void flash_led(uint16_t gpio_pin, int num_flashes, int period);

#endif /* SRC_MUTEXCTRL_H_ */
