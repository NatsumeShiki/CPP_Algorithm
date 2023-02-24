// 给定两个升序排序的有序数组 A
//  和 B
// ，以及一个目标值 x
// 。

// 数组下标从 0
//  开始。

// 请你求出满足 A[i]+B[j]=x
//  的数对 (i,j)
// 。

// 数据保证有唯一解。

// 输入格式
// 第一行包含三个整数 n,m,x
// ，分别表示 A
//  的长度，B
//  的长度以及目标值 x
// 。

// 第二行包含 n
//  个整数，表示数组 A
// 。

// 第三行包含 m
//  个整数，表示数组 B
// 。

// 输出格式
// 共一行，包含两个整数 i
//  和 j
// 。

// 数据范围
// 数组长度不超过 105
// 。
// 同一数组内元素各不相同。
// 1≤数组元素≤109
// 输入样例：
// 4 5 6
// 1 2 4 7
// 3 4 6 8 9
// 输出样例：
// 1 1

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];
int n, m, x;

int main(){
    cin >> n >> m >> x;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int j = 0; j < m; j++) cin >> b[j];
    
    for(int i = 0, j = m - 1; i < n; i++){
        while(a[i] + b[j] > x) j--;
        if(a[i] + b[j] == x) cout << i << " " << j << endl;
    }
    
    return 0;
}