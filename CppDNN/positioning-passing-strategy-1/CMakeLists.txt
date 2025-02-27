cmake_minimum_required(VERSION 3.10)

project(PositioningPassingStrategy)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS} src)

file(GLOB SOURCES
    src/*.cpp
    src/utils/*.cpp
)

add_executable(PositioningPassingStrategy ${SOURCES})

target_link_libraries(PositioningPassingStrategy ${OpenCV_LIBS})