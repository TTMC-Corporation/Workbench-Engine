#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "../debug/log.hpp"

namespace Engine
{
    namespace Renderer
    {
        class WindowSurface
        {
        public:
            WindowSurface(VkInstance instance, GLFWwindow* window);
            ~WindowSurface();
            VkSurfaceKHR surface;

        private:
            VkInstance instance;
            GLFWwindow* window;

        private:
            void createSurface();
            
        };
    }
}
