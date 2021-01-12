#include "arrownode.h"
#include "arrowheadnode.h"
#include "arrowbodynode.h"

ArrowNode::ArrowNode() :
    _body(new ArrowBodyNode),
    _head(new ArrowHeadNode) {
	appendChildNode(_body);
	appendChildNode(_head);
}

void ArrowNode::setEndPoint(const QPointF &end) {
	if (_proportional) {
		_body->setEndPoint(end);
		_head->setEndPoint(end);
	}
	else {
		const double angle = qAtan2(end.y(), end.x());
		const QPointF scaledEnd = {_length*qCos(angle), _length*qSin(angle)};
		_body->setEndPoint(scaledEnd);
		_head->setEndPoint(scaledEnd);
	}
}

void ArrowNode::setProportional(bool on) {
	_proportional = on;
}

void ArrowNode::setLength(double length) {
	_length = length;
}

void ArrowNode::setWidth(double width) {
	_body->setWidth(width);
	_head->setWidth(width);
}

void ArrowNode::setColor(const QColor &color) {
	_body->setColor(color);
	_head->setColor(color);
}

