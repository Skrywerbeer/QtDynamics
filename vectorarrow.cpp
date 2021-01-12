#include "vectorarrow.h"
#include "arrownode.h"

VectorArrow::VectorArrow(QQuickItem *parent) :
    QQuickItem(parent) {
	setFlag(QQuickItem::ItemHasContents);
	setAntialiasing(true);
}

Vector *VectorArrow::target() const {
	return _target;
}

void VectorArrow::setTarget(Vector *target) {
	if (target == _target)
		return;
	if (_target != nullptr)
		disconnectTargetSignals();
	_target = target;
	connectTargetSignals();
	emit targetChanged();
	update();
}

double VectorArrow::length() const {
	return _length;
}

void VectorArrow::setLength(double length) {
	if (length == _length)
		return;
	_length = length;
	emit lengthChanged();
	update();
}

bool VectorArrow::proportional() const {
	return _proportional;
}

void VectorArrow::setProportional(bool on) {
	if (on == _proportional)
		return;
	_proportional = on;
	emit proportionalChanged();
	update();
}

double VectorArrow::lineWidth() const {
	return _thickness;
}

void VectorArrow::setLineWidth(double thickness) {
	if (thickness == _thickness)
		return;
	_thickness = thickness;
	emit lineWidthChanged();
	update();
}

QColor VectorArrow::color() const {
	return _color;
}

void VectorArrow::setColor(const QColor &color) {
	if (color == _color)
		return;
	_color = color;
	emit colorChanged();
	update();
}

QSGNode *VectorArrow::updatePaintNode(QSGNode *node, UpdatePaintNodeData *) {
	if (!node) {
		node = new QSGNode;
		ArrowNode *arrow = new ArrowNode();
		arrow->setWidth(_thickness);
		arrow->setColor(_color);
		arrow->setLength(_length);
		arrow->setProportional(_proportional);
		arrow->setEndPoint(_target->toPoint());
		node->appendChildNode(arrow);
	}
	else {
		static_cast<ArrowNode *>(node->childAtIndex(0))->setEndPoint(_target->toPoint());
	}
	return node;
}

void VectorArrow::disconnectTargetSignals() {
	disconnect(_target, &Vector::changed,
	           this, &QQuickItem::update);
}

void VectorArrow::connectTargetSignals() {
	connect(_target, &Vector::changed,
	        this, &QQuickItem::update);
}

void VectorArrow::registerType() {
	qmlRegisterType<VectorArrow>("Models", 1, 0, "VectorArrow");
}
