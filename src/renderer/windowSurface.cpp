#include "../../headers/renderer/windowSurface.hpp"

Engine::Renderer::WindowSurface::WindowSurface(VkInstance instance, GLFWwindow* window)
{
    this->instance = instance;
}

void Engine::Renderer::WindowSurface::createSurface() 
{
    if (glfwCreateWindowSurface(instance, window, nullptr, &surface) != VK_SUCCESS) 
    {
        Engine::Debug::TerminalLog::Print(2, "failed to create window surface!");
    }
}

Engine::Renderer::WindowSurface::~WindowSurface()
{
    vkDestroySurfaceKHR(instance, surface, nullptr);
}
