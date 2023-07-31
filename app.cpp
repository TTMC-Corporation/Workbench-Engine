#include "headers/renderer/VulkanSetup.hpp"
#include "headers/game/game.hpp"
#include "headers/log/log.hpp"

int main()
{
    Renderer::VulkanSetup *vulkan_setup = new Renderer::VulkanSetup();
    Game *game = new Game(vulkan_setup->GetGLFWWindow());

    delete vulkan_setup;
    delete game;
}