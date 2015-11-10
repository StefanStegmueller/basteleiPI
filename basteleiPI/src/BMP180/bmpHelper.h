/*
 * bmpHelper.h
 *
 *  Created on: 5 Nov 2015
 *      Author: GordonShumway
 */

#ifndef BMP180_BMPHELPER_H_
#define BMP180_BMPHELPER_H_

extern "C"{
	#include "bmp180dev3.h"
}

class bmpHelper {
public:
	bmpHelper();
	virtual ~bmpHelper();
	float press;
	float temp;
	float alt;
};

#endif /* BMP180_BMPHELPER_H_ */
