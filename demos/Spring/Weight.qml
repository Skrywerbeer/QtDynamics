import QtQuick
import QtDynamics

Rectangle {
    id: root

    function reset() {
        x = restingX
        y = restingY
        model.velocity.magnitude = 0
    }

    property real restingX: 0
    property real restingY: 0
    property real springConstant: 10
    property real frictionConstant: 0.2
    property alias mass: model.mass
    property alias displacment: displacementVector.magnitude

    x: restingX
    y: restingY
    width: 50
    height: 50
    radius: 25

    KineticModel {
        id: model
        running: !handle.active
        forces: [
            Vector {
                id: forceVector
                angle: displacementVector.angle + 180
                magnitude: displacementVector.magnitude*root.springConstant
            },
            Vector {
                id: friction
                angle: model.velocity.angle + 180
                magnitude: model.velocity.magnitude*root.frictionConstant
            }
        ]
    }
    DragHandler {
        id: handle
        xAxis.enabled: true
        yAxis.enabled: true
        onActiveChanged: model.velocity.magnitude = 0
    }
    Vector {
        id: displacementVector
        x: root.x - root.restingX
        y: root.y - root.restingY
    }
}
