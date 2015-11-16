/*
 * JsonWrap.cpp
 *
 *  Created on: 4 Nov 2015
 *      Author: GordonShumway
 */

#include "jsonWrap.h"

using namespace rapidjson;

jsonWrap::jsonWrap() {
	// 1. Parse a JSON string into DOM.
	const char* json = "{\"token\":0,\"data\":{\"humidity\":0,\"temperature\":0,\"pressure\":0}}";
	std::cout << json << std::endl;
	d.Parse(json);
}

jsonWrap::~jsonWrap() {
	// TODO Auto-generated destructor stub
}

void jsonWrap::SetData(const char* value, double input){
	assert(d["token"]["data"][value].GetDouble() == input);
}

void jsonWrap::SetToken(const char* token){
	//assert(d["token"].SetString(token,strlen(token)));
}

StringBuffer jsonWrap::GetBuffer(){
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	d.Accept(writer);
	return buffer;
}

