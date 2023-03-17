// 给定 n
//  组询问，每组询问给定两个整数 a，b
// ，请你输出 Cbamod(109+7)
//  的值。

// 输入格式
// 第一行包含整数 n
// 。

// 接下来 n
//  行，每行包含一组 a
//  和 b
// 。

// 输出格式
// 共 n
//  行，每行输出一个询问的解。

// 数据范围
// 1≤n≤10000
// ,
// 1≤b≤a≤105
// 输入样例：
// 3
// 3 1
// 5 3
// 2 2
// 输出样例：
// 3
// 10
// 1

#include<iostream>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10, mod = 1e9 + 7;
int fact[N], infact[N], n;

int qmi(int a, int b, int mod){
    int res = 1;
    while(b){
        if(b & 1) res = (LL)res * a % mod;
        a = (LL)a * a % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    fact[0] = infact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = (LL)fact[i - 1] * i % mod;
        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
    
    cin >> n;
    while(n--){
        int a, b;
        cin >> a >> b;
        cout << (LL)fact[a] * infact[a - b] % mod * infact[b] % mod << endl;
    }
    
    
    return 0;
}