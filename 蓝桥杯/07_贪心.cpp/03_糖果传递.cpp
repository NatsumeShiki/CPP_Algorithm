// 有 n 个小朋友坐成一圈，每人有 a[i] 个糖果。

// 每人只能给左右两人传递糖果。

// 每人每次传递一个糖果代价为 1。

// 求使所有人获得均等糖果的最小代价。

// 输入格式
// 第一行输入一个正整数 n，表示小朋友的个数。

// 接下来 n 行，每行一个整数 a[i]，表示第 i 个小朋友初始得到的糖果的颗数。

// 输出格式
// 输出一个整数，表示最小代价。

// 数据范围
// 1≤n≤1000000,
// 0≤a[i]≤2×109,
// 数据保证一定有解。

// 输入样例：
// 4
// 1
// 2
// 5
// 4
// 输出样例：
// 4

/*
思路：
  n个数围成一圈，假设从ai给a(i-1)糖果，记为xi，这个xi可以为正也可以为负
  假设 xi为正是 ai 给 a(i-1)  xi为负是 a(i-1) 给 ai
  目标：最小化 abs(x1) + abs(x2) + ... + abs(xn)
  假设 a* 是 a1-an的平均值
  那么可以得到：
    a1 - x1 + x2 = a*
    a2 - x2 + x3 = a*
    .
    .
    .
    a(n-1) - x(n-1) + xn = a*
    an - xn + x1 = a*
    求解这个方程组
    每次让后面的方程加到前面的方程，这个方程组可以转化为
    x1 - x2 = a1 - a*                                        x1 = x1 - 0
    x2 - x3 = a2 - a*                                        x2 = x1 - ( (n-1)a* - a2 - a3 - ... - an )
    .                                                        .
    .                                                        .
    .                                                        .   
    x(n-2) - x(n-1) = a(n-2) - a*                            x(n-2) = x1 - (3a* - a(n-2) - a(n-1) - an)
    x(n-1) - xn = a(n-1) - a*                                x(n-1) = x1 - (2a* - a(n-1) - an)
    xn - x1 = an - a*                                        xn = x1 - (a* - an)

    记 cn = (a* - an)  c(n-1) = (2a* - a(n-1) - an) = cn + a* -a(n-1)
    可以得到 ci = c(i+1) + a* - ai

  于是目标就可以转化为求 abs(x1 - c1) + abs(x1 - c2) + ... + abs(x1 - cn)，在数轴上找一个点x1，使其到 c1 ~ cn 的距离和最小
  也就是货仓选址的变形
*/
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N = 1e6 + 10;

int n;
int a[N];
LL c[N];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    LL sum = 0;
    for(int i = 1; i <= n; i++) sum += a[i];
    
    LL avg = sum / n;
    for(int i = n; i > 1; i--)
        c[i] = c[i + 1] + avg - a[i];
        
    c[1] = 0;
    
    sort(c + 1, c + n + 1);
    
    LL res = 0;
    for(int i = 1; i <= n; i++) res += abs(c[i] - c[(i + 1) / 2]);
    
    cout << res << endl;
    
    return 0;
}