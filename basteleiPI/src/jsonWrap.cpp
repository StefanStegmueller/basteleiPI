/*
 * JsonWrap.cpp
 *
 *  Created on: 4 Nov 2015
 *      Author: GordonShumway
 */

#include "jsonWrap.h"

using namespace rapidjson;

jsonWrap::jsonWrap() {
	d.SetObject();
	Document::AllocatorType& allocator = d.GetAllocator();

	d.AddMember("token", "XYZ", allocator);

	Value object(rapidjson::kObjectType);
		object.AddMember("temperature", "0", allocator);
		object.AddMember("humidity", "0", allocator);
		object.AddMember("pressure", "0", allocator);
		object.AddMember("altitude", "0", allocator);

	d.AddMember("data", object, allocator);
}

jsonWrap::~jsonWrap() {
	// TODO Auto-generated destructor stub
}

void jsonWrap::SetData(const char* value, double input){
	d["data"][value].SetDouble(input);
}

void jsonWrap::SetToken(const char* token){
	d["token"].SetString(token,strlen(token));
}

StringBuffer jsonWrap::GetBuffer(){
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	d.Accept(writer);
	return buffer;
}

