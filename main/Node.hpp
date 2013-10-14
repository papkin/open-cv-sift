#pragma once

#include "Point.hpp"

class Node {
private:
	Point* mpPoint;
	bool mVertical;
	Node* mpLeftSon;
	Node* mpRightSon;
public:
	Node(Point* pPoint, bool vertical);
	Node* getLeftSon();
	Node* getRightSon();
	Point* getPoint();
	bool isVertical();
	void putLeftSon(Node* pLeftSon);
	void putRightSon(Node* pRightSon);
};
