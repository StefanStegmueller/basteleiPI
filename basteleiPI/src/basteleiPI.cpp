
#define PIN 0
#define PIN_DHT 4
#define TYPE_DHT 22
#define INPUT 0

#include <iostream>
#include "GpioHelper.h"
#include "DhtHelper.h"

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
	DhtHelper* dht = new DhtHelper(TYPE_DHT,PIN_DHT);
	std::cout << "Humidity: " <<dht->humv << "\tTemperature: " << dht->tempv << std::endl;
	return 0;
}
