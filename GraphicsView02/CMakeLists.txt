cmake_minimum_required(VERSION 3.25)

project(GraphicsView02 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

# 设定源文件和资源路径
file(GLOB SOURCE_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*"
    "${CMAKE_CURRENT_SOURCE_DIR}/ui/*")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(GraphicsView02
        MANUAL_FINALIZATION
        ${SOURCE_FILES}
    )
else()
    if(ANDROID)
        add_library(GraphicsView02 SHARED
            ${SOURCE_FILES}
        )
    else()
        add_executable(GraphicsView02
            ${SOURCE_FILES}
        )
    endif()
endif()

target_link_libraries(GraphicsView02 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(GraphicsView02 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(GraphicsView02)
endif()
