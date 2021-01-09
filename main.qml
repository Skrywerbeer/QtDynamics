import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Particles

import Models 1.0

Window {
    id: root

    width: 400
    height: 400
    visible: true
    color: "black"
    title: qsTr("Pong")

    Repeater {
        id: ballRepeater
        model: 10

        Ball {
            id: ball
            color: "orange"
            x: model.x
            y: model.y
            size: 32

            KinematicModel {
                id: model
                x: root.width*Math.random()
                y: root.height*Math.random()/2
                minimumX: 0
                maximumX: root.width - ball.width
                minimumY: 0
                maximumY: root.height - ball.height
                velocityX: (index % 2) == 0 ? 100 + Math.random()*200 : -100 - Math.random()*200
                accelerationY: 500
                running: true
                onMinimumXReached: velocityX *= -0.9
                onMaximumXReached: velocityX *= -0.9
                onMinimumYReached: velocityY *= -0.9
                onMaximumYReached: velocityY *= -0.9
            }
        }
    }
    Timer {
        interval: 50
        repeat: true
        running: true
        onTriggered: {
            for (let i = 0; i < ballRepeater.count; ++i)
                emitter.emit(ballRepeater.itemAt(i))
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
        lifeSpan: 500
    }
    ItemParticle {
        system: partSys
        fade: false
        delegate: Rectangle {
            width: 4
            height: 4
            radius: 2
            color: "white"
        }
    }

}
