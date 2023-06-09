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
sudo pacman -S vulkan-icd-loader vulkan-validation-layers
sudo pacman -S vulkan-devel
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

## Windows

### install cmake and git
https://cmake.org/download/
https://git-scm.com/downloads

### download and build the project
``` cmd
git clone https://github.com/TTMC-Corporation/Workbench-Engine
cd Workbench-Engine
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

### run
``` cmd
cd Relase
./app.exe
```