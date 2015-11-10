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


void bmpHelper::ReadBmp() {
	int fd;
	fd=i2c_Open(I2CBus);
	printf ("\nCalibration:%i (0= worked)\n",bmp_Calibration(fd));
	printf ("Return:%i\tTemperature\t:%.1f C\n",bmp_GetTemperature(fd,&temp.d),temp.d);
	printf ("Return:%i\tPressure\t:%.2f hPa/mB\tThis is known as station pressure\n",bmp_GetPressure(fd,&press.d),press.d);
	alt.f=bmp_altitude(press.d);
	printf ("\t\tP.Altitude\t:%.0f ft\tThis is known as a Pressure Altitude\n",alt.d);
	printf ("\t\tQNH\t\t:%.2f hPa/mB\tSetting required on an Aircraft\n",bmp_qnh(press.d,5085)); //5085 ft is my station elevation
	printf ("\t\t\t\t\t\taltimeter for it to read Elevation while on the ground\n");	             //use your's
	printf ("\t\t\t\t\t\tand Altitude while in the air\n");
	printf ("\t\t\t\t\t\tSensor Elevation MUST BE KNOWN ACCURATELY\n");
	printf ("\t\tD.Altitude\t:%.0f ft\tThis is known as a density Altitude\n\n",ppl_DensityAlt(alt.d,temp.d));
   close (fd);
}
