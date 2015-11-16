/*
 * bmpHelper.h
 *
 *  Created on: 5 Nov 2015
 *      Author: GordonShumway
 */

#ifndef BMP180_BMPHELPER_H_
#define BMP180_BMPHELPER_H_

#ifndef NULL
#define NULL   ((void *) 0)
#endif

#include <iostream>
#include <unistd.h>
extern "C"{
	#include "bmp180.h"
}

class bmpHelper {
public:
	bmpHelper();
	virtual ~bmpHelper();
	long press;
	float temp;
	float alt;
	void ReadBmp(char* i2c_device, int adress);
};

#endif /* BMP180_BMPHELPER_H_ */
