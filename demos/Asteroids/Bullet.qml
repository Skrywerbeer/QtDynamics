import QtQuick

import QtDynamics
import "logic.js" as Logic

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
        items: Logic.asteroids
        timerInterval: 50
        timerRunning: true
        onCollision: {
            console.log("HIT")
            Logic.destroyAsteroid(item)
            root.destroy()
        }
    }
}
