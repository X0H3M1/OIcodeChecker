# OIcodeChecker
通用对拍器，使用时无需手动添加 freopen，但是需要自备随机数据生成器（以后会在程序中集成数据生成器），暂不支持 SPJ

### 教程：
1. 把待测程序(.cpp)拖入命令行中，回车（即为粘贴路径）
2. 如 1 步，拖入标程，回车
3. 如 2 步，拖入随机数据生成器，回车
4. 对拍就开始了

### 数据生成器
- 随机数据生成器封装在 "OIrandServer.h" 中，使用时请先 `#include "OIrandServer.h"` 
##### 提供调用的类名为 OIrandServer，其成员函数如下:
1. 构造函数，生成真随机数作为 mt19937 的种子
2. `int rand_range(int minn, int maxx)` 返回一个 $[minn, maxx]$ 之间的随机数
3. `int* rand_Sequence(int lenth, int minn, int maxx, char div = ' ', bool whether_Print = 1)` 生成随机整数序列，返回生成出的随机数数组的起始地址，数组大小为 $lenth * sizeof(int) + 100$ ，有效数字下标从 1 开始，前三个参数必须指定，分别为需要生成的序列的长度，序列中元素的最小值，序列中元素的最大值，第四个参数为打印序列时各个数字之间的分隔字符，默认为空格，第五个参数为是否需要将生成的序列打印出来，默认为 1 (需要打印)
4. `int* rand_Permutation(int minn, int maxx, char div = ' ', bool whether_Print = 1)` 生成 $[minn, maxx]$ 之间的随机排列，返回生成出的数组的起始地址，数组大小为 $lenth * sizeof(int) + 100$ ，有效数字下标从 1 开始, 后两个参数的意义与 2 同
5. `Pair* rand_Vector(int total_Need, int minn, int maxx, bool Reversible = 0, bool whether_Print = 1)` 生成随机向量（也可以理解为一对 $l$ 和 $r$），返回一个 $Pair$ 类型的数组，$Pair$ 类只有 `Pair.l` 和 `Pair.r` 两个成员，在上文中没有解释的参数有：$total\_Need$: 需要生成的向量个数，$Reversible$: 是否允许 $l > r$（默认不允许）
6. `Pair* rand_Tree(int n, bool withval = 0, int minn = 0, int maxx = 0, bool couldlian = 1, bool couldjuhua = 1, bool whether_Print = 1)` 生成大小为 $n$ 的随机树，返回一个 $Pair$ 类型的数组，必须指定的只有第一个参数，接下来的参数意义分别为：树上的边是否带权，边权的最小值，边权的最大值（仅在 $withval$ 为 1 时生效），是否允许链式图，是否允许菊花图，生成完毕后是否打印
   注意：$couldlian$ 和 $couldjuhua$ 为 1 时，各有 $\frac{1}{50}$ 的几率必定生成这两种图，但是这两个值为 0 时，如果您运气足够好，也可能会出现链式图和菊花图
7. `Pair* rand_Map(int n, int m, bool directed = 1, bool withval = 0, int minn = 0, int maxx = 0, bool whether_Print = 1)` 生成含有 $n$ 个点 $m$ 条边的随机图，无重边和自环，$directed$ 参数表示生成的图是否有向，默认为 1 (有向图)

##### 实例：
生成 $n$ 个点 $m$ 条边的有向图，每个点有权值
```c++
#include <bits/stdc++.h>
#include "OIrandServer.h"
using namespace std;

int main()
{
    OIrandServer rd;
    int n = rd.rand_range(5, 8), m = rd.rand_range(n, n + 5); // 合适的 n 和 m
    printf("%d %d\n", n, m);
    rd.rand_Sequence(n, 1, 5); // 生成长度为 n，值域为 [1, 5] 的随机序列作为点权
    rd.rand_Map(n, m); // 生成随机的不带权的图
}
```
同时，返回指针的设定使您可以重复利用生成的随机数序列，例如，如果您想记录一个长度为 $n$ 的随机序列并且不打印它们，您可以这样做：
`int *ptr = rd.rand_Sequence(n, 1, 5, ' ', 0);`
接下来，您可以把 ptr 当作数组一样使用，例如，假如您想要输出随机序列的第二项，只需 `printf("%d", ptr[2]);` 即可

### 注意：
1. 请确保 g++ 在环境变量中
2. 编译选项为 C++14，开启 O2 优化
3. 路径中不能有中文，不然会寄
4. 程序无 TLE 检测机制，若卡死请自行 ctrl+c 强制退出
5. 请注意 main 函数的格式，否则可能导致程序因检测不到 main 函数而添加不了 freopen，以下4种格式是可接受的
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
6. 我十分强烈地建议您使用此种方法而不是 `srand(time(0))` 生成随机数种子：
```c++
struct timeb t;
ftime(&t);
srand(t.time * 1000 + t.millitm);
```
此方法会指定毫秒级的随机数种子
一般情况下，一秒钟会对拍多组数据，若不在这一秒内多次更新随机数种子，在这一秒内多次运行的程序生成的随机数据会是相同的，从而大大降低运行效率
7. 请确保您的输入语句不会在 main 函数前执行
8. 程序尚未经过十分充分的测试，若发现 bug 请联系 X0H3M6
9. 程序中藏了一个 flag，格式为 flag{xxxxxxxxxxxxxxxxxxxxxxxxxxxxx}

## v1.1
1. 更新了 README.md，加入了对于 g++ 环境变量、随机数种子的建议内容，并详细说明了 flag 格式
2. 将对拍的输入数据名由 "test.in" 改为 "data.in"
3. 加入了若对拍正确的数据组数大于 1000 则结束程序的机制
4. 提高了执行效率

## v1.2
1. 现在路径中可以包含空格了
2. 在输入待检测程序时输入 "last"，会自动使用上一次对拍使用的程序
3. 更新了检验用户输入的方式，使其更加合理
4. 加入了编译进度实时显示
5. 在对拍时，您可以按 esc 手动结束
6. 对拍正常结束时会输出已对拍数据的最大最小和平均用时
7. 完善了 README.md

## v1.3
修复了两个 bug

## v1.4
1. 修复了一个 bug
2. 附赠了随机数生成器，考虑到随机数的生成需求非常多样，生成器被做成了头文件的形式并封装成类，提供调用接口