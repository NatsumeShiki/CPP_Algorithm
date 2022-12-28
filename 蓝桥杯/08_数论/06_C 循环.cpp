// 对于 C 语言的循环语句，形如：

// for (variable = A; variable != B; variable += C)
//   statement;
// 请问在 k 位存储系统中循环几次才会结束。

// 若在有限次内结束，则输出循环次数。否则输出死循环。

// 输入格式
// 多组数据，每组数据一行四个整数 A,B,C,k。

// 读入以 0 0 0 0 结束。

// 输出格式
// 若在有限次内结束，则输出循环次数。

// 否则输出 FOREVER。

// 数据范围
// 1≤k≤32,
// 0≤A,B,C<2k
// 输入样例：
// 3 3 2 16
// 3 7 2 16
// 7 3 2 16
// 3 4 2 16
// 0 0 0 0
// 输出样例：
// 0
// 2
// 32766
// FOREVER

/*
110010在3位存储系统中表示为 010，也就是2
所以题目的意思是让求 (A + xC) % 2^k = B，求这个x的最小值
(A + xC) % 2^k = B
A + xC - y*(2^k) = B
xC - y*(2^k) = B - A  (ax + by = c)
这里 C就相当于a，2^k相当于b，B-A相当于c
通过扩展欧几里得算法获得最大公约数d，如果(B-A)不能除尽d，就说明无解
否则，有解
想让左边 x和y同时乘以 (B-A)/d，这是因为c应该是x和y的最大公约数d，但是现在是(B-A)，所以要扩展 (B-A)/d 倍
x = x0 + k*(b/d)
所以x的最小值就是 x % (b/d) 的正数
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
    LL a, b, c;
    int k;
    while(cin >> a >> b >> c >> k, a || b || c || k){
        LL x, y;
        LL z = 1ll << k; // 获得 2^k
        
        LL d = exgcd(c, z, x, y); // d是最大公约数
        if((b - a) % d) puts("FOREVER"); // 如果除不尽，无解
        else{
            x *= (b - a) / d; // 让左边扩大 (b-a)/d 倍
            z /= d; // 获得 b/d
            cout << (x % z + z) % z << endl; // 最终求正的余数即可
        }
    }
    
    return 0;
}