#include "aabbcollisiondetector.h"

AABBCollisionDetector::AABBCollisionDetector(QObject *parent) :
    CollisionDetector(parent){}

bool AABBCollisionDetector::collides(QQuickItem *item1, QQuickItem *item2) {
	const double leftX1 = item1->x();
	const double rightX1 = item1->x() + item1->width();
	const double topY1 = item1->y();
	const double bottomY1 = item1->y() + item1->height();
	const double leftX2 = item2->x();
	const double rightX2 = item2->x() + item2->width();
	const double topY2 = item2->y();
	const double bottomY2 = item2->y() + item2->height();

	if ((leftX1 <= rightX2) && (rightX1 >= leftX2) &&
	        (topY1 <= bottomY2) && (bottomY1 >= topY2)) {
		emit collision(item1, item2);
		return true;
	}
	return false;
}

