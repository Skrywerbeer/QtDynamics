import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    id: loaderWindow

    visible: true
    height: 300
    width: 300


    Grid {
        anchors.fill: parent
        columns: 3

        Button {
            text: "Asteroids"
            onClicked: loader.source = "qrc:/qt/qml/QtDynamicsDemo/Asteroids/main.qml"
        }
        Button {
            text: "SolarSystem"
            onClicked: loader.source = "qrc:/qt/qml/QtDynamicsDemo/SolarSystem/main.qml"
        }
        Button {
            text: "Spring"
            onClicked: loader.source = "qrc:/qt/qml/QtDynamicsDemo/Spring/main.qml"
        }
        Button {
            text: "CollisionDrag"
            onClicked: loader.source = "qrc:/qt/qml/QtDynamicsDemo/CollisionDrag/main.qml"
        }
        Button {
            text: "Tension"
            onClicked: loader.source = "qrc:/qt/qml/QtDynamicsDemo/Tension/main.qml"
        }
        Button {
            text: "Bounce"
            onClicked: loader.source = "qrc:/qt/qml/QtDynamicsDemo/Bounce/main.qml"
        }
        Button {
            text: "Breakout"
            onClicked: loader.source = "qrc:/qt/qml/QtDynamicsDemo/Breakout/main.qml"
        }
    }

    Loader {
        id: loader
    }
}
