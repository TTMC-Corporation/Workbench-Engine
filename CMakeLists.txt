cmake_minimum_required(VERSION 3.26.0)
project(WorkbenchEngine LANGUAGES CXX)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Relase)

find_package(Vulkan REQUIRED)

# Specify the include directory for GLFW
if (UNIX)
    set(GLFW_INCLUDE_DIRS "/usr/include/GLFW") 

else()
    set(GLFW_INCLUDE_DIRS "C:/Users/Andris-PC/Downloads/glfw-3.3.8.bin.WIN64/include/GLFW/")
    
endif()

# Add source files
file(GLOB CPP_SOURCES_1 "src/log/*.cpp")
file(GLOB CPP_SOURCES_2 "src/renderer/*.cpp")
file(GLOB CPP_SOURCES_3 "src/game/*.cpp")

# Create the executable
add_executable(app ${CPP_SOURCES_1} ${CPP_SOURCES_2} ${CPP_SOURCES_3} app.cpp)

# Add header files
target_include_directories(app PRIVATE "headers/log")
target_include_directories(app PRIVATE "headers/renderer")
target_include_directories(app PRIVATE "headers/game")

# Link Vulkan and GLFW libraries
target_link_libraries(app PRIVATE ${VULKAN_LIBRARIES} ${GLFW_LIBRARIES})

# Specify the GLFW library
target_link_libraries(app PRIVATE Vulkan::Vulkan glfw)