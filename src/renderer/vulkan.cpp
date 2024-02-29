#include "../../headers/renderer/vulkan.hpp"

Engine::Renderer::Vulkan::Vulkan()
{
    checkForExtension();
    createInstance();

    /*
    this->validationLayer = new Engine::Debug::ValidationLayer();
    if (validationLayer->checkValidationLayerSupport())
    {
        validationLayer->setupDebugMessenger(instance, debugMessenger); // Access validationLayer using a pointer
    }
    else 
    {
        Engine::Debug::TerminalLog::Print(2, "Validation layers are not supported!");
        delete validationLayer;
    }
    */
}

void Engine::Renderer::Vulkan::createInstance()
{
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Engine";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    createInfo.enabledLayerCount = 0;

    result = vkCreateInstance(&createInfo, nullptr, &instance);

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) 
    {
        Engine::Debug::TerminalLog::Print(2, "failed to create instance");
    }

    else
    {
        Engine::Debug::TerminalLog::Print(0, "instance created succesfully");
    }
}

void Engine::Renderer::Vulkan::checkForExtension()
{
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::vector<VkExtensionProperties> extensions(extensionCount);

    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

    Engine::Debug::TerminalLog::Print(0, "available extensions: ");

    for (const auto& extension : extensions)
    {
        std::cout << '\t' << extension.extensionName << '\n';
    }
}

Engine::Renderer::Vulkan::~Vulkan()
{
    //delete validationLayer;
    vkDestroyInstance(instance, nullptr);
    glfwTerminate();
}
