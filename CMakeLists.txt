cmake_minimum_required(VERSION 3.19)

project(QtDynamics
	LANGUAGES CXX
	VERSION 0.1
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS
	Core
	Gui
	Quick
	REQUIRED
  )
qt_standard_project_setup(REQUIRES 6.5)
add_subdirectory(QtDynamics)
add_subdirectory(QtDynamicsDemo)
