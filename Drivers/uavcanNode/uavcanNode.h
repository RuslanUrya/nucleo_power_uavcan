/*
 * uavcanNode.h
 *
 *  Created on: 17 авг. 2020 г.
 *      Author: Rus-PC
 */

#ifndef UAVCANNODE_UAVCANNODE_H_
#define UAVCANNODE_UAVCANNODE_H_

#include "main.h"
#include "uavcan_stm32/uavcan_stm32.hpp"
#include "uavcan/equipment/power/BatteryInfo.hpp"

#define RX_QUEUE_SIZE 128
#define BITRATE (std::uint32_t)1000000
#define NODE_MEM_POOL_SIZE 1000
#define NODE_ID 10

class uavcanNode {
public:
	uavcanNode(float *voltage, float *current);
	virtual ~uavcanNode();

	int init();
	int start();

private:
	float *voltage_ptr;
	float *current_ptr;
//	uavcan_stm32::CanInitHelper<RX_QUEUE_SIZE> can;
	uavcan::Node<NODE_MEM_POOL_SIZE> node;
	uavcan::equipment::power::BatteryInfo status_msg;
//	uavcan::Publisher<uavcan::equipment::power::BatteryInfo>status_pub;

private:
	uavcan::ISystemClock& getSystemClock();
	uavcan::ICanDriver& getCanDriver();
	void can_init();
//	uavcan::Node<NODE_MEM_POOL_SIZE>& getNode();
};

#endif /* UAVCANNODE_UAVCANNODE_H_ */
