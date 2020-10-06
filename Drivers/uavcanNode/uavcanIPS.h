/*
 * uavcanIPS.h
 *
 *  Created on: 17 авг. 2020 г.
 *      Author: Rus-PC
 */

#ifndef UAVCANNODE_UAVCANIPS_H_
#define UAVCANNODE_UAVCANIPS_H_

#include "stm32f4xx_hal.h"//TODO: сделать конфиг файл с автоподключением библиотеки в зависимости от семейства
#include "uavcan_stm32/uavcan_stm32.hpp"
#include "uavcan/equipment/power/BatteryInfo.hpp"
//#include "Periphery.h"

#define RX_QUEUE_SIZE 128
#define BITRATE (std::uint32_t)1000000
#define NODE_MEM_POOL_SIZE 1000
#define NODE_ID 10

class uavcanIPS {
public:
	uavcanIPS();
	virtual ~uavcanIPS();

	int init();
	int routine();
	void adc_to_volt(uint32_t raw);
	void adc_to_curr(uint32_t raw);

private:
//	uavcan_stm32::CanInitHelper<RX_QUEUE_SIZE> can;
//	Periphery CAN;
	uavcan::Node<NODE_MEM_POOL_SIZE> &node;
	uavcan::equipment::power::BatteryInfo status_msg;
	uavcan::Publisher<uavcan::equipment::power::BatteryInfo>status_pub;

	const float v_coef = 8.146153846153848e-4;
	const float c_coef = 1.0;

private:
	uavcan::ISystemClock& getSystemClock();
	uavcan::ICanDriver& getCanDriver();
	uavcan::Node<NODE_MEM_POOL_SIZE>& getNode();

//	uavcan::Node<NODE_MEM_POOL_SIZE>& getNode();
};

#endif /* UAVCANNODE_UAVCANIPS_H_ */
