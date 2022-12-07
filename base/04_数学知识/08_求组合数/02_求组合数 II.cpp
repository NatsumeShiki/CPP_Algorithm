// 给定 n 组询问，每组询问给定两个整数 a，b，请你输出 C(b)(a) mod (1e9+7) 的值。

// 输入格式
// 第一行包含整数 n。

// 接下来 n 行，每行包含一组 a 和 b。

// 输出格式
// 共 n 行，每行输出一个询问的解。

// 数据范围
// 1≤n≤10000,
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

// C(a)(b) = a! / ((a-b)! * b!)，通过逆元的定义，a如果可以整除b，那么存在一个x，使得a/b = a*x(mod m)，所以可以把除法变成乘法，前提是这个m得是质数
// 通过一个数组fact保存1-n的阶乘，再用一个数组infact保存1-n的阶乘的逆元
// 即 fact[i] = i! % mod, infact[i] = (i!)的逆元 % mod
// 那么C(a)(b) = a! / ((a-b)! * b!) 就可以变成 C(a)(b) = fact[a] * infact[a-b] * infact[b]，注意数组中每个数的范围
// 两个 1e9 级别的数可以用longlong保存，但是三个这样的数相乘就会超出范围，所以两个数相乘之后就要模一个数
// 所以上面的式子还得变成 C(a)(b) = fact[a] * infact[a-b] % mod * infact[b] % mod，注意数组中每个数的范围
#include<iostream>
using namespace std;

typedef long long LL;
const int N = 100010, mod = 1e9 + 7;

int fact[N], infact[N];

// 求逆元
int qmi(int a, int k, int p){
    int res = 1;
    while(k){
        if(k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

int main(){
    fact[0] = infact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = (LL)fact[i - 1] * i % mod; // fact[i] = i! % mod = (i-1)! * i % mod = fact[i-1] * i % mod
        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
        // infact[i] = (i!)的逆元 % mod = ((i-1)! & i)的逆元 % mod = (i-1)!的逆元 * i的逆元 % mod = infact[i-1] * i的逆元 % mod
    }
    int n;
    cin >> n;
    while(n--){
        int a, b;
        cin >> a >> b;
        cout << (LL)fact[a] * infact[b] % mod * infact[a - b] % mod << endl;
    }
    return 0;
}