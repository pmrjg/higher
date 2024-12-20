//
// Created by pmrj on 20-12-2024.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class Triangle {
public:
    void run();
private:
    void initVulkan();
    void mainLoop();
    void cleanup();
    void initWindow();
    GLFWwindow* window;
};

#endif //TRIANGLE_H
