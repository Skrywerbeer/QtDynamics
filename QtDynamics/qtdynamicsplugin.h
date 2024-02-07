#ifndef QTDYNAMICSPLUGIN_H
#define QTDYNAMICSPLUGIN_H

#include <QQmlEngineExtensionPlugin>

class QtDynamicsPlugin : public QQmlEngineExtensionPlugin {
		Q_OBJECT
		Q_PLUGIN_METADATA(IID QQmlEngineExtensionInterface_iid)
};

#endif // QTDYNAMICSPLUGIN_H
