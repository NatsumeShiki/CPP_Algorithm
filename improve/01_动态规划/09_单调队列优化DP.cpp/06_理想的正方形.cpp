// 有一个 a×b
//  的整数组成的矩阵，现请你从中找出一个 n×n
//  的正方形区域，使得该区域所有数中的最大值和最小值的差最小。

// 输入格式
// 第一行为三个整数，分别表示 a,b,n
//  的值；

// 第二行至第 a+1
//  行每行为 b
//  个非负整数，表示矩阵中相应位置上的数。

// 输出格式
// 输出仅一个整数，为 a×b
//  矩阵中所有“n×n
//  正方形区域中的最大整数和最小整数的差值”的最小值。

// 数据范围
// 2≤a,b≤1000
// ,
// n≤a,n≤b,n≤100
// ,
// 矩阵中的所有数都不超过 109
// 。

// 输入样例：
// 5 4 2
// 1 2 5 6
// 0 17 16 0
// 16 17 2 1
// 2 10 2 1
// 1 2 2 2
// 输出样例：
// 1

/*
前求出每一行长度为k区间的最小值和最大值，分别保存在row_min和row_max中
然后在每一列枚举，求出长度为k区间的最大值和最小值，此时 k * k 大小的范围内的最大值和最小值就都保存下来了，然后在用最大值减最小值取最小即可
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1010;

int n, m, k;
int w[N][N];
int row_max[N][N], row_min[N][N]; // 保存第i行j-k+1 ~ j的最大值和最小值
int q[N]; // 单调队列

void get_min(int a[], int b[], int tot){
    int hh = 0, tt = -1;
    for(int i = 1; i <= tot; i++){
        if(hh <= tt && q[hh] <= i - k) hh++;
        while(hh <= tt && a[q[tt]] >= a[i]) tt--;
        q[++tt] = i;
        b[i] = a[q[hh]];
    }
}

void get_max(int a[], int b[], int tot){
    int hh = 0, tt = -1;
    for(int i = 1; i <= tot; i++){
        if(hh <= tt && q[hh] <= i - k) hh++;
        while(hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;
        b[i] = a[q[hh]];
    }
}

int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> w[i][j];
            
    for(int i = 1; i <= n; i++){
        get_min(w[i], row_min[i], m); // 获取每一行长度为k区间内的最小值
        get_max(w[i], row_max[i], m); // 获取每一行长度为k区间内的最大值
    }
    
    int res = 1e9; // 计算最小值
    int a[N], b[N], c[N]; // a用来保存一行的最小值和最大值
    for(int i = k; i <= m; i++){ // 枚举列，从k开始
        for(int j = 1; j <= n; j++) a[j] = row_min[j][i]; // 将第j列保存在a中，保存的是最小值
        get_min(a, b, n); // 使用单调队列获取长度为k区间的最小值
        
        for(int j = 1; j <= n; j++) a[j] = row_max[j][i]; // 将第j列保存在a中，保存的是最大值
        get_max(a, c, n); // 使用单调队列获取长度为k区间的最大值
        
        for(int j = k; j <= n; j++) res = min(res, c[j] - b[j]); // 从第k行开始，用最大值减最小值，取较小的作为结果
    }
    
    cout << res << endl;
    
    return 0;
}