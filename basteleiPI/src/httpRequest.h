/*
 * httpRequest.h
 *
 *  Created on: 4 Nov 2015
 *      Author: GordonShumway
 */

#ifndef HTTPREQUEST_H_
#define HTTPREQUEST_H_


#include <cstdlib>
#include <cerrno>
#include <string.h>

#include <cURLpp.hpp>
#include <Easy.hpp>
#include <Options.hpp>
#include <Exception.hpp>
#include "stringbuffer.h"
#include "jsonWrap.h"

class httpRequest {
	jsonWrap* json;
	char* url;
public:
	httpRequest();
	virtual ~httpRequest();
	void Post(float hum, float temp);
};

#endif /* HTTPREQUEST_H_ */
