#ifndef ARROWHEADNODE_H
#define ARROWHEADNODE_H

#include <QSGGeometryNode>
#include <QSGFlatColorMaterial>
#include <QColor>
#include <QTransform>

class ArrowHeadNode : public QSGGeometryNode {
	public:
		ArrowHeadNode();
		void setEndPoint(const QPointF &end);
		void setWidth(double width);
		void setColor(const QColor &color);
	private:
		double _width;
};

inline void operator<<(QSGGeometry::Point2D *vertices, const QList<QPointF> &points) {
	int i = 0;
	for (const auto &point : points)
		vertices->set(point.x(), point.y());
}

inline void operator<<(QSGGeometry::Point2D *vertex, const QPointF &point) {
	vertex->set(point.x(), point.y());
}

#endif // ARROWHEADNODE_H
