import QtQuick 2.12
import QtQuick.Window 2.12

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
        mass: 2000
    }
    Body {
        id: mars

        sun: sunBody
        size: 20
        x: 250
        y: 250
        color: "firebrick"
        mass: 200
    }
    Body {
        id: mars2

        sun: sunBody
        size: 60
        x: 150
        y: 150
        color: "steelblue"
        mass: 200
    }
}
