#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>

#include "../debug/log.hpp"
#include "../definitions/queueFamilyIndices.hpp"
namespace Engine
{
    namespace Rendeier
    {
        class Device
        {
        public:
            Device(VkInstance instance, VkSurfaceKHR surface);
            ~Device();
            uint32_t queueFamilyCount;

        private:
            VkPhysicalDevice physicalDevice;
            VkDevice device;
            VkQueue graphicsQueue;
            VkInstance instance;
            uint32_t deviceCount;
            QueueFamilyIndices indices;
            VkSurfaceKHR surface;

        private:
            void pickPhysicalDevice();
            void createLogicalDevice();
            bool isDeviceSuitable(VkPhysicalDevice device);
            QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
            std::vector<const char*> getRequiredExtensions();
        };
    }
}
