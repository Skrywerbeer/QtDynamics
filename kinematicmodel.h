#ifndef KINEMATICMODEL_H
#define KINEMATICMODEL_H

#include <QObject>
#include <QQmlParserStatus>
#include <QQuickItem>
#include <QQmlEngine>
#include <QElapsedTimer>
#include <QDateTime>
#include <QTimerEvent>

#include "vector.h"

class KinematicModel : public QObject, public QQmlParserStatus {
		Q_OBJECT
		Q_INTERFACES(QQmlParserStatus)
		QML_ELEMENT
		Q_PROPERTY(QQuickItem *target
		           READ target \
		           WRITE setTarget \
		           NOTIFY targetChanged
		           REQUIRED)
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

		QQuickItem *target() const;
		void setTarget(QQuickItem *target);
		// Sets the x property of _target to x, capped by minimumX and maximumX.
		void setTargetX(double x);
		double minimumX() const;
		void setMinimumX(double minimum);
		double maximumX() const;
		void setMaximumX(double maximum);

		// Sets the y property of _target to y, capped by minimumY and maximumY
		void setTargetY(double y);
		double minimumY() const;
		void setMinimumY(double minimum);
		double maximumY() const;
		void setMaximumY(double maximum);

		Vector *velocity() const;
		void setVelocity(Vector *vector);

		Vector *acceleration() const;
		void setAcceleration(Vector *vector);

		bool running() const;
		void setRunning(bool running);

		void timerEvent(QTimerEvent *event) override;

	signals:
		void targetChanged();
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
		QQuickItem *_target = nullptr;
		double _minimumX = -1e6;
		double _maximumX = 1e6;
		// NOTE: use very large values because no screen has that many pixels.
		double _minimumY = -1e6;
		double _maximumY = 1e6;
		Vector *_velocity = nullptr;
		Vector *_acceleration = nullptr;

		bool _running = false;

		QElapsedTimer _clock;

		int _timerID;

		void tickHandler();
};

#endif // KINEMATICMODEL_H
