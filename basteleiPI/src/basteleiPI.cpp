
#define PIN 0
#define INPUT 0
#define DHT_PIN 4
#define DHT_TYPE 22
#define I2C_ADRESS 0x77

#include <iostream>
#include <iomanip>
#include <unistd.h>
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
char* i2c_device = "/dev/i2c-1";

void Setup(char* token){
	dht = new dhtHelper();
	bmp = new bmpHelper();
	http = new httpRequest("http://api.bastelei-ws.de/insert.php", token);
}

void ConsoleOutput(){
	time_t result = time(nullptr);
	cout << asctime(localtime(&result)) << "Humidity: " <<dht->humv << "\tTemperature: " << dht->tempv
		 << "\tErrArg: " << dht->errArg << endl;

	cout << fixed << setw(2) << setprecision(3) << "Temp: " << bmp->temp.f << " Press: " << bmp->press.f
		 << " Altitude: " << bmp->alt.l << endl;
}

int main(int argc, char* argv[]) {
	Setup(argv[0]);
	while(true){
		dht->ReadDht(DHT_TYPE,DHT_PIN);
		bmp->ReadBmp(i2c_device, I2C_ADRESS);
		//http->Post(dht->humv,dht->tempv, bmp->press.f);
		ConsoleOutput();
		usleep(5 * 1000 * 1000);
	}
	delete dht;
	delete bmp;
	delete http;
	return 0;
}
