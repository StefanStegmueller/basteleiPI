/*
 * jsonWrap.h
 *
 *  Created on: 4 Nov 2015
 *      Author: GordonShumway
 */

#ifndef JSONWRAP_H_
#define JSONWRAP_H_

#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/document.h"
#include <string>
#include <iostream>

using namespace rapidjson;

class jsonWrap {
	Document d;
public:
	jsonWrap();
	virtual ~jsonWrap();
	void SetData(const char*, double);
	void SetToken(const char* token);
	StringBuffer GetBuffer();
};

#endif /* JSONWRAP_H_ */
