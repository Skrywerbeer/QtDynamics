#ifndef KINEMATICMODEL_H
#define KINEMATICMODEL_H

#include "mechanicsmodel.h"

// This class is used just to expose the _acceleration member of MechanicsModel
// as a writeable property. In KineticModel _acceleration is a read only property.
class KinematicModel : public MechanicsModel {
		Q_OBJECT
		QML_ELEMENT
		Q_PROPERTY(Vector *acceleration \
		           READ acceleration \
		           WRITE setAcceleration \
		           NOTIFY accelerationChanged)
	public:
		explicit KinematicModel(QObject *parent = nullptr);
};

#endif // KINEMATICMODEL_H
