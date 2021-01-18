import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Shapes

Window {
    id: root

    width: 640
    height: 480
    visible: true
    title: qsTr("Spring")

    ColumnLayout {
        id: controls
        ColumnLayout {
            Layout.topMargin: 10
            Text {
                Layout.alignment: Qt.AlignHCenter
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: "Mass: " + massSlider.value.toPrecision(2)
            }
            Slider {
                id: massSlider
                from: 0.1
                to: 10
            }
        }
        ColumnLayout {
            Text {
                Layout.alignment: Qt.AlignHCenter
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: "Spring constant: " + springSlider.value.toPrecision(2)
            }
            Slider {
                id: springSlider
                from: 1
                to: 100
            }
        }
        ColumnLayout {
            Text {
                Layout.alignment: Qt.AlignHCenter
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: "Friction: " + frictionSlider.value.toPrecision(2)
            }
            Slider {
                id: frictionSlider
                from: 0
                to: 10
            }
        }
        Button {
            Layout.alignment: Qt.AlignHCenter
            text: "Reset"
            onClicked: springWeight.reset()
        }
    }
    Shape {
        ShapePath {
            strokeWidth: 4
            strokeColor: "yellow"
            startX: springWeight.restingX + springWeight.width/2
            startY: springWeight.restingY + springWeight.height/2
            PathLine {
                x: springWeight.x + springWeight.width/2
                y: springWeight.y + springWeight.height/2
            }
        }
    }

    Weight {
        id: springWeight
        color: "royalblue"
        restingX: root.width/2 - width/2
        restingY: root.height/2 - height/2
        mass: massSlider.value
        springConstant: springSlider.value
        frictionConstant: frictionSlider.value
    }

}
