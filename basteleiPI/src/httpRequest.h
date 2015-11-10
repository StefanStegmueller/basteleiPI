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

	void Init(const string& url, const string& token);

public:
	httpRequest(string url, string token);
	virtual ~httpRequest();
	void Post(float hum, float temp, float press);
};

#endif /* HTTPREQUEST_H_ */
