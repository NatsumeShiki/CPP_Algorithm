// 有 N
//  件物品和一个容量是 V
//  的背包，背包能承受的最大重量是 M
// 。

// 每件物品只能用一次。体积是 vi
// ，重量是 mi
// ，价值是 wi
// 。

// 求解将哪些物品装入背包，可使物品总体积不超过背包容量，总重量不超过背包可承受的最大重量，且价值总和最大。
// 输出最大价值。

// 输入格式
// 第一行三个整数，N,V,M
// ，用空格隔开，分别表示物品件数、背包容积和背包可承受的最大重量。

// 接下来有 N
//  行，每行三个整数 vi,mi,wi
// ，用空格隔开，分别表示第 i
//  件物品的体积、重量和价值。

// 输出格式
// 输出一个整数，表示最大价值。

// 数据范围
// 0<N≤1000

// 0<V,M≤100

// 0<vi,mi≤100

// 0<wi≤1000
// 输入样例
// 4 5 6
// 1 2 3
// 2 4 4
// 3 4 5
// 4 5 6
// 输出样例：
// 8

// 自己的代码 三维
/*
动态规划
  状态表示f[i, j, k]
    集合：所有只从前i个物品中选，并且总体积不超过j，总重量不超过k的选法
    属性：Max
  状态计算：
    1.所有不包含物品i的选法 f[i - 1, j, k]
    2.所有包含物品i的选法 f[i - 1, j - vi, k - mi] + wi
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010, K = 110;
int f[N][K][K];
int n, V, M;

int main(){
    cin >> n >> V >> M;
    for(int i = 1; i <= n; i++){
        int v, m, w;
        cin >> v >> m >> w;
        for(int j = 0; j <= V; j++)
            for(int k = 0; k <= M; k++){
                f[i][j][k] = f[i - 1][j][k];
                if(j >= v && k >= m) f[i][j][k] = max(f[i][j][k], f[i - 1][j - v][k - m] + w);
            }
    }
    cout << f[n][V][M] << endl;
    
    return 0;
}

// 自己的代码 二维
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;
int f[N][N];
int n, V, M;

int main(){
    cin >> n >> V >> M;
    for(int i = 1; i <= n; i++){
        int v, m, w;
        cin >> v >> m >> w;
        for(int j = V; j >= v; j--)
            for(int k = M; k >= m; k--)
                f[j][k] = max(f[j][k], f[j - v][k - m] + w);
    }
    
    cout << f[V][M] << endl;
    
    return 0;
}