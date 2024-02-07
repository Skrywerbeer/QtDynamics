import QtQuick 2.0

Item {
    id: root

    function buildWall() {
        const BRICK_WIDTH = root.width/root.columns
        const BRICK_HEIGHT = root.height/root.rows
        let brickComponent = Qt.createComponent("Brick.qml")
        for (let i = 0; i < root.rows; ++i) {
            let Y = i*BRICK_HEIGHT
            for (let j = 0; j < root.columns; ++j) {
                let X = j*BRICK_WIDTH
                let brick = brickComponent.createObject(root, {
                                                            x: X,
                                                            y: Y,
                                                            width: BRICK_WIDTH,
                                                            height: BRICK_HEIGHT
                                            })
                bricks.push(brick)
                brick.pressed.connect(destroyBrick)
            }
        }
        ball.collideableItems = root.bricks
    }
    function resizeBricks() {
        const BRICK_WIDTH = root.width/root.columns
        const BRICK_HEIGHT = root.height/root.rows
        let row = 0
        let column = 0
        for (let brick of bricks) {
            brick.width = BRICK_WIDTH
            brick.height = BRICK_HEIGHT
            brick.x = column*BRICK_WIDTH
            brick.y = row*BRICK_HEIGHT
            if (++column == root.columns) {
                column = 0
                if(++row == root.rows)
                    row = 0
            }
        }
    }
    function destroyBrick(brick) {
        bricks.splice(bricks.indexOf(brick), 1)
        brick.destroy()
        ball.collideableItems = root.bricks
    }

    property var bricks: Array()
    property int rows: 0
    property int columns: 0

    Connections {
        function onWidthChanged() {root.resizeBricks()}
        function onHeightChanged() {root.resizeBricks()}
    }
}
