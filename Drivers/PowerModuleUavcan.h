/*
 * PowerModuleUavcan.h
 *
 *  Created on: 28 июл. 2020 г.
 *      Author: Руслан
 */

#ifndef POWERMODULEUAVCAN_H_
#define POWERMODULEUAVCAN_H_


class PowerModuleUavcan {
public:
	PowerModuleUavcan();
	virtual ~PowerModuleUavcan();

	void can_init ();
};

#endif /* POWERMODULEUAVCAN_H_ */
