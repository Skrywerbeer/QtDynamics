#ifndef ARROWBODYNODE_H
#define ARROWBODYNODE_H

#include <QSGGeometryNode>
#include <QSGFlatColorMaterial>
#include <QColor>

class ArrowBodyNode : public QSGGeometryNode {
	public:
		ArrowBodyNode();

		void setEndPoint(const QPointF &end);
		void setWidth(double width);
		void setColor(const QColor &color);
};

#endif // ARROWBODYNODE_H
