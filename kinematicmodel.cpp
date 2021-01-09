#include "kinematicmodel.h"

KinematicModel::KinematicModel(QObject *parent) :
    QObject(parent) {
}

KinematicModel::KinematicModel(double vX, double vY, QObject *parent) :
    QObject(parent),
    _velocityX(vX), _velocityY(vY) {
}

KinematicModel::KinematicModel(double vX, double vY,
                               double aX, double aY,
                               QObject *parent) :
    QObject(parent),
    _velocityX(vX), _velocityY(vY),
    _accelerationX(aX), _accelerationY(aY) {
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

double KinematicModel::velocityX() const {
	return _velocityX;
}

void KinematicModel::setVelocityX(const double &velocity) {
	if (velocity == _velocityX)
		return;
	_velocityX = velocity;
	emit velocityXChanged();
}

double KinematicModel::velocityY() const {
	return _velocityY;
}

void KinematicModel::setVelocityY(const double &velocity) {
	if (velocity == _velocityY)
		return;
	_velocityY = velocity;
	emit velocityYChanged();
}

double KinematicModel::accelerationX() const {
	return _accelerationX;
}

void KinematicModel::setAccelerationX(const double &acceleration) {
	if (acceleration == _accelerationX)
		return;
	_accelerationX = acceleration;
	emit accelerationXChanged();
}

double KinematicModel::accelerationY() const {
	return _accelerationY;
}

void KinematicModel::setAccelerationY(const double &acceleration) {
	if (acceleration == _accelerationY)
		return;
	_accelerationY = acceleration;
	emit accelerationYChanged();
}

void KinematicModel::timerEvent(QTimerEvent *event) {
	Q_UNUSED(event);
	const qint64 dt = QDateTime::currentMSecsSinceEpoch() - _lastMSecSinceEpoch;
	const double dt_IN_SECS = static_cast<double>(dt)/1000;
	_lastMSecSinceEpoch = QDateTime::currentMSecsSinceEpoch();

	const double dx = _velocityX*dt_IN_SECS;
	const double x = parent()->property("x").toDouble() + dx;
	if (x > _maximumX) {
		parent()->setProperty("x", qMin(x, _maximumX));
		emit maximumXReached();
	}
	else if (x < _minimumX) {
		parent()->setProperty("x", qMax(x, _minimumX));
		emit minimumXReached();
	}
	else {
		parent()->setProperty("x", x);
	}

	const double dy = _velocityY*dt_IN_SECS;
	const double y = parent()->property("y").toDouble() + dy;
	if (y > _maximumY) {
		parent()->setProperty("y", qMin(y, _maximumY));
		emit maximumYReached();
	}
	else if (y < _minimumY) {
		parent()->setProperty("y", qMax(y, _minimumY));
		emit minimumYReached();
	}
	else {
		parent()->setProperty("y", y);
	}
	_velocityX += _accelerationX*dt_IN_SECS;
	emit velocityXChanged();
	_velocityY += _accelerationY*dt_IN_SECS;
	emit velocityYChanged();
}

bool KinematicModel::running() const {
	return _running;
}

void KinematicModel::setRunning(bool running) {
	if (running == _running)
		return;
	_running = running;
	if (running)
//		_timerID = startTimer(_tickInterval);//, Qt::PreciseTimer);
		_timerID = startTimer(0);
	else
		killTimer(_timerID);
	emit runningChanged(running);
}

void KinematicModel::registerType() {
	qmlRegisterType<KinematicModel>("Models", 1, 0, "KinematicModel");
}
