# Workbench Engine

## What is the Workbanch Engine?

### Workbench engine is a small simple game engine written in c++ with vulkan

### The map editor is created in c# and you can download here: <https://github.com/TTMC-Corporation/Workbench-World-Editor>

## Install dependences

### Arch

``` bash
sudo pacman -S glfw-x11 
sudo pacman -S vulkan-headers 
sudo pacman -S vulkan-tools
sudo pacman -S vulkan-validation-layers
sudo pacman -S cmake
```

### Debian

``` bash
sudo apt-get install vulkan-utils
sudo apt-get install libvulkan1 
sudo apt-get install vulkan-dev
sudo apt-get install cmake
```

## Build and run the project

``` bash
git clne https://github.com/TTMC-Corporation/Workbench-Engine.git
cd Workbench-Engine
mkdir build && cd build
cmake ../
make
```

``` bash
./app
```