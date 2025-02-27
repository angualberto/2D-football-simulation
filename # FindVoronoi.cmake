# FindVoronoi.cmake

find_path(VORONOI_INCLUDE_DIR
  NAMES voro++.hh
  PATHS ${CMAKE_CURRENT_LIST_DIR}/../../voro/src
  NO_DEFAULT_PATH
)

find_library(VORONOI_LIBRARY
  NAMES voro++
  PATHS ${CMAKE_CURRENT_LIST_DIR}/../../voro/src
  NO_DEFAULT_PATH
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Voronoi DEFAULT_MSG VORONOI_INCLUDE_DIR VORONOI_LIBRARY)

if(Voronoi_FOUND)
  set(Voronoi_INCLUDE_DIRS ${VORONOI_INCLUDE_DIR})
  set(Voronoi_LIBRARIES ${VORONOI_LIBRARY})
endif()

mark_as_advanced(VORONOI_INCLUDE_DIR VORONOI_LIBRARY)
