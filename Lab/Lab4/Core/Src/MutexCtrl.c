#include "MutexCtrl.h"

osMutexId myMutex01Handle;
uint8_t buffer[100];
const int write_size = 60;
osStatus status;

void init_mutex_and_buffer(void) {
	osMutexDef(myMutex01);
	myMutex01Handle = osMutexCreate(osMutex(myMutex01));
	buffer[write_size - 2] = '\r';
	buffer[write_size - 1] = '\n';
}
void load_and_print_buffer(char val, UART_HandleTypeDef * uart_ptr) {
	status = osMutexWait(myMutex01Handle, osWaitForever);
	for (int i=0; i<write_size - 2; i++) {
		buffer[i] = val;
	}

	int j = 0;
	while (j < write_size) {
		if (uart_ptr->gState == HAL_UART_STATE_READY) {
			uart_ptr->ErrorCode = HAL_UART_ERROR_NONE;
			uart_ptr->gState = HAL_UART_STATE_BUSY_TX;
			uart_ptr->TxXferSize = 1;
			uart_ptr->TxXferCount = 1;
			uart_ptr->Instance->TDR = (uint16_t)(buffer[j]);
			osDelay(2);
			uart_ptr->gState = HAL_UART_STATE_READY;
			j++;
		}
	}
	osMutexRelease(myMutex01Handle);
}
