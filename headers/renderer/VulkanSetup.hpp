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
        void Run();
        void InitWindow();
        void InitVulkan();
        void CreateInstance();
        void Version();

    private:
        GLFWwindow* window;
        VkInstance instance;

    /* this is temporary and I will access 
    them from the settings class when it is ready */
    private:
        int screenWidth;
        int screenHeight;
        const char* name;
    };
}