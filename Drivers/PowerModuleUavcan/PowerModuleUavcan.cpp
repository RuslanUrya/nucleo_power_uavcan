/*
 * PowerModuleUavcan.cpp
 *
 *  Created on: 28 июл. 2020 г.
 *      Author: Руслан
 */

#include "PowerModuleUavcan.h"

#include "main.h"

PowerModuleUavcan::PowerModuleUavcan() :
node(&voltage, &current) {

}

PowerModuleUavcan::~PowerModuleUavcan() {

}

void PowerModuleUavcan::init() {
	voltage = 25.2;
	current = 99.4;
	node.init();
}

void PowerModuleUavcan::start() {
	node.start();
}

