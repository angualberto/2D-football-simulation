# VoronoiConfig.cmake

include(CMakeFindDependencyMacro)

find_path(VORONOI_INCLUDE_DIR
  NAMES voro++.hh
  PATHS ${CMAKE_CURRENT_LIST_DIR}/../src
  NO_DEFAULT_PATH
)

find_library(VORONOI_LIBRARY
  NAMES voro++
  PATHS ${CMAKE_CURRENT_LIST_DIR}/../src
  NO_DEFAULT_PATH
)

if(NOT VORONOI_INCLUDE_DIR OR NOT VORONOI_LIBRARY)
  message(FATAL_ERROR "Could not find Voronoi library")
endif()

set(Voronoi_INCLUDE_DIRS ${VORONOI_INCLUDE_DIR})
set(Voronoi_LIBRARIES ${VORONOI_LIBRARY})

mark_as_advanced(VORONOI_INCLUDE_DIR VORONOI_LIBRARY)
