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

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;
int w[N], f[N], q[N];
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> w[i];
    int hh = 0, tt = 0;
    for(int i = 1; i <= n; i++){
        if(q[hh] < i - m) hh++;
        f[i] = w[i] + f[q[hh]];
        while(hh <= tt && f[q[tt]] >= f[i]) tt--;
        q[++tt] = i;
    }
    int res = 1e9;
    for(int i = n; i > n - m; i--) res = min(res, f[i]);
    cout << res << endl;
    
    return 0;
}