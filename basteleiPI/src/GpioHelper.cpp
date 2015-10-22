#include "GpioHelper.h"
#include <wiringPi.h>

int errmsg;

GpioHelper::GpioHelper(int pin, int mode) {
	errmsg = wiringPiSetup();
	pinMode(pin,mode);
}

GpioHelper::~GpioHelper() {
}

