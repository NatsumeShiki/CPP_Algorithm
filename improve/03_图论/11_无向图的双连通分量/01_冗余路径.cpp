// 为了从 F
//  个草场中的一个走到另一个，奶牛们有时不得不路过一些她们讨厌的可怕的树。

// 奶牛们已经厌倦了被迫走某一条路，所以她们想建一些新路，使每一对草场之间都会至少有两条相互分离的路径，这样她们就有多一些选择。

// 每对草场之间已经有至少一条路径。

// 给出所有 R
//  条双向路的描述，每条路连接了两个不同的草场，请计算最少的新建道路的数量，路径由若干道路首尾相连而成。

// 两条路径相互分离，是指两条路径没有一条重合的道路。

// 但是，两条分离的路径上可以有一些相同的草场。

// 对于同一对草场之间，可能已经有两条不同的道路，你也可以在它们之间再建一条道路，作为另一条不同的道路。

// 输入格式
// 第 1
//  行输入 F
//  和 R
// 。

// 接下来 R
//  行，每行输入两个整数，表示两个草场，它们之间有一条道路。

// 输出格式
// 输出一个整数，表示最少的需要新建的道路数。

// 数据范围
// 1≤F≤5000
// ,
// F−1≤R≤10000
// 输入样例：
// 7 7
// 1 2
// 2 3
// 3 4
// 2 5
// 4 5
// 5 6
// 5 7
// 输出样例：
// 2

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 5010, M = 20010;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
int id[N], dcc_cnt;
bool is_bridge[M]; // 判断边是否为桥
int d[N]; // 保存一个点的度数

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u, int from){
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjan(j, i);
            low[u] = min(low[u], low[j]);
            if(dfn[u] < low[j]) // 如果成立，说明i这条边是桥
                is_bridge[i] = is_bridge[i ^ 1] = true; // 则把正向边i和反向边i^1设置为true
        }else if(i != (from ^ 1)) low[u] = min(low[u], dfn[j]); // 如果i不是from的反向边，则更新low[u]
    }
    
    if(dfn[u] == low[u]){
        ++dcc_cnt;
        int y;
        do{
            y = stk[top--];
            id[y] = dcc_cnt;
        }while(y != u);
    }
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--){
        int a, b;
        cin >> a >>b;
        add(a, b), add(b, a); // 无向边，加两条
    }
    
    tarjan(1, -1);
    
    for(int i = 0; i < idx; i++) // 枚举每一条边
        if(is_bridge[i]) // 如果这个边是桥
            d[id[e[i]]]++; // 则让连通块的入度加1
            
    int cnt = 0; // 统计度为1的点的个数
    for(int i = 1; i <= dcc_cnt; i++)
        if(d[i] == 1)
            cnt++;
            
    cout << (cnt + 1) / 2 << endl;
    
    return 0;
}