#include "led_tasks.h"
#include "main.h"
#include "cmsis_os.h"

// 绿灯任务, 周期 1000 ms
void LedG_TaskRun(void *argument)
{
    (void) argument;
    for(;;)
    {
        HAL_GPIO_TogglePin(LED_G_GPIO_Port, LED_G_Pin);
        osDelay(500);
    }
}

// 红灯任务, 周期 500 ms
void LedR_TaskRun(void *argument)
{
    (void) argument;
    for(;;)
    {
        HAL_GPIO_TogglePin(LED_R_GPIO_Port, LED_R_Pin);
        osDelay(250);
    }
}

