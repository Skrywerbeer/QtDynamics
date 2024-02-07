#include "aabbcollisiondetector.h"

AABBCollisionDetector::AABBCollisionDetector(QObject *parent) :
    CollisionDetector(parent){}

bool AABBCollisionDetector::collides(QQuickItem *item) {
	if (item == nullptr) {
		qWarning("Checking for collision with null item");
		return false;
	}
	const double leftX1 = _target->x();
	const double rightX1 = _target->x() + _target->width();
	const double topY1 = _target->y();
	const double bottomY1 = _target->y() + _target->height();

	const QPointF itemMapped = _target->parentItem() != item->parentItem() ?
	                                                        item->mapToItem(_target->parentItem(), item->position()) - item->position() :
	                                                        item->position();
	const double leftX2 = itemMapped.x();
	const double rightX2 = itemMapped.x() + item->width();
	const double topY2 = itemMapped.y();
	const double bottomY2 = itemMapped.y() + item->height();

	if ((leftX1 <= rightX2) && (rightX1 >= leftX2) &&
	        (topY1 <= bottomY2) && (bottomY1 >= topY2))
		return true;
	return false;
}

