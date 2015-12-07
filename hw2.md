# HW2

学习使用代码测试覆盖分析工具

对于`gcc` 有专门的选项

只需在编译时开启选项`-fprofile-arcs -ftest-coverage`

## 以`test/test.cpp` 为例

```shell
g++ -fprofile-arcs -ftest-coverage -o test test.cpp -lgtest -lgtest_main -lpthread
./test
gcov test.cpp
cat test.cpp.gcov
``````

更多分析选项

```shell
gcov -b test.cpp
```
