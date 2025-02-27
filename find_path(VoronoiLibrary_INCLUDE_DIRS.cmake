find_path(VoronoiLibrary_INCLUDE_DIRS
  NAMES voro++.hh
  PATHS ${CMAKE_CURRENT_LIST_DIR}/../../voro/src
)

find_library(VoronoiLibrary_LIBRARIES
  NAMES voro++
  PATHS ${CMAKE_CURRENT_LIST_DIR}/../../voro/src
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(VoronoiLibrary DEFAULT_MSG
  VoronoiLibrary_INCLUDE_DIRS
  VoronoiLibrary_LIBRARIES
)

if(VoronoiLibrary_FOUND)
  set(VoronoiLibrary_INCLUDE_DIRS ${VoronoiLibrary_INCLUDE_DIRS})
  set(VoronoiLibrary_LIBRARIES ${VoronoiLibrary_LIBRARIES})
endif()
