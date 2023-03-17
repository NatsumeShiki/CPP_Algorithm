// 给定一个 n×m
//  的网格，请计算三点都在格点上的三角形共有多少个。

// 下图为 4×4
//  的网格上的一个三角形。

// a.png

// 注意：三角形的三点不能共线。

// 输入格式
// 输入一行，包含两个空格分隔的正整数 m
//  和 n
// 。

// 输出格式
// 输出一个正整数，为所求三角形数量。

// 数据范围
// 1≤m,n≤1000
// 输入样例：
// 2 2
// 输出样例：
// 76

#include<iostream>
using namespace std;

typedef long long LL;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

LL C(int a){
    return (LL)a * (a - 1) * (a - 2) / 6;
}

int main(){
    int n, m;
    cin >> n >> m;
    n++, m++;
    
    LL res = C(n * m) - n * C(m) - m * C(n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            res -= 2 * (gcd(i, j) - 1) * (n - i) * (m - j);
            
    cout << res << endl;
    
    return 0;
}