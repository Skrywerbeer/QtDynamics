.pragma library

let asteroids = Array()

let root
let board

function initLogicState(window, scoreBoard) {
    root = window
    board = scoreBoard
}

function newGame() {
    spawnAsteroid(80,
                  Math.random()*(root.width - 80) ,
                  Math.random()*(root.height - 80))
    spawnAsteroid(80,
                  Math.random()*(root.width - 80) ,
                  Math.random()*(root.height - 80))
    spawnAsteroid(80,
                  Math.random()*(root.width - 80) ,
                  Math.random()*(root.height - 80))
}

function endGame() {
    for (let asteroid of asteroids)
        asteroid.moving = false
}

function spawnAsteroid(size, X, Y) {
    let comp = Qt.createComponent("Asteroid.qml")
    let asteroid = comp.createObject(root, {
                                         size: size,
                                         x: X - size/2,
                                         y: Y - size/2,
                                         rotation: Math.random()*100
                                     })
    asteroids.push(asteroid)
}

function destroyAsteroid(asteroid) {
    asteroids.splice(asteroids.indexOf(asteroid), 1)
    board.incrementScore()
    if (asteroid.size > 10) {
        spawnAsteroid(asteroid.size/2, asteroid.x, asteroid.y)
        spawnAsteroid(asteroid.size/2, asteroid.x, asteroid.y)
    }
    asteroid.destroy()
}
