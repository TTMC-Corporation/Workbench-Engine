cmake_minimum_required(VERSION 3.26.0)
project(WorkbenchEngine LANGUAGES CXX)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Vulkan REQUIRED)

# Specify the include directory for GLFW
if (UNIX)
    set(GLFW_INCLUDE_DIRS "/usr/include/GLFW") 

else()
    set(GLFW_INCLUDE_DIRS "C:/Users/Andris-PC/Downloads/glfw-3.3.8.bin.WIN64/include/GLFW/")
    
endif()

# Add source files
file(GLOB CPP_SOURCES "src/log/*.cpp")
file(GLOB CPP_SOURCES "src/renderer/*.cpp")

# Create the executable
add_executable(app ${CPP_SOURCES} app.cpp)

# Add header files
target_include_directories(app PRIVATE "headers/log")
target_include_directories(app PRIVATE "headers/renderer")

# Link Vulkan and GLFW libraries
target_link_libraries(app PRIVATE ${VULKAN_LIBRARIES} ${GLFW_LIBRARIES})

# Specify the GLFW library
target_link_libraries(app PRIVATE glfw)