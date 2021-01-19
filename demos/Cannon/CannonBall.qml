import QtQuick

import QtDynamics

Image {
    id: root

    source: "./cannonball.png"
    width: 48
    height: 48

    KineticModel {
        id: model

        running: true
        velocity: Vector {angle: -35; magnitude: 1000}
        forces: [Vector {angle: 90; magnitude: 800}]
    }

    onXChanged: {
        if (x > parent.width)
            root.destroy()
    }
    onYChanged: {
        if (y > parent.height)
            root.destroy()
    }
}
