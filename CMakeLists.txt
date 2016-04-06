cmake_minimum_required(VERSION 2.8.9)
project (SoftwareRenderer)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake") 

set( project_sources
   main.cpp
   camera.h
   camera.cpp
   renderer.h
   renderer.cpp
   mesh.h
   mesh.cpp
)

add_executable(SoftwareRenderer
  ${project_sources}
)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(SoftwareRenderer ${SDL2_LIBRARY})

find_package(GLM REQUIRED)
include_directories(${GLM_INCLUDE_DIRS})
link_directories(${GLM_LIBRARY_DIRS})