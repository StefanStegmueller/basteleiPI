/*
 * HttpRequest.cpp *
 *  Created on: 4 Nov 2015
 *      Author: GordonShumway
 */

#include "httpRequest.h"


httpRequest::httpRequest(string url, string token) {
	Init(url, token);
	json->SetToken(cToken);
}

httpRequest::~httpRequest() {
	delete json;
	free(curl);
}

void httpRequest::Init(const string& url, const string& token) {
	json = new jsonWrap();
	curl = (CURL*) (malloc(sizeof(CURL*)));
	this->url = url;
	cToken = token.c_str();
	humName = "humidity";
	cHumName = humName.c_str();
	tempName = "temperature";
	cTempName = tempName.c_str();
	pressureName = "pressure";
	cPressureName = pressureName.c_str();
}

void httpRequest::Post(float hum, float temp, float press) {
	json->SetData(cHumName, hum);
	json->SetData(cTempName, temp);
	json->SetData(cPressureName, press);

	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();

	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json->GetBuffer().GetString());

	curl_easy_perform(curl);

	curl_easy_cleanup(curl);
	curl_global_cleanup();
}

