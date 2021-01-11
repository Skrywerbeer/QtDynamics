#include "vector.h"

Vector::Vector(QObject *parent) : QObject(parent) {

}

double Vector::xComponent() const {
	return _xComponent;
}

void Vector::setXComponent(const double &value) {
	if (value == _xComponent)
		return;
	_xComponent = value;
	emit xComponentChanged();
	emit magnitudeChanged();
	emit angleChanged();
}

void Vector::setYComponent(const double &value) {
	if (value == _yComponent)
		return;
	_yComponent = value;
	emit yComponentChanged();
	emit magnitudeChanged();
	emit angleChanged();
}

double Vector::angle() const {
	return qRadiansToDegrees(qAtan2(_yComponent, _xComponent));
}

void Vector::setAngle(const double &degrees) {
	if (degrees == angle())
		return;
	const double RADIANS = qDegreesToRadians(degrees);
	const double MAG = magnitude();
	_xComponent = MAG*qCos(RADIANS);
	_yComponent = MAG*qSin(RADIANS);
	emit xComponentChanged();
	emit yComponentChanged();
	emit angleChanged();
}

double Vector::magnitude() const {
	const double xSquared = _xComponent*_xComponent;
	const double ySquared = _yComponent*_yComponent;
	return qSqrt(xSquared + ySquared);
}

void Vector::setMagnitude(const double &mag) {
	if (mag == magnitude())
		return;
	const double SCALE_FACTOR = mag/magnitude();
	_xComponent *= SCALE_FACTOR;
	_yComponent *= SCALE_FACTOR;
	emit xComponentChanged();
	emit yComponentChanged();
	emit magnitudeChanged();
}

void Vector::registerType() {
	qmlRegisterType<Vector>("Models", 1, 0, "Vector");
}
