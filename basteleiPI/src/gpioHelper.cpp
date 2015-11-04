#include <wiringPi.h>
#include <stdlib.h>
#include "gpioHelper.h"

int errmsg;

gpioHelper::gpioHelper(int pin,bool mode) {
	errmsg = wiringPiSetup();
	if(mode){
		pinMode(pin,INPUT);
	}
	else{
		pinMode(pin,OUTPUT);
	}
}

gpioHelper::~gpioHelper() {
}

