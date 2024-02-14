#include "headers/definitions/settings.hpp"
#include "headers/renderer/window.hpp"

int main()
{
    settings setting = {1280, 720, "Engine"};

    Engine::Renderer::Window *window = new Engine::Renderer::Window();
    window->createWindow(setting);
    while (!window->shouldClose())
    {
        glfwPollEvents();
    }

    delete window;
}