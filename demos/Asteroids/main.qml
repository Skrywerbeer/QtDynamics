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

        onShipDestroyed: Logic.endGame()
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
    Text {
        id: gameOver
        anchors.centerIn: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pointSize: 24
        text: "GAME OVER"

        Keys.onPressed: {
            Logic.newGame()
        }
    }


    Component.onCompleted: {
        Logic.newGame()
    }
}
