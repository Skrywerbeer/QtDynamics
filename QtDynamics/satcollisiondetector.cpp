#include "satcollisiondetector.h"

SATCollisionDetector::SATCollisionDetector(QObject *parent) :
    CollisionDetector(parent) {}

bool SATCollisionDetector::collides(QQuickItem *item) {
	const QList<QPointF> targetVertices = rectVertices(_target, _target->parentItem());
	const QList<QPointF> itemVertices = rectVertices(item, _target->parentItem());
	qDebug() << "target vertices:" << targetVertices;
	qDebug() << "item vertices:" << itemVertices;
	qDebug() << "--------------------------------------------------------------";
	const double targetRotationRad = qDegreesToRadians(_target->rotation());
//	const double itemRotationRad = qDegreesToRadians(item->rotation());
	const QPointF i = {qCos(targetRotationRad), qSin(targetRotationRad)};
	const QPointF j = {-i.y(), i.x()};
	const QPointF itemWVector = itemVertices[1] - itemVertices[0];
	const QPointF itemHVector = itemVertices[2] - itemVertices[1];
//	const QPointF itemCenter = center(itemVertices[0], itemVertices[2]);
	const QPointF itemCenter = (itemVertices[2] + itemVertices[0])/2;
//	const QPointF targetCenter = center(targetVertices[0], targetVertices[2]);
	const QPointF targetCenter = (targetVertices[2] + targetVertices[0])/2;
//	qDebug() << "itemCenter:" << itemCenter;
//	qDebug() << "targetCenter:" << targetCenter;
//	qDebug() << "item vertices:" << itemVertices;
//	qDebug() << "target vertices:" << targetVertices;
//	qDebug() << "-------------------------------------------------------------";
	const QPointF displacement = itemCenter - targetCenter;
	const double maxIProjection = qMax(qAbs(QPointF::dotProduct(i, itemWVector + itemHVector)),
	                                   qAbs(QPointF::dotProduct(i, itemWVector - itemHVector)));
	const double maxJProjection = qMax(qAbs(QPointF::dotProduct(j, itemWVector + itemHVector)),
	                                   qAbs(QPointF::dotProduct(j, itemWVector - itemHVector)));
	return (
	            (qAbs(QPointF::dotProduct(displacement, i)) <= (_target->width() + maxIProjection)/2) &&
	            (qAbs(QPointF::dotProduct(displacement, j) <= (_target->height() + maxJProjection))/2)
	        );

}

QPolygonF SATCollisionDetector::rectVertices(QQuickItem *item, QQuickItem *parentItem) {
	QPolygonF poly;
	const QPointF pos = item->position();
	poly << pos
	     << pos + QPointF{item->width(), 0}
	     << pos + QPointF{item->width(), item->height()}
	     << pos + QPointF{0, item->height()};
	for (auto &point : poly) {
		if (parentItem == nullptr)
			point = item->mapToItem(item->parentItem(), point);
		else
			point = item->mapToItem(parentItem, point);
	}
	return poly;
}


QPointF SATCollisionDetector::center(QQuickItem *item) {
	return QPointF{item->width()/2, item->height()/2};
}

QPointF SATCollisionDetector::center(const QPointF &p1, const QPointF p2) {
	return {(p1.x() + p2.x())/2, (p1.y() + p2.y())/2};
}
