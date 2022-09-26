/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
void setNumberOnClock(int num);
void clearAllClock ();
void clearNumberOnClock(int num);
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  	  int count_seconds= 0;
  	  int count_minutes= 0;
  	  int count_hours= 0;
  while (1)
  {
	  // reset trang thai den
	  clearAllClock();
	  if(count_seconds<=58){
		  clearNumberOnClock(count_seconds%12);
		  count_seconds++;
	  }
	  // kim giay quay 5 vong-> kim phut +1.
	  if(count_seconds==59){
		  if(count_minutes==11){
			  // reset all
			  if(count_hours==11){
				  count_seconds= 0;
				  count_minutes= 0;
				  count_hours= 0;
			  }
			  // reset phut, gio+1;
			  count_minutes= 0;
			  count_hours++;
		  }
		  // reset giay, phut+1.
		  count_seconds= 0;
		  count_minutes++;
		  clearNumberOnClock(count_minutes);
	  }

	  setNumberOnClock( count_seconds%12);
	  setNumberOnClock( count_minutes);
	  setNumberOnClock( count_hours);
	  HAL_Delay(500);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
void clearAllClock () {
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, SET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, SET);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, SET);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, SET);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, SET);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, SET);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, SET);
			HAL_GPIO_WritePin(H_GPIO_Port, H_Pin, SET);
			HAL_GPIO_WritePin(I_GPIO_Port, I_Pin, SET);
			HAL_GPIO_WritePin(K_GPIO_Port, K_Pin, SET);
			HAL_GPIO_WritePin(L_GPIO_Port, L_Pin, SET);
			HAL_GPIO_WritePin(M_GPIO_Port, M_Pin, SET);
}

void setNumberOnClock(int num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(H_GPIO_Port, H_Pin, RESET);
		break;
	case 8:
		HAL_GPIO_WritePin(I_GPIO_Port, I_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(K_GPIO_Port, K_Pin, RESET);
		break;
	case 10:
		HAL_GPIO_WritePin(L_GPIO_Port, L_Pin, RESET);
		break;
	case 11:
		HAL_GPIO_WritePin(M_GPIO_Port, M_Pin, RESET);
		break;
	}
}
void clearNumberOnClock(int num){
		switch(num){
		case 0:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, SET);
		break;
		case 1:
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, SET);
		break;
		case 2:
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, SET);
		break;
		case 3:
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, SET);
		break;
		case 4:
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, SET);
		break;
		case 5:
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, SET);
		break;
		case 6:
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, SET);
		break;
		case 7:
		HAL_GPIO_WritePin(H_GPIO_Port, H_Pin, SET);
		break;

		case 8:
		HAL_GPIO_WritePin(I_GPIO_Port, I_Pin, SET);
		break;
		case 9:
		HAL_GPIO_WritePin(K_GPIO_Port, K_Pin, SET);
		break;
		case 10:
		HAL_GPIO_WritePin(L_GPIO_Port, L_Pin, SET);
		break;
		case 11:
		HAL_GPIO_WritePin(M_GPIO_Port, M_Pin, SET);
		break;
		}
}
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, A_Pin|B_Pin|C_Pin|D_Pin
                          |E_Pin|F_Pin|G_Pin|H_Pin
                          |I_Pin|K_Pin|L_Pin|M_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : A_Pin B_Pin C_Pin D_Pin
                           E_Pin F_Pin G_Pin H_Pin
                           I_Pin K_Pin L_Pin M_Pin */
  GPIO_InitStruct.Pin = A_Pin|B_Pin|C_Pin|D_Pin
                          |E_Pin|F_Pin|G_Pin|H_Pin
                          |I_Pin|K_Pin|L_Pin|M_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/