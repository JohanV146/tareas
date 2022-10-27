#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>

#include "node.hpp"
#include "queue.hpp"

class graph {
private:
	node *vertex;
	bool  directed;
	bool  weighted;
	int	  vCount;
public:
	static const int DIRECTED 	 = true;
	static const int NOTDIRECTED = false;
	static const int WEIGHTED 	 = true;
	static const int NOTWEIGHTED = false;

	graph (bool d, bool w) {
		vertex = nullptr;
		directed = d;
		weighted = w;
		vCount = 0;
	}
	
	int getVCount () {
		return vCount;
	}

	bool getWeighted () { return weighted; }
	bool getDirected () { return directed; }

	void insertVertex (node *v) {
		v->setNextV (vertex);
		vertex = v;
		vCount++;
	}

	void insertConnection (char v1, char v2, int cost) {
		node *n1 = seekV (v1);
		node *n2 = seekV (v2);

		if (n1 == nullptr) {
			insertVertex (new node (v1));
			n1 = seekV (v1);
		}
		if (n2 == nullptr) {
			insertVertex (new node (v2));
			n2 = seekV (v2);
		}

		node *c1 = seekC (v1, v2);
		if (c1 == nullptr) {
			node *t = n1->getNextA ();
			node *n = new node (v2, cost);

			n1->setNextA (n);
			n->setNextA (t);
		} else c1->setCost (cost);

		if (!directed) {
			node *c2 = seekC (v2, v1);
			if (c2 == nullptr) {
				node *t = n2->getNextA ();
				node *n = new node (v1, cost);

				n2->setNextA (n);
				n->setNextA (t);
			} else c2->setCost (cost);
		}
	}

	void insertConnection (char v1, char v2) {
		insertConnection (v1, v2, 1);
	}

	char seekV (int i) {
		if (i >= vCount)
			return '\0';
		node *t = vertex;
		for (int p = 0; p < i; p++)
			t = t->getNextV ();
		return t->getName ();
	}

	node* seekV (char v) {
		for (node *t = vertex; t != nullptr; t = t->getNextV ())
			if (t->getName () == v)
				return t;
		return nullptr;
	}

	node* seekC (char v1, char v2) {
		node *n1 = seekV (v1);

		if (n1 != nullptr)
			for (node *t = n1->getNextA (); t != nullptr; t = t->getNextA ())
				if (t->getName () == v2)
					return t;
		return nullptr;
	}

	void print () {
		for (node *v = vertex; v != nullptr; v = v->getNextV ()) {
			std::cout << "[" << v << "]:[" << v->getName () << "]";
			for (node *a = v->getNextA (); a != nullptr; a = a->getNextA ())
				std::cout << "->" << a->getName () << "(" << a->getCost () << ")";
			std::cout << std::endl;
		}
	}

	float** ToMatrix () {
		float **matrix = new float*[vCount];
		for (int i = 0; i < vCount; i++) {
			matrix[i] = new float[vCount];
			for (int j = 0; j < vCount; j++) {
				node *t = seekC (seekV (i), seekV (j));
				if (t != nullptr)
					matrix[i][j] = t->getCost ();
				else matrix[i][j] = 0;
			}
		}
		return matrix;
	}

	void depth () {
		// Insert code here
	}

	void width (char v) {
		node *s = seekV(v);
		if (s != nullptr) {
			s->setMark ();
			queue *q = new queue ();
			q->enqueue (s->getName ());
			while (!q->empty ()) {
				s = seekV (q->dequeue ());
				if (s != nullptr) {
					std::cout << "[" << s << "]:[" << s->getName () << "]" << std::endl;
					for (node *a = s->getNextA (); a != nullptr; a = a->getNextA ()) {
						s = seekV (a->getName ());
						if (s != nullptr && !s->getMark ()) {
							s->setMark ();
							q->enqueue (s->getName ());
						}
					}
				}
			}
			for (s = vertex; s != nullptr; s = s->getNextV ())
				s->clearMark ();
		} else {
			std::cout << "Source vertex not found!" << std::endl;
		}
	}

	void components () {
		// Insert code here
	}
};
#endif
