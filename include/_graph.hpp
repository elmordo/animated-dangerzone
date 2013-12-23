/*
 * _graph.hpp
 *
 *  Created on: 22. 12. 2013
 *      Author: petr
 */

#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <list>
#include <string>
#include <stddef.h>

using namespace std;

namespace Gremlin {
namespace Utils {

class Node;

typedef list<Node *> NodeList;

class Graph {

	/**
	 * seznam uzlu v grafu
	 */
	NodeList n;

	/**
	 * seznam uzlu stupne nula
	 * (odpadak)
	 */
	NodeList t;

public:

	/**
	 * bezparametricky konstruktor
	 */
	Graph();

	/**
	 * destruktor
	 */
	virtual ~Graph();

	/**
	 * vytvori novy uzel grafu
	 */
	Node *createNode(size_t nodeType);

	/**
	 * vraci seznam uzlu v grafu
	 */
	const NodeList &nodes() const;

	/**
	 * vraci seznam uzlu daneho typu
	 */
	NodeList nodes(size_t filter) const;

	/**
	 * vraci seznam uzlu se stupnem nula
	 */
	const NodeList &trash() const;

	/**
	 * vraci seznam uzlu se stupnem nula daneho typu
	 */
	NodeList trash(size_t filter) const;

	friend Node;
};

class Node {

	/**
	 * rodicovsky graf
	 */
	Graph *g;

	/**
	 * seznam primych potomku
	 */
	NodeList ch;

	/**
	 * jmeno uzlu
	 */
	string n;

	/**
	 * seznam primych predku
	 */
	NodeList p;

	/**
	 * typ uzlu
	 * umoznuje filtraci
	 */
	size_t t;

public:

	/**
	 * bezparametricky konstruktor uzlu
	 * nastavi typ uzlu na nulu
	 */
	Node();

	/**
	 * nastavi typ uzlu a priradi uzel grafu
	 */
	Node(size_t type, Graph *graph);

	/**
	 * destruktor
	 * smaze uzel ze vsech asociovanych seznamu
	 */
	virtual ~Node();

	/**
	 * prida potomka
	 */
	void addChild(Node *child);

	/**
	 * prida predka
	 */
	void addParent(Node *parent);

	/**
	 * vraci ukazatel na graf
	 */
	Graph *graph() const;

	/**
	 * vraci seznam primych potomku
	 */
	const NodeList &children() const;

	/**
	 * vraci seznam primych nasledniku dle daneho typu
	 */
	NodeList children(size_t filter) const;

	/**
	 * vraci jmeno uzlu
	 */
	const string &name() const;

	/**
	 * nastavi jmeno uzlu
	 */
	void name(const string &n);

	/**
	 * vraci typ uzlu
	 */
	size_t nodeType() const;

	/**
	 * vraci seznam primych predku
	 */
	const NodeList &parents() const;

	/**
	 * vraci seznam primych predku vyfiltrovanych dle filtru
	 */
	NodeList parents(size_t filter) const;

	friend Graph;
};

/**
 * vyfiltruje uzly dle typu
 */
inline NodeList filterNodes(const NodeList &s, size_t nodeType) {
	NodeList retVal;

	return retVal;
}

}
}

#endif /* GRAPH_HPP_ */
