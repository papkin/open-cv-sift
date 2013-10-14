#include "KDTree.hpp"
void KDTree::traverseAdd(Point* pPoint) {
	Node* pCurrentNode = mpRoot;
	Node* pPreviousNode = nullptr;
	bool isLeftSon = true;
	while(pCurrentNode != nullptr) {
		pPreviousNode = pCurrentNode;
		if(pCurrentNode->isVertical()) {
			if(pPoint->getY() < pCurrentNode->getPoint()->getY()) {
				pCurrentNode = pCurrentNode->getLeftSon();
				isLeftSon = true;
			}
			else {
				pCurrentNode = pCurrentNode->getRightSon();
				isLeftSon = false;
			}
		}
		else if(!pCurrentNode->isVertical()) {
			if(pPoint->getX() < pCurrentNode->getPoint()->getX()) {
				pCurrentNode = pCurrentNode->getLeftSon();
				isLeftSon = true;
			}
			else {
				pCurrentNode = pCurrentNode->getRightSon();
				isLeftSon = false;
			}
		}
	}
	Node* pNewNode = mpNodeFactory->createNode(pPoint, !pPreviousNode->isVertical());
	if(isLeftSon) {
		pPreviousNode->putLeftSon(pNewNode);
	}
	else {
		pPreviousNode->putRightSon(pNewNode);
	}
}
KDTree::KDTree(NodeFactory* pNodeFactory) {
	this->mpRoot = nullptr;
	this->mpNodeFactory = pNodeFactory;
}

void KDTree::add(Point* pPoint) {
	if(mpRoot == nullptr) {
		mpRoot = mpNodeFactory->createNode(pPoint, true);
	}
	else {
		traverseAdd(pPoint);				
	}
}

Point* KDTree::findNearest(Point* pPoint) {
	double bestDistance = DBL_MAX;
	Point* bestPoint;
	Node* pCurrentNode = mpRoot;
	while(pCurrentNode != nullptr) {
		if(pPoint->distanceFrom(pCurrentNode->getPoint()) < bestDistance) {
			bestDistance = pPoint->distanceFrom(pCurrentNode->getPoint());
			bestPoint = pCurrentNode->getPoint();
		}
		if(pCurrentNode->isVertical()) {
			if(pPoint->getY() < pCurrentNode->getPoint()->getY()) {
				pCurrentNode = pCurrentNode->getLeftSon();
			}
			else {
				pCurrentNode = pCurrentNode->getRightSon();
			}
		}
		else {
			if(pPoint->getX() < pCurrentNode->getPoint()->getX()) {
				pCurrentNode = pCurrentNode->getLeftSon();
			}
			else {
				pCurrentNode = pCurrentNode->getRightSon();
			}
		}
	}
	return bestPoint;
}
