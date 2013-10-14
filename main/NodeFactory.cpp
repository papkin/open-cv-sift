#include "NodeFactory.hpp"

Node* NodeFactory::createNode(Point* pPoint, bool isVertical) {
	return new Node(pPoint, isVertical);	
}

