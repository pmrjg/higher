//
// Created by pmrj on 20-12-2024.
//

#ifndef TRIANGLEAPP_H
#define TRIANGLEAPP_H

#define GLFW_INCLUDE_VULKAN
#include <vector>
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

constexpr uint32_t WIDTH = 800;
constexpr uint32_t HEIGHT = 600;

const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
};

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

struct QueueFamilyIndices {
    uint32_t graphicsFamily;
};

class TriangleApp {
    GLFWwindow* window;
    VkInstance instance;

public:
    void run();
    ~TriangleApp() = default;
private:
    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();
    void createInstance();
    bool checkValidationLayerSupport();
    void pickPhysicalDevice();
    bool isDeviceSuitable(VkPhysicalDevice device);
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
};



#endif //TRIANGLEAPP_H
