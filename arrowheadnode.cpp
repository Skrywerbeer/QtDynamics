#include "arrowheadnode.h"

ArrowHeadNode::ArrowHeadNode() {
	QSGGeometry *geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 3);
	geometry->setDrawingMode(QSGGeometry::DrawTriangles);

	QSGFlatColorMaterial *material = new QSGFlatColorMaterial;

	setGeometry(geometry);
	setFlag(QSGNode::OwnsGeometry);
	setMaterial(material);
	setFlag(QSGNode::OwnsMaterial);
}

void ArrowHeadNode::setEndPoint(const QPointF &end) {
	QTransform transform;
	transform.translate(end.x(), end.y());
	transform.rotate(qRadiansToDegrees(qAtan2(end.y(), end.x())));
	auto vertices = geometry()->vertexDataAsPoint2D();
	const QList<QPointF> points{{_width, 0},
		                        {-_width, -_width},
		                        {-_width, _width}};
	for (auto &point : points)
		vertices++ << transform*point;
	markDirty(QSGNode::DirtyGeometry);
}

void ArrowHeadNode::setWidth(double width) {
	geometry()->setLineWidth(width);
	_width = width;
	markDirty(QSGNode::DirtyGeometry);
}

void ArrowHeadNode::setColor(const QColor &color) {
	static_cast<QSGFlatColorMaterial *>(material())->setColor(color);
	markDirty(QSGNode::DirtyMaterial);
}
