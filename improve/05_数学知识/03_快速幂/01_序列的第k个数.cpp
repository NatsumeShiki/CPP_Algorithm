// BSNY 在学等差数列和等比数列，当已知前三项时，就可以知道是等差数列还是等比数列。

// 现在给你 整数 序列的前三项，这个序列要么是等差序列，要么是等比序列，你能求出第 k
//  项的值吗。

// 如果第 k
//  项的值太大，对其取模 200907
// 。

// 输入格式
// 第一行一个整数 T
// ，表示有 T
//  组测试数据；

// 对于每组测试数据，输入前三项 a,b,c
// ，然后输入 k
// 。

// 输出格式
// 对于每组数据，输出第 k
//  项取模 200907
//  的值。

// 数据范围
// 1≤T≤100
// ,
// 1≤a≤b≤c≤109
// ,
// 1≤k≤109
// 输入样例：
// 2
// 1 2 3 5
// 1 2 4 5
// 输出样例：
// 5
// 16

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mod = 200907;

LL qmi(LL a, LL b){
    LL res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int a, b, c, k;
        cin >> a >> b >> c >> k;
        if(b - a == c - b){
            LL len = b - a;
            cout << (a + len % mod * (k - 1) % mod) % mod << endl;
        }else{
            int len = b / a;
            cout << (LL)a * qmi(len, k - 1) % mod << endl;
        }
    }
    
    return 0;
}