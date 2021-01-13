#ifndef KINEMATICMODEL_H
#define KINEMATICMODEL_H

#include <QObject>
#include <QQuickItem>
#include <QQmlEngine>
#include <QPropertyAnimation>
#include <QDateTime>
#include <QTimerEvent>

#include "vector.h"

class KinematicModel : public QObject {
		Q_OBJECT
		QML_ELEMENT
		Q_PROPERTY(QQuickItem *parent
		           READ parentItem)
		Q_PROPERTY(double minimumX \
		           READ minimumX \
		           WRITE setMinimumX \
		           NOTIFY minimumXChanged)
		Q_PROPERTY(double maximumX \
		           READ maximumX \
		           WRITE setMaximumX \
		           NOTIFY maximumXChanged)
		Q_PROPERTY(double minimumY \
		           READ minimumY \
		           WRITE setMinimumY \
		           NOTIFY minimumYChanged)
		Q_PROPERTY(double maximumY \
		           READ maximumY \
		           WRITE setMaximumY \
		           NOTIFY maximumYChanged)
		Q_PROPERTY(Vector *velocity \
		           READ velocity \
		           WRITE setVelocity
		           NOTIFY velocityChanged)
		Q_PROPERTY(Vector *acceleration \
		           READ acceleration \
		           WRITE setAcceleration \
		           NOTIFY accelerationChanged)
		Q_PROPERTY(bool running \
		           READ running \
		           WRITE setRunning \
		           NOTIFY runningChanged)
	public:
		explicit KinematicModel(QObject *parent = nullptr);

		QQuickItem *parentItem() const;

		double minimumX() const;
		void setMinimumX(double minimum);
		double maximumX() const;
		void setMaximumX(double maximum);

		double minimumY() const;
		void setMinimumY(double minimum);
		double maximumY() const;
		void setMaximumY(double maximum);

		Vector *velocity() const;
		void setVelocity(Vector *vector);

		Vector *acceleration() const;
		void setAcceleration(Vector *vector);

		void timerEvent(QTimerEvent *event) override;

		bool running() const;
		void setRunning(bool running);

	signals:
		void minimumXChanged();
		void minimumXReached();
		void maximumXChanged();
		void maximumXReached();
		void minimumYChanged();
		void minimumYReached();
		void maximumYChanged();
		void maximumYReached();
		void velocityChanged();
		void accelerationChanged();
		void runningChanged(bool run);

	private:
		double _minimumX = -1e6;
		double _maximumX = 1e6;
		// NOTE: use very large values because no screen has that many pixels.
		double _minimumY = -1e6;
		double _maximumY = 1e6;
		Vector *_velocity = nullptr;
		Vector *_acceleration = nullptr;

		bool _running = false;
		qint64 _lastMSecSinceEpoch = QDateTime::currentMSecsSinceEpoch();
		int _timerID;

		void tickHandler();
};

#endif // KINEMATICMODEL_H
