/*
 * Periphery.h
 *
 *  Created on: 5 окт. 2020 г.
 *      Author: Rus-PC
 */

#ifndef PERIPHERY_PERIPHERY_H_
#define PERIPHERY_PERIPHERY_H_
//класс для инициализации периферии через библиотеку ХАЛ. Пока реализован только
//КАН

#include "stm32f4xx_hal.h"

#define CAN1_TX_Pin GPIO_PIN_1
#define CAN1_TX_GPIO GPIOD
#define CAN1_RX_Pin GPIO_PIN_0
#define CAN1_RX_GPIO GPIOD

class Periphery {
public:
	Periphery();
	virtual ~Periphery();

public:
//	typedef enum {
//		CAN,
//		UART,
//		I2C,
//		PWM,
//		ADC,
//		DAC
//	} periph_type;

private:
	GPIO_InitTypeDef CAN1_AFIO;

};

#endif /* PERIPHERY_PERIPHERY_H_ */
