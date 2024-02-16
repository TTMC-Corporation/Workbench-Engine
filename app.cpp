#include "headers/definitions/settings.hpp"
#include "headers/renderer/window.hpp"
#include "headers/renderer/vulkan.hpp"
#include "headers/debug/log.hpp"

int main()
{
    settings setting = {1280, 720, "Engine"};

    Engine::Renderer::Window *window = new Engine::Renderer::Window();
    Engine::Renderer::Vulkan *vulkan = new Engine::Renderer::Vulkan();

    window->createWindow(setting);
    while (!window->shouldClose())
    {
        glfwPollEvents();
    }

    delete window;
    delete vulkan;
}