/*
 * bmpHelper.cpp
 *
 *  Created on: 5 Nov 2015
 *      Author: GordonShumway
 */

#include "bmpHelper.h"

bmpHelper::bmpHelper() {
	press = 0.0;
	temp = 0.0;
	alt = 0.0;
}

bmpHelper::~bmpHelper() {
	// TODO Auto-generated destructor stub
}


void bmpHelper::ReadBmp(char* i2c_device, int adress) {
	cout << "Start BMP INIT" << endl;
	void *bmp = bmp180_init(adress, i2c_device);
	cout << "BMP INIT done." << endl;

	temp = 0;
	press = 0;
	alt = 0;

	bmp180_eprom_t eprom;
	bmp180_dump_eprom(bmp, &eprom);
	bmp180_set_oss(bmp, 1);

	if(bmp != NULL){
		for(int i = 0; i < 10; i++) {
			if(temp == 0)
				temp = bmp180_temperature(bmp);
			if(press == 0)
				press = bmp180_pressure(bmp);
			if(alt == 0)
				alt = bmp180_altitude(bmp);

		    usleep(1000);
		}
		bmp180_close(bmp);
	}
}
