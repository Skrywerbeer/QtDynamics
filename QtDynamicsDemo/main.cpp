#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char **argv) {
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine(QUrl("qrc:/qt/qml/QtDynamicsDemo/demoLoader.qml"));

	return app.exec();
}
