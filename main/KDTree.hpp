#pragma once

#include "Node.hpp"
#include "NodeFactory.hpp"
#include "Point.hpp"
#include <float.h>

class KDTree {
private:
	Node* mpRoot;
	NodeFactory* mpNodeFactory;
	void traverseAdd(Point* pPoint);
public:
	KDTree(NodeFactory* pNodeFactory = new NodeFactory());
	void add(Point* pPoint);
	Point* findNearest(Point* pPoint);
};
