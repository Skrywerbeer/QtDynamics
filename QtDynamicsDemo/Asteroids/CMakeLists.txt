cmake_minimum_required(VERSION 3.19)

project(Asteroids
	LANGUAGES CXX
	VERSION 1.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS
	Core
	Quick
	REQUIRED)
qt_standard_project_setup(REQUIRES 6.5)

set(MODULE_QML
	main.qml
	Asteroid.qml
	Bullet.qml
	SpaceShip.qml

	global.js
	logic.js
)

set(MODULE_RESOURCES
	asteroid1.png
	asteroid1.svg
	bullet.png
	bullet.svg

	spaceship_engine_off.png
	spaceship_engine_off.svg
	spaceship_engine_on.png
	spaceship_engine_on.svg
)

qt_add_library(Asteroids SHARED)
qt_add_qml_module(Asteroids
	URI QtDynamicsDemo.Asteroids
	VERSION 1.0
	QML_FILES ${MODULE_QML}
	RESOURCES ${MODULE_RESOURCES}
)
