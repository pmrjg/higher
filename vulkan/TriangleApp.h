//
// Created by pmrj on 20-12-2024.
//

#ifndef TRIANGLEAPP_H
#define TRIANGLEAPP_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

class TriangleApp {
    GLFWwindow* window;
    VkInstance instance;
    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;
public:
    void run();
    ~TriangleApp() = default;
private:
    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();
    void createInstance();
};



#endif //TRIANGLEAPP_H
