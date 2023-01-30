// 有 N
//  件物品和一个容量是 V
//  的背包。每件物品只能使用一次。

// 第 i
//  件物品的体积是 vi
// ，价值是 wi
// 。

// 求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。

// 输出 最优选法的方案数。注意答案可能很大，请输出答案模 109+7
//  的结果。

// 输入格式
// 第一行两个整数，N，V
// ，用空格隔开，分别表示物品数量和背包容积。

// 接下来有 N
//  行，每行两个整数 vi,wi
// ，用空格隔开，分别表示第 i
//  件物品的体积和价值。

// 输出格式
// 输出一个整数，表示 方案数 模 109+7
//  的结果。

// 数据范围
// 0<N,V≤1000

// 0<vi,wi≤1000
// 输入样例
// 4 5
// 1 2
// 2 4
// 3 4
// 4 6
// 输出样例：
// 2

/*
动态规划
  状态表示f[i, j] g[i, j]，f是价值的最大值，g保存方案数
    集合：从前i个物品中选，体积恰好为j的方案
    属性：Max
  状态计算：
    左边：不选i f[i - 1][j]
    右边：选i f[i - 1][j - v] + w
    1.左大 g[i][j] = g[i - 1, j] f[i][j] = f[i - 1][j]
    2.右大 g[i][j] = g[i - 1, j - v] f[i][j] = f[i - 1][j - v] + w
    3.左 == 右 g[i][j] = g[i - 1, j] + g[i - 1, j - v] f[i][j] = f[i - 1][j]
*/
// 二维
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 1010, mod = 1e9 + 7;
int f[N][N], g[N][N];
int n, m;

int main(){
    cin >> n >> m;
    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;
    g[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        int v, w;
        cin >> v >> w;
        
        for(int j = 0; j <= m; j++){
            int maxv;
            if(j < v) maxv = f[i - 1][j];
            else maxv = max(f[i - 1][j], f[i - 1][j - v] + w);
            int cnt = 0;
            if(maxv == f[i - 1][j]) cnt += g[i - 1][j];
            if(j >= v && maxv == f[i - 1][j - v] + w) cnt += g[i - 1][j - v];
            g[i][j] = cnt % mod;
            f[i][j] = maxv;
        }
    }
    
    int res = 0;
    for(int i = 0; i <= m; i++) res = max(res, f[n][i]);
    int cnt = 0;
    for(int i = 0; i <= m; i++)
        if(res == f[n][i])
            cnt = (cnt + g[n][i]) % mod;
    
    cout << cnt << endl;
    
    return 0;
}


// 一维
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010, mod = 1e9 + 7;
int f[N], g[N];
int n, m;

int main(){
    cin >> n >> m;
    
    memset(f, -0x3f, sizeof f); // 从前0个物品选，体积刚好等于i(i != 0)的方案不存在，所以设置成无穷小
    f[0] = 0; // 从前0个物品选，体积刚好等于0的价值最大是0
    g[0] = 1; // 从前0个物品选，体积刚好等于0的方案数是1，即什么都不选
    
    while(n--){
        int v, w;
        cin >> v >> w;
        for(int j = m; j >= v; j--){
            int maxv = max(f[j], f[j - v] + w); // 现获取较大的价值
            int cnt = 0; // cnt保存方案数
            if(maxv == f[j]) cnt += g[j];
            if(maxv == f[j - v] + w) cnt += g[j - v];
            f[j] = maxv;
            g[j] = cnt % mod;
        }
    }
    
    int res = 0; // f[i]记录的是体积刚好等于i时的价值的最大值，所以需要从0-m遍历一遍获取最大价值
    for(int i = 0; i <= m; i++) res = max(res, f[i]);
    int cnt = 0;
    for(int i = 0; i <= m; i++) // 再遍历一遍获取等于最大价值时方案数
        if(res == f[i]) 
            cnt = (cnt + g[i]) % mod;
    
    cout << cnt << endl;
    
    return 0;
}