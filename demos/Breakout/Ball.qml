import QtQuick
import QtDynamics

Rectangle {
    id: root

    property alias collideableItems: detector.items
    property alias velocity: model.velocity

    width: 32
    height: 32
    radius: 16
    color: "yellow"

    KinematicModel {
        id: model

        minimumX: 0
        maximumX: root.parent.width - root.width

        velocity: Vector {
            angle: Math.random()*45 - 90
            magnitude: 200
        }
        onMinimumXReached: velocity.x *= -1
        onMaximumXReached: velocity.x *= -1
    }
    AABBCollisionDetector {
        id: detector

        timerRunning: true
        timerInterval: 50
        onCollision: {
            model.velocity.y *= -1
            wall.destroyBrick(item)
        }
    }
}
