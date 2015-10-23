/*
 * GpioHandler.h
 *
 *  Created on: 22 Oct 2015
 *      Author: GordonShumway
 */

#ifndef GPIOHELPER_H_
#define GPIOHELPER_H_

class GpioHelper {
public:
	int errmsg;

	GpioHelper(int, bool);
	virtual ~GpioHelper();
};

#endif /* GPIOHELPER_H_ */
