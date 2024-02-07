import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: Screen.width
    height: 480
    visible: true
    title: qsTr("Tension")

    String {
        id: string
        y: parent.height/2
        count: 101
        mass: 200
        damping: 0.4
        k: 100
    }
    Timer {
        interval: 1000
        running: true
        onTriggered: string.start()
    }
}
