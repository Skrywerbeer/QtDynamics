cmake_minimum_required(VERSION 3.19)

project(QtDynamicsDemos
	LANGUAGES CXX
	VERSION 1.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT_VERSION_MAJOR 6)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS
	Core
	Quick
	REQUIRED)

set(PROJECT_SOURCES
	main.cpp
	demos.qrc)

add_executable(QtDynamicsDemos
	${PROJECT_SOURCES})
target_link_libraries(QtDynamicsDemos PRIVATE
	Qt${QT_VERSION_MAJOR}::Core
	Qt${QT_VERSION_MAJOR}::Quick)

set(QML_IMPORT_PATH ${MODULE_LOCATION}
	CACHE STRING "Plugin import path"
	FORCE)
