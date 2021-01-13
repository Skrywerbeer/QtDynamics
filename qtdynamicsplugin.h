#ifndef QTDYNAMICSPLUGIN_H
#define QTDYNAMICSPLUGIN_H

#include <QQmlEngineExtensionPlugin>

class QtDynamicsPlugin : public QQmlEngineExtensionPlugin {
		Q_OBJECT
		Q_PLUGIN_METADATA(IID QQmlEngineExtensionInterface_iid)
};

//void qml_register_types_QtDynamics();

//void reg();

#endif // QTDYNAMICSPLUGIN_H
