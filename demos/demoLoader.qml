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
            onClicked: loader.source = "qrc:/demo/Asteroids/main.qml"
        }
        Button {
            text: "SolarSystem"
            onClicked: loader.source = "qrc:/demo/SolarSystem/main.qml"
        }
        Button {
            text: "Spring"
            onClicked: loader.source = "qrc:/demo/Spring/main.qml"
        }
        Button {
            text: "CollisionDrag"
            onClicked: loader.source = "qrc:/demo/CollisionDrag/main.qml"
        }
        Button {
            text: "Tension"
            onClicked: loader.source = "qrc:/demo/Tension/main.qml"
        }
        Button {
            text: "Bounce"
            onClicked: loader.source = "qrc:/demo/Bounce/main.qml"
        }
    }

    Loader {
        id: loader
    }
}
