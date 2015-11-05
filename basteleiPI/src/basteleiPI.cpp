
#define PIN 0
#define INPUT 0
#define PIN_DHT 4
#define TYPE_DHT 22

#include <iostream>
#include "gpioHelper.h"
#include "DHT22/dhtHelper.h"
#include "BMP180/bmpHelper.h"
#include "httpRequest.h"
#include <sys/time.h>

using namespace std;

dhtHelper* dht;
bmpHelper* bmp;
httpRequest* http;

int Setup(){
	/*gpioHelper* gpio = new gpioHelper(PIN,INPUT);
	return gpio->errmsg;*/
	dht = new dhtHelper(TYPE_DHT,PIN_DHT);
	bmp = new bmpHelper();
	http = new httpRequest();
}

void ConsoleOutput(){
	time_t result = time(nullptr);
	cout << asctime(localtime(&result)) << "Humidity: " <<dht->humv << "\tTemperature: " << dht->tempv
		 << "\tErrArg: " << dht->errArg << std::endl;
}

int main() {
	//Init GPIO
	/*if(Setup() == -1){
		std::cout << "Setup failed" << std::endl;
		return 1;
	}*/
	Setup();
	//http->Post(dht->humv,dht->tempv);
	ConsoleOutput();
	delete dht;
	delete http;
	return 0;
}
