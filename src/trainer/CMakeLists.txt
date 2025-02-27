add_executable(sample_trainer
  sample_trainer.cpp
  main_trainer.cpp
  )

target_include_directories(sample_trainer
  PRIVATE
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/trainer
    ${PROJECT_BINARY_DIR}
  PUBLIC
    ${Boost_INCLUDE_DIRS}
    ${LIBRCSC_INCLUDE_DIR}
  )

target_link_libraries(sample_trainer
  PUBLIC
    ${LIBRCSC_LIB}
    Boost::system
    ZLIB::ZLIB
  )

set_target_properties(sample_trainer
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin
  )

# Ensure the source file exists
configure_file(${CMAKE_SOURCE_DIR}/src/trainer/train.sh.in ${CMAKE_BINARY_DIR}/CMakeFiles/train.sh @ONLY)

# Ensure the files exist before copying
if(EXISTS ${CMAKE_BINARY_DIR}/CMakeFiles/train.sh)
  file(COPY ${CMAKE_BINARY_DIR}/CMakeFiles/train.sh DESTINATION ${CMAKE_BINARY_DIR}/bin)
else()
  message(FATAL_ERROR "train.sh file not found!")
endif()

if(EXISTS ${CMAKE_SOURCE_DIR}/src/trainer/formations-dt)
  file(COPY ${CMAKE_SOURCE_DIR}/src/trainer/formations-dt DESTINATION ${CMAKE_BINARY_DIR}/bin)
else()
  message(FATAL_ERROR "formations-dt file not found!")
endif()
