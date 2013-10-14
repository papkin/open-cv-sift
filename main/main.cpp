#include <iostream>
#include "KDTree.hpp"

int main(int argc, char* argv[]) {
	auto pNodeFactory = new NodeFactory();
	auto pKDTree = new KDTree(pNodeFactory);
	auto pPoint1 = new Point(1.2, 2.4);
	auto pPoint2 = new Point(1.3,4.3);
	auto pPoint3 = new Point(1.1, 6.2);
	auto pPoint4 = new Point(1.1,2.3);
	pKDTree->add(pPoint1);
	pKDTree->add(pPoint2);
	pKDTree->add(pPoint3);
	Point* pResult = pKDTree->findNearest(pPoint4);
	std::cout << pResult->getX() << ", " << pResult->getY() << std::endl;
	return 0;
}
