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
	union data{
		double d;
		float f;
	};
public:
	bmpHelper();
	virtual ~bmpHelper();
	data press;
	data temp;
	data alt;
	void ReadBmp();
};

#endif /* BMP180_BMPHELPER_H_ */
