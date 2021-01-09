#ifndef KINEMATICMODEL_H
#define KINEMATICMODEL_H

#include <QObject>
#include <QQmlEngine>
#include <QPropertyAnimation>
#include <QDateTime>

class KinematicModel : public QObject {
		Q_OBJECT

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
		Q_PROPERTY(double velocityX \
		           READ velocityX \
		           WRITE setVelocityX \
		           NOTIFY velocityXChanged)
		Q_PROPERTY(double velocityY \
		           READ velocityY \
		           WRITE setVelocityY \
		           NOTIFY velocityYChanged)
		Q_PROPERTY(double accelerationX \
		           READ accelerationX \
		           WRITE setAccelerationX \
		           NOTIFY accelerationXChanged)
		Q_PROPERTY(double accelerationY \
		           READ accelerationY \
		           WRITE setAccelerationY \
		           NOTIFY accelerationYChanged)
		Q_PROPERTY(bool running \
		           READ running \
		           WRITE setRunning \
		           NOTIFY runningChanged)
		QML_ELEMENT
	public:
		explicit KinematicModel(QObject *parent = nullptr);
		KinematicModel(double vX, double vY, QObject *parent = nullptr);
		KinematicModel(double vX, double vY,
		               double aX, double aY,
		               QObject *parent = nullptr);

		double minimumX() const;
		void setMinimumX(double minimum);
		double maximumX() const;
		void setMaximumX(double maximum);

		double minimumY() const;
		void setMinimumY(double minimum);
		double maximumY() const;
		void setMaximumY(double maximum);

		double velocityX() const;
		void setVelocityX(const double &velocity);

		double velocityY() const;
		void setVelocityY(const double &velocity);

		double accelerationX() const;
		void setAccelerationX(const double &acceleration);

		double accelerationY() const;
		void setAccelerationY(const double &acceleration);

		void timerEvent(QTimerEvent *event) override;

		bool running() const;
		void setRunning(bool running);

		static void registerType();

	signals:
		void minimumXChanged();
		void minimumXReached();
		void maximumXChanged();
		void maximumXReached();
		void minimumYChanged();
		void minimumYReached();
		void maximumYChanged();
		void maximumYReached();
		void velocityXChanged();
		void velocityYChanged();
		void accelerationXChanged();
		void accelerationYChanged();
		void runningChanged(bool run);

	private:
		double _minimumX = -1e6;
		double _maximumX = 1e6;
		// NOTE: use very large values because no screen has that many pixels.
		double _minimumY = -1e6;
		double _maximumY = 1e6;
		double _velocityX = 0;
		double _velocityY = 0;
		double _accelerationX = 0;
		double _accelerationY = 0;

		bool _running = false;
		qint64 _lastMSecSinceEpoch = QDateTime::currentMSecsSinceEpoch();
		int _timerID;

		void tickHandler();
};

#endif // KINEMATICMODEL_H
