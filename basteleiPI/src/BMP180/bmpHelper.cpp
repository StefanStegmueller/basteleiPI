/*
 * bmpHelper.cpp
 *
 *  Created on: 5 Nov 2015
 *      Author: GordonShumway
 */

#include "bmpHelper.h"

bmpHelper::bmpHelper() {
	press.f = 0.0;
	temp.f = 0.0;
	alt.f = 0.0;
}

bmpHelper::~bmpHelper() {
	// TODO Auto-generated destructor stub
}


void bmpHelper::ReadBmp(char* i2c_device, int adress) {
	void *bmp = bmp180_init(adress, i2c_device);
	if(bmp != NULL){
		for(int i = 0; i < 10; i++) {
			if(temp.f == NULL)
				temp.f = bmp180_temperature(bmp);
			if(press.l == NULL)
				press.l = bmp180_pressure(bmp);
			if(alt.f == NULL)
				alt.f = bmp180_altitude(bmp);
		}
		bmp180_close(bmp);
	}
}
