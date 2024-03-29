import QtQuick
import QtQuick.Particles

Item {
    id: root

    required property var traceItem
    property color traceColor: "black"
    property alias interval: timer.interval;

    ParticleSystem {
        id: partSys
    }
    Emitter {
        id: emitter
        system: partSys
        enabled: false
        lifeSpan: 5000
    }
    ItemParticle {
        system: partSys
        delegate: Rectangle {
            width: 4
            height: 4
            radius: 1
            color: traceColor
        }
    }
    Timer {
        id: timer;

        interval: 50
        repeat: true
        running: true
        onTriggered: {
            const point = mapToItem(root.parent, traceItem.x, traceItem.y)
            emitter.burst(1, point.x + traceItem.width/2, point.y + traceItem.height/2)
        }
    }
}
