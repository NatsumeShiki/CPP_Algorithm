// 给定 n 对正整数 ai,bi，对于每对数，求出一组 xi,yi，使其满足 ai×xi+bi×yi=gcd(ai,bi)。

// 输入格式
// 第一行包含整数 n。

// 接下来 n 行，每行包含两个整数 ai,bi。

// 输出格式
// 输出共 n 行，对于每组 ai,bi，求出一组满足条件的 xi,yi，每组结果占一行。

// 本题答案不唯一，输出任意满足条件的 xi,yi 均可。

// 数据范围
// 1≤n≤105,
// 1≤ai,bi≤2×109
// 输入样例：
// 2
// 4 6
// 8 18
// 输出样例：
// -1 1
// -2 1

#include<iostream>
using namespace std;

int exgcd(int a, int b, int& x, int& y){
    if(!b){
      // 此时 gcd(a, b) = a，b是0，那么最大公约数就是a
      // 所以要求x和y，使得 ax + by = 0，当x = 1，y = 0时等式必成立
        x = 1, y = 0;
        return a;
    }
    // 一开始 ax1 + by1 = gcd(a, b), bx2 + (a % b)y2 = gcd(b, a % b)
    // 所以 ax1 + by1 = bx2 + (a % b) * y2
    //                = bx2 + (a - a/b(整除) * b) * y2
    //                = ay2 + (x2 - a/b(整除) * y2) * b
    // 因此 x1 = y2，y1 = x2 - a/b(整除) * y2
    // 这就是为什么下面x和y要交换，以及 y -= a / b * x 的原因 
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int a, b, x, y;
        cin >> a >> b;
        exgcd(a, b, x, y);
        cout << x << " " << y << endl;
    }
    return 0;
}