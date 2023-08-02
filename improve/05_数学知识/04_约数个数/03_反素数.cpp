// 对于任何正整数 x
// ，其约数的个数记作 g(x)
// ，例如 g(1)=1、g(6)=4
// 。

// 如果某个正整数 x
//  满足：对于任意的小于 x
//  的正整数 i
// ，都有 g(x)>g(i)
// ，则称 x
//  为反素数。

// 例如，整数 1，2，4，6
//  等都是反素数。

// 现在给定一个数 N
// ，请求出不超过 N
//  的最大的反素数。

// 输入格式
// 一个正整数 N
// 。

// 输出格式
// 一个整数，表示不超过 N
//  的最大反素数。

// 数据范围
// 1≤N≤2?109
// 输入样例：
// 1000
// 输出样例：
// 840

/*
g(i) < g(x) x是反素数
1~N中最大的反素数是哪个约数个数最小的数
1.不同的质因子最多只会包含9个，前九个质数相乘已经超过了2e9
2.每个质因子的次数最大是30
3.所有质因子的次数一定递减
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 110;
int primes[N], cnt;
bool st[N];
int res, ans;
int n;

void init(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= n; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

void dfs(int u, int last, int p, int s){
    if(s > res || s == res && p < ans){
        res = s;
        ans = p;
    }
    if(u == 9) return;
    
    for(int i = 1; i <= last; i++){
        if((LL)p * primes[u] > n) break;
        p *= primes[u];
        dfs(u + 1, i, p, s * (i + 1));
    }
}

int main(){
    init(100);
    cin >> n;
    
    dfs(0, 30, 1, 1);
    cout << ans << endl;
    
    return 0; 
}