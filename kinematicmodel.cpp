#include "kinematicmodel.h"
#include "vector.h"

KinematicModel::KinematicModel(QObject *parent) :
    QObject(parent) {

}

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

Vector *KinematicModel::velocity() const {
	return _velocity;
}

void KinematicModel::setVelocity(Vector *vector) {
	if (vector == _velocity)
		return;
	_velocity = vector;
	emit velocityChanged();
}

Vector *KinematicModel::acceleration() const {
	return _acceleration;
}

void KinematicModel::setAcceleration(Vector *vector) {
	if (vector == _acceleration)
		return;
	_acceleration = vector;
	emit accelerationChanged();
}

void KinematicModel::timerEvent(QTimerEvent *event) {
	if (!_running || _velocity == nullptr) {
		event->ignore();
		return;
	}
	Q_UNUSED(event);
	const qint64 dt = QDateTime::currentMSecsSinceEpoch() - _lastMSecSinceEpoch;
	const double dt_IN_SECS = static_cast<double>(dt)/1000;
	_lastMSecSinceEpoch = QDateTime::currentMSecsSinceEpoch();

	const double dx = _velocity->xComponent()*dt_IN_SECS;
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

	const double dy = _velocity->yComponent()*dt_IN_SECS;
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
	if (_acceleration != nullptr)
		*_velocity += _acceleration->toPoint()*dt_IN_SECS;
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
