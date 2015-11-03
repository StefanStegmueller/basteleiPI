/*
 * DhtHelper.h
 *
 *  Created on: 29 Oct 2015
 *      Author: GordonShumway
 */

#ifndef DHTHELPER_H_
#define DHTHELPER_H_

class DhtHelper {
public:
	float humv;
	float tempv;
	float* hum = &humv;
	float* temp = &tempv;
	DhtHelper(int, int);
	virtual ~DhtHelper();
	int test_dht_read(int type, int pin, float* humidity, float* temperature);
	int pi_2_dht_read(int type, int pin, float* humidity, float* temperature);
};

#endif /* DHTHELPER_H_ */
