import QtQuick

import Models

Rectangle {
    id: root

    property real ballSize: 0
    property real scaler: 3
    property bool showVectors: true

    width: ballSize
    height: ballSize
    radius: ballSize/2
    color: "firebrick"

    KinematicModel {
        id: model
        minimumX: 0
        maximumX: rootWindow.width - ballSize
        minimumY: 0
        maximumY: rootWindow.height - ballSize
        velocityVector: Vector {
            id: velocityVector
            angle: accelerationVector.angle-90
            magnitude: accelerationVector.magnitude
        }
        accelerationVector: Vector {
            id: accelerationVector
            xComponent: (rootWindow.width/2 - root.x)/scaler
            yComponent: (rootWindow.height/2 - root.y)/scaler
        }
        running: true
        onMinimumXReached: velocityVector.xComponent *= -0.9
        onMaximumXReached: velocityVector.xComponent *= -0.9
        onMinimumYReached: velocityVector.yComponent *= -0.9
        onMaximumYReached: velocityVector.yComponent *= -0.9
    }
    VectorArrow {
        anchors.centerIn: parent
        target: velocityVector
        length: 50
        thickness: 4
        color: "steelblue"
        visible: showVectors
    }
    VectorArrow {
        anchors.centerIn: parent
        target: accelerationVector
        length: 30
        thickness: 4
        color: "firebrick"
        visible: showVectors
    }

    MouseArea {
        anchors.fill: root
        onClicked: model.velocityVector.yComponent = 300
    }
}
