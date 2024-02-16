#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>

#include "../debug/log.hpp"

namespace Engine
{
    namespace Renderer
    {
        class Vulkan 
        {
        public:
            Vulkan();
            ~Vulkan();

        private:
            void createInstance();
            void checkForExtension();

        private:
            VkInstance instance;
            VkResult result;
            uint32_t extensionCount = 0;
        };
    }
}