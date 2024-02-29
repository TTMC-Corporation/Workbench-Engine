#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>

#include "../debug/log.hpp"
//#include "../debug/validationLayer.hpp"

namespace Engine
{
    namespace Renderer
    {
        class Vulkan 
        {
        public:
            Vulkan();
            ~Vulkan();

        public:
            VkInstance instance;

        private:
            void createInstance();
            void checkForExtension();

        private:
            VkResult result;
            uint32_t extensionCount = 0;
            //Engine::Debug::ValidationLayer* validationLayer;
            //VkDebugUtilsMessengerEXT debugMessenger; 
        };
    }
}
