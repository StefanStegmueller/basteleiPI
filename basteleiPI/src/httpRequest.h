/*
 * httpRequest.h
 *
 *  Created on: 4 Nov 2015
 *      Author: GordonShumway
 */

#ifndef HTTPREQUEST_H_
#define HTTPREQUEST_H_


#include <cstdlib>
#include <cerrno>
#include <string>
extern "C"{
	#include <curl/curl.h>
}
#include "rapidjson/stringbuffer.h"
#include "jsonWrap.h"

using namespace std;


struct data{
	const char* hum = "humidity";
	const char* temp = "temperature";
	const char* press = "airpressure";
	const char* alt = "altitude";
};

class httpRequest {
	jsonWrap* json;
	CURL* curl;
	struct curl_slist* headers;
	string url;
	struct data DataNames;
	const char* cToken;

	void Init(const string& url);

public:
	httpRequest(string url);
	virtual ~httpRequest();
	void Post(string token, double hum, double temp, double press, double alt);
};

#endif /* HTTPREQUEST_H_ */
