
#define PIN 0
#define INPUT 0
#define DHT_PIN 4
#define DHT_TYPE 22
#define I2C_ADRESS 0x77
#define I2C_DEVICE "/dev/i2c-1"

#include <iostream>
#include <iomanip>
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

void Setup(char* token){
	dht = new dhtHelper();
	bmp = new bmpHelper();
	http = new httpRequest("http://api.bastelei-ws.de/insert.php", token);
}

void ConsoleOutput(){
	time_t result = time(nullptr);
	cout << asctime(localtime(&result)) << "Humidity: " <<dht->humv << "\tTemperature: " << dht->tempv
		 << "\tErrArg: " << dht->errArg << endl;

	cout << fixed << setw(2) << setprecision(3) << "Temp: " << bmp->temp << "\tPress: " << bmp->press
		 << "\tAltitude: " << bmp->alt << endl;
}

int main(int argc, char* argv[]) {
	Setup(argv[0]);
	while(true){
		dht->ReadDht(DHT_TYPE,DHT_PIN);
		//bmp->ReadBmp(I2C_DEVICE, I2C_ADRESS);
		http->Post((double)dht->humv,(double)dht->tempv, (double)bmp->press);
		ConsoleOutput();
	}
	delete dht;
	delete bmp;
	delete http;
	return 0;
}
