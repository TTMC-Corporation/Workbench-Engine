#include "headers/renderer/VulkanSetup.hpp"
#include "headers/game/game.hpp"
#include "headers/log/log.hpp"

int main()
{
    Log log;
    Renderer::VulkanSetup vulkan;
    log.Print(2, "aaaa");
    Game game(vulkan.GetGLFWWindow());
}