#!/bin/bash

#install dependences
if [ -f "/etc/arch-release" ]; then
    #arch
    #check if a package is installed and if not install
    package_names=("glfw-x11" "vulkan-headers" "vulkan-tools" "vulkan-validation-layers" "cmake")

    for package_name in "${package_names[@]}"; do
        if pacman -Qs "$package_name" > /dev/null; then
            echo "$package_name already installed."
        else
            echo "$package_name is not installed."
            sudo pacman -Sy --noconfirm $package_name
        fi
    done

elif [ -f "/etc/os-release" ]; then
    #debian
    #check if a package is installed and if not install
    if grep -qi "ID=debian" "/etc/os-release"; then
        package_names=("vulkan-utils" "libvulkan1" "vulkan-dev" "cmake")

        for package_name in "${package_names[@]}"; do
            if dpkg -s "$package_name" &> /dev/null; then
                echo "$package_name already installed."
            else
                echo "$package_name is not installed."
                sudo apt-get install -y $package_name
            fi
        done
    fi   
fi

# build the project
build()
{
    cd build 
    cmake ..
    make
}

#check if build folder exisit
if [ -d "./build" ]; then
    echo "the folder is already exist"
    build
else
    echo "folder doesn't exist creating..."
    mkdir build
    build
fi

./app