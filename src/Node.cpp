/*
 * Node.cpp
 *
 *  Created on: 23. 12. 2013
 *      Author: petr
 */

#include "Node.hpp"

namespace Gremlin {
namespace Utils {

Node::Node() {
	// nastaveni vsech referenci na nulu
	g = 0x0;
	t = 0;
}

Node::~Node() {
	// odebrani ze seznamu potomku a predku
	NodeList::iterator p, e;

	for (p = ch.begin(), e = ch.end();
			p != e;
			p++) {
		(*p)->p.remove(this);
	}

	for (p = this->p.begin(), e = this->p.end();
			p != e;
			p++) {
		(*p)->ch.remove(this);
	}
}

 Node::Node(size_t type, Graph* graph) {
	t = type;
	g = graph;

	g->n.push_back(this);
	g->t.push_back(this);
}

 void Node::addChild(Node* child) {
}

 void Node::addParent(Node* parent) {
}

 Graph* Node::graph() const {
	 return g;
}

 const NodeList& Node::children() const {
	 return ch;
}

 NodeList Node::children(size_t filter) const {
	 return filterNodes(ch, filter);
}

 const string& Node::name() const {
	 return n;
}

 void Node::name(const string& n) {
	 this->n = n;
}

 size_t Node::nodeType() const {
	 return t;
}

 const NodeList& Node::parents() const {
	 return p;
}

 NodeList Node::parents(size_t filter) const {
	 return filterNodes(p, filter);
}

} /* namespace Utils */
} /* namespace Gremlin */
