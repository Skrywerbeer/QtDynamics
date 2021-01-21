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
	updatePolar();
	emit changed();
}

double Vector::y() const {
	return _vector.y();
}

void Vector::setY(const double &value) {
	if (value == _vector.y())
		return;
	_vector.setY(value);
	updatePolar();
	emit changed();
}

QPointF Vector::toPoint() const {
	return _vector;
}

void Vector::fromPoint(const QPointF &point) {
	_vector = point;
	updatePolar();
	emit changed();
}

double Vector::angle() const {
	return _angle;
}

void Vector::setAngle(double degrees) {
	if (degrees == _angle)
		return;
	while (degrees > 360)
		degrees -= 360;
	while (degrees < -360)
		degrees += 360;
	_angle = degrees;
	updateCartesian();
	emit changed();
}

double Vector::magnitude() const {
	return _magnitude;
}

void Vector::setMagnitude(const double &mag) {
	if (mag == _magnitude)
		return;
	_magnitude = mag;
	updateCartesian();
	emit changed();
}

QPointF &Vector::vector() {
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
}

void Vector::operator-=(const QPointF &vec) {
	_vector -= vec;
	emit changed();
}

void Vector::updatePolar() {
	_magnitude = qSqrt(QPointF::dotProduct(_vector, _vector));
	_angle = qRadiansToDegrees(qAtan2(_vector.y(), _vector.x()));
}

void Vector::updateCartesian() {
	_vector.setX(_magnitude*qCos(qDegreesToRadians(_angle)));
	_vector.setY(_magnitude*qSin(qDegreesToRadians(_angle)));
}
