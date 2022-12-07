// 给定 n 组数据 ai,bi,mi，对于每组数求出一个 xi，使其满足 ai×xi≡bi(modmi)，如果无解则输出 impossible。

// 输入格式
// 第一行包含整数 n。

// 接下来 n 行，每行包含一组数据 ai,bi,mi。

// 输出格式
// 输出共 n 行，每组数据输出一个整数表示一个满足条件的 xi，如果无解则输出 impossible。

// 每组数据结果占一行，结果可能不唯一，输出任意一个满足条件的结果均可。

// 输出答案必须在 int 范围之内。

// 数据范围
// 1≤n≤105,
// 1≤ai,bi,mi≤2×109
// 输入样例：
// 2
// 2 3 6
// 4 3 5
// 输出样例：
// impossible
// -3

// 这道题是扩展欧几里得算法的应用，或者变形
// 题目要求一个数x，使得 ax 等同于 b (mod m)
// 那么存在一个数y，这个y是整数，使得 ax = my + b
// ax - my = b
// 令y1 = y
// 所以 ax + my1 = b
// 通过exgcd(a, m)求出a和m的最大公约数以及x，y1的结果无所谓
// 然后通过上面的x，把x * (b / d)，就得出结果了，因为上面的公式是满足 ax + my = d，而正确的应该是 ax + my = b
// 第二个式子的结果是第一个式子的 b / d倍，所以x相应的也要乘以 b / d
// 无解的情况是  b % gcd(a, m) != 0 
#include<iostream>
using namespace std;

typedef long long LL;

int exgcd(int a, int b, int &x, int& y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int a, b, m;
        cin >> a >> b >> m;
        int x, y;
        int d = exgcd(a, m, x, y);
        if(b % d) cout << "impossible" << endl;
        else cout << (LL)x * (b / d) % m << endl;
    }
    return 0;
}