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

class httpRequest {
	jsonWrap* json;
	CURL* curl;
	string url;
	string humName;
	const char* cHumName;
	string tempName;
	const char* cTempName;
	string pressureName;
	const char* cPressureName;
	const char* cToken;

	void Init(const string& url);

public:
	httpRequest(string url);
	virtual ~httpRequest();
	void Post(string token, double hum, double temp, double press);
};

#endif /* HTTPREQUEST_H_ */
