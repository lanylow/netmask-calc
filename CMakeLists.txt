cmake_minimum_required(VERSION 3.21.0)
project(netmask-calc)

set(CMAKE_C_STANDARD 17)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.c")

add_executable(netmask-calc ${SOURCES})
