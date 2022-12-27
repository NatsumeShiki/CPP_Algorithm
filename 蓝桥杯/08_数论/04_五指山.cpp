// 大圣在佛祖的手掌中。

// 我们假设佛祖的手掌是一个圆圈，圆圈的长为 n，逆时针记为：0,1,2,…,n−1，而大圣每次飞的距离为 d。

// 现在大圣所在的位置记为 x，而大圣想去的地方在 y。

// 要你告诉大圣至少要飞多少次才能到达目的地。

// 注意：孙悟空的筋斗云只沿着逆时针方向翻。

// 输入格式
// 有多组测试数据。

// 第一行是一个正整数 T，表示测试数据的组数；

// 每组测试数据包括一行，四个非负整数，分别为如来手掌圆圈的长度 n，筋斗所能飞的距离 d，大圣的初始位置 x 和大圣想去的地方 y。

// 输出格式
// 对于每组测试数据，输出一行，给出大圣最少要翻多少个筋斗云才能到达目的地。

// 如果无论翻多少个筋斗云也不能到达，输出 Impossible。

// 数据范围
// 1≤T≤5,
// 2<n<109,
// 0<d<n,
// 0≤x,y<n
// 输入样例：
// 2
// 3 2 0 2
// 3 2 0 1
// 输出样例：
// 1
// 2

/*
这道题的意思是求 x + bd = y(mod n)
变形成 x + bd = y + an
      -an + bd = y - x
在这里面，n d (y-x) 是常数，-a和b是变量
那么如果 (y-x)可以整除 (n,d)的最大公约数gcd，就表明有解
然后让左右两边同时除以  (y-x)/gcd 就可以得到原式子
现在要求b的最小值，b的表达式是 b = b0 + k * n/gcd
所以最终的结果就是 b0 mod gcd，并且结果是正数
*/
#include<iostream>
using namespace std;

typedef long long LL;

LL exgcd(LL a, LL b, LL &x, LL &y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        LL n, d, x, y, a, b;
        cin >> n >> d >> x >> y;
        int gcd = exgcd(n, d, a, b); // 先获得n和d的最大公约数
        if((y - x) % gcd) puts("Impossible"); // 如果不可以被y-x除尽，表明无解
        else{ // 否则
            b *= (y - x) / gcd; // 让b 乘以 (y-x)/gcd 获得b
            n /= gcd; // 得到 n/gcd
            cout << (b % n + n) % n << endl; // 最终按照 b mod gcd这个式子获得结果即可
        }
    }
    
    return 0;
}