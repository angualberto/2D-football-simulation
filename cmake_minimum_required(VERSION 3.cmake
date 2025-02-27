cmake_minimum_required(VERSION 3.10)
project(Cyrus2DBase)

# ...existing code...

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/scripts")
find_package(VoronoiLibrary REQUIRED)

include_directories(${VoronoiLibrary_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${VoronoiLibrary_LIBRARIES})

# ...existing code...
