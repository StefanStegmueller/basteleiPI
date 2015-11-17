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
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();

	this->url = url;
	cToken = token.c_str();
	json->SetToken(cToken);

	humName = "humidity";
	cHumName = humName.c_str();
	tempName = "temperature";
	cTempName = tempName.c_str();
	pressureName = "pressure";
	cPressureName = pressureName.c_str();
}

void httpRequest::Post(double hum, double temp, double press) {
	json->SetData(cHumName, hum);
	json->SetData(cTempName, temp);
	json->SetData(cPressureName, press);
	string jsonStr = json->GetBuffer().GetString();

	cout << jsonStr << endl;

	struct curl_slist *headers = NULL;

	headers = curl_slist_append(headers, "Accept: application/json");
	headers = curl_slist_append(headers, "Content-Type: application/json");

	curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonStr.c_str());

	curl_easy_perform(curl);

	curl_easy_cleanup(curl);
	curl_global_cleanup();
}

