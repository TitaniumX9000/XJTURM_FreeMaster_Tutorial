/* USER CODE BEGIN led_tasks.h */
#ifndef LED_TASKS_H
#define LED_TASKS_H

#include "cmsis_os.h"
#include "../Inc/main.h"

#ifdef __cplusplus
extern "C" {
#endif

void LedG_TaskRun(void *argument);
void LedR_TaskRun(void *argument);

#ifdef __cplusplus
}
#endif

#endif /* LED_TASKS_H */
/* USER CODE END led_tasks.h */

