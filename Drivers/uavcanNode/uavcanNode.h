/*
 * uavcanNode.h
 *
 *  Created on: 17 авг. 2020 г.
 *      Author: Rus-PC
 */

#ifndef UAVCANNODE_UAVCANNODE_H_
#define UAVCANNODE_UAVCANNODE_H_

#include "uavcan_stm32/uavcan_stm32.hpp"

#define RX_QUEUE_SIZE 128
#define BITRATE (std::uint32_t)1000000
#define NODE_MEM_POOL_SIZE 1000
#define NODE_ID 10

class uavcanNode {
public:
	uavcanNode();
	virtual ~uavcanNode();

	int init();

private:
	uavcan_stm32::CanInitHelper<RX_QUEUE_SIZE> can;
	uavcan::Node<NODE_MEM_POOL_SIZE> node;

private:
	uavcan::ISystemClock& getSystemClock();
	uavcan::ICanDriver& getCanDriver();
//	uavcan::Node<NODE_MEM_POOL_SIZE>& getNode();
};

#endif /* UAVCANNODE_UAVCANNODE_H_ */
