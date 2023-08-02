// 夏洛克有了一个新女友（这太不像他了！）。

// 情人节到了，他想送给女友一些珠宝当做礼物。

// 他买了 n
//  件珠宝，第 i
//  件的价值是 i+1
// ，也就是说，珠宝的价值分别为 2,3,…,n+1
// 。

// 华生挑战夏洛克，让他给这些珠宝染色，使得一件珠宝的价格是另一件珠宝的价格的质因子时，两件珠宝的颜色不同。

// 并且，华生要求他使用的颜色数尽可能少。

// 请帮助夏洛克完成这个简单的任务。

// 输入格式
// 只有一行一个整数 n
// ，表示珠宝件数。

// 输出格式
// 第一行一个整数 k
// ，表示所使用的颜色数；

// 第二行 n
//  个整数，表示第 1
//  到第 n
//  件珠宝被染成的颜色。

// 若有多种答案，输出任意一种。

// 请用 1
//  到 k
//  表示你用到的颜色。

// 数据范围
// 1≤n≤105
// 输入样例1：
// 3
// 输出样例1：
// 2
// 1 1 2
// 输入样例2：
// 4
// 输出样例2：
// 2
// 2 1 1 2

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int primes[N], cnt;
bool st[N];

void init(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= n; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}


int main(){
    int n;
    cin >> n;
    n++;
    init(n);
    
    if(n <= 3) puts("1");
    else puts("2");
    for(int i = 2; i <= n; i++)
        if(!st[i]) cout << 1 << " ";
        else cout << 2 << " ";
    
    return 0;
}