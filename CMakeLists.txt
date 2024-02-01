cmake_minimum_required(VERSION 3.25)
project(module_image)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(module_image
        src/mainTest.cpp
        src/Pixel.h
        src/Image.h
        src/Image.cpp
)

get_filename_component(PROJECT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/" ABSOLUTE)
message("Chemin vers CMakeLists.txt : ${PROJECT_ROOT}")
#install(TARGETS module_image DESTINATION "${PROJECT_ROOT}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_ROOT}/bin)
