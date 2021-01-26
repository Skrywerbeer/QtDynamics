import QtQuick
import QtQuick.Window

import QtDynamics
import "logic.js" as Logic

Window {
    id: rootWindow

    width: 640
    height: 480
    visible: true
    title: qsTr("Asteroids")

    SpaceShip {
        id: ship

        x: parent.width/2 - width/2
        y: parent.height/2 - height/2
//        onShipDestroyed: Logic.endGame()
//        onShipDestroyed: console.log("CRASH!!!")
    }
    Text {
        id: scoreBoard

        function incrementScore() {
            score += 100
        }

        property int score: 0

        anchors {top: parent.top; right: parent.right}
        topPadding: 10
        rightPadding: 10
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pointSize: 24
        text: score
        Behavior on score {NumberAnimation {duration: 100}}
    }

    Component.onCompleted: {
        Logic.initLogicState(rootWindow, scoreBoard)
        Logic.newGame()
//        let comp = Qt.createComponent("SpaceShip.qml")
//        let ship = comp.createObject(rootWindow, {
//                                         x: 100,
//                                         y: 100,
//                                     })
//        console.log(ship)
    }
}
