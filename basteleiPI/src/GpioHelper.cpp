#include "GpioHelper.h"
#include <wiringPi.h>
#include <stdlib.h>

int errmsg;

GpioHelper::GpioHelper(int pin,bool mode) {
	errmsg = wiringPiSetup();
	if(mode){
		pinMode(pin,INPUT);
	}
	else{
		pinMode(pin,OUTPUT);
	}
}

GpioHelper::~GpioHelper() {
}

