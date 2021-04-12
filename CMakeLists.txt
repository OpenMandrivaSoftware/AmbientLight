cmake_minimum_required(VERSION 3.10.2)
project(ambient-light VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)

find_package(Qt5 5.15.0 CONFIG REQUIRED COMPONENTS Core DBus Sensors)
add_definitions(${QT_DEFINITIONS})
add_definitions(-DQT_DISABLE_DEPRECATED_BEFORE=0x050f00)

# FIXME why don't we get proper values from find_package Qt5 here?
include_directories(/usr/include/qt5 /usr/include/qt5/QtCore /usr/include/qt5/QtDBus /usr/include/qt5/QtSensors)
add_subdirectory(src)
