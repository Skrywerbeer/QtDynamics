import QtQuick

Window {
    id: rootWindow

    width: 300
    height: 600
    visible: true

    BrickWall {
        id: wall

        width: parent.width
        height: 100
        rows: 3
        columns: 5
        Component.onCompleted: buildWall()
    }
    Ball {
        id: ball

        x: (rootWindow.width - width)/2
        y:  rootWindow.height - height
    }
    Paddle {
        id: paddle

    }


}
