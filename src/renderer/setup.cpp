#include "../../headers/renderer/setup.hpp"
#include "../../libraries/GLFW/include/GLFW/glfw3.h"
#include <vulkan/vulkan.h>
#include <iostream>
namespace Renderer
{
    void Setup::teszt()
    {
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW" << std::endl;
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan GLFW Test", nullptr, nullptr);
        if (!window) {
            std::cerr << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
        }

        uint32_t extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
        std::cout << "Available Vulkan instance extensions: " << extensionCount << std::endl;

        glfwDestroyWindow(window);
        glfwTerminate();
    }
}