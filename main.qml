import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Particles

import Models 1.0

Window {
    id: rootWindow

    width: 800
    height: 800
    visible: true
    color: "black"
    title: qsTr("Pong")

    Ball {
        id: ball
        color: "orange"
        x: 200
        y: 100
        ballSize: 32
    }
    Timer {
        interval: 50
        repeat: true
        running: true
        onTriggered: emitter.emit(ball)
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

}
