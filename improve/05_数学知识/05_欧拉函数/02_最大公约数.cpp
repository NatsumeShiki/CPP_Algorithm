// 给定整数 N
// ，求 1≤x,y≤N
//  且 GCD(x,y)
//  为素数的数对 (x,y)
//  有多少对。

// GCD(x,y)
//  即求 x，y
//  的最大公约数。

// 输入格式
// 输入一个整数 N
// 。

// 输出格式
// 输出一个整数，表示满足条件的数对数量。

// 数据范围
// 1≤N≤107
// 输入样例：
// 4
// 输出样例：
// 4

/*
数据范围是1e7，要求gcd(x, y)是素数
那么 一层循环枚举质数p，二层循环枚举x从1到n，三层循环枚举y从1到n，如果gcd(x, y)等于p，结果就自增，
他就等于 一维循环枚举p，二维循环枚举x从1到n/p，三维循环枚举y从1到n/p，如果gcd(x, y)等于1，结果就自增
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e7 + 10;
int primes[N], cnt;
bool st[N];
int n;
LL s[N], phi[N];

void init(int n){
    // phi[1] = 1;
    for(int i = 2; i <= n; i++){
        if(!st[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; primes[j] * i <= n; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0){
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1); 
        }
    }
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + phi[i];
}

int main(){
    cin >> n;
    init(n);
    LL res = 0;
    for(int i = 0; i < cnt; i++){
        int p = primes[i];
        res += (LL)s[n / p] * 2 + 1;
    }
    cout << res << endl;
    
    return 0;
}