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

	bmp180_eprom_t eprom;
	bmp180_dump_eprom(bmp, &eprom);
	bmp180_set_oss(bmp, 1);

	if(bmp != NULL){
		for(int i = 0; i < 10; i++) {
			if(temp.f == 0)
				temp.f = bmp180_temperature(bmp);
			if(press.l == 0)
				press.l = bmp180_pressure(bmp);
			if(alt.f == 0)
				alt.f = bmp180_altitude(bmp);

		    usleep(5 * 1000 * 1000);
		}
		bmp180_close(bmp);
	}
}
