//
// Created by pmrj on 20-12-2024.
//

#include "Triangle.h"
#include <GLFW/glfw3.h>

void Triangle::run() {
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
}

void Triangle::initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
}

void Triangle::initVulkan() {

}

void Triangle::mainLoop() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}

void Triangle::cleanup() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

