import QtQuick

import Models

Rectangle {
    id: root

    property real ballSize: 0

    width: ballSize
    height: ballSize
    radius: ballSize/2
    color: "firebrick"

    KinematicModel {
        id: model
        minimumX: 0
        maximumX: rootWindow.width - ballSize
//        maximumX: parent.parent.width - ballSize
        minimumY: 0
        maximumY: rootWindow.height - ballSize
//        maximumY: parent.parent.height - ballSize
        velocityX: 100
        accelerationY: 500
        running: true
        onMinimumXReached: velocityX *= -0.9
        onMaximumXReached: velocityX *= -0.9
        onMinimumYReached: velocityY *= -0.9
        onMaximumYReached: velocityY *= -0.9
    }
    MouseArea {
        anchors.fill: root
//        onClicked: model.running = true
//        onClicked: {
//            root.y = 100
//            root.x = 100
//        }
    }
}
