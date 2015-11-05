/*
 * HttpRequest.cpp *
 *  Created on: 4 Nov 2015
 *      Author: GordonShumway
 */

#include "httpRequest.h"

httpRequest::httpRequest() {
	curl = new CURL();
	curl = curl_easy_init();
	json = new jsonWrap();
}

httpRequest::~httpRequest() {
	delete curl;
	delete json;
}

void httpRequest::Post(float hum, float temp){
	json->SetData("humidity", hum);
	json->SetData("temperature", temp);
	curl_easy_setopt(curl, CURLOPT_URL, "http://api.bastelei-ws.de/insert.php");
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json->GetBuffer().GetString());

	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
}

