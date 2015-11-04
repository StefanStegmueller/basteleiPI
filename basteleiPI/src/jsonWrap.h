/*
 * jsonWrap.h
 *
 *  Created on: 4 Nov 2015
 *      Author: GordonShumway
 */

#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

#ifndef JSONWRAP_H_
#define JSONWRAP_H_


class jsonWrap {
	rapidjson::Document d;
public:
	jsonWrap();
	virtual ~jsonWrap();
	void SetData(char*, double);
	rapidjson::StringBuffer GetBuffer();
};

#endif /* JSONWRAP_H_ */
