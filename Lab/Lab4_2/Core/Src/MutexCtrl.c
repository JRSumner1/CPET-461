/*
 * MutexCtrl.c
 *
 *  Created on: Feb 9, 2025
 *      Author: Jon Sumner
 */

#include "MutexCtrl.h"

osMutexId myMutex01Handle;
osStatus status;

void init_mutex(void) {
	osMutexDef(myMutex01);
	myMutex01Handle = osMutexCreate(osMutex(myMutex01));
}

void flash_led(uint16_t gpio_pin, int num_flashes, int period) {
	status = osMutexWait(myMutex01Handle, osWaitForever);
	for (int i = 0; i < num_flashes; i++)
	{
		HAL_GPIO_WritePin(GPIOA, gpio_pin, GPIO_PIN_SET);
		osDelay(period);
		HAL_GPIO_WritePin(GPIOA, gpio_pin, GPIO_PIN_RESET);
		osDelay(period);
	}
	osMutexRelease(myMutex01Handle);
}
