import QtQuick
import QtQuick.Window

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Asteroids")

    SpaceShip {
        x: parent.width/2 - width/2
        y: parent.height/2 - height/2
    }
}
