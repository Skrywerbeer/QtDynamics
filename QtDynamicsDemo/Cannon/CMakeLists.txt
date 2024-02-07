cmake_minimum_required(VERSION 3.19)

project(Cannon
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
	Cannon.qml
	CannonBall.qml
	Tracer.qml
)

set(MODULE_RESOURCES
	cannon.png
	cannon.svg
	cannonball.png
	cannonball.svg
)

qt_add_library(Cannon SHARED)
qt_add_qml_module(Cannon
	URI QtDynamicsDemo.Cannon
	VERSION 1.0
	QML_FILES ${MODULE_QML}
	RESOURCES ${MODULE_RESOURCES}
)
