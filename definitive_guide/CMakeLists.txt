cmake_minimum_required(VERSION 3.30)
project(definitive_guide)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

set(GLFW_USE_WAYLAND ON)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(definitive_guide main.cpp
        ops/Triangle.cpp
        ops/Triangle.h
        ops/QueueFamilyIndices.h)

find_library(GLFW glfw)
find_library(DL libdl)
find_library(PTHREAD pthread)

target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan ${GLFW} ${dl} ${PTHREAD})

