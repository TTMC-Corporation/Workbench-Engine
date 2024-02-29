#include "../../headers/renderer/device.hpp"

Engine::Rendeier::Device::Device(VkInstance instance, VkSurfaceKHR surface)
{
    this->instance = instance;
    this->surface = surface;
    deviceCount = 0;
    queueFamilyCount = 0;
    std::cout << "before phisiacl device\n";
    pickPhysicalDevice();
    std::cout << "after phisical device\n";
    createLogicalDevice();
    std::cout << " after logical device\n";
}

Engine::Rendeier::Device::~Device()
{
    vkDestroyDevice(device, nullptr);
}
