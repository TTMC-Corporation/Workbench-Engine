cmake_minimum_required(VERSION 3.26.0)
project(WorkbenchEngine LANGUAGES CXX)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find Vulkan package
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(GLFW_LIB_DIR "libraries/GLFW/lib-vc2022/")
    set(GLFW_INCLUDE_DIR "libraries/GLFW/include/")

    # Specify the path to the Vulkan library and include its headers
    set(VULKAN_LIB_DIR "libraries/VULKAN/Lib/vulkan-1.lib")
    set(VULKAN_INCLUDE_DIR "libraries/VULKAN/Include")

    # Include GLFW and Vulkan directories
    include_directories(${GLFW_INCLUDE_DIR} ${VULKAN_INCLUDE_DIR})

    # Set GLFW libraries
    set(GLFW_LIBRARIES glfw3)

elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(GLFW_LIB_DIR "/usr/lib")
    set(GLFW_INCLUDE_DIR "/usr/include")

    # Find Vulkan package
    find_package(Vulkan REQUIRED)

elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(GLFW_LIB_DIR "/usr/local/Cellar/glfw/3.3.8/")
    set(GLFW_INCLUDE_DIR "/usr/local/Cellar/glfw/3.3.8/include")

    # Find GLFW and Vulkan package
    find_package(GLFW3 REQUIRED)
    find_package(Vulkan REQUIRED)

    # Include GLFW and Vulkan directories
    include_directories(${GLFW3_INCLUDE_DIRS} ${VULKAN_INCLUDE_DIR})

    # Set GLFW libraries
    set(GLFW_LIBRARIES ${GLFW3_LIBRARIES})
endif()

# Add header files
include_directories(headers/)

# Add source files
file(GLOB CPP_SOURCES "src/*.cpp")

# Create the executable
add_executable(app ${CPP_SOURCES} app.cpp)

# Link Vulkan and GLFW libraries
target_link_libraries(app PRIVATE vulkan-1 ${GLFW_LIBRARIES})