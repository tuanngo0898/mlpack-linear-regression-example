cmake_minimum_required(VERSION 3.5)
project(mlpack-linear-regression)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

# set(CMAKE_VERBOSE_MAKEFILE on)

find_package(PkgConfig REQUIRED)
pkg_search_module(MLPACK REQUIRED mlpack)

include_directories(
    ${MLPACK_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} main.cpp)
target_compile_options(${PROJECT_NAME} PUBLIC ${MLPACK_CFLAGS_OTHER})
target_link_libraries(${PROJECT_NAME} ${MLPACK_LIBRARIES})

add_executable(make_data make_data.cpp)
