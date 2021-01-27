import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    id: loaderWindow

    visible: true
    height: 300
    width: 300


    GridLayout {
        anchors.fill: parent

        Button {
            text: "Asteroids"
            onClicked: loader.state = "Asteroids"
        }
        Button {
            text: "SolarSystem"
            onClicked: loader.state = "SolarSystem"
        }
        Button {
            text: "Spring"
            onClicked: loader.state = "Spring"
        }
    }

    Loader {
        id: loader

        states: [
            State {
                name: "Asteroids"
                PropertyChanges {target: loader; source: "qrc:/demo/Asteroids/main.qml"}
            },
            State {
                name: "SolarSystem"
                PropertyChanges {target: loader; source: "qrc:/demo/SolarSystem/main.qml"}
            },
            State {
                name: "Spring"
                PropertyChanges {target: loader; source: "qrc:/demo/Spring/main.qml"}
            }

        ]
    }
}
