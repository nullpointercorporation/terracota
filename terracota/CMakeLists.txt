cmake_minimum_required(VERSION 2.8)
project(Terracota)

# Set directory folders
set (PROJECT_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set (PROJECT_SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

# Gets the list of files inside the src directory
file(GLOB_RECURSE SOURCES "${PROJECT_SRC_DIR}/*.cpp")

# Include Headers
include_directories("${PROJECT_INCLUDE_DIR}")

#### Compilation ####

# Compilation Flags
set(CMAKE_CXX_FLAGS "-Wall -W -pedantic -std=c++11 -g3")

#### Dependencies ####

# Add ijengine
set (PROJECT_ENGINE_DIR "/usr/local/include/ijengine")
include_directories(${PROJECT_ENGINE_DIR})

#### Executable ####

add_executable(Terracota ${SOURCES})

include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_search_module(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)
pkg_search_module(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)

include_directories(include ${SDL2_INCLUDE_DIRS} 
			${SDL2IMAGE_INCLUDE_DIRS}
			${SDL2TTF_INCLUDE_DIRS}
			${SDL2MIXER_INCLUDE_DIRS})

target_link_libraries(Terracota 
		ijengine
		${SDL2_LIBRARIES} 
		${SDL2IMAGE_LIBRARIES}
		${SDL2TTF_LIBRARIES}
		${SDL2MIXER_LIBRARIES})

