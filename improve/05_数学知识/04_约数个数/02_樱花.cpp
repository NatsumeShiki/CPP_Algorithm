// 给定一个整数 n
// ，求有多少正整数数对 (x,y)
//  满足 1x+1y=1n!
// 。

// 输入格式
// 一个整数 n
// 。

// 输出格式
// 一个整数，表示满足条件的数对数量。

// 答案对 109+7
//  取模。

// 数据范围
// 1≤n≤106
// 输入样例：
// 2
// 输出样例：
// 3
// 样例解释
// 共有三个数对 (x,y)
//  满足条件，分别是 (3,6),(4,4),(6,3)
// 。

/*
1/x + 1/y = 1/n!
(x + y) / xy = 1/n!
x*n! + y*n! = xy
x*n! = (x - n!)*y
y = x*n! / (x - n!) = (x - n! + n!) * n! / (x - n!) = (x - n!)*n! / (x - n!) + n!^2 / (x - n!) = n! + n!^2 / (x - n!)
所以这道题意思就是求 n! ^ 2 的约数个数
n! = p1 ^ c1 + p2 ^ c2 + ... + pn ^ cn
因此n!的约数个数为 (c1 + 1) * (c2 + 1) * ... * (cn + 1)
n! ^ 2 = p1 ^ 2c1 + p2 ^ 2c2 + ... + pn ^ 2cn
因此n! ^ 2的约数个数为 (2c1 + 1) * (2c2 + 1) * ... * (2cn + 1)
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, mod = 1e9 + 7;
int primes[N], cnt;
bool st[N];
int n;

void init(){
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= n; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main(){
    cin >> n;
    init();
    
    int res = 1;
    for(int i = 0; i < cnt; i++){
        int p = primes[i];
        int s = 0;
        for(int j = n; j; j /= p) s += j / p;
        res = (res * (2ll * s + 1)) % mod;
    }
    cout << res << endl;
    
    return 0;
}