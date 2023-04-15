cmake_minimum_required(VERSION 3.16)
project(Map)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(TARGET_SOURCE_DIR ${CMAKE_SOURCE_DIR})


if(NOT DEFINED ENV{QGIS_PATH})
    set(QGIS_PATH /root/apps CACHE PATH "specify path to QGIS install directory")
endif()
message("QGIS_PATH is defined -- /root/dev/cpp/QGIS")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Xml
        Sql
        REQUIRED)

link_directories(/root/apps/lib)


set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(Map  main.cpp
                    map.cpp
                    map.h)

target_include_directories(Map PRIVATE
                                    /root/apps/include/qgis
                                    /usr/include/gdal)

target_link_directories(Map PRIVATE /root/apps/QGIS/lib)
target_link_libraries(Map
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Xml
        Qt5::Sql
        qgis_native
        qgis_core
        qgis_app
        qgis_gui
        gdal
        )


