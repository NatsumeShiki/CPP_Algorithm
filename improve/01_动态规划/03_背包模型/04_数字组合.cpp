// 给定 N
//  个正整数 A1,A2,…,AN
// ，从中选出若干个数，使它们的和为 M
// ，求有多少种选择方案。

// 输入格式
// 第一行包含两个整数 N
//  和 M
// 。

// 第二行包含 N
//  个整数，表示 A1,A2,…,AN
// 。

// 输出格式
// 包含一个整数，表示可选方案数。

// 数据范围
// 1≤N≤100
// ,
// 1≤M≤10000
// ,
// 1≤Ai≤1000
// ,
// 答案保证在 int 范围内。

// 输入样例：
// 4 4
// 1 1 2 2
// 输出样例：
// 3

// 自己的代码  二维
/*
M看成是背包容量
把每个数看成一个物品，Ai看成体积
目标：求出总体积恰好是M的方案数

动态规划：
  状态表示f[i, j]
    集合：所有只从前i个物品中选，且总体积恰好是j的方案的集合
    属性：Count
  状态计算：
    1.不包含物品i的所有选法 f[i - 1, j]
    2.包含物品i的所有选法 f[i, j - vi]
  所以 f[i][j] = f[i - 1][j] + f[i - 1][j - vi]

  要先把 f[0][0] 设置成1，表示从前0个物品选，且总体积恰好是0的方案数是1，空集也是一种方案
  然后 f[0][1] f[0][1] .. f[0][m] 都是0，从前0个物品选体积只会是0，所有初始时这些方案数都是0 
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, M = 1e5 + 10;
int f[N][M];

int main(){
    int n, m;
    cin >> n >> m;
    
    f[0][0] = 1;
    
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for(int j = 0; j <= m; j++){
            f[i][j] = f[i - 1][j];
            if(j >= x) f[i][j] += f[i - 1][j - x];
        }
    }
    
    cout << f[n][m] << endl;
    return 0;
}

// 自己的代码 一维
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, M = 1e5 + 10;
int f[M];

int main(){
    int n, m;
    cin >> n >> m;
    
    f[0] = 1;
    
    for(int i = 1; i <= n; i++){
        int v;
        cin >> v;
        for(int j = m; j >= v; j--)
            f[j] += f[j - v];
    }
    
    cout << f[m] << endl;
    
    return 0;
}

// 大佬的代码
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int f[N];

int main(){
    cin >> n >> m;
    
    f[0] = 1;
    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        for(int j = m; j >= v; j--)
            f[j] += f[j - v];
    }
    
    cout << f[m] << endl;
    
    return 0;
}