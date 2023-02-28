// 假设现在有两个自然数 A
//  和 B
// ，S
//  是 AB
//  的所有约数之和。

// 请你求出 Smod9901
//  的值是多少。

// 输入格式
// 在一行中输入用空格隔开的两个整数 A
//  和 B
// 。

// 输出格式
// 输出一个整数，代表 Smod9901
//  的值。

// 数据范围
// 0≤A,B≤5×107
// 输入样例：
// 2 3
// 输出样例：
// 15
// 注意: A
//  和 B
//  不会同时为 0
// 。

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int mod = 9901;

int qmi(int a, int k){
    a %= mod;
    int res = 1;
    while(k){
        if(k & 1) res = res * a % mod;
        a = a * a % mod;
        k >>= 1;
    }
    return res;
}

int sum(int p, int k){
    if(k == 0) return 1;
    if(k % 2 == 0) return (p % mod * sum(p, k - 1) + 1) % mod;
    return (1 + qmi(p, k / 2 + 1)) * sum(p, k / 2) % mod;
}

int main(){
    int A, B;
    cin >> A >> B;
    int res = 1;
    for(int i = 2; i <= A; i++){
        int s = 0;
        while(A % i == 0){
            s++;
            A /= i;
        }
        if(s) res = res * sum(i, s * B) % mod;
    }
    if(!A) res = 0;
    cout << res << endl;
    
    
    return 0;
}