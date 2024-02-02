cmake_minimum_required(VERSION 3.25)
project(module_image)

set(CMAKE_DEBUG_POSTFIX "")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)

add_executable(test
        src/mainTest.cpp
        src/Pixel.h
        src/Image.h
        src/Image.cpp
)

add_executable(exemple
        src/mainExemple.cpp
        src/Pixel.h
        src/Image.h
        src/Image.cpp
)

add_executable(affichage
        src/mainAffichage.cpp
        src/Pixel.h
        src/Image.h
        src/Image.cpp
        src/ImageViewer.cpp
)

# Inclusion des en-têtes des bibliothèques
target_include_directories(affichage PRIVATE
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS}
        ${SDL2_MIXER_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS}
)

if(WIN32)
    target_link_libraries(affichage PRIVATE
            SDL2::SDL2main
            SDL2::SDL2
            SDL2_image::SDL2_image;
            #"Shlwapi.lib"
    )
else()      # APPLE and LINUX
    target_link_libraries(affichage PRIVATE
            SDL2
            SDL2_image
    )
endif()


get_filename_component(PROJECT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/" ABSOLUTE)
message("Chemin vers CMakeLists.txt : ${PROJECT_ROOT}")
#install(TARGETS module_image DESTINATION "${PROJECT_ROOT}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_ROOT}/bin)
