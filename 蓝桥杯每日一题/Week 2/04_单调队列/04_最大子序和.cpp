// 输入一个长度为 n
//  的整数序列，从中找出一段长度不超过 m
//  的连续子序列，使得子序列中所有数的和最大。

// 注意： 子序列的长度至少是 1
// 。

// 输入格式
// 第一行输入两个整数 n,m
// 。

// 第二行输入 n
//  个数，代表长度为 n
//  的整数序列。

// 同一行数之间用空格隔开。

// 输出格式
// 输出一个整数，代表该序列的最大子序和。

// 数据范围
// 1≤n,m≤300000
// 输入样例：
// 6 4
// 1 -3 5 1 -2 3
// 输出样例：
// 7

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 3e5 + 10;
int a[N], q[N];
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
    int hh = 0, tt = 0;
    int res = -1e9;
    for(int i = 1; i <= n; i++){
        if(hh <= tt && q[hh] < i - m) hh++;
        while(hh <= tt && a[q[tt]] >= a[i]) tt--;
         
        res = max(res, a[i] - a[q[hh]]);
        q[++tt] = i;
    }
    cout << res << endl;
     
    return 0;
}