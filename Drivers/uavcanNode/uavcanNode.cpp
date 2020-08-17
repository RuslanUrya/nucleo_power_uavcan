/*
 * uavcanNode.cpp
 *
 *  Created on: 17 авг. 2020 г.
 *      Author: Rus-PC
 */

#include "uavcanNode.h"

uavcanNode::uavcanNode() :
node(getCanDriver(), getSystemClock()) {

}

uavcanNode::~uavcanNode() {
	// TODO Auto-generated destructor stub
}

uavcan::ISystemClock& uavcanNode::getSystemClock() {
	return uavcan_stm32::SystemClock::instance();
}
uavcan::ICanDriver& uavcanNode::getCanDriver(){
//	static uavcan_stm32::CanInitHelper<RxQueueSize> can;
	static bool initialized = false;
	if (!initialized){
		initialized = true;
		int res = can.init(BITRATE);
		if(res <0){
//			while(1);TODO: сделать выход из метода
		}
	}
	return can.driver;
}

int uavcanNode::init() {
	int res = static_cast<int>(node.setNodeID(NODE_ID));
	if (res == 0){
		  return res;
	  }

	  node.setName("Barsuk IPS");
	  node.setHealthOk();

	  res = node.start();
	  if (res < 0){
		  return res;
	  }
	  return res;
}
