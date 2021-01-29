.import "global.js" as Global

function newGame() {
    Global.setRootItem(rootWindow)
    gameOver.visible = false
    ship.canPilot = true
    ship.focus = true
    spawnAsteroid(80,
                  80 + Math.random()*(rootWindow.width - 80) ,
                  80 + Math.random()*(rootWindow.height - 70))
    spawnAsteroid(60,
                  60 + Math.random()*(rootWindow.width - 60) ,
                  60 + Math.random()*(rootWindow.height - 60))
    spawnAsteroid(40,
                  40 + Math.random()*(rootWindow.width - 40) ,
                  40 + Math.random()*(rootWindow.height - 40))
}

function endGame() {
    ship.canPilot = false
    gameOver.visible = true
    for (let asteroid of Global.asteroids)
        asteroid.moving = false
}

function spawnAsteroid(size, X, Y) {
    Global.spawnAsteroid(size, X, Y)
    ship.collideables = Global.asteroids
}

function destroyAsteroid(asteroid) {
    Global.destroyAsteroid(asteroid)
    scoreBoard.incrementScore()
    ship.collideables = Global.asteroids
}
