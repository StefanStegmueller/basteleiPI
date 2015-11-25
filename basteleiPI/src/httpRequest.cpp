/*
 * HttpRequest.cpp *
 *  Created on: 4 Nov 2015
 *      Author: GordonShumway
 */

#include "httpRequest.h"


httpRequest::httpRequest(string url) {
	Init(url);
}

httpRequest::~httpRequest() {
	delete json;
	curl_easy_cleanup(curl);
	curl_global_cleanup();
	free(curl);
}

void httpRequest::Init(const string& url) {
	json = new jsonWrap();
	headers = NULL;

	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();

	headers = curl_slist_append(headers, "Accept: application/json");
	headers = curl_slist_append(headers, "Content-Type: application/json");

	this->url = url;
}

void httpRequest::Post(string token, double hum, double temp, double press, double alt) {

	cToken = token.c_str();
	json->SetToken(cToken);

	json->SetData(DataNames.hum, hum);
	json->SetData(DataNames.temp, temp);
	json->SetData(DataNames.press, press);
	json->SetData(DataNames.alt, alt);
	string jsonStr = json->GetBuffer().GetString();

	curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonStr.c_str());

	curl_easy_perform(curl);
}

