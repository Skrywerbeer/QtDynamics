#include "kinematicmodel.h"
#include "vector.h"

KinematicModel::KinematicModel(QObject *parent) :
    QObject(parent) {

}

QQuickItem *KinematicModel::target() const {
	return _target;
}

void KinematicModel::setTarget(QQuickItem *target) {
	if (target == _target)
		return;
	_target = target;
	emit targetChanged();
}

void KinematicModel::setTargetX(double x) {
	if (x > _maximumX) {
		_target->setX(qMin(x, _maximumX));
		emit maximumXReached();
	}
	else if (x < _minimumX) {
		_target->setX(qMax(x, _minimumX));
		emit minimumXReached();
	}
	else {
		_target->setX(x);
	}
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

void KinematicModel::setTargetY(double y) {
	if (y > _maximumY) {
		_target->setY(qMin(y, _maximumY));
		emit maximumYReached();
	}
	else if (y < _minimumY) {
		_target->setY(qMax(y, _minimumY));
		emit minimumYReached();
	}
	else {
		_target->setY(y);
	}
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

bool KinematicModel::running() const {
	return _running;
}

void KinematicModel::setRunning(bool running) {
	if (running == _running)
		return;
	_running = running;
	if (running) {
		_clock.start();
		_timerID = startTimer(0);
	}
	else {
		killTimer(_timerID);
	}
	emit runningChanged(running);
}

void KinematicModel::timerEvent(QTimerEvent *event) {
	Q_UNUSED(event);
	if (!_running) {
		event->ignore();
		return;
	}
	const qint64 dt = _clock.restart();
	const double dt_IN_SECS = static_cast<double>(dt)/1000;

	const double dx = _velocity->xComponent()*dt_IN_SECS;
	setTargetX(_target->x() + dx);
	const double dy = _velocity->yComponent()*dt_IN_SECS;
	setTargetY(_target->y() + dy);

	*_velocity += _acceleration->toPoint()*dt_IN_SECS;
	_target->update();
}

void KinematicModel::classBegin() {

}

void KinematicModel::componentComplete() {
	if (_velocity == nullptr)
		_velocity = new Vector;
	if (_acceleration == nullptr)
		_acceleration = new Vector;
	if (_target == nullptr)
		_target = qobject_cast<QQuickItem *>(parent());
}
