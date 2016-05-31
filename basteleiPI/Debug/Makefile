CFLAGS=-I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -std=gnu99 -MMD -MP
CPPFLAGS=-I/usr/local/include/rapidjson -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP

all: basteleiPI

basteleiPI: common_dht_read.o dhtHelper.o pi_2_dht_read.o pi_2_mmio.o test_dht_read.o bmp180.o bmpHelper.o basteleiPI.o gpioHelper.o httpRequest.o jsonWrap.o
	g++ -L/usr/lib -L/usr/local/lib -o "basteleiPI"  ./src/DHT22/common_dht_read.o ./src/DHT22/dhtHelper.o ./src/DHT22/pi_2_dht_read.o ./src/DHT22/pi_2_mmio.o ./src/DHT22/test_dht_read.o  ./src/BMP180/bmp180.o ./src/BMP180/bmpHelper.o  ./src/basteleiPI.o ./src/gpioHelper.o ./src/httpRequest.o ./src/jsonWrap.o   -lwiringPi -lcurl -lpthread

common_dht_read.o:
	gcc $(CFLAGS) -MF"src/DHT22/common_dht_read.d" -MT"src/DHT22/common_dht_read.o" -o "src/DHT22/common_dht_read.o" "../src/DHT22/common_dht_read.c"
	
dhtHelper.o:
	g++ $(CPPFLAGS) -MF"src/DHT22/dhtHelper.d" -MT"src/DHT22/dhtHelper.o" -o "src/DHT22/dhtHelper.o" "../src/DHT22/dhtHelper.cpp"
	
pi_2_dht_read.o:
	gcc $(CFLAGS) -MF"src/DHT22/pi_2_dht_read.d" -MT"src/DHT22/pi_2_dht_read.o" -o "src/DHT22/pi_2_dht_read.o" "../src/DHT22/pi_2_dht_read.c"
	
pi_2_mmio.o:
	gcc $(CFLAGS) -MF"src/DHT22/pi_2_mmio.d" -MT"src/DHT22/pi_2_mmio.o" -o "src/DHT22/pi_2_mmio.o" "../src/DHT22/pi_2_mmio.c"
	
test_dht_read.o:
	gcc $(CFLAGS) -MF"src/DHT22/test_dht_read.d" -MT"src/DHT22/test_dht_read.o" -o "src/DHT22/test_dht_read.o" "../src/DHT22/test_dht_read.c"

bmp180.o:
	gcc $(CFLAGS) -MF"src/BMP180/bmp180.d" -MT"src/BMP180/bmp180.o" -o "src/BMP180/bmp180.o" "../src/BMP180/bmp180.c"

bmpHelper.o:
	g++ $(CPPFLAGS) -MF"src/BMP180/bmpHelper.d" -MT"src/BMP180/bmpHelper.o" -o "src/BMP180/bmpHelper.o" "../src/BMP180/bmpHelper.cpp"

basteleiPI.o:
	g++ $(CPPFLAGS) -MF"src/basteleiPI.d" -MT"src/basteleiPI.o" -o "src/basteleiPI.o" "../src/basteleiPI.cpp"
	
gpioHelper.o:
	g++ $(CPPFLAGS) -MF"src/gpioHelper.d" -MT"src/gpioHelper.o" -o "src/gpioHelper.o" "../src/gpioHelper.cpp"

httpRequest.o:
	g++ $(CPPFLAGS) -MF"src/httpRequest.d" -MT"src/httpRequest.d" -o "src/httpRequest.o" "../src/httpRequest.cpp"

jsonWrap.o:
	g++ $(CPPFLAGS) -MF"src/jsonWrap.d" -MT"src/jsonWrap.o" -o "src/jsonWrap.o" "../src/jsonWrap.cpp"
	
clean:
	rm  -Rf src/*
	rm basteleiPI
