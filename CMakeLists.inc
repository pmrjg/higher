cmake_minimum_required(VERSION 3.30)

project(vulkan)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_CXX_FLAGS "-lglfw -lvulkan -ldl -lpthread ")
set(CMAKE_EXE_LINKER_FLAGS_INIT "-lglfw -lvulkan -ldl -lpthread")

find_package(Vulkan REQUIRED)

add_executable(${PROJECT_NAME} main.cpp
        TriangleApp.cpp
        TriangleApp.h)

target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)