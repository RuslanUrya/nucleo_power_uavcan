/*
 * PowerModuleUavcan.cpp
 *
 *  Created on: 28 июл. 2020 г.
 *      Author: Руслан
 */

#include "PowerModuleUavcan.h"

#include "main.h"

PowerModuleUavcan::PowerModuleUavcan() {
	// TODO Auto-generated constructor stub

}

PowerModuleUavcan::~PowerModuleUavcan() {
	// TODO Auto-generated destructor stub
}

void PowerModuleUavcan::init() {
	can_init();
}

void PowerModuleUavcan::can_init() {
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


