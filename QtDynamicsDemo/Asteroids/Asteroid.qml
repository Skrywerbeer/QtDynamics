import QtQuick

import QtDynamics

Image {
    id: root

    property real size: 80
    property alias moving: model.running

    width: size
    height: size
    source: "asteroid1.png"

    KinematicModel {
        id: model

        minimumX: 0
        maximumX: root.parent.width - root.width
//        maximumX: rootWindow.width - root.width
        minimumY: 0
        maximumY: root.parent.height - root.height
//        maximumY: rootWindow.height - root.height

        velocity: Vector {
            angle: Math.random()*360
            magnitude: 100
        }

        onMinimumXReached: velocity.x *= -1
        onMaximumXReached: velocity.x *= -1
        onMinimumYReached: velocity.y *= -1
        onMaximumYReached: velocity.y *= -1
    }
}
