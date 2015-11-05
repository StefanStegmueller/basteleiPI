/*
 * jsonWrap.h
 *
 *  Created on: 4 Nov 2015
 *      Author: GordonShumway
 */

#ifndef JSONWRAP_H_
#define JSONWRAP_H_

#include "writer.h"
#include "stringbuffer.h"
#include "document.h"
#include <iostream>

using namespace rapidjson;

class jsonWrap {
	Document d;
public:
	jsonWrap();
	virtual ~jsonWrap();
	void SetData(char*, double);
	rapidjson::StringBuffer GetBuffer();
};

#endif /* JSONWRAP_H_ */
