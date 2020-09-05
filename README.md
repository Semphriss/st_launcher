# SuperTux launcher

[![Travis build status](https://travis-ci.com/semphris-bot/st_launcher.svg?branch=master)](https://travis-ci.com/semphris-bot/)
[![AppVeyor build status](https://ci.appveyor.com/api/projects/status/5c5y2gp7wq65qo5d/?svg=true)](https://ci.appveyor.com/project/semphris-bot/st-launcher/)

This is a simple program that allows users to manage multiple versions of SuperTux on a single computer.

### Downloads

There are no downloads available yet. You are very welcome to contribute!

### Install from source

You will need the following tools:
- Build essentials (A C++ compiler like clang or gcc, make, etc.)
- CMake, version 3.10 or later

1. Download the source code either as a ZIP archive or with `git`.
2. Open a terminal and navigate to the source folder (the folder containing `README.md`)
3. `mkdir build; cd build`
4. `cmake ..`
5. `make` (You can also use `make -j$(nproc)` or `make -j8` where 8 is the number of cores on your computer)
6. Launch with `./st_launcher`
