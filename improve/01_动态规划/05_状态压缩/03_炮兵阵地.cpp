// 司令部的将军们打算在 N×M
//  的网格地图上部署他们的炮兵部队。

// 一个 N×M
//  的地图由 N
//  行 M
//  列组成，地图的每一格可能是山地（用 H 表示），也可能是平原（用 P 表示），如下图。

// 在每一格平原地形上最多可以布置一支炮兵部队（山地上不能够部署炮兵部队）；一支炮兵部队在地图上的攻击范围如图中黑色区域所示：

// 1185_1.jpg

// 如果在地图中的灰色所标识的平原上部署一支炮兵部队，则图中的黑色的网格表示它能够攻击到的区域：沿横向左右各两格，沿纵向上下各两格。

// 图上其它白色网格均攻击不到。

// 从图上可见炮兵的攻击范围不受地形的影响。

// 现在，将军们规划如何部署炮兵部队，在防止误伤的前提下（保证任何两支炮兵部队之间不能互相攻击，即任何一支炮兵部队都不在其他支炮兵部队的攻击范围内），在整个地图区域内最多能够摆放多少我军的炮兵部队。

// 输入格式
// 第一行包含两个由空格分割开的正整数，分别表示 N
//  和 M
// ；

// 接下来的 N
//  行，每一行含有连续的 M
//  个字符(P 或者 H)，中间没有空格。按顺序表示地图中每一行的数据。

// 输出格式
// 仅一行，包含一个整数 K
// ，表示最多能摆放的炮兵部队的数量。

// 数据范围
// N≤100,M≤10
// 输入样例：
// 5 4
// PHPP
// PPHH
// PPPP
// PHPP
// PHHP
// 输出样例：
// 6

/*
状态压缩DP
  状态表示f[i, j, k]
    集合：所有已经摆完前i行，且第i-1行的状态是j，第i行的状态是k的所有摆放方案的最大值
    属性：Max
  状态计算：
    枚举第i、i-1、i-2这三行的方案，如果不符合下面这两个条件，就continue，否则去较大值
    1.((a & b) | (a & c) | (b & c)) == 0
    2.(g[i - 1] & a | g[i] & b) == 0
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 11, M = 1 << 10;
int n, m;
int g[110]; // 每一行记录不能摆放的位置
int cnt[M]; // 记录每一种合法方案中可以放的数量
vector<int> state; // 保存合法方案
int f[2][M][M]; // 使用滚动数组，否则 100 * M * M 是1亿，题目给出空间是64mb，空间不够，所以使用滚动数组

bool check(int state){ // 检查该方案是否合法
    for(int i = 0; i < m; i++)
        if((state >> i & 1) && ((state >> i + 1 & 1) || (state >> i + 2 & 1)))  // i位置放置，i+1或者i+2位置也有放置就非法
            return false;
            
    return true;
}

int count(int state){ // 计算该方案中放置的数量
    int res = 0;
    for(int i = 0; i < m; i++) res += state >> i & 1;
    return res;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = m - 1; j >= 0; j--){
            char t;
            cin >> t;
            if(t == 'H') g[i] += 1 << j;
        }
        
    for(int i = 0; i < 1 << m; i++)
        if(check(i)){
            state.push_back(i);
            cnt[i] = count(i);
        }
            
    for(int i = 1; i <= n + 2; i++)
        for(int j = 0; j < state.size(); j++) // 第i行
            for(int k = 0; k < state.size(); k++) // 第i-1行
                for(int u = 0; u < state.size(); u++){ // 第i-2行
                    int a = state[j], b = state[k], c = state[u]; // 获取这三行的方案
                    if((a & b) | (a & c) | (b & c)) continue; // 如果其中有两个 & 不为0，说明不合法
                    if(g[i] & a | g[i - 1] & b) continue; // 如果g[i] & a 不为0 或者 g[i-1] & b 不为0，说明放置在了山地上，不合法
                    f[i & 1][k][j] = max(f[i & 1][k][j], f[i - 1 & 1][u][k] + cnt[a]); // 否则，取较大值
                }
                
    cout << f[n + 2 & 1][0][0] << endl; // 最终输出摆放了前n + 2行，第n和n+1行都没有摆放的最大值
    
    return 0;
}