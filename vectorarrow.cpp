#include "vectorarrow.h"

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

double VectorArrow::thickness() const {
	return _thickness;
}

void VectorArrow::setThickness(double thickness) {
	if (thickness == _thickness)
		return;
	_thickness = thickness;
	emit thicknessChanged();
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

QSGNode *VectorArrow::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *) {
	QSGGeometryNode *node = nullptr;
	if (!oldNode) {
		QSGGeometry *geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 2);
		geometry->setDrawingMode(QSGGeometry::DrawLines);
		geometry->setLineWidth(_thickness);
		auto vertices = geometry->vertexDataAsPoint2D();
		vertices[0].set(0, 0);
		if (_proportional)
			vertices[1] << _target->toPoint();
		else
			vertices[1] << _target->normalized()*_length;
		QSGFlatColorMaterial *material = new QSGFlatColorMaterial;
		material->setColor(_color);

		node = new QSGGeometryNode;
		node->setGeometry(geometry);
		node->setFlag(QSGNode::OwnsGeometry);
		node->setMaterial(material);
		node->setFlag(QSGNode::OwnsMaterial);
	}
	else {
		node = static_cast<QSGGeometryNode *>(oldNode);
		QSGGeometry *geometry = node->geometry();
		auto vertices = geometry->vertexDataAsPoint2D();
		if (_proportional)
			vertices[1] << (_target->toPoint());
		else
			vertices[1] << _target->normalized()*_length;

	}
	node->markDirty(QSGNode::DirtyGeometry);
	node->markDirty(QSGNode::DirtyMaterial);
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
