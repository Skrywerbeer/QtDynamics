#include "arrowbodynode.h"

ArrowBodyNode::ArrowBodyNode() {
	QSGGeometry *geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 2);
	geometry->setDrawingMode(QSGGeometry::DrawLines);
	auto vertices = geometry->vertexDataAsPoint2D();
	vertices[0].set(0, 0);

	QSGFlatColorMaterial *material = new QSGFlatColorMaterial;

	setGeometry(geometry);
	setFlag(QSGNode::OwnsGeometry);
	setMaterial(material);
	setFlag(QSGNode::OwnsMaterial);
}

void ArrowBodyNode::setEndPoint(const QPointF &end) {
	geometry()->vertexDataAsPoint2D()[1].set(end.x(), end.y());
	markDirty(QSGNode::DirtyGeometry);
}

void ArrowBodyNode::setWidth(double width) {
	geometry()->setLineWidth(width);
	markDirty(QSGNode::DirtyGeometry);
}

void ArrowBodyNode::setColor(const QColor &color) {
	static_cast<QSGFlatColorMaterial *>(material())->setColor(color);
	markDirty(QSGNode::DirtyMaterial);
}
