#include "Node.hpp"
Node::Node(Point* pPoint, bool vertical) {
	this->mpPoint = pPoint;
	this->mpLeftSon = nullptr;
	this->mpRightSon = nullptr;
	this->mVertical = vertical;
}
Node* Node::getLeftSon() {
	return this->mpLeftSon;
}
Node* Node::getRightSon() {
	return this->mpRightSon;
}
Point* Node::getPoint() {
	return this->mpPoint;
}
bool Node::isVertical() {
	return this->mVertical;
}
void Node::putLeftSon(Node* pLeftSon) {
	this->mpLeftSon = pLeftSon;
}
void Node::putRightSon(Node* pRightSon) {
	this->mpRightSon = pRightSon;
}
