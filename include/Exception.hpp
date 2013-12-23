/*
 * Exception.hpp
 *
 *  Created on: 26.9.2013
 *      Author: petr
 */

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <string>
#include <cstdio>

// definice makra pro generovani vyjimky
#define THROW_EXCEPTION(CLASS_NAME,MESSAGE,CODE,PREV) throw CLASS_NAME(MESSAGE, CODE, __FILE__, __LINE__, PREV);

// makro definujici vytvoreni odvozene vyjimky
#define NEW_EXCEPTION_CLASS(NEW_CLASS,OLD_CLASS) class NEW_CLASS : public OLD_CLASS {\
public:\
	NEW_CLASS() : OLD_CLASS() {}\
	NEW_CLASS(string msg, int code = 0, string file = "", int line = 0, const Exception* prev = 0x0) : OLD_CLASS(msg,code,file,line,prev) {}\
	virtual ~NEW_CLASS() {}\
};

using namespace std;

namespace Gremlin {
namespace Utils {

class Exception {

	/**
	 * zprava
	 */
	string m;

	/**
	 * chybovy kod
	 */
	int c;

	/**
	 * soubor
	 */
	string f;

	/**
	 * radek
	 */
	int l;

	/**
	 * predchozi vyjimka
	 */
	const Exception *p;

public:

	/**
	 * vytvori prazdnou instanci vyjimky
	 */
	Exception();

	/**
	 * vytvori instanci vyjimky s informacemi
	 */
	Exception(string msg, int code = 0, string file = "", int line = 0, const Exception* prev = 0x0);

	/**
	 * znici vyjimku
	 */
	virtual ~Exception();

	/**
	 * vraci kod chyby
	 */
	int code() const;

	/**
	 * vraci soubor, kde chyba vznikla
	 */
	string file() const;

	/**
	 * vraci radek, na kterem byla vyjimka vyvolana
	 */
	int line() const;

	/**
	 * vraci zpravu
	 */
	string message() const;

	/**
	 * vraci predchozi vyjimku
	 */
	const Exception* previous() const;

	/**
	 * sestavi kompletni chybove hlaseni
	 */
	string toString() const;
};

} /* namespace Utils */
} /* namespace Gremlin */
#endif /* EXCEPTION_HPP_ */
