#ifndef VECTOR_H
#define VECTOR_H

#include <QObject>
#include <QQmlEngine>
#include <QPointF>

class Vector : public QObject {
		Q_OBJECT
		QML_ELEMENT
		Q_PROPERTY(double x \
		           READ x \
		           WRITE setX \
		           NOTIFY changed)
		Q_PROPERTY(double y \
		           READ y \
		           WRITE setY \
		           NOTIFY changed)
		Q_PROPERTY(double angle \
		           READ angle \
		           WRITE setAngle \
		           NOTIFY changed)
		Q_PROPERTY(double magnitude \
		           READ magnitude \
		           WRITE setMagnitude \
		           NOTIFY changed)
	public:
		explicit Vector(QObject *parent = nullptr);
		Vector(double x, double y, QObject *parent = nullptr);

		double x() const;
		void setX(const double &value);

		double y() const;
		void setY(const double &value);

		QPointF toPoint() const;
		void fromPoint(const QPointF &point);

		double angle() const;
		void setAngle(double angle);

		double magnitude() const;
		void setMagnitude(const double &magnitude);

		QPointF &vector();
		QPointF normalized() const;

		Q_INVOKABLE Vector *inverse() const;

		void operator+=(const QPointF &vec);
		void operator-=(const QPointF &vec);

	signals:
		void changed();

	private:
		QPointF _vector;
		double _angle;
		double _magnitude;
		void updatePolar();
		void updateCartesian();
};



#endif // VECTOR_H
