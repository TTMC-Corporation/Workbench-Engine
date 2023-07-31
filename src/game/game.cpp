#include "../../headers/game/game.hpp"
#include "../../headers/renderer/VulkanSetup.hpp"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

Game::Game(GLFWwindow* window)
{
    this->window = window;
    MainLoop();
}

void Game::MainLoop()
{
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }
}

Game::~Game()
{

}