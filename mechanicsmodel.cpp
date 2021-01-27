#include "mechanicsmodel.h"

MechanicsModel::MechanicsModel(QObject *parent) :
    QObject(parent) {

}

QQuickItem *MechanicsModel::target() const {
	return _target;
}

void MechanicsModel::setTarget(QQuickItem *target) {
	if (target == _target)
		return;
	_target = target;
	emit targetChanged();
}

bool MechanicsModel::running() const {
	return _running;
}

void MechanicsModel::setRunning(bool running) {
	if (running == _running)
		return;
	_running = running;
	if (running) {
		_clock.start();
		_timerID = startTimer(0);
	}
	else if (!running && (_timerID != 0)) {
		killTimer(_timerID);
		_timerID = 0;
	}
	emit runningChanged();
}

void MechanicsModel::setTargetX(double x) {
	if (_minimumX >= _maximumX) {
		_target->setX(x);
		return;
	}
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

double MechanicsModel::minimumX() const {
	return _minimumX;
}

void MechanicsModel::setMinimumX(double minimum) {
	if (minimum == _minimumX)
		return;
	_minimumX = minimum;
	emit minimumXChanged();
}

double MechanicsModel::maximumX() const {
	return _maximumX;
}

void MechanicsModel::setMaximumX(double maximum) {
	if (maximum == _maximumX)
		return;
	_maximumX = maximum;
	emit maximumXChanged();
}

void MechanicsModel::setTargetY(double y) {
	if (_minimumY >= _maximumY) {
		_target->setY(y);
		return;
	}
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

double MechanicsModel::minimumY() const {
	return _minimumY;
}

void MechanicsModel::setMinimumY(double minimum) {
	if (minimum == _minimumY)
		return;
	_minimumY = minimum;
	emit minimumYChanged();
}

double MechanicsModel::maximumY() const {
	return _maximumY;
}

void MechanicsModel::setMaximumY(double maximum) {
	if (maximum == _maximumY)
		return;
	_maximumY = maximum;
	emit maximumYChanged();
}

Vector *MechanicsModel::displacement() const {
	return _displacement;
}

Vector *MechanicsModel::velocity() const {
	return _velocity;
}

void MechanicsModel::setVelocity(Vector *vector) {
	if (vector == _velocity)
		return;
	_velocity = vector;
	emit velocityChanged();
}

Vector *MechanicsModel::acceleration() const {
	return _acceleration;
}

void MechanicsModel::setAcceleration(Vector *vector) {
	if (vector == _acceleration)
		return;
	_acceleration = vector;
	emit accelerationChanged();
}

void MechanicsModel::timerEvent(QTimerEvent *event) {
	Q_UNUSED(event);
	if (!_running) {
		event->ignore();
		return;
	}
	const qint64 dt = _clock.restart();
	const double dt_IN_SECS = static_cast<double>(dt)/1000;

	const double dx = _velocity->x()*dt_IN_SECS;
	setTargetX(_target->x() + dx);
	const double dy = _velocity->y()*dt_IN_SECS;
	setTargetY(_target->y() + dy);


	const QPointF ds = {dx, dy};
	if (ds.manhattanLength() > 0) {
		_displacement->fromPoint(_displacement->toPoint() + ds);
		emit displacementChanged();
	}

	const QPointF dv = _acceleration->toPoint()*dt_IN_SECS;
	if (dv.manhattanLength() > 0) {
		_velocity->fromPoint(_velocity->toPoint() + dv);
		emit velocityChanged();
	}
	_target->update();
}

void MechanicsModel::classBegin() {

}

void MechanicsModel::componentComplete() {
	if (_target == nullptr)
		_target = qobject_cast<QQuickItem *>(parent());
	if (_velocity == nullptr)
		_velocity = new Vector;
	if (_acceleration == nullptr)
		_acceleration = new Vector;
	if (_running) {
		_clock.start();
		_timerID = startTimer(0);
	}
}
