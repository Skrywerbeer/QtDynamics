#ifndef VECTOR_H
#define VECTOR_H

#include <QObject>
#include <QQmlEngine>
#include <QPointF>
#include <QSGGeometry>

class Vector : public QObject {
		Q_OBJECT
		Q_PROPERTY(double xComponent \
		           READ xComponent \
		           WRITE setXComponent \
		           NOTIFY xComponentChanged)
		Q_PROPERTY(double yComponent \
		           READ yComponent \
		           WRITE setYComponent \
		           NOTIFY yComponentChanged)
		Q_PROPERTY(double angle \
		           READ angle \
		           WRITE setAngle \
		           NOTIFY angleChanged
		           STORED false)
		Q_PROPERTY(double magnitude \
		           READ magnitude \
		           WRITE setMagnitude \
		           NOTIFY magnitudeChanged
		           STORED false)
	public:
		explicit Vector(QObject *parent = nullptr);
		Vector(double x, double y, QObject *parent = nullptr);

		double xComponent() const;
		void setXComponent(const double &value);

		double yComponent() const;
		void setYComponent(const double &value);

		double angle() const;
		void setAngle(const double &angle);

		double magnitude() const;
		void setMagnitude(const double &magnitude);

		QPointF &vector();
		QPointF toPoint() const;
		QPointF normalized() const;

		void operator+=(const QPointF &vec);
		void operator-=(const QPointF &vec);

		static void registerType();

	signals:
		void changed();
		void xComponentChanged();
		void yComponentChanged();
		void angleChanged();
		void magnitudeChanged();

	private:
		QPointF _vector;
};

inline void operator<<(QSGGeometry::Point2D &point2d, const QPointF &point) {
	point2d.set(point.x(), point.y());
}

#endif // VECTOR_H
