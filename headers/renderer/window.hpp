#pragma once

#include <GLFW/glfw3.h>

#include "../definitions/settings.hpp"

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