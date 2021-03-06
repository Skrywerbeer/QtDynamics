cmake_minimum_required(VERSION 3.14)

project(QtDynamics LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 COMPONENTS
	Core
	Gui
	Quick
	REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS
	Core
	Gui
	Quick
	REQUIRED)

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

	qtdynamicsplugin.cpp qtdynamicsplugin.h
)

set(MODULE_LOCATION "${CMAKE_CURRENT_BINARY_DIR}/imports")
set(MODULE_INSTALL_LOCATION "lib/qmlImports/QtDynamics")

set(BUILD_SHARED_LIBS ON)

qt6_add_qml_module(qtdynamicsplugin
	OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	VERSION 1.0
	URI "QtDynamics"
	SOURCES ${PROJECT_SOURCES})

target_link_libraries(qtdynamicsplugin PRIVATE
	Qt${QT_VERSION_MAJOR}::Core
	Qt${QT_VERSION_MAJOR}::Gui
	Qt${QT_VERSION_MAJOR}::Quick)
target_sources(qtdynamicsplugin PRIVATE ${PROJECT_SOURCES})

set_target_properties(qtdynamicsplugin PROPERTIES
	QT_QML_MODULE_VERSION 1.0
	QT_QML_MODULE_URI QtDynamics)
qt6_qml_type_registration(qtdynamicsplugin)

add_custom_command(TARGET qtdynamicsplugin POST_BUILD
	COMMAND mkdir -p "${MODULE_LOCATION}/QtDynamics/"
	COMMAND cp $<TARGET_FILE:qtdynamicsplugin> "${MODULE_LOCATION}/QtDynamics/"
	COMMAND cp qmldir "${MODULE_LOCATION}/QtDynamics/"
	COMMAND qmlplugindump-qt6 -nonrelocatable QtDynamics 1.0 ${MODULE_LOCATION} > ${MODULE_LOCATION}/QtDynamics/plugins.qmltypes
	)

target_compile_definitions(qtdynamicsplugin
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

install(TARGETS qtdynamicsplugin
	RUNTIME DESTINATION ${MODULE_INSTALL_LOCATION}
	BUNDLE DESTINATION ${MODULE_INSTALL_LOCATION}
	LIBRARY DESTINATION ${MODULE_INSTALL_LOCATION})

add_subdirectory(demos)
