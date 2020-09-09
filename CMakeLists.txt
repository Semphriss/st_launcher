#
# SuperTux Launcher - root build script
# Copyright (C) 2020 A. Semphris <semphris@protonmail.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#

cmake_minimum_required(VERSION 3.10)

project(st_launcher VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# LIB : OpenGL
#find_package(OpenGL REQUIRED)
#include_directories(${OpenGL_INCLUDE_DIRS})
#link_directories(${OpenGL_LIBRARY_DIRS})
#add_definitions(${OpenGL_DEFINITIONS})
#if(NOT OPENGL_FOUND)
#  message(ERROR "OpenGL not found")
#endif(NOT OPENGL_FOUND)

# LIB : SDL
find_package(SDL2 REQUIRED)
include_directories(st_launcher_lib ${SDL2_INCLUDE_DIRS})

# EXTERNAL : Nanogui
set(NANOGUI_BUILD_EXAMPLE Off CACHE BOOL "Disable Nanogui example program" FORCE)
add_subdirectory(${PROJECT_SOURCE_DIR}/external/nanogui-sdl)
include_directories(st_launcher_lib ${PROJECT_SOURCE_DIR}/external/nanogui-sdl)

# Launcher library
file(GLOB st_launcher_src src/*/*.cpp)
add_library(st_launcher_lib ${st_launcher_src})
target_include_directories(st_launcher_lib PUBLIC "${PROJECT_SOURCE_DIR}/src")
target_link_libraries(st_launcher_lib ${OPENGL_LIBRARIES} ${SDL2_LIBRARIES} nanogui_sdl)

# Executable library
add_executable(st_launcher "src/main.cpp")
target_include_directories(st_launcher PUBLIC "${PROJECT_SOURCE_DIR}/src")
target_link_libraries(st_launcher st_launcher_lib)
