#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>

namespace Renderer
{
    class VulkanSetup
    {
    public:
        VulkanSetup();
        ~VulkanSetup();
        GLFWwindow* GetGLFWWindow();

    private:
        void Run();
        void InitWindow();
        void InitVulkan();
        void CreateInstance();
        void Version();
        bool CheckValidationLayerSupport();
        std::vector<const char*> GetExtensions();

    private:
        GLFWwindow* window;
        VkInstance instance;
        bool enableValidationLayers;
        const std::vector<const char*> validationLayers = {"VK_LAYER_KHRONOS_validation"};
        int screenWidth;
        int screenHeight;
        const char* name;
    };
}