#ifndef KINEMATICMODEL_H
#define KINEMATICMODEL_H

#include <QObject>
#include <QQmlParserStatus>
#include <QQuickItem>
#include <QQmlEngine>
#include <QElapsedTimer>
#include <QDateTime>
#include <QTimerEvent>

#include "mechanicsmodel.h"

class KinematicModel : public MechanicsModel {
		Q_OBJECT
		Q_INTERFACES(QQmlParserStatus)
		QML_ELEMENT

		Q_PROPERTY(Vector *acceleration \
		           READ acceleration \
		           WRITE setAcceleration \
		           NOTIFY accelerationChanged)

	public:
		explicit KinematicModel(QObject *parent = nullptr);

		Vector *acceleration() const;
		void setAcceleration(Vector *vector);

		void timerEvent(QTimerEvent *event) override;

		void classBegin() override;
		void componentComplete() override;

	signals:
		void accelerationChanged();

	private:
		Vector *_acceleration = nullptr;
		void tickHandler();
};

#endif // KINEMATICMODEL_H
