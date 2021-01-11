import QtQuick
import QtQuick.Window
import QtQuick.Particles
import QtQuick.Shapes

import Models

Window {
    id: rootWindow

    width: 800
    height: 800
    visible: true

    color: "black"
    title: qsTr("Pong")

    Ball {
        id: ballOrange
        color: "orange"
        x: 100
        y: 400
        ballSize: 32
        scaler: 3
    }
    Ball {
        id: ballGreen
        x: 250
        y: 250
        color: "lawngreen"
        ballSize: 24
        scaler: 2.3
        showVectors: ballOrange.showVectors
    }
    Ball {
        id: ballBlue
        x: 400
        y: 500
        color: "cornflowerblue"
        ballSize: 12
        scaler: 1
        showVectors: ballOrange.showVectors
    }
    Rectangle {
        id: sun
        anchors.centerIn: parent
        width: 48
        height: 48
        radius: 24
        gradient: RadialGradient {
            centerRadius: 100
            centerX: 50; centerY: 50
            focalX: centerX; focalY: centerY
            GradientStop {position: 0; color: Qt.lighter("yellow")}
            GradientStop {position: 0.6; color: "yellow"}
            GradientStop {position: 1; color: "white"}
        }
    }
    Timer {
        interval: 50
        repeat: true
        running: true
        onTriggered: {
            emitter.emit(ballGreen)
            emitter.emit(ballOrange)
            emitter.emit(ballBlue)
        }
    }
    ParticleSystem {
        id: partSys
    }
    Emitter {
        function emit(ball) {
            burst(1, ball.x + ball.width/2, ball.y + ball.height/2)
        }

        id: emitter
        enabled: false
        system: partSys
        emitRate: 10
        lifeSpan: 5000
        size: 8
        endSize: 16
    }
    ItemParticle {
        system: partSys
        fade: true
        delegate: Rectangle {
            width: 4
            height: 4
            radius: 2
            color: "white"
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            ballOrange.showVectors = ! ballOrange.showVectors
        }
    }
}
