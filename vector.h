#ifndef VECTOR_H
#define VECTOR_H

#include <QObject>
#include <QQmlEngine>

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
		           READ magnitudeChanged \
		           WRITE setMagnitude \
		           NOTIFY magnitudeChanged
		           STORED false)
	public:
		explicit Vector(QObject *parent = nullptr);

		double xComponent() const;
		void setXComponent(const double &value);

		double yComponent() const;
		void setYComponent(const double &value);

		double angle() const;
		void setAngle(const double &angle);

		double magnitude() const;
		void setMagnitude(const double &magnitude);

		static void registerType();

	signals:
		void xComponentChanged();
		void yComponentChanged();
		void angleChanged();
		void magnitudeChanged();

	private:
		double _xComponent;
		double _yComponent;
};

#endif // VECTOR_H
