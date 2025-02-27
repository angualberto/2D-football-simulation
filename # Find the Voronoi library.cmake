# Find the Voronoi library
find_path(VORONOI_INCLUDE_DIR voronoi/Voronoi.h)
find_library(VORONOI_LIBRARY NAMES voronoi)

if (VORONOI_INCLUDE_DIR AND VORONOI_LIBRARY)
    set(VORONOI_FOUND TRUE)
else()
    set(VORONOI_FOUND FALSE)
endif()

if (VORONOI_FOUND)
    message(STATUS "Found Voronoi: ${VORONOI_LIBRARY}")
    set(VORONOI_INCLUDE_DIRS ${VORONOI_INCLUDE_DIR})
    set(VORONOI_LIBRARIES ${VORONOI_LIBRARY})
else()
    message(FATAL_ERROR "Could not find Voronoi")
endif()

mark_as_advanced(VORONOI_INCLUDE_DIR VORONOI_LIBRARY)
