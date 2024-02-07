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
	REQUIRED)
qt_standard_project_setup(REQUIRES 6.5)

set(PROJECT_SOURCES
	mechanicsmodel.cpp mechanicsmodel.h
	kinematicmodel.cpp kinematicmodel.h
	kineticmodel.cpp kineticmodel.h

	vector.cpp vector.h

	vectorarrow.cpp vectorarrow.h
	arrownode.cpp arrownode.h
	arrowbodynode.cpp arrowbodynode.h
	arrowheadnode.cpp arrowheadnode.h

	collisiondetector.cpp collisiondetector.h
	aabbcollisiondetector.cpp aabbcollisiondetector.h
	satcollisiondetector.cpp satcollisiondetector.h

	qtdynamicsplugin.cpp qtdynamicsplugin.h
)

set(BUILD_SHARED_LIBS ON)

qt_add_library(QtDynamics SHARED)
qt_add_qml_module(QtDynamics
	URI QtDynamics
	VERSION 1.0
	SOURCES ${PROJECT_SOURCES})

target_link_libraries(QtDynamics PRIVATE
	Qt6::Core
	Qt6::Gui
	Qt6::Quick)
target_sources(QtDynamics PRIVATE ${PROJECT_SOURCES})
