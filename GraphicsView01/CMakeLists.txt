cmake_minimum_required(VERSION 3.26)

project(GraphicsView01 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

# 添加源代码和touwwenj
file(GLOB SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*")
# 添加资源文件
file(GLOB RESOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/resources/*.qrc")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(GraphicsView01
        MANUAL_FINALIZATION
        ${SOURCE_FILES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET GraphicsView01 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(GraphicsView01 SHARED
            ${SOURCE_FILES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(GraphicsView01
            ${SOURCE_FILES}
            ${RESOURCE_FILES}
        )
    endif()
endif()

qt5_add_resources(QRC_FILES ${RESOURCE_FILES})
target_link_libraries(GraphicsView01 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(GraphicsView01 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(GraphicsView01)
endif()
