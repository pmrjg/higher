//
// Created by pmrj on 20-12-2024.
//

#include "include/Triangle.h"

#include <iostream>
#include <stdexcept>
#include <vector>
#include <SDL3/SDL.h>
#include <SDL3/SDL_vulkan.h>

void Triangle::run() {
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
}

void Triangle::initWindow() {
    SDL_PropertiesID props;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_SetBooleanProperty(props, SDL_PROP_WINDOW_CREATE_WAYLAND_CREATE_EGL_WINDOW_BOOLEAN, true);
    SDL_SetBooleanProperty(props, SDL_PROP_WINDOW_CREATE_VULKAN_BOOLEAN, true);
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_WIDTH_NUMBER, WIDTH);
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_HEIGHT_NUMBER, HEIGHT);

    window = SDL_CreateWindowWithProperties(props);


    if (window == nullptr) {
        throw std::runtime_error("Failed to create window");
    }
}

void Triangle::initVulkan() {
    createInstance();
    uint32_t extensionCount = 0;

    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::vector<VkExtensionProperties> extensions(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

    std::cout << "available extensions: " << std::endl;
    for (const auto& extension : extensions) {
        std::cout << '\t' << extension.extensionName << std::endl;
    }
}

void Triangle::createInstance() {
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_MAKE_VERSION(1, 0, 0);
    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t countExtension = 0;
    const char* const* instanceExtensions = SDL_Vulkan_GetInstanceExtensions(&countExtension);

    if (instanceExtensions == nullptr) {
        throw std::runtime_error("Failed to get instance extensions");
    }

    int countExtensions = countExtension + 1;


    createInfo.enabledLayerCount = 0;
    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

    if (result != VK_SUCCESS) {
        throw std::runtime_error("failed to create instance");
    }
}


void Triangle::mainLoop() {
    SDL_Event event;
    while (true) {
        SDL_PollEvent(&event);

        switch (event.type) {
            case SDL_EVENT_QUIT:
                return;
            default: {}
        }
    }
}

void Triangle::cleanup() {
    vkDestroyInstance(instance, nullptr);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

