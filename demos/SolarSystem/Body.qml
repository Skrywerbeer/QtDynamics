import QtQuick

import QtDynamics

Rectangle {
    id: root

    property real size: 100
    property alias mass: model.mass
    property alias forces: model.forces
    property Body sun;

    width: size
    height: size
    radius: size/2

    KineticModel {
        id: model
        running: true
        velocity: Vector {
            angle: -45
            magnitude: sun !== null ?
                           Math.sqrt(1000*root.sun.mass/toSun.magnitude) : 0
        }
        onVelocityChanged: console.log("velocity angle: " + velocity.angle)
        forces: [
            Vector {
                id: gravity
                angle: toSun.angle
                magnitude: sun !== null ?
                               (1000*root.sun.mass*root.mass)/Math.pow(toSun.magnitude, 2) : 0
            }
        ]
    }
    Vector {
        id: toSun
        x: sun !== null ?
               (sun.x + sun.width/2) - (root.x + root.width/2) : 0
        y: root.sun !== null ?
               (sun.y + sun.height/2) - (root.y + root.height/2) : 0
    }
    VectorArrow {
        anchors.centerIn: parent
        target: toSun
        proportional: true
        lineWidth: 4
        color: "white"
    }
}
