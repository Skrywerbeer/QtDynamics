import QtQuick

Rectangle {
    id: root

    width: 20
    height: 100
    color: "orange"

    Behavior on y {NumberAnimation {duration: 100}}
}
