// 农夫约翰的土地由 M×N
//  个小方格组成，现在他要在土地里种植玉米。

// 非常遗憾，部分土地是不育的，无法种植。

// 而且，相邻的土地不能同时种植玉米，也就是说种植玉米的所有方格之间都不会有公共边缘。

// 现在给定土地的大小，请你求出共有多少种种植方法。

// 土地上什么都不种也算一种方法。

// 输入格式
// 第 1
//  行包含两个整数 M
//  和 N
// 。

// 第 2..M+1
//  行：每行包含 N
//  个整数 0
//  或 1
// ，用来描述整个土地的状况，1
//  表示该块土地肥沃，0
//  表示该块土地不育。

// 输出格式
// 输出总种植方法对 108
//  取模后的值。

// 数据范围
// 1≤M,N≤12
// 输入样例：
// 2 3
// 1 1 1
// 0 1 0
// 输出样例：
// 9

/*
状态压缩DP
  状态表示f[i, s]
    集合：所有已经摆完前i行，且第i行的状态是s的所有摆放方案的集合
    属性：Count
  状态计算：
    已经摆完前i行，且第i行的状态是a，第i-1行的状态是b的所有摆放方案
    枚举第i-1行的状态b，累加起来 f[i - 1, b]
      两个条件：
        1.a，b的二进制表示中不包含连续两个1
        2.a & b == 0
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 15, M = 1 << 12, mod = 1e8;
int n, m;
int g[N]; // 保存第i行，注意，这里1变成0，0变成1，意思是为1的地方不能摆放
vector<int> state; // 所有合法的状态
vector<int> head[M]; // 第i行为a，第i-1行为合法的方案
int f[N][M];

bool check(int state){ // 记录合法的方案
    for(int i = 0; i < m - 1; i++)  
        if((state >> i & 1) && (state >> i + 1 & 1))
            return false;
    
    return true;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = m - 1; j >= 0; j--){
            int t;
            cin >> t;
            g[i] += !t << j; // 最终g[i]保存为1的位置是不能种玉米的
        }
        
    for(int i = 0; i < 1 << m; i++)
        if(check(i))
            state.push_back(i);
            
    for(int i = 0; i < state.size(); i++)
        for(int j = 0; j < state.size(); j++){
            int a = state[i], b = state[j];
            if((a & b) == 0)
                head[i].push_back(j);
        }
        
    f[0][0] = 1; // 摆了前0行，且第0行摆放方案是0的方案有1种
    for(int i = 1; i <= n + 1; i++) // 枚举到第n+1行
        for(int a = 0; a < state.size(); a++){
            if(g[i] & state[a]) continue; // 如果g[i] & state[a]不为0，表示玉米田在某个位置不能使用，但是方案state[a]需要，因此该方案不可行
            for(int b : head[a])
                f[i][a] = (f[i][a] + f[i - 1][b]) % mod; // 累加上第i-1行为b的方案数
        }
            
    cout << f[n + 1][0] << endl; // 最终输出摆放了前n+1行，且第n+1行为0的方案数
    
    return 0;
}