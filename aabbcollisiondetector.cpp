#include "aabbcollisiondetector.h"

AABBCollisionDetector::AABBCollisionDetector(QObject *parent) :
    CollisionDetector(parent){}

bool AABBCollisionDetector::collides(QQuickItem *item) {
	const double leftX1 = _target->x();
	const double rightX1 = _target->x() + _target->width();
	const double topY1 = _target->y();
	const double bottomY1 = _target->y() + _target->height();

	const double leftX2 = item->x();
	const double rightX2 = item->x() + item->width();
	const double topY2 = item->y();
	const double bottomY2 = item->y() + item->height();

	if ((leftX1 <= rightX2) && (rightX1 >= leftX2) &&
	        (topY1 <= bottomY2) && (bottomY1 >= topY2))
		return true;
	return false;
}

