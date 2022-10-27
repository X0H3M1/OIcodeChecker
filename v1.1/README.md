# OIcodeChecker
花大半天时间写成的通用对拍器，使用时无需手动添加 freopen，但是需要自备随机数据生成器（以后会在程序中集成数据生成器）
##### 教程：
1、把待测程序(.cpp)拖入命令行中，回车（即为粘贴路径，路径中目前不能有空格）
2、如 1 步，拖入标程，回车
3、如 2 步，拖入随机数据生成器，回车
4、对拍就开始了
##### 注意：
1、请确保 g++ 在环境变量中
2、编译选项为 C++14，开启 O2 优化
3、程序未开启 TLE 检测，若卡死请自行 ctrl+c 强制退出
4、请注意 main 函数的格式，否则可能导致程序因检测不到 main 函数而添加不了 freopen，以下4种格式是可接受的
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
5、我十分强烈地建议您使用此种方法而不是 `srand(time(0))` 生成随机数种子：
```c++
struct timeb t;
ftime(&t);
srand(t.time * 1000 + t.millitm);
```
此方法会指定毫秒级的随机数种子
一般情况下，一秒钟会对拍多组数据，若不在这一秒内多次更新随机数种子，在这一秒内生成的随机数据会是相同的，从而大大降低运行效率
6、程序尚未经过十分充分的测试，若发现 bug 请联系 X0H3M6
7、程序中藏了一个 flag，格式为 flag{xxxxxxxxxxxxxxxxxxxxxxxxxxxxx}

## v1.1
1、更新了 README.md，加入了对于 g++ 环境变量、随机数种子的建议内容，并详细说明了 flag 格式
2、将对拍的输入数据名由 "test.in" 改为 "data.in"
3、加入了若对拍正确的数据组数大于 1000 则结束程序的机制
4、提高了执行效率