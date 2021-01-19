import QtQuick

Image {
    id: root

    readonly property var ballComponent: Qt.createComponent("CannonBall.qml")
    property var ball

    source: "./cannon.png"
    z: 1

    MouseArea {
        anchors.fill: parent
        onClicked: {
            ball = ballComponent.createObject(root.parent, {
                                                  x: root.x + (root.width - 48)/2,
                                                  y: root.y + (root.height - 48)/2
                                              })
        }
    }
}
