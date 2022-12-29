// 大家都知道 Fibonacci 数列吧，f1=1,f2=1,f3=2,f4=3,…,fn=fn−1+fn−2。

// 现在问题很简单，输入 n 和 m，求 fn 的前 n 项和 Snmodm。

// 输入格式
// 共一行，包含两个整数 n 和 m。

// 输出格式
// 输出前 n 项和 Snmodm 的值。

// 数据范围
// 1≤n≤2000000000,
// 1≤m≤1000000010
// 输入样例：
// 5 1000
// 输出样例：
// 12

/*
Fn = [ fn, f(n+1), sn ]
F(n+1) = [ f(n+1), f(n+2), s(n+1) ]
Fn * A = F(n+1)
[ fn, f(n+1), sn ][0 1 0] = [ f(n+1), f(n+2), s(n+1) ]
                  [1 1 1]
                  [0 1 1]
所以要求第n个斐波那契数，直接 fn = f1 * A^(n-1)即可，时间复杂度是logn
*/
#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 3;
int n, m;

void mul(int c[], int a[], int b[][N]){ // 一维乘二维
    int temp[N] = {0};
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            temp[i] = (temp[i] + (LL)a[j] * b[j][i]) % m;
            
    memcpy(c, temp, sizeof temp);
}

void mul(int c[][N], int a[][N], int b[][N]){ // 二维乘二维
    int temp[N][N] = {0};
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++)
                temp[i][j] = (temp[i][j] + (LL)a[i][k] * b[k][j]) % m;
    memcpy(c, temp, sizeof temp);
}

int main(){
    cin >> n >> m;
    
    int f1[N] = {1, 1, 1}; // 分别是 {f1, f2, s1}
    int a[N][N] = { // 保存矩阵
        {0, 1, 0},
        {1, 1, 1},
        {0, 0, 1}
    };
    n--;
    while(n){
        if(n & 1) mul(f1, f1, a); // res = res * a
        mul(a, a, a); // a = a * a
        n >>= 1;
    }
    cout << f1[2] << endl;
    return 0;
}