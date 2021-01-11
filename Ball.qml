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
        velocityVector: Vector {id: vec; xComponent: 200; yComponent: 0}
        accelerationVector: Vector {
            xComponent: (rootWindow.width/2 - root.x)/3
            yComponent: (rootWindow.height/2 - root.y)/3
        }
        running: true
        onMinimumXReached: velocityVector.xComponent *= -0.9
        onMaximumXReached: velocityVector.xComponent *= -0.9
        onMinimumYReached: velocityVector.yComponent *= -0.9
        onMaximumYReached: velocityVector.yComponent *= -0.9
    }
    MouseArea {
        anchors.fill: root
        onClicked: model.velocityVector.yComponent = 300
    }
}
