/*
 * AnalogIn.h
 *
 *  Created on: 25 сент. 2020 г.
 *      Author: Rus-PC
 */

#ifndef ANALOGIN_ANALOGIN_H_
#define ANALOGIN_ANALOGIN_H_

#include "main.h"

class AnalogIn {
public:
	AnalogIn();
	virtual ~AnalogIn();

	typedef struct {
		uint8_t id_adc = 1;
		uint8_t num_of_channels = 1;
	}Settings;

	void init();
	uint32_t read();
private:
	ADC_HandleTypeDef hadc;
};

#endif /* ANALOGIN_ANALOGIN_H_ */
