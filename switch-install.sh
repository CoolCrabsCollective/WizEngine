#! /bin/bash

cmake -B build-switch -S . -DCMAKE_TOOLCHAIN_FILE=../cmake/toolchains/DevkitA64Libnx.cmake
cd build-switch
make
cd ..

sudo cp out/switch/* $DEVKITPRO/portlibs/switch/lib/
sudo cp -r include/* $DEVKITPRO/portlibs/switch/include/
sudo cp -r build-switch/_deps/sfml-src/include/* $DEVKITPRO/portlibs/switch/include/
