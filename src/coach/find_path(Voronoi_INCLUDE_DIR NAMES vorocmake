find_path(Voronoi_INCLUDE_DIR NAMES voronoi/voronoi.h)
find_library(Voronoi_LIBRARY NAMES voronoi)

if (Voronoi_INCLUDE_DIR AND Voronoi_LIBRARY)
    set(Voronoi_FOUND TRUE)
else()
    set(Voronoi_FOUND FALSE)
endif()

if (Voronoi_FOUND)
    message(STATUS "Found Voronoi: ${Voronoi_LIBRARY}")
    set(Voronoi_LIBRARIES ${Voronoi_LIBRARY})
    set(Voronoi_INCLUDE_DIRS ${Voronoi_INCLUDE_DIR})
else()
    message(FATAL_ERROR "Could not find Voronoi")
endif()

mark_as_advanced(Voronoi_INCLUDE_DIR Voronoi_LIBRARY)
