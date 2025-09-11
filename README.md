# BIT course

## Brief

A simple OS like early Linux implemented in C (Developing...)

## Build

build it on `macOS`

如果brew没有安装请访问官网：
https://brew.sh

GCC编译器 和 CMake
```bash
brew install x86_64-elf-gcc
brew install x86_64-elf-gdb
brew isntall cmake
```

Qemu模拟器
```bash
brew install qemu
```

请使用vscode打开项目
```bash
cd OSKernel-2025-plugOS-main/os/os
```

## Run

1.Build
选择[GCC 15.2.0 x86_64-elf]
2.Run Task
此时Qemu会启动
3.F5启动调试
