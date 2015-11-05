/*
 * httpRequest.h
 *
 *  Created on: 4 Nov 2015
 *      Author: GordonShumway
 */

#ifndef HTTPREQUEST_H_
#define HTTPREQUEST_H_

#include <curl/curl.h>
#include "stringbuffer.h"
#include "jsonWrap.h"

class httpRequest {
	CURL* curl;
	jsonWrap* json;
public:
	httpRequest();
	virtual ~httpRequest();
	void Post(float hum, float temp);
};

#endif /* HTTPREQUEST_H_ */
