# OIcodeChecker
花大半天时间写成的通用对拍器，使用时无需手动添加 freopen，但是需要自备随机数据生成器（以后会在程序中集成数据生成器）
##### 教程：
1、把待测程序(.cpp)拖入命令行中，回车（即为粘贴路径，路径中目前不能有空格）
2、如 1 步，拖入标程，回车
3、如 2 步，拖入随机数据生成器，回车
4、对拍就开始了
##### 注意：
1、编译选项为 C++14，开启 O2 优化
2、程序未开启 TLE 检测，若卡死请自行 ctrl+c 强制退出
3、请注意 main 函数的格式，否则可能导致程序因检测不到 main 函数而添加不了 freopen，以下4种格式是可接受的
```c++
int main(){
    //code
}
int main()
{
    //code
}
signed main(){
    //code
}
signed main()
{
    //code
}
```
下面的例子是不能接受的
```c++
int n, m, a[10005]; int main(){
    //code
}
int n, m, a[10005]; int main()
{
    //code
}
int main(int argc, const char **argv, const char **envp)
{
    //code
}
```
~~我也相信应该没人会这么写~~
4、程序尚未经过十分充分的测试，若发现 bug 请联系 X0H3M6
5、程序中藏了一个 flag