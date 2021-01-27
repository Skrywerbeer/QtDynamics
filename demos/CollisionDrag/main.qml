import QtQuick
import QtQuick.Window

import QtDynamics

Window {
    id: root

    width: 640
    height: 480
    visible: true
    title: qsTr("CollisionDrag")

    Rectangle {
        id: rect1
        x: 250
        y: 140
        width: 100
        height: 100
        color: "blue"

        DragHandler {}
        AABBCollisionDetector {id: detector1}

        onXChanged: {
            if (detector1.collides(rect2))
                rect1.color = "red"
            else
                rect1.color = "blue"
        }
        onYChanged: {
            if (detector1.collides(rect2))
                rect1. color = "red"
            else
                color = "blue"
        }
    }

    Rectangle {
        id: parentRect
        x: 100
        y: 100
        width: 100
        height: 100
        color: "transparent"
        border {width: 1; color: "black"}

        Rectangle {
            id: rect2
            width: 80
            height: 60
            color: "blue"

            DragHandler {}
            AABBCollisionDetector {id: detector2}

            onXChanged: {
                if (detector2.collides(rect1))
                    rect2.color = "red"
                else
                    rect2.color = "blue"
            }
            onYChanged: {
                if (detector2.collides(rect1))
                    rect2.color = "red"
                else
                    rect2.color = "blue"
            }
        }
    }
}
