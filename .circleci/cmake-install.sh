#!/usr/bin/env bash
echo "========> Install CMake"
cd $HOME
wget --quiet https://github.com/Kitware/CMake/releases/download/v3.13.3/cmake-3.13.3-Linux-x86_64.tar.gz && tar -xf cmake-3.13.3-Linux-x86_64.tar.gz
ln -s cmake-3.13.3-Linux-x86_64 cmake_folder