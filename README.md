# GUnitTest
GoogleTest is a C++ unit test framework for classes. This repository is created as part of my learning GoogleTest.

## compile your program:
g++ file1.cpp file2.cpp ... main.cpp -lgtest -lpthread

## Installation
Download GoogleTest https://codeload.github.com/google/googletest/zip/release-1.8.1
unzip googletest-release-1.8.1.zip
cd googletest-release-1.8.1/
mkdir build && cd build
cmake ..
make -j
sudo cp -r ../googletest/include /usr/include
sudo cp -r ./googlemock/gtest/libgtest* /usr/local/lib/
sudo cp -r ./googlemock/libgmock* /usr/local/lib/

## Find googletest with pkg-config
pkg-config --libs --cflags gtest
'If you get a message about gtest not being found (“Package gtest was not found in the pkg-config search path”) then it essentially means pkg-config cannot find gtest’s .pc file which provides configuration' 
pkg-config --variable pc_path pkg-config
e.g. /usr/lib/pkgconfig
Create a file named gtest.pc which should like similar to this:
includedir=/usr/include/

Name: gtest
Description: gtest
Version: 1.8.0
Libs: -lgtest -lpthread
Cflags: -I${includedir}

## Integrating googlemock with a C++ project
Create a file named gmock.pc which should like similar to this:
includedir=/usr/include/

Name: gmock
Description: gmock
Version: 1.8.0
Libs: -lgmock -lpthread
Cflags: -I${includedir}

#### Citation
https://lchsk.com/how-to-set-up-googletest-library-from-source.html
