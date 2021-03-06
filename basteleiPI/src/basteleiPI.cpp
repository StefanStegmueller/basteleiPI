
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
#include <sstream>
#include <chrono>
#include <thread>

using namespace std;

dhtHelper* dht;
bmpHelper* bmp;
httpRequest* http;

bool CheckArgs(int argc, char* argv[]){
	if(argc != 3){
		cout << "wrong number of arguments" << endl;
		return false;
	}
	else{
		return true;
	}
}

void Setup(){
	dht = new dhtHelper();
	bmp = new bmpHelper();
	http = new httpRequest("http://api.bastelei-ws.de/insert.php");
}

void ConsoleOutput(){
	time_t result = time(nullptr);
	cout << endl << asctime(localtime(&result)) << "Humidity: " <<dht->humv << "\tTemperature: " << dht->tempv
		 << "\tErrArg: " << dht->errArg << endl;

	cout << fixed << setw(2) << setprecision(3) << "Temp: " << bmp->temp << "\tPress: " << bmp->press
		 << "\tAltitude: " << bmp->alt << endl << endl;
}

unsigned int GetTimeout(char* param){
	unsigned int timeout;
	stringstream sstream;
	sstream << param;
	sstream >> timeout;
	return timeout;
}

int main(int argc, char* argv[]) {
	if(!CheckArgs(argc, argv)){
		return 100;
		cout << "Invalid Arguments" << endl;
	}
	Setup();
	cout << "Setup finished" << endl;
	while(true){
		cout << "Read DHT Sensor..." << endl;
		dht->ReadDht(DHT_TYPE,DHT_PIN);
		cout << "Done." << endl;
		cout << "Read BMP Sensor..." << endl;
		bmp->ReadBmp(I2C_DEVICE, I2C_ADRESS);
		cout << "Done." << endl;
		cout << "Sending Data..." << endl;
		http->Post(argv[1], (double)dht->humv,(double)dht->tempv, (double)bmp->press, (double)bmp->alt);
		cout << "Done." << endl;
		ConsoleOutput();
		this_thread::sleep_for(chrono::seconds(GetTimeout(argv[2])));
	}
	delete dht;
	delete bmp;
	delete http;
	return 0;
}
