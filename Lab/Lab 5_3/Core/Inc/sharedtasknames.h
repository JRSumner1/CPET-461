/*
 * sharedtasknames.h
 *
 *  Created on: Mar 19, 2025
 *      Author: Jon Sumner
 */

#ifndef SHAREDTASKNAMES_H_
#define SHAREDTASKNAMES_H_

#include "cmsis_os.h"
// tells compiler these variables are defined somewhere else
extern osThreadId Task1Handle;
extern osThreadId Task2Handle;
extern osThreadId Task3Handle;

#endif /* SHAREDTASKNAMES_H_ */
