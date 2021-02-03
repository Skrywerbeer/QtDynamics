import QtQuick
import QtDynamics

Rectangle {
    id: root

    function moveLeft() {
        movingRight = false
        movingLeft = true
    }
    function moveRight() {
        movingLeft = false
        movingRight = true
    }
    function stopMoving() {
        movingLeft = false
        movingRight = false
    }

    property bool movingLeft: false
    property bool movingRight: false

    width: 60
    height: 20
    color: "orange"
    anchors.bottom: parent.bottom
    focus: true

    KinematicModel {
        id: model

        velocity: Vector {
            x: {
                if (movingLeft)
                    return -300
                else if (movingRight)
                    return 300
                else
                    return 0
            }
        }
    }

    AABBCollisionDetector {
        id: detector

        timerRunning: true
        timerInterval: 50
        items: ball

        onCollision: {
            ball.velocity.y *= -1
            ball.velocity.x = model.velocity.x
        }
    }

    Keys.onPressed: {
        switch (event.key) {
        case (Qt.Key_Right):
            moveRight()
            break
        case (Qt.Key_Left):
            moveLeft()
            break
        }
    }
    Keys.onReleased: {
        switch (event.key) {
        case (Qt.Key_Right):
            stopMoving()
            break
        case (Qt.Key_Left):
            stopMoving()
            break
        }
    }
}
