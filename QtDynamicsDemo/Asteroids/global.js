.pragma library

let asteroids = Array()
let root

function setRootItem(item) {
    root = item
}

function spawnAsteroid(size, X, Y) {
    let comp = Qt.createComponent("Asteroid.qml")
    let asteroid = comp.createObject(root, {
                                         size: size,
                                         x: X - size/2,
                                         y: Y - size/2,
                                         rotation: Math.random()*360
                                     })
    asteroids.push(asteroid)
}

function destroyAsteroid(asteroid) {
    asteroids.splice(asteroids.indexOf(asteroid), 1)
    if (asteroid.size > 10) {
        spawnAsteroid(asteroid.size/2, asteroid.x, asteroid.y)
        spawnAsteroid(asteroid.size/2, asteroid.x, asteroid.y)
    }
    asteroid.destroy()
}
