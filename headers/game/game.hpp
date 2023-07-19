#pragma once
#include "../renderer/VulkanSetup.hpp"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class Game
{
private:
    GLFWwindow* window;

public:
    Game(GLFWwindow* window);
    ~Game();

private:
    void MainLoop();
};