/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include "led_tasks.h"
#include "ins_task.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for INSTask */
osThreadId_t INSTaskHandle;
const osThreadAttr_t INSTask_attributes = {
  .name = "INSTask",
  .stack_size = 1024 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for LED_G_Task */
osThreadId_t LED_G_TaskHandle;
const osThreadAttr_t LED_G_Task_attributes = {
  .name = "LED_G_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for LED_R_Task */
osThreadId_t LED_R_TaskHandle;
const osThreadAttr_t LED_R_Task_attributes = {
  .name = "LED_R_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartINSTask(void *argument);
void StartGLEDTask(void *argument);
void StartRLEDTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of INSTask */
  INSTaskHandle = osThreadNew(StartINSTask, NULL, &INSTask_attributes);

  /* creation of LED_G_Task */
  LED_G_TaskHandle = osThreadNew(StartGLEDTask, NULL, &LED_G_Task_attributes);

  /* creation of LED_R_Task */
  LED_R_TaskHandle = osThreadNew(StartRLEDTask, NULL, &LED_R_Task_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartINSTask */
/**
  * @brief  Function implementing the INSTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartINSTask */
void StartINSTask(void *argument)
{
  /* USER CODE BEGIN StartINSTask */
  /* 初始化 INS 模块并在任务循环中调用 INS_Task() */
  INS_Init();
  for(;;)
  {
    INS_Task();
    osDelay(INS_TASK_PERIOD); /* INS_TASK_PERIOD 以 ms 为单位 (见 Core/Tasks/ins_task.h) */
  }
  /* USER CODE END StartINSTask */
}

/* USER CODE BEGIN Header_StartGLEDTask */
/**
* @brief Function implementing the LED_G_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartGLEDTask */
void StartGLEDTask(void *argument)
{
  /* USER CODE BEGIN StartGLEDTask */
  /* delegate to implementation in Core/Tasks/led_tasks.c so CubeMX regions stay clean */
  LedG_TaskRun(argument);
  /* USER CODE END StartGLEDTask */
}

/* USER CODE BEGIN Header_StartRLEDTask */
/**
* @brief Function implementing the LED_R_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartRLEDTask */
void StartRLEDTask(void *argument)
{
  /* USER CODE BEGIN StartRLEDTask */
  /* delegate to implementation in Core/Tasks/led_tasks.c */
  LedR_TaskRun(argument);
  /* USER CODE END StartRLEDTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
