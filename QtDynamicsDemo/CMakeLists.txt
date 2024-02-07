cmake_minimum_required(VERSION 3.19)

project(demos
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

set(PROJECT_SOURCES
	main.cpp
)
set(MODULE_QML
	demoLoader.qml
)

add_subdirectory(Asteroids)
add_subdirectory(Bounce)
add_subdirectory(Breakout)
add_subdirectory(Cannon)
add_subdirectory(CollisionDrag)
add_subdirectory(SolarSystem)
add_subdirectory(Spring)
add_subdirectory(Tension)

qt_add_executable(demos
	${PROJECT_SOURCES})
qt_add_qml_module(demos
	URI QtDynamicsDemo
	VERSION 0.1
	QML_FILES ${MODULE_QML}
)
target_link_libraries(demos PRIVATE
	Qt6::Core
	Qt6::Quick

	QtDynamics

	Asteroids
	Bounce
	Breakout
	Cannon
	CollisionDrag
	SolarSystem
	Spring
	Tension
)
