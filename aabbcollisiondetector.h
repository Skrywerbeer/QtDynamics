#ifndef AABBCOLLISIONDETECTOR_H
#define AABBCOLLISIONDETECTOR_H

#include "collisiondetector.h"

class AABBCollisionDetector : public CollisionDetector {
		Q_OBJECT
		QML_ELEMENT
	public:
		explicit AABBCollisionDetector(QObject *parent = nullptr);

		bool collides(QQuickItem *item) override;

	signals:

	private:

};

#endif // AABBCOLLISIONDETECTOR_H
