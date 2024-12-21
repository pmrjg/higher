cmake_minimum_required(VERSION 3.30)
project(definitive_guide)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

find_package(Vulkan REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(SDL3 REQUIRED)


add_executable(definitive_guide main.cpp
        src/Triangle.cpp
        include/Triangle.h)

find_library(GLFW glfw)
find_library(DL dl)
find_library(PTHREAD pthread)

set_target_properties(${PROJECT_NAME} PROPERTIES GLFW_USE_WAYLAND ON)
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan ${GLFW} ${DL} ${PTHREAD} SDL3::SDL3)

