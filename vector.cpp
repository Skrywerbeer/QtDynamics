#include "vector.h"

Vector::Vector(QObject *parent) : QObject(parent) {

}

Vector::Vector(double x, double y, QObject *parent) :
    QObject(parent),
    _vector(x, y) {
}

double Vector::xComponent() const {
	return _vector.x();
}

void Vector::setXComponent(const double &value) {
	if (value == _vector.x())
		return;
	_vector.setX(value);
	emit changed();
	emit xComponentChanged();
	emit magnitudeChanged();
	emit angleChanged();
}

double Vector::yComponent() const {
	return _vector.y();
}

void Vector::setYComponent(const double &value) {
	if (value == _vector.y())
		return;
	_vector.setY(value);
	emit changed();
	emit yComponentChanged();
	emit magnitudeChanged();
	emit angleChanged();
}

double Vector::angle() const {
	return qRadiansToDegrees(qAtan2(_vector.y(), _vector.x()));
}

void Vector::setAngle(const double &degrees) {
	if (degrees == angle())
		return;
	const double RADIANS = qDegreesToRadians(degrees);
	const double MAG = magnitude();
	_vector.setX(MAG*qCos(RADIANS));
	_vector.setY(MAG*qSin(RADIANS));
	emit changed();
	emit xComponentChanged();
	emit yComponentChanged();
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
	emit xComponentChanged();
	emit yComponentChanged();
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

void Vector::operator+=(const QPointF &vec) {
	_vector += vec;
	emit changed();
	emit xComponentChanged();
	emit yComponentChanged();
	emit magnitudeChanged();
	emit angleChanged();
}

void Vector::operator-=(const QPointF &vec) {
	_vector -= vec;
	emit changed();
	emit xComponentChanged();
	emit yComponentChanged();
	emit magnitudeChanged();
	emit angleChanged();
}

void Vector::registerType() {
	qmlRegisterType<Vector>("Models", 1, 0, "Vector");
}
