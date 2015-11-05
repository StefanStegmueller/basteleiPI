/*
 * HttpRequest.cpp *
 *  Created on: 4 Nov 2015
 *      Author: GordonShumway
 */

#include "httpRequest.h"

httpRequest::httpRequest() {
	json = new jsonWrap();
	url = "http://api.bastelei-ws.de/insert.php";
}

httpRequest::~httpRequest() {
	delete json;
}

void httpRequest::Post(float hum, float temp){
	json->SetData("humidity", hum);
	json->SetData("temperature", temp);
	 try {
		curlpp::Cleanup cleaner;
		curlpp::Easy request;

		request.setOpt(new curlpp::options::Url(url));
		request.setOpt(new curlpp::options::Verbose(true));
		request.setOpt(new curlpp::options::PostFields(json->GetBuffer().GetString()));

		request.perform();
	  }
	  catch ( curlpp::LogicError & e ) {
		std::cout << e.what() << std::endl;
	  }
	  catch ( curlpp::RuntimeError & e ) {
		std::cout << e.what() << std::endl;
	  }
}

