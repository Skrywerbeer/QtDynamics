#include "vector.h"

Vector::Vector(QObject *parent) : QObject(parent) {

}

Vector::Vector(double x, double y, QObject *parent) :
    QObject(parent),
    _vector(x, y) {
}

double Vector::x() const {
	return _vector.x();
}

void Vector::setX(const double &value) {
	if (value == _vector.x())
		return;
	_vector.setX(value);
	emit changed();
	emit xChanged();
	emit magnitudeChanged();
	emit angleChanged();
}

double Vector::y() const {
	return _vector.y();
}

void Vector::setY(const double &value) {
	if (value == _vector.y())
		return;
	_vector.setY(value);
	emit changed();
	emit yChanged();
	emit magnitudeChanged();
	emit angleChanged();
}

double Vector::angle() const {
	return qRadiansToDegrees(qAtan2(_vector.y(), _vector.x()));
}

void Vector::setAngle(double degrees) {
	if (degrees == angle())
		return;

	if (degrees > 360)
		while (degrees > 360)
			degrees -= 360;
	else if (degrees < -360)
		while (degrees < -360)
			degrees += 360;

	const double RADIANS = qDegreesToRadians(degrees);
	const double MAG = magnitude();
	_vector.setX(MAG*qCos(RADIANS));
	_vector.setY(MAG*qSin(RADIANS));
	emit changed();
	emit xChanged();
	emit yChanged();
	emit angleChanged();
}

double Vector::magnitude() const {
	const double xSquared = _vector.x() * _vector.x();
	const double ySquared = _vector.y()*_vector.y();
	return qSqrt(xSquared + ySquared);
}

void Vector::setMagnitude(const double &mag) {
	if (mag == magnitude())
		return;
	const double RADIANS = qDegreesToRadians(angle());
	_vector.setX(mag*qCos(RADIANS));
	_vector.setY(mag*qSin(RADIANS));
	emit changed();
	emit xChanged();
	emit yChanged();
	emit magnitudeChanged();
}

QPointF &Vector::vector() {
	return _vector;
}

QPointF Vector::toPoint() const {
	return _vector;
}

QPointF Vector::normalized() const {
	return _vector/qSqrt(QPointF::dotProduct(_vector, _vector));
}

Vector *Vector::inverse() const {
	return new Vector(-_vector.x(), -_vector.y());
}

void Vector::operator+=(const QPointF &vec) {
	_vector += vec;
	emit changed();
	emit xChanged();
	emit yChanged();
	emit magnitudeChanged();
	emit angleChanged();
}

void Vector::operator-=(const QPointF &vec) {
	_vector -= vec;
	emit changed();
	emit xChanged();
	emit yChanged();
	emit magnitudeChanged();
	emit angleChanged();
}
