/*
 * gpioHandler.h
 *
 *  Created on: 22 Oct 2015
 *      Author: GordonShumway
 */

#ifndef GPIOHELPER_H_
#define GPIOHELPER_H_

class gpioHelper {
public:
	int errmsg;

	gpioHelper(int, bool);
	virtual ~gpioHelper();
};

#endif /* GPIOHELPER_H_ */
