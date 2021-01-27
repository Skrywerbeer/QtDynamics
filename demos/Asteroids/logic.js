.import "global.js" as Global

function newGame() {
    gameOver.visible = false
    ship.canPilot = true
    spawnAsteroid(80,
                  Math.random()*(rootWindow.width - 80) ,
                  Math.random()*(rootWindow.height - 80))
    spawnAsteroid(60,
                  Math.random()*(rootWindow.width - 60) ,
                  Math.random()*(rootWindow.height - 60))
    spawnAsteroid(40,
                  Math.random()*(rootWindow.width - 40) ,
                  Math.random()*(rootWindow.height - 40))
}

function endGame() {
    gameOver.visible = true
    ship.canPilot = false
    for (let asteroid of Global.asteroids)
        asteroid.moving = false
//        asteroid.destroy()
}

function spawnAsteroid(size, X, Y) {
    let comp = Qt.createComponent("Asteroid.qml")
    let asteroid = comp.createObject(rootWindow, {
                                         size: size,
                                         x: X - size/2,
                                         y: Y - size/2,
                                         rotation: Math.random()*360
                                     })
    Global.asteroids.push(asteroid)
    ship.collideables = Global.asteroids
}

function destroyAsteroid(asteroid) {
    console.log(Global.asteroids.splice(Global.asteroids.indexOf(asteroid), 1))
    scoreBoard.incrementScore()
    if (asteroid.size > 10) {
        spawnAsteroid(asteroid.size/2, asteroid.x, asteroid.y)
        spawnAsteroid(asteroid.size/2, asteroid.x, asteroid.y)
    }
}
