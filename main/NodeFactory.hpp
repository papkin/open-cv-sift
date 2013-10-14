#pragma once
#include "Node.hpp"
#include "Point.hpp"
class NodeFactory {
public:
	Node* createNode(Point* pPoint, bool isVertical);
};
