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
extern "C"{
	#include "bmp180.h"
}

class bmpHelper {
	union data{
		long l;
		float f;
	};
public:
	bmpHelper();
	virtual ~bmpHelper();
	data press;
	data temp;
	data alt;
	void ReadBmp(char* i2c_device, int adress);
};

#endif /* BMP180_BMPHELPER_H_ */
