/*
 * DhtHelper.cpp
 *
 *  Created on: 29 Oct 2015
 *      Author: GordonShumway
 */

#include "DhtHelper.h"
#include <stdlib.h>
extern "C"{
	#include "pi_2_dht_read.h"
}

DhtHelper::DhtHelper(int type, int pin) {
	//test_dht_read(type, pin, hum,temp);
	errArg = pi_2_dht_read(type,pin,hum,temp);
}

int DhtHelper::test_dht_read(int type, int pin, float* humidity, float* temperature) {
  // Validate humidity and temperature arguments and set them to zero.
  if (humidity == NULL || temperature == NULL) {
    return -1;
  }
  *temperature = 42.0f;
  *humidity = 50.0f;

  return 0;
}

DhtHelper::~DhtHelper() {
	// TODO Auto-generated destructor stub
}

