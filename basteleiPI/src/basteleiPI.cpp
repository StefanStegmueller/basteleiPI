
#define PIN 0
#define INPUT 0

#include <iostream>
#include "GpioHelper.h"
#include "DhtHelper.h"
#include "curl_easy.h"

int Setup(){
	GpioHelper* gpio = new GpioHelper(PIN,INPUT);
	return gpio->errmsg;
}

int main() {
	//Init GPIO
	/*if(Setup() == -1){
		std::cout << "Setup failed" << std::endl;
		return 1;
	}*/
	DhtHelper* dht = new DhtHelper(0,PIN);
	std::cout << "Humidity: " <<dht->humv << "\tTemperature: " << dht->tempv << std::endl;
	return 0;
}
