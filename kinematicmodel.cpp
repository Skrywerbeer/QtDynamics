#include "kinematicmodel.h"
#include "vector.h"

KinematicModel::KinematicModel(QObject *parent) :
    MechanicsModel(parent) {

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
	MechanicsModel::componentComplete();
	if (_acceleration == nullptr)
		_acceleration = new Vector;
}
