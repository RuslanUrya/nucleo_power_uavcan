/*
 * chip.h
 *
 *  Created on: 27 июл. 2020 г.
 *      Author: Руслан
 */

#ifndef CHIP_H_
#define CHIP_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h" //CMSIS general header

uint32_t GetAPB1TimFreq();

#define STM32F4XX
#define UAVCAN_STM32_TIMER_NUMBER 2
#define UAVCAN_STM32_BAREMETAL 1
//#define UAVCAN_STM32_TINY 1
#define UAVCAN_STM32_NUM_IFACES 1

#define STM32_PCLK1				HAL_RCC_GetPCLK1Freq()
#define STM32_TIMCLK1           (84000000ul)
#define CAN1_TX_IRQHandler      CAN1_TX_IRQHandler
#define CAN1_RX0_IRQHandler     CAN1_RX0_IRQHandler
#define CAN1_RX1_IRQHandler     CAN1_RX1_IRQHandler

//uint32_t GetAPB1TimFreq() {
//	/* Get PCLK1 frequency */
//	uint32_t pclk1 = HAL_RCC_GetPCLK1Freq();
//
//	/* Get PCLK1 prescaler */
//	if((RCC->CFGR & RCC_CFGR_PPRE1) == 0)
//	{
//	/* PCLK1 prescaler equal to 1 => TIMCLK = PCLK1 */
//	return (pclk1);
//	}
//	else
//	{
//	/* PCLK1 prescaler different from 1 => TIMCLK = 2 * PCLK1 */
//	return(2 * pclk1);
//	}
//}

#ifdef __cplusplus
}
#endif

#endif /* CHIP_H_ */

