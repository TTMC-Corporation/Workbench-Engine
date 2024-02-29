#include "headers/definitions/settings.hpp"
#include "headers/renderer/window.hpp"
#include "headers/renderer/vulkan.hpp"
#include "headers/renderer/device.hpp"
#include "headers/renderer/windowSurface.hpp"

int main()
{
    settings setting = {1280, 720, "Engine"};

    Engine::Renderer::Window *window = new Engine::Renderer::Window();
    Engine::Renderer::Vulkan *vulkan = new Engine::Renderer::Vulkan();
    Engine::Renderer::WindowSurface *windowSurface = new Engine::Renderer::WindowSurface(vulkan->instance, window->window);
    std::cout << vulkan->instance << " " << windowSurface->surface << "\n";
    Engine::Rendeier::Device *device = new Engine::Rendeier::Device(vulkan->instance, windowSurface->surface);

    window->createWindow(setting);
    while (!window->shouldClose())
    {
        glfwPollEvents();
    }

    delete window;
    delete vulkan;
    delete windowSurface;
    delete device;
}
