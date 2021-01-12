#ifndef ARROWNODE_H
#define ARROWNODE_H

#include <QSGNode>
#include <QColor>

class ArrowHeadNode;
class ArrowBodyNode;

class ArrowNode : public QSGNode {
	public:
		ArrowNode();

		void setEndPoint(const QPointF &end);
		void setProportional(bool on);
		void setLength(double length);
		void setWidth(double width);
		void setColor(const QColor &color);

	private:
		ArrowBodyNode *_body;
		ArrowHeadNode *_head;
		double _length = 10;
		bool _proportional = false;
};

#endif // ARROWNODE_H
