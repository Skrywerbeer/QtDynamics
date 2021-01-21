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
        count: 41
        mass: 100
        damping: 0.8
        k: 50
    }
    Timer {
        interval: 1000
        running: true
        onTriggered: string.start()
    }
}
