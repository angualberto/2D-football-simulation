# Add the CMakeModules directory to the module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(Voronoi REQUIRED)

add_executable(sample_coach
  sample_freeform_message.cpp
  sample_coach.cpp
  main_coach.cpp
  )

target_include_directories(sample_coach
  PRIVATE
    ${PROJECT_SOURCE_DIR}/src/
    ${PROJECT_SOURCE_DIR}/src/coach
    ${PROJECT_BINARY_DIR}
  PUBLIC
    ${Boost_INCLUDE_DIRS}
    ${LIBRCSC_INCLUDE_DIR}
    ${Voronoi_INCLUDE_DIRS}  # Added Voronoi include directories
  )

find_package(OpenCV REQUIRED)

target_link_libraries(sample_coach
  PUBLIC
    ${LIBRCSC_LIB}
    Boost::system
    ZLIB::ZLIB
    ${OpenCV_LIBS}
    ${Voronoi_LIBRARIES}  # Added Voronoi libraries
  )

set_target_properties(sample_coach
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin
  )
