#include "../../headers/renderer/window.hpp"

Engine::Renderer::Window::Window()
{
    glfwInit();
}

void Engine::Renderer::Window::createWindow(settings setting)
{
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(setting.screenWidth, setting.screenHeight, setting.windowName, nullptr, nullptr);
}

bool Engine::Renderer::Window::shouldClose()
{
    return glfwWindowShouldClose(window);
}

Engine::Renderer::Window::~Window()
{
    glfwDestroyWindow(window);
}