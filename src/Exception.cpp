/*
 * Exception.cpp
 *
 *  Created on: 26.9.2013
 *      Author: petr
 */

#include "Exception.hpp"

namespace Gremlin {
namespace Utils {

Exception::Exception() {
	c = 0;
	l = 0;
	p = 0x0;
}

Exception::Exception(string msg, int code, string file, int line,
		const Exception* prev) {

	m = msg;
	c = code;
	f = file;
	l = line;
	p = prev;
}

Exception::~Exception() {
	// TODO Auto-generated destructor stub
}

int Exception::code() const {
	return c;
}

string Exception::file() const {
	return f;
}

int Exception::line() const {
	return l;
}

string Exception::message() const {
	return m;
}

const Exception* Exception::previous() const {
	return p;
}

string Exception::toString() const {
	string retVal;
	char buffer[4096];
	if (p != 0x0) {
		retVal += p->toString();
	} else {
		sprintf(buffer, "code: %d - %s\n\n", c, m.c_str());
		retVal += buffer;
	}

	sprintf(buffer, "%s (%d)", f.c_str(), l);
	retVal += buffer;

	return retVal;
}

} /* namespace Utils */
} /* namespace Gremlin */
