import QtQuick
import QtQuick.Window

import QtDynamicsDemo.Bounce

Window {
    width: 800
    height: 800
    visible: true
    title: qsTr("SolarSystem")
    color: "black"

    Body {
        id: sunBody
        anchors.centerIn: parent
        color: "yellow"
        size: 50
        mass: 10000
    }
    Body {
        id: littleGrey;

        sun: sunBody
        size: 20
        x: 250
        y: 350
        color: "lightgrey";
        mass: 10
    }
    Body {
        id: mediumRed

        sun: sunBody
        size: 30
        x: 250
        y: 250
        color: "firebrick"
        mass: 300
    }
    Body {
        id: bigBlue

        sun: sunBody
        size: 60
        x: 150
        y: 150
        color: "steelblue"
        mass: 2000
    }

    Tracer {
        traceItem: littleGrey;
        traceColor: Qt.lighter(bigBlue.color);
        interval: 200;
    }
    Tracer {
        traceItem: bigBlue;
        traceColor: Qt.lighter(bigBlue.color);
        interval: 100;
    }
    Tracer {
        traceItem: mediumRed;
        traceColor: Qt.lighter(mediumRed.color);
        interval: 100;
    }
}
