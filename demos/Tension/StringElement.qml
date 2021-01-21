import QtQuick

import QtDynamics

Rectangle {
    id: root

    property bool running
    property alias dm: model.mass
    property real k: 1
    property real mu: 0.5
    property StringElement previousElement
    property StringElement nextElement

    width: 6
    height: 6
    radius: 3
    border {width: 2; color: "royalblue"}

    KineticModel {
        id: model
        running: !handle.active// && root.running
//        running: true
        forces: [
            Vector {
                angle: thisToPrevious.angle
                magnitude: thisToPrevious.magnitude*k
            },
            Vector {
                angle: thisToNext.angle
                magnitude: thisToNext.magnitude*k
            },
            Vector {
                id: friction
                angle: model.velocity !== null ?
                           model.velocity.angle + 180 : 0
                magnitude: model.velocity !== null ?
                               model.velocity.magnitude*mu : 0
            },
            Vector {
                id: weight
                magnitude: (root.nextElement !== null) && (root.previousElement !== null) ?
                               10*root.dm : 0
                angle: 90
            }
        ]
    }
    Vector {
        id: thisToPrevious
        x: previousElement !== null ?
               (previousElement.x + previousElement.width/2) - (root.x + root.width/2) : 0
        y: previousElement !== null ?
               (previousElement.y + previousElement.height/2) - (root.y + root.height/2) : 0
    }
    Vector {
        id: thisToNext
        x: nextElement !== null ?
             (nextElement.x + nextElement.width/2) - (root.x + root.width/2) : 0
        y: nextElement !== null ?
               (nextElement.y + nextElement.height/2) - (root.y + root.height/2) : 0
    }
    VectorArrow {
        anchors.centerIn: parent
        target: thisToPrevious
        lineWidth: 4
        color: "blue"
        proportional: false
        length: 10
    }
    VectorArrow {
        anchors.centerIn: parent
        target: thisToNext
        lineWidth: 4
        color: "red"
        proportional: false
        length: 10
    }
    DragHandler {
        id: handle
        xAxis.enabled: false
//        yAxis.enabled: (root.previousElement !== null) &&
//                       (root.nextElement !== null) ? true : false
    }
}
