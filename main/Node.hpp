#pragma once

#include "Point.hpp"

class Node {
private:
	Point* mpPoint;
	bool mVertical;
	Node* mpLeftSon;
	Node* mpRightSon;
public:
	Node(Point* pPoint, bool vertical) {
		this->mpPoint = pPoint;
		this->mpLeftSon = nullptr;
		this->mpRightSon = nullptr;
		this->mVertical = vertical;
	}
	Node* getLeftSon() {
		return this->mpLeftSon;
	}
	Node* getRightSon() {
		return this->mpRightSon;
	}
	Point* getPoint() {
		return this->mpPoint;
	}
	bool isVertical() {
		return this->mVertical;
	}
	void putLeftSon(Node* pLeftSon) {
		this->mpLeftSon = pLeftSon;
	}
	void putRightSon(Node* pRightSon) {
		this->mpRightSon = pRightSon;
	}
};
