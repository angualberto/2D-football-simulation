cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(DRIGONSSC2D)

# Configurações de compilação
set(CMAKE_CXX_STANDARD 11)

# Definir a política CMP0079 para NEW
if(POLICY CMP0079)
  cmake_policy(SET CMP0079 NEW)
endif()

# Encontrar e incluir pacotes OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Incluir diretórios Boost Python
find_package(Boost COMPONENTS python numpy REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

# Incluir diretórios librcsc
include_directories(/home/andre/local/include)

# Adicionar diretórios de inclusão
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/src/player/basic_actions)
include_directories(${PROJECT_SOURCE_DIR}/src/evolution)  # Add this line

# Encontrar a biblioteca voronoi_library
find_library(VORONOI_LIBRARY voro++)
find_path(VORONOI_INCLUDE_DIR voro++.hh)

if (NOT VORONOI_LIBRARY OR NOT VORONOI_INCLUDE_DIR)
    message(FATAL_ERROR "voronoi_library not found")
endif()

set(VORONOI_LIBDIR ${VORONOI_LIBRARY})
set(VORONOI_INCLUDE_DIR ${VORONOI_INCLUDE_DIR})

# Verificar se a biblioteca foi encontrada
if(NOT VORONOI_LIBRARY)
  message(FATAL_ERROR "voronoi_library not found")
endif()

# Incluir a biblioteca voro
find_library(VORO_LIBRARY NAMES voro++)
if(NOT VORO_LIBRARY)
    message(FATAL_ERROR "voro++ library not found")
endif()

include_directories(/usr/local/include/voro++)
link_directories(/usr/local/lib)

# Adicionar o executável
add_executable(sample_trainer src/trainer/sample_trainer.cpp)

# Linkar bibliotecas necessárias
target_link_libraries(sample_trainer ${OpenCV_LIBS} ${Boost_LIBRARIES} ${VORONOI_LIBRARY} /home/andre/local/lib/librcsc.so)

# Adicionar o executável principal
add_executable(${PROJECT_NAME} src/main.cpp)  # Add this line

# Linkar a biblioteca voro
target_link_libraries(${PROJECT_NAME} ${VORO_LIBRARY})

add_subdirectory(player)
add_subdirectory(coach)
add_subdirectory(trainer)

# generate shell scripts and copy them to the binary directory as an executable script
configure_file(
  ${PROJECT_SOURCE_DIR}/start.sh.in
  ${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/start.sh
  @ONLY
)
file(
  COPY ${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/start.sh
  DESTINATION ${PROJECT_BINARY_DIR}/bin
  FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)

configure_file(
  ${PROJECT_SOURCE_DIR}/keepaway.sh.in
  ${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/keepaway.sh
  @ONLY
)
file(
  COPY ${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/keepaway.sh
  DESTINATION ${PROJECT_BINARY_DIR}/bin
  FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)

configure_file(
  ${PROJECT_SOURCE_DIR}/train.sh.in
  ${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/train.sh
  @ONLY
)
file(
  COPY ${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/train.sh
  DESTINATION ${PROJECT_BINARY_DIR}/bin
  FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)

# copy other files to the binary directory
file(COPY
  formations-dt formations-keeper formations-taker player.conf coach.conf start-debug.sh start-offline.sh unmark_dnn_weights.txt
  DESTINATION ${PROJECT_BINARY_DIR}/bin
)
