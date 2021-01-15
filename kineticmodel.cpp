#include "kineticmodel.h"

KineticModel::KineticModel(QObject *parent) :
    MechanicsModel(parent) {
//	connect(this, &KineticModel::forcesChanged,
//	        this, &KineticModel::calculateForce);
//	connect(this, &KineticModel::massChanged,
//	        this, &KineticModel::calculateAcceleration);
//	connect(this, &KineticModel::forceChanged,
//	        this, &KineticModel::calculateAcceleration);
}

KineticModel::~KineticModel() {
	disconnect(this, &KineticModel::forcesChanged,
	        this, &KineticModel::calculateForce);
	disconnect(this, &KineticModel::massChanged,
	        this, &KineticModel::calculateAcceleration);
	disconnect(this, &KineticModel::forceChanged,
	        this, &KineticModel::calculateAcceleration);
}

Vector *KineticModel::force() const {
	return _force;
}

QQmlListProperty<Vector> KineticModel::forces() {
	return {this, this,
	&KineticModel::appendForce,
	&KineticModel::forceCount,
	&KineticModel::forceAt,
	&KineticModel::clearForces,
	&KineticModel::replaceForce,
	&KineticModel::removeLastForce};
}

void KineticModel::appendForce(Vector *force) {
	_forces.append(force);
	emit forcesChanged();
}

qsizetype KineticModel::forceCount() const {
	return _forces.count();
}

Vector *KineticModel::forceAt(qsizetype index) const {
	return _forces.at(index);
}

void KineticModel::clearForces() {
	_forces.clear();
	emit forcesChanged();
}

void KineticModel::replaceForce(qsizetype index, Vector *force) {
	_forces.replace(index, force);
	emit forcesChanged();
}

void KineticModel::removeLastForce() {
	_forces.removeLast();
	emit forcesChanged();
}

double KineticModel::mass() const {
	return _mass;
}

void KineticModel::setMass(double mass) {
	if (mass == _mass)
		return;
	if (mass == 0)
		qFatal("Objects can not have zero mass");
	_mass = mass;
	emit massChanged();
}

void KineticModel::componentComplete() {
	MechanicsModel::componentComplete();
	connect(this, &KineticModel::forcesChanged,
	        this, &KineticModel::calculateForce);
	connect(this, &KineticModel::massChanged,
	        this, &KineticModel::calculateAcceleration);
	connect(this, &KineticModel::forceChanged,
	        this, &KineticModel::calculateAcceleration);
	calculateForce();
	calculateAcceleration();
}

void KineticModel::appendForce(QQmlListProperty<Vector> *list, Vector *force) {
	reinterpret_cast<KineticModel *>(list->data)->appendForce(force);
}

qsizetype KineticModel::forceCount(QQmlListProperty<Vector> *list) {
	return reinterpret_cast<KineticModel *>(list->data)->forceCount();
}

Vector *KineticModel::forceAt(QQmlListProperty<Vector> *list, qsizetype index) {
	return reinterpret_cast<KineticModel *>(list->data)->forceAt(index);
}

void KineticModel::clearForces(QQmlListProperty<Vector> *list) {
	reinterpret_cast<KineticModel *>(list->data)->clearForces();
}

void KineticModel::replaceForce(QQmlListProperty<Vector> *list, qsizetype index, Vector *force) {
	reinterpret_cast<KineticModel *>(list->data)->replaceForce(index, force);
}

void KineticModel::removeLastForce(QQmlListProperty<Vector> *list) {
	reinterpret_cast<KineticModel *>(list->data)->removeLastForce();
}

void KineticModel::calculateForce() {
	_force->vector() = {0, 0};
	for (const auto &force : _forces)
		_force->vector() += force->vector();
	emit forceChanged();
}

void KineticModel::calculateAcceleration() {
//	if (_acceleration == nullptr)
//		return;
	_acceleration->setAngle(_force->angle());
	_acceleration->setMagnitude(_force->magnitude()/_mass);
}
