import QtQuick
import QtQuick.Window

import QtDynamics

Window {
    id: rootWindow

    width: 640
    height: 480
    visible: true
    title: qsTr("Bounce")

    Text {
        anchors {top: parent.top; horizontalCenter: parent.horizontalCenter}
        topPadding: 10
        width: contentWidth/2
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.WordWrap
        color: "black"
        font.pointSize: 14
        text: "Press and hold the left mouse button to " +
              "accelerate the ball towards the cursor"
    }

    Ball {
        id: ball

        property bool followMouse: false

        x: rootWindow.width/2 - width/2
        y: rootWindow.height - height

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
            }
            acceleration: Vector {
                id: accVec
                angle: ball.followMouse ? mouseVector.angle : 90
                magnitude: 400
            }
            onMinimumXReached: velVec.x = -k*velVec.x
            onMaximumXReached: velVec.x = -k*velVec.x

            onMinimumYReached: velVec.y = -k*velVec.y
            onMaximumYReached: velVec.y = -k*velVec.y
        }
    }
    Rectangle {
        anchors {
            top: parent.top; right: parent.right
            topMargin: 4; rightMargin: 4}
        width: 100
        height: 100
        radius: 50
        color: "transparent"
        border {width: 2; color: "darkgrey"}

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

        Vector {
            id: mouseVector
            x: mouseArea.mouseX - (ball.x + ball.width/2)
            y: mouseArea.mouseY - (ball.y + ball.height/2)
        }

        onPressed: ball.followMouse = true
        onReleased: ball.followMouse = false
    }
    Tracer {
        traceItem: ball
        traceColor: "blue"
    }
}
