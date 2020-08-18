/*
 * uavcanNode.cpp
 *
 *  Created on: 17 авг. 2020 г.
 *      Author: Rus-PC
 */

#include "uavcanNode.h"

uavcanNode::uavcanNode(float *voltage, float *current) :
voltage_ptr(voltage), current_ptr(current),
node(getCanDriver(), getSystemClock())
//status_pub(node)
{

}

uavcanNode::~uavcanNode() {
	// TODO Auto-generated destructor stub
}

uavcan::ISystemClock& uavcanNode::getSystemClock() {
	return uavcan_stm32::SystemClock::instance();
}
uavcan::ICanDriver& uavcanNode::getCanDriver(){
	static uavcan_stm32::CanInitHelper<RX_QUEUE_SIZE> can;
	static bool initialized = false;
	if (!initialized){
		initialized = true;
		int res = can.init(BITRATE);
		if(res <0){
			while(1);
		}
	}
	return can.driver;
}

int uavcanNode::init() {
	can_init();
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

//	  res = status_pub.init();
//	  if(res < 0){
//		  return res;
//	  }

//	  status_pub.setTxTimeout(uavcan::MonotonicDuration::fromMSec(500));
//	  status_pub.setPriority(uavcan::TransferPriority::MiddleLower);

	  node.setModeOperational();

	  return res;
}

int uavcanNode::start() {
	int res = node.spin(uavcan::MonotonicDuration::fromMSec(500));
	if (res < 0) {
		return res;
	}
//
//	status_msg.battery_id = 1;
//	status_msg.voltage = *voltage_ptr;
//	status_msg.current = *current_ptr;
//
//	res = status_pub.broadcast(status_msg);
//	if (res < 0) {
//		return res;
//	}
	return res;
}

void uavcanNode::can_init() {
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
