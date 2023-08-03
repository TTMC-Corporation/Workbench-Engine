#include "../../headers/renderer/VulkanSetup.hpp"
#include "../../headers/log/log.hpp"
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <optional>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace Renderer
{
    VulkanSetup::VulkanSetup()
    {
        #ifdef NDEBUG
            this->enableValidationLayers = false;
        #else
            this->enableValidationLayers = true;
        #endif
        this->screenWidth = 1280;
        this->screenHeight = 720;
        this->name = "Workbanch-Engine";
        Run();
    }

    void VulkanSetup::Run()
    {
        InitWindow();
        Log::Print(0, "ez még lwfut");
        Version();
        Log::Print(0, "ez még lwfut");
        InitVulkan();
        Log::Print(0, "ez még lwfut");
        //PickPhisicalDevice(); 
        Log::Print(0, "ez még lwfut");
        //CreateLogicalDevice();
        Log::Print(0, "ez még lwfut");
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
        if (enableValidationLayers && !CheckValidationLayerSupport()) 
        {
            Log::Print(2 ,"Validation layers not available!");
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

        if (enableValidationLayers) 
        {
            createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
            createInfo.ppEnabledLayerNames = validationLayers.data();
        } else 
        {
            createInfo.enabledLayerCount = 0;
        }

        if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) 
        {
            Log::Print(2, "Failed to create Vulkan instance!");
        }
    }

    bool VulkanSetup::CheckValidationLayerSupport()
    {
        uint32_t layerCount;
        vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

        std::vector<VkLayerProperties> availableLayers(layerCount);
        vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

        return false;

        for (const char* layerName : validationLayers) 
        {
            bool layerFound = false;

            for (const auto& layerProperties : availableLayers) 
            {
                if (std::strcmp(layerName, layerProperties.layerName) == 0) 
                {
                    layerFound = true;
                    break;
                }

                if (!layerFound) 
                {
                    return false;
                }
            }

        return true;
        }
    }
    

    std::vector<const char*> VulkanSetup::GetExtensions()
    {
        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;

        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

        if (enableValidationLayers) 
        {
            extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
        }

        return extensions;
    }

    void VulkanSetup::PickPhisicalDevice()
    {
        uint32_t deviceCount = 0;
        vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

        if (deviceCount == 0) 
        {
            Log::Print(2, "failed to find GPUs with Vulkan support!");
            return;
        }

        std::vector<VkPhysicalDevice> devices(deviceCount);
        vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

        std::multimap<int, VkPhysicalDevice> candidates;

        for (const auto& device : devices) 
        {
            int score = rateDeviceSuitability(device);
            candidates.insert(std::make_pair(score, device));
        }

        if (candidates.rbegin()->first > 0)
        {
            physicalDevice = candidates.rbegin()->second;

            VkPhysicalDeviceProperties deviceProperties;
            vkGetPhysicalDeviceProperties(physicalDevice, &deviceProperties);

            Log::Print(0, "Found GPU: " + std::string(deviceProperties.deviceName));

            QueueFamilyIndices indices = findQueueFamilies(physicalDevice);
            if (!indices.isComplete()) 
            {
                Log::Print(2, "failed to find a suitable graphics queue family!");
                return; 
            }
        }
        else
        {
            Log::Print(2, "failed to find a suitable GPU!");
        }
    }

    bool VulkanSetup::IsDeviceSuitable(VkPhysicalDevice device)
    {
        VkPhysicalDeviceProperties deviceProperties;
        VkPhysicalDeviceFeatures deviceFeatures;
        vkGetPhysicalDeviceProperties(device, &deviceProperties);
        vkGetPhysicalDeviceFeatures(device, &deviceFeatures);

        return deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU &&
            deviceFeatures.geometryShader;
    }

    int VulkanSetup::rateDeviceSuitability(VkPhysicalDevice device)
    {
        VkPhysicalDeviceProperties deviceProperties;
        vkGetPhysicalDeviceProperties(device, &deviceProperties);

        int score = 0;

        if (deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU)
        {
            score += 1000;
        }

        score += deviceProperties.limits.maxImageDimension2D;

        VkPhysicalDeviceFeatures deviceFeatures;
        vkGetPhysicalDeviceFeatures(device, &deviceFeatures);

        if (!deviceFeatures.geometryShader)
        {
            return 0;
        }

        return score;
    }

    QueueFamilyIndices VulkanSetup::findQueueFamilies(VkPhysicalDevice device)
    {
        QueueFamilyIndices indices;

        std::optional<uint32_t> graphicsFamily;
        std::cout << std::boolalpha << graphicsFamily.has_value() << std::endl;
        graphicsFamily = 0;
        std::cout << std::boolalpha << graphicsFamily.has_value() << std::endl; 

        return indices;
    }

    QueueFamilyIndices VulkanSetup::findQueueFamilies(VkPhysicalDevice device)
    {
        QueueFamilyIndices indices;

        uint32_t queueFamilyCount = 0;
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);
        std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

        int i = 0;
        for (const auto& queueFamily : queueFamilies) 
        {
            if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) 
            {
                indices.graphicsFamily = i;
            }

            if (indices.isComplete()) 
            {
                break;
            }

            i++;
        }

        return indices;
    }


    void VulkanSetup::CreateLogicalDevice()
    {
        QueueFamilyIndices indices = findQueueFamilies(physicalDevice);

        VkDeviceQueueCreateInfo queueCreateInfo{};
        queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queueCreateInfo.queueFamilyIndex = indices.graphicsFamily;
        queueCreateInfo.queueCount = 1;
        float queuePriority = 1.0f;
        queueCreateInfo.pQueuePriorities = &queuePriority;
    }

    bool VulkanSetup::isComplete()
    {
        return graphicsFamily.has_value();
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