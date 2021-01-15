#ifndef KINETICMODEL_H
#define KINETICMODEL_H

#include <QList>
#include <QQmlListProperty>

#include "mechanicsmodel.h"

class KineticModel : public MechanicsModel {
		Q_OBJECT
		Q_PROPERTY(Vector *force \
		           READ force \
		           NOTIFY forceChanged)
		Q_PROPERTY(QQmlListProperty<Vector> forces \
		           READ forces)
		Q_PROPERTY(Vector *acceleration \
		           READ acceleration
		           NOTIFY accelerationChanged)
		Q_PROPERTY(double mass \
		           READ mass \
		           WRITE setMass \
		           NOTIFY massChanged)

	public:
		KineticModel(QObject *parent = nullptr);
		~KineticModel();

		Vector *force() const;

		QQmlListProperty<Vector> forces();
		void appendForce(Vector *force);
		qsizetype forceCount() const;
		Vector *forceAt(qsizetype index) const;
		void clearForces();
		void replaceForce(qsizetype index, Vector *force);
		void removeLastForce();

		double mass() const;
		void setMass(double mass);

	signals:
		void forceChanged();
		void forcesChanged();
		void massChanged();

	private:
		Vector *_force = new Vector;
		QList<Vector *> _forces;
		double _mass = 1;

		static void appendForce(QQmlListProperty<Vector> *list, Vector *force);
		static qsizetype forceCount(QQmlListProperty<Vector> *list);
		static Vector *forceAt(QQmlListProperty<Vector> *list, qsizetype index);
		static void clearForces(QQmlListProperty<Vector> *list);
		static void replaceForce(QQmlListProperty<Vector> *list, qsizetype index, Vector *force);
		static void removeLastForce(QQmlListProperty<Vector> *list);


	private slots:
		// Sum Vector from _forces and write to _force.
		void calculateForce();
		// Write _force/mass to _acceleration.
		void calculateAcceleration();
};

#endif // KINETICMODEL_H
