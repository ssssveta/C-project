cmake_minimum_required(VERSION 3.16)
project(4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(TARGET_SOURCE_DIR ${CMAKE_SOURCE_DIR})

if(NOT DEFINED ENV{QGIS_PATH})
    set(QGIS_PATH /root/apps CACHE PATH "specify path to QGIS install directory")
endif()
message("QGIS_PATH is defined -- /root/dev/cpp/QGIS")

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS
    Widgets
    Core
    Gui
    Sql
    Xml
    REQUIRED)

link_directories(/root/apps/lib)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#if(ANDROID)
add_executable(4 main.cpp
                     mainwindow.cpp
                     mainwindow.h
                     mainwindow.ui
                     map.cpp
                     map.h
                    )

target_include_directories(4 PRIVATE
                                    /root/apps/include/qgis
                                    /usr/include/gdal)

target_link_directories(4 PRIVATE /root/apps/QGIS/lib)
target_link_libraries(4
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
