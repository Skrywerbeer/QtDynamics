#include "kinematicmodel.h"
#include "vector.h"

KinematicModel::KinematicModel(QObject *parent) :
    QObject(parent) {

}

//KinematicModel::KinematicModel(double vX, double vY, QObject *parent) :
//    QObject(parent),
//    _velocityX(vX), _velocityY(vY) {
//}

//KinematicModel::KinematicModel(double vX, double vY,
//                               double aX, double aY,
//                               QObject *parent) :
//    QObject(parent),
//    _velocityX(vX), _velocityY(vY),
//    _accelerationX(aX), _accelerationY(aY) {
//}n

QQuickItem *KinematicModel::parentItem() const {
	return qobject_cast<QQuickItem *>(parent());
}

double KinematicModel::minimumX() const {
	return _minimumX;
}

void KinematicModel::setMinimumX(double minimum) {
	if (minimum == _minimumX)
		return;
	_minimumX = minimum;
	emit minimumXChanged();
}

double KinematicModel::maximumX() const {
	return _maximumX;
}

void KinematicModel::setMaximumX(double maximum) {
	if (maximum == _maximumX)
		return;
	_maximumX = maximum;
	emit maximumXChanged();
}

double KinematicModel::minimumY() const {
	return _minimumY;
}

void KinematicModel::setMinimumY(double minimum) {
	if (minimum == _minimumY)
		return;
	_minimumY = minimum;
	emit minimumYChanged();
}

double KinematicModel::maximumY() const {
	return _maximumY;
}

void KinematicModel::setMaximumY(double maximum) {
	if (maximum == _maximumY)
		return;
	_maximumY = maximum;
	emit maximumYChanged();
}

Vector *KinematicModel::velocityVector() const {
	return _velocityVector;
}

void KinematicModel::setVelocityVector(Vector *vector) {
	if (vector == _velocityVector)
		return;
	_velocityVector = vector;
	emit velocityVectorChanged();
}

Vector *KinematicModel::accelerationVector() const {
	return _accelerationVector;
}

void KinematicModel::setAccelerationVector(Vector *vector) {
	if (vector == _accelerationVector)
		return;
	_accelerationVector = vector;
	emit accelerationVectorChanged();
}

//double KinematicModel::velocityX() const {
//	return _velocityX;
//}

//void KinematicModel::setVelocityX(const double &velocity) {
//	if (velocity == _velocityX)
//		return;
//	_velocityX = velocity;
//	emit velocityXChanged();
//}

//double KinematicModel::velocityY() const {
//	return _velocityY;
//}

//void KinematicModel::setVelocityY(const double &velocity) {
//	if (velocity == _velocityY)
//		return;
//	_velocityY = velocity;
//	emit velocityYChanged();
//}

//double KinematicModel::accelerationX() const {
//	return _accelerationX;
//}

//void KinematicModel::setAccelerationX(const double &acceleration) {
//	if (acceleration == _accelerationX)
//		return;
//	_accelerationX = acceleration;
//	emit accelerationXChanged();
//}

//double KinematicModel::accelerationY() const {
//	return _accelerationY;
//}

//void KinematicModel::setAccelerationY(const double &acceleration) {
//	if (acceleration == _accelerationY)
//		return;
//	_accelerationY = acceleration;
//	emit accelerationYChanged();
//}

void KinematicModel::timerEvent(QTimerEvent *event) {
	if (!_running || _velocityVector == nullptr) {
		event->ignore();
		return;
	}
	Q_UNUSED(event);
	const qint64 dt = QDateTime::currentMSecsSinceEpoch() - _lastMSecSinceEpoch;
	const double dt_IN_SECS = static_cast<double>(dt)/1000;
	_lastMSecSinceEpoch = QDateTime::currentMSecsSinceEpoch();

	const double dx = _velocityVector->xComponent()*dt_IN_SECS;
	const double x = parentItem()->x() + dx;
	if (x > _maximumX) {
		parentItem()->setX(qMin(x, _maximumX));
		emit maximumXReached();
	}
	else if (x < _minimumX) {
		parentItem()->setX(qMax(x, _minimumX));
		emit minimumXReached();
	}
	else {
		parentItem()->setX(x);
	}

	const double dy = _velocityVector->yComponent()*dt_IN_SECS;
	const double y = parentItem()->y() + dy;
	if (y > _maximumY) {
		parentItem()->setY(qMin(y, _maximumY));
		emit maximumYReached();
	}
	else if (y < _minimumY) {
		parentItem()->setY(qMax(y, _minimumY));
		emit minimumYReached();
	}
	else {
		parentItem()->setY(y);
	}
	if (_accelerationVector == nullptr)
		return;
	const double dv_x = _accelerationVector->xComponent()*dt_IN_SECS;
	_velocityVector->setXComponent(_velocityVector->xComponent() + dv_x);
	const double dv_y = _accelerationVector->yComponent()*dt_IN_SECS;
	_velocityVector->setYComponent(_velocityVector->yComponent() + dv_y);
}

bool KinematicModel::running() const {
	return _running;
}

void KinematicModel::setRunning(bool running) {
	if (running == _running)
		return;
	_running = running;
	if (running) {
		_lastMSecSinceEpoch = QDateTime::currentMSecsSinceEpoch();
		_timerID = startTimer(0);
	}
	else {
		killTimer(_timerID);
	}
	emit runningChanged(running);
}

void KinematicModel::registerType() {
	qmlRegisterType<KinematicModel>("Models", 1, 0, "KinematicModel");
}
