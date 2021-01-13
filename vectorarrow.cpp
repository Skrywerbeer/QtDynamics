#include "vectorarrow.h"
#include "arrownode.h"

VectorArrow::VectorArrow(QQuickItem *parent) :
    QQuickItem(parent) {
	setFlag(QQuickItem::ItemHasContents);
//	setAntialiasing(true);
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
	QMutexLocker locker(&_mutex);
	if (length == _length)
		return;
	_length = length;
	emit lengthChanged();
	m_lengthChanged = true;
	update();
}

bool VectorArrow::proportional() const {
	return _proportional;
}

void VectorArrow::setProportional(bool on) {
	QMutexLocker locker(&_mutex);
	if (on == _proportional)
		return;
	_proportional = on;
	emit proportionalChanged();
	m_proportionalChanged = true;
	update();
}

double VectorArrow::lineWidth() const {
	return _lineWidth;
}

void VectorArrow::setLineWidth(double thickness) {
	QMutexLocker locker(&_mutex);
	if (thickness == _lineWidth)
		return;
	_lineWidth = thickness;
	emit lineWidthChanged();
	m_lineWidthChanged = true;
	update();
}

QColor VectorArrow::color() const {
	return _color;
}

void VectorArrow::setColor(const QColor &color) {
	QMutexLocker locker(&_mutex);
	if (color == _color)
		return;
	_color = color;
	emit colorChanged();
	m_colorChanged = true;
	update();
}

QSGNode *VectorArrow::updatePaintNode(QSGNode *node, UpdatePaintNodeData *) {
	if (!node) {
		node = new QSGNode;
		ArrowNode *arrow = new ArrowNode();
		arrow->setWidth(_lineWidth);
		arrow->setColor(_color);
		arrow->setLength(_length);
		arrow->setProportional(_proportional);
		arrow->setEndPoint(_target->toPoint());
		node->appendChildNode(arrow);
	}
	ArrowNode *arrow = static_cast<ArrowNode *>(node->childAtIndex(0));
	arrow->setEndPoint(_target->toPoint());
	QMutexLocker locker(&_mutex);
	if (m_lengthChanged) {
		m_lengthChanged = false;
		arrow->setLength(_length);
	}
	if (m_proportionalChanged) {
		m_proportionalChanged = false;
		arrow->setProportional(_proportional);
	}
	if (m_lineWidthChanged) {
		m_lineWidthChanged = false;
		arrow->setWidth(_lineWidth);
	}
	if (m_colorChanged) {
		m_colorChanged = false;
		arrow->setColor(_color);
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
