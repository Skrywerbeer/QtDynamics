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
        maximumX: root.parent.width - ballSize
        minimumY: 0
        maximumY: root.parent.height - ballSize
        velocityX: 100
        accelerationY: 500
        running: true
        onMinimumXReached: velocityX *= -0.9
        onMaximumXReached: velocityX *= -0.9
        onMinimumYReached: velocityY *= -0.9
        onMaximumYReached: velocityY *= -0.9
    }
}
