// 烽火台是重要的军事防御设施，一般建在交通要道或险要处。

// 一旦有军情发生，则白天用浓烟，晚上有火光传递军情。

// 在某两个城市之间有 n
//  座烽火台，每个烽火台发出信号都有一定的代价。

// 为了使情报准确传递，在连续 m
//  个烽火台中至少要有一个发出信号。

// 现在输入 n,m
//  和每个烽火台的代价，请计算在两城市之间准确传递情报所需花费的总代价最少为多少。

// 输入格式
// 第一行是两个整数 n,m
// ，具体含义见题目描述；

// 第二行 n
//  个整数表示每个烽火台的代价 ai
// 。

// 输出格式
// 输出仅一个整数，表示最小代价。

// 数据范围
// 1≤m≤n≤2×105
// ,
// 0≤ai≤1000
// 输入样例：
// 5 3
// 1 2 5 6 2
// 输出样例：
// 4

/*
动态规划
  状态表示f[i]  
    集合：从1-i且点燃i号烽火台的方案
    属性：Min
  状态计算
    f[i] = min(f[j]) + w[i], i - m <= j < i
    使用单调队列
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;
int w[N], q[N]; // w是代价，q是单调队列
int n, m;
int f[N]; // f保存最小代价

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> w[i];
    
    int hh = 0, tt = 0; // 一开始有一个，即第0号烽火台，代价是f[0] = 0，在全局定义，因此可以省略
    for(int i = 1; i <= n; i++){
        if(hh <= tt && q[hh] < i - m) hh++;
        f[i] = f[q[hh]] + w[i]; // 现获取最小值
        while(hh <= tt && f[q[tt]] >= f[i]) tt--; // 再把它自身加进去
        q[++tt] = i;
    }
    
    int res = 1e9;
    for(int i = n; i > n - m; i--) // 最终在 n - m + 1 ~ n取最小值
        res = min(res, f[i]);
        
    cout << res << endl;
    
    return 0;
}