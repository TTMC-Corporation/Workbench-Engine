#include "headers/renderer/VulkanSetup.hpp"
#include "headers/game/game.hpp"
#include "headers/log/log.hpp"

int main()
{
    Renderer::VulkanSetup vulkan;
    Game game(vulkan.GetGLFWWindow());
}