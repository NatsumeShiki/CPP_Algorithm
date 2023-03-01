// 城市的规划在城市建设中是个大问题。

// 不幸的是，很多城市在开始建设的时候并没有很好的规划，城市规模扩大之后规划不合理的问题就开始显现。

// 而这座名为 Fractal 的城市设想了这样的一个规划方案，如下图所示：

// city.png

// 当城区规模扩大之后，Fractal 的解决方案是把和原来城区结构一样的区域按照图中的方式建设在城市周围，提升城市的等级。

// 对于任意等级的城市，我们把正方形街区从左上角开始按照道路标号。

// 虽然这个方案很烂，Fractal 规划部门的人员还是想知道，如果城市发展到了等级 N
// ，编号为 A
//  和 B
//  的两个街区的直线距离是多少。

// 街区的距离指的是街区的中心点之间的距离，每个街区都是边长为 10
//  米的正方形。

// 输入格式
// 第一行输入正整数 n
// ，表示测试数据的数目。

// 以下 n
//  行，输入 n
//  组测试数据，每组一行。

// 每组数据包括三个整数 N,A,B
// ，表示城市等级以及两个街区的编号，整数之间用空格隔开。

// 输出格式
// 一共输出 n
//  行数据，每行对应一组测试数据的输出结果，结果四舍五入到整数。

// 数据范围
// 1≤N≤31
// ,
// 1≤A,B≤22N
// ,
// 1≤n≤1000
// 输入样例：
// 3 
// 1 1 2 
// 2 16 1 
// 3 4 33 
// 输出样例：
// 10 
// 30 
// 50

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;

PLL calc(LL n, LL m){
    if(n == 0) return {0, 0};
    LL len = 1 << n - 1, cnt = 1ll << 2 * n - 2;
    auto pos = calc(n - 1, m % cnt);
    auto x = pos.first, y = pos.second;
    auto z = m / cnt;
    if(z == 0) return {y, x};
    if(z == 1) return {x, y + len};
    if(z == 2) return {x + len, y + len};
    return {2 * len - 1 - y, len - 1 - x};
}

int main(){
    int t;
    cin >> t;
    while(t--){
        LL n, a, b;
        cin >> n >> a >> b;
        auto ac = calc(n, a - 1);
        auto bc = calc(n, b - 1);
        double x = ac.first - bc.first, y = ac.second - bc.second;
        printf("%.0lf\n", sqrt(x * x + y * y) * 10);
    }
}