import QtQuick
import QtQuick.Window

import QtQuick.Particles 2.12

import QtDynamics

Window {
    id: rootWindow

    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Text {
        anchors {top: parent.top; horizontalCenter: parent.horizontalCenter}
        topPadding: 10
        width: contentWidth/2
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.WordWrap
        color: "black"
        font.pointSize: 14
        text: "Press and hold the mouse to accelerate the ball towards the mouse"
    }

    Ball {
        id: ball

        property bool followMouse: false

        KinematicModel {
            id: model

            property real k: 0.7

            running: true
            minimumX: 0
            maximumX: rootWindow.width - ball.width
            minimumY: 0
            maximumY: rootWindow.height - ball.height
            velocity: Vector {
                id: velVec
                angle: 0
                magnitude: 100
            }
            acceleration: Vector {
                id: accVec
                angle: 90
                magnitude: 400
            }
            onMinimumXReached: velVec.xComponent = -k*velVec.xComponent
            onMaximumXReached: velVec.xComponent = -k*velVec.xComponent

            onMinimumYReached: velVec.yComponent = -k*velVec.yComponent
            onMaximumYReached: velVec.yComponent = -k*velVec.yComponent
        }
        onXChanged: {
            if (followMouse) {
                accVec.xComponent = mouseArea.mouseX - (ball.x + ball.width/2)
                accVec.yComponent = mouseArea.mouseY - (ball.y + ball.height/2)
            }
        }
        onYChanged: {
            if (followMouse) {
                accVec.xComponent = mouseArea.mouseX - (ball.x + ball.width/2)
                accVec.yComponent = mouseArea.mouseY - (ball.y + ball.height/2)
            }
        }
    }
    Rectangle {
        anchors {top: parent.top; right: parent.right}
        width: 100
        height: 100
        radius: 50
        color: "transparent"
        border {width: 2; color: "black"}

        VectorArrow {
            anchors.centerIn: parent
            target: velVec
            proportional: false
            length: 30
            lineWidth: 4
            color: "steelblue"
        }
        VectorArrow {
            anchors.centerIn: parent
            target: accVec
            proportional: false
            length: 30
            lineWidth: 4
            color: "orange"
        }
    }
    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onPressed: {
            ball.followMouse = true
        }
        onReleased: {
            ball.followMouse = false
            accVec.magnitude = 400
            accVec.angle = 90
        }
    }
    Tracer {
        traceItem: ball
        traceColor: "blue"
    }
}
