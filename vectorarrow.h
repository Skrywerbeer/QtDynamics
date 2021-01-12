#ifndef VECTORARROW_H
#define VECTORARROW_H

#include <QQuickItem>
#include <QQmlEngine>
#include <QSGFlatColorMaterial>
#include <QSGGeometry>
#include <QSGGeometryNode>
#include <QTransform>

#include <QMutex>
#include <QMutexLocker>

#include "vector.h"

class VectorArrow : public QQuickItem {
		Q_OBJECT
		Q_PROPERTY(Vector *target \
		           READ target \
		           WRITE setTarget \
		           NOTIFY targetChanged
		           REQUIRED)
		Q_PROPERTY(double length \
		           READ length \
		           WRITE setLength \
		           NOTIFY lengthChanged)
		Q_PROPERTY(bool proportional \
		           READ proportional \
		           WRITE setProportional \
		           NOTIFY proportionalChanged)
		Q_PROPERTY(double lineWidth \
		           READ lineWidth \
		           WRITE setLineWidth \
		           NOTIFY lineWidthChanged)
		Q_PROPERTY(QColor color \
		           READ color \
		           WRITE setColor \
		           NOTIFY colorChanged)
	public:
		VectorArrow(QQuickItem *parent = nullptr);

		Vector *target() const;
		void setTarget(Vector *target);

		double length() const;
		void setLength(double length);

		bool proportional() const;
		void setProportional(bool on);

		double lineWidth() const;
		void setLineWidth(double thickness);

		QColor color() const;
		void setColor(const QColor &color);

		QSGNode *updatePaintNode(QSGNode *node, UpdatePaintNodeData *);

		static void registerType();

	signals:
		void targetChanged();
		void lengthChanged();
		void proportionalChanged();
		void lineWidthChanged();
		void colorChanged();

	private:
		Vector *_target = nullptr;

		double _length = 0;
		bool m_lengthChanged = false;

		bool _proportional = false;
		bool m_proportionalChanged = false;
		// TODO: check for maximum line width.
		double _lineWidth = 0;
		bool m_lineWidthChanged = false;

		QColor _color = "black";
		bool m_colorChanged = false;

		QMutex _mutex;

		void disconnectTargetSignals();
		void connectTargetSignals();
};

inline void operator<<(QSGGeometry::Point2D &point2d, const QPointF &point) {
	point2d.set(point.x(), point.y());
}

#endif // VECTORARROW_H
