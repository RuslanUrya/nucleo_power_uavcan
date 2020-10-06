/*
 * uavcanNode.cpp
 *
 *  Created on: 17 авг. 2020 г.
 *      Author: Rus-PC
 */

#include <uavcanIPS.h>

uavcanIPS::uavcanIPS() :
//CAN(),
node(getNode()),
status_pub(node)
{

}

uavcanIPS::~uavcanIPS() {
	// TODO Auto-generated destructor stub
}

uavcan::ISystemClock& uavcanIPS::getSystemClock() {
	return uavcan_stm32::SystemClock::instance();
}

uavcan::ICanDriver& uavcanIPS::getCanDriver(){
	static uavcan_stm32::CanInitHelper<RX_QUEUE_SIZE> can;
	static bool initialized = false;
	if (!initialized){
		initialized = true;
		int res = can.init(BITRATE);
		if(res < 0){
			while(1);
		}
	}
	return can.driver;
}

uavcan::Node<NODE_MEM_POOL_SIZE>& uavcanIPS::getNode(){
	static uavcan::Node<NODE_MEM_POOL_SIZE> node(getCanDriver(), getSystemClock());
	return node;
}

int uavcanIPS::init() {
	int res = static_cast<int>(node.setNodeID(NODE_ID));
	if (res == 0){
		return res;
	}

	node.setName("BarsukIPS");
	node.setHealthOk();

	res = node.start();
	if (res < 0){
		return res;
	}

	  res = status_pub.init();
	  if(res < 0){
		  return res;
	  }

	  status_pub.setTxTimeout(uavcan::MonotonicDuration::fromMSec(500));
	  status_pub.setPriority(uavcan::TransferPriority::MiddleLower);

	  node.setModeOperational();
	  
	  status_msg.battery_id = 1;

	  return res;
}

int uavcanIPS::routine() {
	int res = node.spin(uavcan::MonotonicDuration::fromMSec(500));
	if (res < 0) {
		return res;
	}

	res = status_pub.broadcast(status_msg);
	if (res < 0) {
		return res;
	}
	return res;
}

void uavcanIPS::adc_to_volt(uint32_t raw) {
	status_msg.voltage = raw * v_coef;
}

void uavcanIPS::adc_to_curr(uint32_t raw) {
	status_msg.current = raw * c_coef;
}

//void uavcanIPS::can_init() {
//	//gpiod clock is enabled before, because should not
//	GPIO_InitTypeDef CAN1_AFIO;
//	//Configure CAN1_RX_Pin
//	CAN1_AFIO.Pin = CAN1_RX_Pin;
//	CAN1_AFIO.Mode = GPIO_MODE_AF_PP;
//	CAN1_AFIO.Pull = GPIO_NOPULL;
//	CAN1_AFIO.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//	CAN1_AFIO.Alternate = GPIO_AF9_CAN1;
//	HAL_GPIO_Init(CAN1_RX_GPIO, &CAN1_AFIO);
//
//	//Configure CAN1_TX_Pin
//	CAN1_AFIO.Pin = CAN1_TX_Pin;
//	CAN1_AFIO.Mode = GPIO_MODE_AF_PP;
//	CAN1_AFIO.Pull = GPIO_NOPULL;
//	CAN1_AFIO.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//	CAN1_AFIO.Alternate = GPIO_AF9_CAN1;
//	HAL_GPIO_Init(CAN1_TX_GPIO, &CAN1_AFIO);
//}

