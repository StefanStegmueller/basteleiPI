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
		int i;
		for(i = 0; i < 10; i++) {
			temp.f = bmp180_temperature(bmp);
			press.l = bmp180_pressure(bmp);
			alt.f = bmp180_altitude(bmp);
			std::cout << "Temp: " << temp.f << "Press: " << press.f << "Altitude" << alt.l;
			usleep(2 * 1000 * 1000);
		}
		bmp180_close(bmp);
	}
}
