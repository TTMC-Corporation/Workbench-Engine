#include "../../headers/renderer/VulkanSetup.hpp"
#include "../../headers/log/log.hpp"
#include <iostream>
#include <vector>
#include <cstring>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

namespace Renderer
{
    VulkanSetup::VulkanSetup()
    {
        this->enableValidationLayers = true;
        this->screenWidth = 1280;
        this->screenHeight = 720;
        this->name = "Workbanch-Engine";
        Run();
    }

    void VulkanSetup::Run()
    {
        InitWindow();
        Version();
        InitVulkan();
    }

    void VulkanSetup::InitWindow()
    {
        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(screenWidth, screenHeight, name, nullptr, nullptr);
    }

    void VulkanSetup::InitVulkan()
    {
        CreateInstance();
    }

    void VulkanSetup::CreateInstance()
    {
        if (enableValidationLayers && !CheckValidationLayerSupport()) {
            Log::Print(1 ,"Validation layers not available!");
        }

        VkApplicationInfo appInfo = {};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Workbanch-Engine";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "Workbanch-Engine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        auto extensions = GetExtensions();
        createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
        createInfo.ppEnabledExtensionNames = extensions.data();

        if (enableValidationLayers) {
            createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
            createInfo.ppEnabledLayerNames = validationLayers.data();
        } else {
            createInfo.enabledLayerCount = 0;
        }

        if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
            Log::Print(1, "Failed to create Vulkan instance!");
        }
    }

    bool VulkanSetup::CheckValidationLayerSupport()
    {
        uint32_t layerCount;
        vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

        std::vector<VkLayerProperties> availableLayers(layerCount);
        vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

        return false;

        for (const char* layerName : validationLayers) {
        bool layerFound = false;

        for (const auto& layerProperties : availableLayers) 
        {
            if (std::strcmp(layerName, layerProperties.layerName) == 0) 
            {
                layerFound = true;
                break;
            }
        }

            if (!layerFound) 
            {
                return false;
            }
        }

        return true;
    }
    

    std::vector<const char*> VulkanSetup::GetExtensions()
    {
        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;

        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

        if (enableValidationLayers) {
            extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
        }

        return extensions;
    }

    GLFWwindow* VulkanSetup::GetGLFWWindow()
    {
        return window;
    }

    void VulkanSetup::Version()
    {
        int major, minor, revision;
        glfwGetVersion(&major, &minor, &revision);

        std::string major_string = std::to_string(major);
        std::string minor_string = std::to_string(minor);
        std::string major_revision = std::to_string(revision);
        std::string glfw_vesrion_string = "GLFW version: " + major_string + "." + minor_string + "." + major_revision;

        Log::Print(0, glfw_vesrion_string);
    }

    VulkanSetup::~VulkanSetup()
    {
        vkDestroyInstance(instance, nullptr);
        glfwDestroyWindow(window);
        glfwTerminate();
    }
}