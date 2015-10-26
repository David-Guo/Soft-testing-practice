## Google test 安装：

环境：ubuntu 14.04

编译器：g++

1. Get the googletest framework

    $ wget https://github.com/google/googletest/archive/release-1.7.0.zip

2. Unzip and build google test

    $ unzip gtest-1.7.0.zip
    $ cd gtest-1.7.0
    $ ./configure
    $ make

3. "Install" the headers and libs on my system.

    $ sudo cp -a include/gtest /usr/include
    $ sudo cp -a lib/.libs/* /usr/lib/

4. Update the cache of the linker

    sudo ldconfig -v | grep gtest

## 简单使用
 
`test.cpp` 文件：

``C++
#include <gtest/gtest.h>
TEST(MathTest, TwoPlusTwoEqualsFour) {
    EXPECT_EQ(2 + 2, 4);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}

$  g++ -Wall -o test test.cpp  -lgtest -lgtest_main -lpthread
``

## 参考


[How to properly setup googleTest on Linux](http://stackoverflow.com/questions/13513905/how-to-properly-setup-googletest-on-linux#comment49621755_21314020)
