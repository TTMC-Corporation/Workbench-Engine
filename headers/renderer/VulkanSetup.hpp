#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace Renderer
{
    class VulkanSetup
    {
    public:
        VulkanSetup();
        ~VulkanSetup();
        GLFWwindow* GetGLFWWindow() const;

    private:
        void InitWindow();
        void InitVulkan();

    /* this is temporary and I will access 
    them from the setup class when it is ready */
    private:
        int screenWidth;
        int screenHeight;
        const char* name;

    private:
        GLFWwindow* window;
    };
}