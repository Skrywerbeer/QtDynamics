import QtQuick

import QtDynamics
import "logic.js" as Logic
import "global.js" as Global

Image {
    id: root

    property real shipVelocity: 0

    width: 20
    height: 20
    source: "bullet.png"

    KinematicModel {
        id: model

        velocity: Vector {
            angle: root.rotation
            magnitude: 300 + shipVelocity
        }
        onDisplacementChanged: {
            if (displacement.magnitude >= 300)
                root.destroy()
        }
    }
    AABBCollisionDetector {
        id: detector
        target: root
        items: Global.asteroids
        timerInterval: 50
        timerRunning: true
        onCollision: {
            root.destroy()
//            Global.destroyAsteroid(item)
            Logic.destroyAsteroid(item)
        }
    }
}
