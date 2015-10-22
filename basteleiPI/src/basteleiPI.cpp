
#define PIN 0
#define INPUT 0

#include <iostream>
#include "GpioHelper.h"

int Setup(){
	GpioHelper* gpio = new GpioHelper(PIN,INPUT);
	return gpio->errmsg;
}

int main() {
	if(Setup() == -1){
		std::cout << "Setup failed" << std::endl;
		return 1;
	}
	std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!
	return 0;
}
