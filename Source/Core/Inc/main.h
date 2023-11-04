/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RED_VERTICAL_Pin GPIO_PIN_1
#define RED_VERTICAL_GPIO_Port GPIOA
#define YELLOW_VERTICAL_Pin GPIO_PIN_2
#define YELLOW_VERTICAL_GPIO_Port GPIOA
#define GREEN_VERTICAL_Pin GPIO_PIN_3
#define GREEN_VERTICAL_GPIO_Port GPIOA
#define RED_HORIZONTAL_Pin GPIO_PIN_4
#define RED_HORIZONTAL_GPIO_Port GPIOA
#define YELLOW_HORIZONTAL_Pin GPIO_PIN_5
#define YELLOW_HORIZONTAL_GPIO_Port GPIOA
#define GREEN_HORIZONTAL_Pin GPIO_PIN_6
#define GREEN_HORIZONTAL_GPIO_Port GPIOA
#define EN_VER1_Pin GPIO_PIN_7
#define EN_VER1_GPIO_Port GPIOA
#define BUTTON1_Pin GPIO_PIN_0
#define BUTTON1_GPIO_Port GPIOB
#define BUTTON2_Pin GPIO_PIN_1
#define BUTTON2_GPIO_Port GPIOB
#define BUTTON3_Pin GPIO_PIN_2
#define BUTTON3_GPIO_Port GPIOB
#define EN_7SEG_VER1_Pin GPIO_PIN_11
#define EN_7SEG_VER1_GPIO_Port GPIOB
#define EN_7SEG_VER2_Pin GPIO_PIN_12
#define EN_7SEG_VER2_GPIO_Port GPIOB
#define EN_7SEG_HORI1_Pin GPIO_PIN_13
#define EN_7SEG_HORI1_GPIO_Port GPIOB
#define EN_7SEG_HORI2_Pin GPIO_PIN_14
#define EN_7SEG_HORI2_GPIO_Port GPIOB
#define EN_VER2_Pin GPIO_PIN_8
#define EN_VER2_GPIO_Port GPIOA
#define EN_HORI1_Pin GPIO_PIN_9
#define EN_HORI1_GPIO_Port GPIOA
#define EN_HORI2_Pin GPIO_PIN_10
#define EN_HORI2_GPIO_Port GPIOA
#define seg_a_Pin GPIO_PIN_3
#define seg_a_GPIO_Port GPIOB
#define seg_b_Pin GPIO_PIN_4
#define seg_b_GPIO_Port GPIOB
#define seg_c_Pin GPIO_PIN_5
#define seg_c_GPIO_Port GPIOB
#define seg_d_Pin GPIO_PIN_6
#define seg_d_GPIO_Port GPIOB
#define seg_e_Pin GPIO_PIN_7
#define seg_e_GPIO_Port GPIOB
#define seg_f_Pin GPIO_PIN_8
#define seg_f_GPIO_Port GPIOB
#define seg_g_Pin GPIO_PIN_9
#define seg_g_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
