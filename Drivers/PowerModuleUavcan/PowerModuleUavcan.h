/*
 * PowerModuleUavcan.h
 *
 *  Created on: 28 июл. 2020 г.
 *      Author: Руслан
 */

#ifndef POWERMODULEUAVCAN_POWERMODULEUAVCAN_H_
#define POWERMODULEUAVCAN_POWERMODULEUAVCAN_H_

#include "uavcanNode.h"

class PowerModuleUavcan {
public:
	PowerModuleUavcan();
	virtual ~PowerModuleUavcan();

	void init();
	void start();

private:


private:
	float voltage;
	float current;
	uavcanNode node;
};

#endif /* POWERMODULEUAVCAN_POWERMODULEUAVCAN_H_ */
