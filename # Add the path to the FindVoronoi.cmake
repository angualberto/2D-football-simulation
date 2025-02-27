# Add the path to the FindVoronoi.cmake file
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_LIST_DIR}/../../voro/cmake/Modules)

find_package(Voronoi REQUIRED)
