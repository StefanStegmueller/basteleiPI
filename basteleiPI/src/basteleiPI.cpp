
#define PIN 0
#define PIN_DHT 4
#define TYPE_DHT 22
#define INPUT 0

#include <iostream>
#include "GpioHelper.h"
#include "DhtHelper.h"
#include <sys/time.h>
#include <ctime>

using namespace std;

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

	time_t result = time(nullptr);

	while(true) {
	DhtHelper* dht = new DhtHelper(TYPE_DHT,PIN_DHT);
	cout << asctime(localtime(&result)) << "Humidity: " <<dht->humv << "\tTemperature: " << dht->tempv
			  << "\tErrArg: " << dht->errArg << std::endl;
	}
	return 0;
}
