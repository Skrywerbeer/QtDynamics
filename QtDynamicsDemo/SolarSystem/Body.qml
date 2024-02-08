import QtQuick
import QtQuick.Particles

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
            angle: toSun.angle - 90;
            magnitude: sun !== null ?
                           Math.sqrt(1000*root.sun.mass/toSun.magnitude) : 0
        }
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
    // VectorArrow {
    //     anchors.centerIn: parent
    //     target: toSun
    //     proportional: true
    //     lineWidth: 4
    //     color: "white"
    // }
    // ParticleSystem {
    //     id: partSys;
    // }
    // Emitter {
    //     id: emitter;
    //     system: partSys;

    //     enabled: false;
    //     lifeSpan: 5000;
    //     lifeSpanVariation: 100;
    //     emitRate: 100;
    // }
    // ItemParticle {
    //     system: partSys;
    //     delegate: Rectangle {
    //         width: 4;
    //         height: width;
    //         radius: width/2;
    //         color: Qt.lighter(root.color);
    //     }
    // }
    // Timer {
    //     interval: 100;
    //     running: true;
    //     repeat: true;
    //     onTriggered: function() {
    //         emitter.burst(1, emitter.x, emitter.y);
    //     }
    // }

}
