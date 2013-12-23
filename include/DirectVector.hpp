/*
 * DirectVector.hpp
 *
 *  Created on: 23.8.2013
 *      Author: petr
 */

#ifndef DIRECTVECTOR_HPP_
#define DIRECTVECTOR_HPP_

#include <cstddef>
#include <memory>
#include <cstring>
#include <algorithm>

using namespace std;

namespace Gremlin {
namespace Utils {

template <class T>
class DirectVector {

	static const size_t REALLOC_MULTIPLIER = 2;

	/**
	 * pole dat
	 */
	T *d;

	/**
	 * pocet prvku
	 */
	size_t n;

	/**
	 * pocet alokovanych prvku
	 * rozdil s a n je rezerva
	 */
	size_t s;

	/**
	 * realokuje datovou pamet
	 */
	void reallocate(size_t newSize) {
		// alokace nove pameti
		T *newMem;
		allocator<T> alloc;
		newMem = alloc.allocate(newSize);

		// prekopirovani dat
		size_t l = min(newSize, s);			// delka novych dat
		memcpy(newMem, d, sizeof(T) * l);

		// uvolneni starych dat
		alloc.deallocate(d, s);
		s = newSize;
		d = newMem;
	}

public:

	/**
	 * vytvori neinicializovanou instanci
	 */
	DirectVector() {
		d = 0x0;
		n = 0;
		s = 0;
	}

	/**
	 * kopytor
	 */
	DirectVector(const DirectVector<T> &o) {
		// rezerva nebude kopirovana
		n = o.n;
		s = n;

		// alokace pameti
		allocator<T> alloc;
		d = alloc.allocate(n);

		// prekopirovani dat
		memcpy(d, o.d, sizeof(T) * n);
	}

	/**
	 * destruktor
	 */
	virtual ~DirectVector() {
		// pokud je nejaka pamet zaalokovana, dealokuje se
		if (d != 0x0) {
			// vytvoreni alokatoru a dealokace pameti
			allocator<T> alloc;
			alloc.deallocate(d, s);
		}
	}

	/**
	 * vraci alokovanou velikost
	 */
	size_t capacity() {
		return s;
	}

	/**
	 * pripoji prvek na konec seznamu a vraci jeho index
	 */
	size_t push_back(const T& item) {
		// kontrola, jestli je dost prostoru
		if (n == s) {
			// vypocet nove velikosti
			size_t newSize = REALLOC_MULTIPLIER * s;

			// pokud je nova velikost nula, pak se stanovi na jednicku
			if (newSize == 0)
				newSize = 1;

			// veskery alokovany prostor je zaplnen
			reallocate(newSize);
		}

		// zapis noveho prvku
		d[n++] = item;

		return n - 1;
	}

	/**
	 * vraci ukazatel na data
	 */
	T *rawData() {
		return d;
	}

	/**
	 * vraci konstantni ukazatel na data
	 */
	const T *rawData() const {
		return d;
	}

	/**
	 * vraci pocet prvku
	 */
	size_t size() const {
		return n;
	}

	/**
	 * orizne pocet alokovanych prvku na skutecny pocet prvku
	 */
	void slice() {
		reallocate(n);
	}

	/**
	 * poskytuje pristup k prvku pole
	 */
	T &operator [](size_t i) { return d[i]; }
	const T &operator [](size_t i) const { return d[i]; }

	DirectVector<T> operator=(const DirectVector<T> o) {
		// realokace pameti
		reallocate(o.n);

		s = n = o.n;

		// prekopirovani pameti
		memcpy(d, o.d, o.n * sizeof(T));

		return *this;
	}
};

}
}


#endif /* DIRECTVECTOR_HPP_ */
