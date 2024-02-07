cmake_minimum_required(VERSION 3.19)

project(Bounce
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
	Tracer.qml
)

qt_add_library(Bounce SHARED)
qt_add_qml_module(Bounce
	URI QtDynamicsDemo.Bounce
	VERSION 1.0
	QML_FILES ${MODULE_QML}
)
