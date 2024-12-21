//
// Created by pmrj on 20-12-2024.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

#define GLFW_INCLUDE_VULKAN
#include <vector>
#include <GLFW/glfw3.h>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
};

#ifdef NDEBUG
    const bool enableValidationLayers = true;
#else
    const bool enableValidationLayers = false;
#endif

class Triangle {
public:
    void run();
private:
    void initVulkan();
    void mainLoop();
    void cleanup();
    void initWindow();
    void createInstance();
    GLFWwindow* window;
    VkInstance instance;
    bool checkValidationLayerSupport();
};

#endif //TRIANGLE_H
