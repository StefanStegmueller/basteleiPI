/*
 * dhtHelper.h
 *
 *  Created on: 29 Oct 2015
 *      Author: GordonShumway
 */

#ifndef DHTHELPER_H_
#define DHTHELPER_H_

#include <stdlib.h>
extern "C"{
	#include "pi_2_dht_read.h"
}

class dhtHelper {
public:
	float humv;
	float tempv;
	int errArg;
	dhtHelper(int, int);
	virtual ~dhtHelper();
	int test_dht_read(int type, int pin, float* humidity, float* temperature);
private:
	float* hum;
	float* temp;
};

#endif /* DHTHELPER_H_ */
