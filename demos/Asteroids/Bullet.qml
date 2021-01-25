import QtQuick

import QtDynamics

Image {
    id: root

    property real shipVelocity: 0

    width: 20
    height: 20
    source: "bullet.png"

    KinematicModel {
        id: model

        running: true
        velocity: Vector {
            angle: root.rotation
            magnitude: 300 + shipVelocity
        }
        onDisplacementChanged: {
            if (displacement.magnitude >= 300)
                root.destroy()
        }
    }
//    onXChanged: {
//        if ((x < 0) || x > (root.parent.width))
//            destroy()
//    }
//    onYChanged: {
//        if ((y < 0 )|| (x > root.parent.height))
//            destroy()
//    }
}
