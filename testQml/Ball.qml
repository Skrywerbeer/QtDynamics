import QtQuick

import QtDynamics

Rectangle {
    id: root

    property real ballSize: 0
    property real scaler: 3
    property bool showVectors: false

    width: ballSize
    height: ballSize
    radius: ballSize/2
    transform: Rotation {
        origin {x: root.width/2; y: root.height/2}
        angle: accelerationVector.angle - 90
    }

//    rotation: accelerationVector.angle-90
    gradient: Gradient {
        GradientStop {position: 0.5; color: "black"}
        GradientStop {position: 0.7; color: Qt.darker(root.color)}
        GradientStop {position: 1; color: root.color}
    }

    KinematicModel {
        id: model
        velocity: Vector {
            id: velocityVector
            angle: accelerationVector.angle-90
            magnitude: accelerationVector.magnitude
        }
        acceleration: Vector {
            id: accelerationVector
            xComponent: (rootWindow.width/2 - (root.x + root.width/2))/scaler
            yComponent: (rootWindow.height/2 - (root.y + root.width/2))/scaler
        }
        running: true
    }
    VectorArrow {
        anchors.centerIn: parent
        target: velocityVector
        proportional: true
        lineWidth: 4
        color: "steelblue"
        visible: showVectors
    }
    VectorArrow {
        anchors.centerIn: parent
        target: accelerationVector
        proportional: true
        lineWidth: 4
        color: "firebrick"
        visible: showVectors
    }

    MouseArea {
        anchors.fill: root
        onClicked: model.velocityVector.yComponent = 300
    }
}
