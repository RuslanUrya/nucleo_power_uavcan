/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
#include "adc.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "chip.h"

//#include "uavcan_stm32/uavcan_stm32.hpp"
//#include "uavcan/equipment/power/BatteryInfo.hpp"
#include "uavcanIPS.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//#define T_CONV_MSEC  (HAL_RCC_GetPCLK2Freq() / (uint32_t)((RCC->CFGR & RCC_CFGR_PPRE2) >> 3U))
#define T_CONV_MSEC ((112 + 12) / 168000)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uavcanIPS *pBarsuk_power;
//uint32_t adc_raw;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void can_init();
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
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
  MX_ADC1_Init();
  MX_ADC2_Init();
  /* USER CODE BEGIN 2 */
  can_init();
  uavcanIPS barsuk_power;
  pBarsuk_power = &barsuk_power;
  barsuk_power.init();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  barsuk_power.routine();

//	  HAL_ADC_Start(&hadc1);
//	  HAL_ADC_PollForConversion(&hadc1, T_CONV_MSEC + 10);
//	  barsuk_power.adc_to_volt(HAL_ADC_GetValue(&hadc1));
//	  HAL_ADC_Stop(&hadc1);
//
//	  HAL_ADC_Start(&hadc2);
//	  HAL_ADC_PollForConversion(&hadc2, T_CONV_MSEC + 10);
//	  barsuk_power.adc_to_curr(HAL_ADC_GetValue(&hadc2));
//	  HAL_ADC_Stop(&hadc2);

	  HAL_ADC_Start_IT(&hadc1);
	  HAL_ADC_Start_IT(&hadc2);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/** Configure the main internal regulator output voltage
	*/
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
	/** Initializes the RCC Oscillators according to the specified parameters
	* in the RCC_OscInitTypeDef structure.
	*/
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 4;
	RCC_OscInitStruct.PLL.PLLN = 168;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 7;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}
	/** Initializes the CPU, AHB and APB buses clocks
	*/
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
							  |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
	{
		Error_Handler();
	}
}

/* USER CODE BEGIN 4 */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
	if (hadc->Instance == ADC1) {
		pBarsuk_power->adc_to_volt(HAL_ADC_GetValue(hadc));
	}
	else if (hadc->Instance == ADC2)
		pBarsuk_power->adc_to_curr(HAL_ADC_GetValue(hadc));
//	adc_raw = HAL_ADC_GetValue(hadc);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

void can_init() {
	//gpiod clock is enabled before, because should not
	GPIO_InitTypeDef CAN1_AFIO;
	//Configure CAN1_RX_Pin
	CAN1_AFIO.Pin = CAN1_RX_Pin;
	CAN1_AFIO.Mode = GPIO_MODE_AF_PP;
	CAN1_AFIO.Pull = GPIO_NOPULL;
	CAN1_AFIO.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	CAN1_AFIO.Alternate = GPIO_AF9_CAN1;
	HAL_GPIO_Init(CAN1_RX_GPIO, &CAN1_AFIO);

	//Configure CAN1_TX_Pin
	CAN1_AFIO.Pin = CAN1_TX_Pin;
	CAN1_AFIO.Mode = GPIO_MODE_AF_PP;
	CAN1_AFIO.Pull = GPIO_NOPULL;
	CAN1_AFIO.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	CAN1_AFIO.Alternate = GPIO_AF9_CAN1;
	HAL_GPIO_Init(CAN1_TX_GPIO, &CAN1_AFIO);
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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
