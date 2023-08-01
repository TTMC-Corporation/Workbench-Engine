# Workbench Engine

### Workbench engine is a small simple game engine written in c++ with vulkan. 
### The map editor is created in c# and you can download here: https://github.com/TTMC-Corporation/Workbench-World-Editor

<br>

# build

<br>

## Linux

### download necessary dependencies
#### debian
``` bash
download necessary dependencies
sudo apt install vulkan-utils libvulkan1
sudo apt install vulkan-dev
```

#### arch
``` bash
sudo pacman -S glfw-x11
pacman -S vulkan-headers
sudo pacman -S vulkan-tools
sudo pacman -S vulkan-validation-layers
```

### install cmake and git

#### debian 
``` bash
sudo ap-get install cmake
sudo ap-get install git
```

#### arch
``` bash
sudo pacman -S cmake
sudo pacman -S git
```

### download and build the project
``` bash
git clone https://github.com/TTMC-Corporation/Workbench-Engine
cd Workbench-Engine
mkdir build
cd build
cmake ..
make
```

### run
``` bash
./app
```

<br>