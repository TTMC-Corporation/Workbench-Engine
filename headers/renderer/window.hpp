#pragma once
#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>

#include "../definitions/settings.hpp"
#include "../debug/log.hpp"

namespace Engine
{
    namespace Renderer
    {
        class Window
        {
        public:
            Window();
            ~Window();
            void createWindow(settings setting);
            bool shouldClose();
            GLFWwindow* window;
        };
    }
}