import QtQuick

import QtDynamics
import "logic.js" as Logic

Image {
    id: root

    function fire() {
        let bulletComponent = Qt.createComponent("Bullet.qml")
        let bullet = bulletComponent.createObject(root.parent, {
                                                      x: root.x + root.width/2 -10,
                                                      y: root.y + root.height/2 -10,
                                                      rotation: root.rotation,
                                                      shipVelocity: model.velocity.magnitude
                                                  })
    }

    property bool engineOn: false
    property bool turningLeft: false
    property bool turningRight: false
    property bool fired: false

    signal shipDestroyed

    width: 32
    height: 32
    focus: true
    source: engineOn ? "spaceship_engine_on.png" : "spaceship_engine_off.png"

    KineticModel {
        id: model

        minimumX: -root.width
        maximumX: root.parent.width
        minimumY: -root.height
        maximumY: root.parent.height
        mass: 1
        forces: [
            Vector {
                id: thrust
                angle: root.rotation
                magnitude: engineOn ? 100 : 0
            }
        ]
        onMinimumXReached: root.x = root.parent.width
        onMaximumXReached: root.x = -root.width+1
        onMinimumYReached: root.y =root.parent.height
        onMaximumYReached: root.y = -root.height+1
    }
    AABBCollisionDetector {
        items: Logic.asteroids
        timerInterval: 50
        timerRunning: true
//        onCollision: root.shipDestroyed()
//        onCollision: console.log("Your ship has crashed")
    }

    Behavior on rotation {NumberAnimation{ duration: 100}}
    Timer {
        interval: 100
        repeat: true
        running: turningLeft || turningRight
        onTriggered: {
            if (turningLeft)
                rotation -= 10
            else if (turningRight)
                rotation += 10
        }
    }
    Timer {
        interval: 200
        running: fired
        onTriggered: fired = false
    }

    Keys.onPressed: {
        switch (event.key) {
        case (Qt.Key_Up):
            event.accepeted = true
            engineOn = true;
            break;
        case (Qt.Key_Left):
            event.accepeted = true
            turningRight = false
            turningLeft = true
            rotation -= 10
            break;
        case (Qt.Key_Right):
            event.accepeted = true
            turningLeft = false
            turningRight = true
            rotation += 10
            break;
        case (Qt.Key_Space):
            event.accepeted = true
            if (!fired) {
                root.fire()
                fired = true
            }
            break
        default:
            event.accepted = false;
        }
    }
    Keys.onReleased: {
        switch (event.key) {
        case (Qt.Key_Up):
            event.accepted = true
            engineOn = false
            break;
        case (Qt.Key_Left):
            turningLeft = false
            break;
        case (Qt.Key_Right):
            turningRight = false
            break;
        }
    }
}
