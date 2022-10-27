#ifndef NODE_HPP
#define NODE_HPP
class node {
private:
	char	  name;
	float	  cost;
	bool  mark;
	node *nextV;
	node *nextA;

	void init (char n, float c) {
		name = n;
		cost = c;
		mark = false;
		nextV = nullptr;
		nextA = nullptr;
	}
public:
	node (char name) {
		init (name, 1);
	}

	node (char name, float cost) {
		init (name, cost);
	}

	char getName () { return name; }
	float getCost () { return cost; }
	node* getNextV () { return nextV; }
	node* getNextA () { return nextA; }
	bool getMark () { return mark; }

	void setCost  (float c) { cost = c; }
	void setNextV (node *v) { nextV = v; }
	void setNextA (node *a) { nextA = a; }
	void setMark () { mark = true; }
	void clearMark () { mark = false; }
};
#endif
