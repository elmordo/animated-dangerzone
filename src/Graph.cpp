/*
 * Graph.cpp
 *
 *  Created on: 23. 12. 2013
 *      Author: petr
 */

#include "Graph.hpp"

namespace Gremlin {
namespace Utils {

Graph::Graph() {
	// kontruktor nic delat nemusi
}

Graph::~Graph() {
	// destruktor znici vsechny uzly grafu
	NodeList::iterator p = n.begin(), e = n.end();

	while (p != e) {
		delete *p;
		p++;
	}
}

 Node* Graph::createNode(size_t nodeType) {
	 // vytvoreni uzlu - uzel je do grafu pridan ze sveho konstruktoru
	 Node *retVal = new Node(nodeType, this);

	 // vraceni hodnoty
	 return retVal;
}

 const NodeList& Graph::nodes() const {
	 return n;
}

 NodeList Graph::nodes(size_t filter) const {
	 return filterNodes(n, filter);
}

 const NodeList& Graph::trash() const {
	 return t;
}

 NodeList Graph::trash(size_t filter) const {
	 return filterNodes(t, filter);
}

} /* namespace Utils */
} /* namespace Gremlin */
