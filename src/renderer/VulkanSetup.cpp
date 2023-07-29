#include "../../headers/renderer/VulkanSetup.hpp"
#include "../../headers/log/log.hpp"
#include <iostream>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

namespace Renderer
{
    VulkanSetup::VulkanSetup()
    {
        /* this is temporary and I will access 
        them from the settings class when it is ready */
        this->screenWidth = 1280;
        this->screenHeight = 720;
        this->name = "Workbanch-Engine";
        Run();
    }

    void VulkanSetup::Run()
    {
        InitWindow();
        Version();
        InitVulkan();
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
        CreateInstance();
    }

    void VulkanSetup::CreateInstance()
    {
        VkApplicationInfo appInfo = {};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Workbanch-Engine";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "Workbanch-Engine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;
    }

    GLFWwindow* VulkanSetup::GetGLFWWindow() const
    {
        return window;
    }

    void VulkanSetup::Version()
    {
        int major, minor, revision;
        glfwGetVersion(&major, &minor, &revision);

        std::string major_string = std::to_string(major);
        std::string minor_string = std::to_string(minor);
        std::string major_revision = std::to_string(revision);
        std::string glfw_vesrion_string = "GLFW version: " + major_string + "." + minor_string + "." + major_revision;

        Log::Print(0, glfw_vesrion_string);
    }

    VulkanSetup::~VulkanSetup()
    {

    }
}