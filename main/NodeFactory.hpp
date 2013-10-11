#pragma once

#include "Point.hpp"
#include "Node.hpp"

class NodeFactory {
private:
public:
	Node* createNode(Point* pPoint, bool isVertical) {
		return new Node(pPoint, isVertical);	
	}
};
