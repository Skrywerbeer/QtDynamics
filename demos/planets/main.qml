import QtQuick
import QtQuick.Window
import QtQuick.Particles
import QtQuick.Shapes


Window {
    id: rootWindow

    width: 800
    height: 800
    visible: true

    color: "black"
    title: qsTr("Planets")

    Planet {
        id: planetOrange
        color: "orange"
        x: 100
        y: 400
        ballSize: 32
        scaler: 4
    }
    Planet {
        id: planetGreen
        x: 200 - ballSize/2
        y: 400 - ballSize/2
        color: "lawngreen"
        ballSize: 24
        scaler: 2
        showVectors: planetOrange.showVectors
    }
    Planet {
        id: planetBlue
        x: 400
        y: 500
        color: "cornflowerblue"
        ballSize: 12
        scaler: 1
        showVectors: planetOrange.showVectors
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
            emitter.emit(planetGreen)
            emitter.emit(planetOrange)
            emitter.emit(planetBlue)
        }
    }
    ParticleSystem {
        id: partSys
    }
    Emitter {
        function emit(planet) {
            burst(1,
                  planet.x + planet.width/2,
                  planet.y + planet.height/2)
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
