import QtQuick
import QtQuick.Window

import QtDynamics

Window {
    id: root

    width: 640
    height: 480
    visible: true
    title: qsTr("CollisionDrag")

    component Mark : Rectangle {
        required property Rectangle markedItem
        x: markedItem.x
        y: markedItem.y
        width: markedItem.width
        height: markedItem.height
        color: "transparent"
        border {width: 1; color: "black"}
    }
    Mark {
        markedItem: rect1
    }
    Mark {
        markedItem: rect2
    }

    Rectangle {
        id: rect1
        x: 250
        y: 140
        width: 100
        height: 100
        color: "blue"
        rotation: 45
        DragHandler {}
//        AABBCollisionDetector {id: detector1}

        SATCollisionDetector {
            id: detector1
//            items: rect2
//            timerRunning: true
//            timerInterval: 1000
        }

        onXChanged: {
            console.log("x: " + x)
            if (detector1.collides(rect2))
                rect1.color = "red"
            else
                rect1.color = "blue"
        }
        onYChanged: {
            console.log("y: " + y)
            if (detector1.collides(rect2))
                rect1. color = "red"
            else
                color = "blue"
        }
    }

//    Rectangle {
//        id: parentRect
//        x: 100
//        y: 100
//        width: 100
//        height: 100
//        color: "transparent"
//        border {width: 1; color: "black"}

        Rectangle {
            id: rect2
            width: 80
            height: 50
            color: "blue"
//            rotation: 45
            rotation: 10

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
//    }
}
