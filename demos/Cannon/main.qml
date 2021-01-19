import QtQuick 2.12
import QtQuick.Window 2.12

import "."

Window {
    width: Screen.width
    height: 400
    visible: true
    title: qsTr("Cannon")

    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        topPadding: 10
        font.pointSize: 18
        text: "Click the cannon."
    }

    Cannon {
        anchors {left: parent.left; bottom: parent.bottom}
    }
}
