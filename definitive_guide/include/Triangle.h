//
// Created by pmrj on 20-12-2024.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <SDL3/SDL_video.h>
#include <vulkan/vulkan.h>

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
    void createInstance();
    SDL_Window *window;
    VkInstance instance;
};

#endif //TRIANGLE_H
