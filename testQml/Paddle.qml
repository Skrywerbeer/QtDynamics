import QtQuick

Rectangle {
    id: root

    width: 100
    height: 20
    color: "lawngreen"

    Behavior on y {NumberAnimation {duration: 100}}
}
