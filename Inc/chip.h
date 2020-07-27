/*
 * chip.h
 *
 *  Created on: 27 июл. 2020 г.
 *      Author: Руслан
 */

#ifndef CHIP_H_
#define CHIP_H_

#include "stm32f4xx.h" //CMSIS general header
#define STM32F4XX
#define UAVCAN_STM32_TIMER_NUMBER 2
#define UAVCAN_STM32_BAREMETAL 1
//#define UAVCAN_STM32_TINY 1
#define UAVCAN_STM32_NUM_IFACES 1

//#define STM32_PCLK1             (42000000ul)/*clock.PCLK1_Frequency */
#define STM32_PCLK1				HAL_RCC_GetPCLK1Freq();
#define STM32_TIMCLK1           (84000000ul) //84MHz. TODO: сделать авторасчет если APB1 Presc = 1, то итог = HAL_RCC_GetPCLK1Freq(), иначе HAL_RCC_GetPCLK1Freq() * 2
#define CAN1_TX_IRQHandler      CAN1_TX_IRQHandler
#define CAN1_RX0_IRQHandler     CAN1_RX0_IRQHandler
#define CAN1_RX1_IRQHandler     CAN1_RX1_IRQHandler

#endif /* CHIP_H_ */
