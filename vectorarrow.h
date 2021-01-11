#ifndef VECTORARROW_H
#define VECTORARROW_H

#include <QQuickItem>
#include <QQmlEngine>
#include <QSGFlatColorMaterial>
#include <QSGGeometry>
#include <QSGGeometryNode>

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
		Q_PROPERTY(double thickness \
		           READ thickness \
		           WRITE setThickness \
		           NOTIFY thicknessChanged)
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

		double thickness() const;
		void setThickness(double thickness);

		QColor color() const;
		void setColor(const QColor &color);

		QSGNode *updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *);

		static void registerType();

	signals:
		void targetChanged();
		void lengthChanged();
		void proportionalChanged();
		void thicknessChanged();
		void colorChanged();

	private:
		Vector *_target = nullptr;
		double _length = 0;
		bool _proportional = false;
		double _thickness = 0;
		QColor _color = "black";

		void disconnectTargetSignals();
		void connectTargetSignals();
};

#endif // VECTORARROW_H
