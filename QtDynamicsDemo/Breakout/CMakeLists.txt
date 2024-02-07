cmake_minimum_required(VERSION 3.19)

project(Breakout
	LANGUAGES CXX
	VERSION 1.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS
	Core
	Quick
	REQUIRED)
qt_standard_project_setup(REQUIRES 6.5)

set(MODULE_QML
	main.qml
	Ball.qml
	Brick.qml
	Paddle.qml
	BrickWall.qml

	logic.js
)

qt_add_library(Breakout SHARED)
qt_add_qml_module(Breakout
	URI QtDynamicsDemo.Breakout
	QML_FILES ${MODULE_QML}
)
