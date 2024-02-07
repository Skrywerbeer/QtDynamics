import QtQuick

Rectangle {
    id: root

    signal pressed(Item brick)

    width: 64
    height: 24
    color: "royalblue"
    border {width: 2; color: Qt.darker(root.color)}

    MouseArea {
        anchors.fill: parent
        onClicked: root.pressed(root)
    }
}
