#pragma once

#include <iostream>
#include <vector>
#include <cstring>
#include <vulkan/vulkan.h>

#include "../definitions/validationLayers.hpp"
#include "log.hpp"

namespace Engine
{
    namespace Debug
    {
        class ValidationLayer
        {
        public:
            ValidationLayer();
            ~ValidationLayer();
            bool checkValidationLayerSupport();
            void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
            void setupDebugMessenger(VkInstance instance, VkDebugUtilsMessengerEXT& debugMessenger);

        public:
            bool enableValidationLayers;
                                
        private:
            static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
                VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                VkDebugUtilsMessageTypeFlagsEXT messageType,
                const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                void* pUserData
            );
            VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
        };
    }
}
