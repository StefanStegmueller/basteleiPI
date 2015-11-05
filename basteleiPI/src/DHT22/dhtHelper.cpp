/*
 * dhtHelper.cpp
 *
 *  Created on: 29 Oct 2015
 *      Author: GordonShumway
 */

#include "dhtHelper.h"

dhtHelper::dhtHelper(int type, int pin) {
	hum = &humv;
	temp = &tempv;
	errArg = pi_2_dht_read(type,pin,hum,temp);
	sleep_milliseconds(2500);
}

int dhtHelper::test_dht_read(int type, int pin, float* humidity, float* temperature) {
  // Validate humidity and temperature arguments and set them to zero.
  if (humidity == NULL || temperature == NULL) {
    return -1;
  }
  *temperature = 42.0f;
  *humidity = 50.0f;

  return 0;
}

dhtHelper::~dhtHelper() {
	// TODO Auto-generated destructor stub
}

