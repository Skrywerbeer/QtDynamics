#ifndef SATCOLLISIONDETECTOR_H
#define SATCOLLISIONDETECTOR_H

#include "collisiondetector.h"

class SATCollisionDetector : public CollisionDetector {
		Q_OBJECT
		QML_ELEMENT
	public:
		SATCollisionDetector(QObject *parent = nullptr);

		bool collides(QQuickItem *item) override;
	private:
		QPolygonF rectVertices(QQuickItem *item, QQuickItem *parentItem = nullptr);
		QPointF center(QQuickItem *item);
		QPointF center(const QPointF &p1, const QPointF p2);
};

#endif // SATCOLLISIONDETECTOR_H
