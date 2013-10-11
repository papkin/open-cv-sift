#include <iostream>
#include "KDTree.hpp"

int main(void) {
	KDTree* pKDTree = new KDTree();
	Point* pPoint1 = new Point(1.2, 2.4);
	Point* pPoint2 = new Point(1.3,4.3);
	Point* pPoint3 = new Point(1.1, 6.2);
	Point* pPoint4 = new Point(1.1,2.3);
	pKDTree->add(pPoint1);
	pKDTree->add(pPoint2);
	pKDTree->add(pPoint3);
	Point* pResult = pKDTree->findNearest(pPoint4);
	std::cout << pResult->getX() << ", " << pResult->getY() << std::endl;
	return 0;
}
