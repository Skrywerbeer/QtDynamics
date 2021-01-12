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
//    rotation: accelerationVector.angle-90
//    gradient: Gradient {
//        GradientStop {position: 0.5; color: "black"}
//        GradientStop {position: 0.7; color: Qt.darker(root.color)}
//        GradientStop {position: 1; color: root.color}
//    }

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
        length: 50
        thickness: 10
        color: "steelblue"
        visible: showVectors
    }
    VectorArrow {
        anchors.centerIn: parent
        target: accelerationVector
        length: 30
//        opacity: 0.5
//        layer.enabled: true
        thickness: 10
        color: "firebrick"
        visible: showVectors
    }

    MouseArea {
        anchors.fill: root
        onClicked: model.velocityVector.yComponent = 300
    }
}
