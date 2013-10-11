#pragma once

#include "Node.hpp"
#include "NodeFactory.hpp"
#include "Point.hpp"
#include <float.h>

class KDTree {
private:
	Node* mpRoot;
	NodeFactory* mpNodeFactory;
	void traverseAdd(Point* pPoint) {
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
public:
	KDTree(NodeFactory* pNodeFactory = new NodeFactory()) {
		this->mpRoot = nullptr;
		this->mpNodeFactory = pNodeFactory;
	}
	void add(Point* pPoint) {
		if(mpRoot == nullptr) {
			mpRoot = new Node(pPoint, true);
		}
		else {
			traverseAdd(pPoint);				
		}
	}
	Point* findNearest(Point* pPoint) {
		double bestDistance = DBL_MAX;
		Point* bestPoint;
		Node* pCurrentNode = mpRoot;
		while(pCurrentNode != nullptr) {
			if(pPoint->distanceFrom(pCurrentNode->getPoint()) < bestDistance) {
				bestDistance = pPoint->distanceFrom(pCurrentNode->getPoint());
				std::cout << pPoint->getX() << "," << pPoint->getY() << ":" << pCurrentNode->getPoint()->getX() << "," << pCurrentNode->getPoint()->getY() << std::endl;
				std::cout << pPoint->distanceFrom(pCurrentNode->getPoint()) << std::endl;
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
};
