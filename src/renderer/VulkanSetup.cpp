#include "../../headers/renderer/VulkanSetup.hpp"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace Renderer
{
    VulkanSetup::VulkanSetup()
    {
        /* this is temporary and I will access 
        them from the setup class when it is ready */
        this->screenWidth = 1280;
        this->screenHeight = 720;
        this->name = "Workbanch-Engine";
        InitWindow();
    }

    void VulkanSetup::InitWindow()
    {
        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(screenWidth, screenHeight, name, nullptr, nullptr);
    }

    void VulkanSetup::InitVulkan()
    {

    }

    GLFWwindow* VulkanSetup::GetGLFWWindow() const
    {
        return window;
    }

    VulkanSetup::~VulkanSetup()
    {

    }
}