
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
#include <string>

using namespace std;

dhtHelper* dht;
bmpHelper* bmp;
httpRequest* http;

void Setup(){
	dht = new dhtHelper();
	bmp = new bmpHelper();
	http = new httpRequest("http://api.bastelei-ws.de/insert.php");
}

void ConsoleOutput(){
	time_t result = time(nullptr);
	cout << asctime(localtime(&result)) << "Humidity: " <<dht->humv << "\tTemperature: " << dht->tempv
		 << "\tErrArg: " << dht->errArg << std::endl;
}

int main() {
	Setup();
	while(true){
		dht->ReadDht(TYPE_DHT,PIN_DHT);
		bmp->ReadBmp();
		http->Post(dht->humv,dht->tempv, bmp->press.f);
		ConsoleOutput();
	}
	delete dht;
	delete bmp;
	delete http;
	return 0;
}
