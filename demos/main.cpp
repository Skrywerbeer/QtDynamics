#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "importpath.h"

int main(int argc, char **argv) {
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine(QUrl("qrc:/demoLoader.qml"));
	engine.addImportPath(PLUGIN_PATH);
	return app.exec();
}
