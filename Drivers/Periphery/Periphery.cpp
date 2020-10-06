/*
 * Periphery.cpp
 *
 *  Created on: 5 окт. 2020 г.
 *      Author: Rus-PC
 */

#include "Periphery.h"

Periphery::Periphery() {
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

Periphery::~Periphery() {
	// TODO Auto-generated destructor stub
}

