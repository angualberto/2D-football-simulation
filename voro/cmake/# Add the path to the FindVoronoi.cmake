# Add the path to the FindVoronoi.cmake file
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_LIST_DIR}/../../voro/cmake/Modules)

# Add the path to the VoronoiConfig.cmake file
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${CMAKE_CURRENT_LIST_DIR}/../../voro/cmake)

find_package(Voronoi REQUIRED)
