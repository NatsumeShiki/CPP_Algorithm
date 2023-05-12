// 给定一个由 n
//  个点 m
//  条边构成的无向图，请你求出该图删除一个点之后，连通块最多有多少。

// 输入格式
// 输入包含多组数据。

// 每组数据第一行包含两个整数 n,m
// 。

// 接下来 m
//  行，每行包含两个整数 a,b
// ，表示 a,b
//  两点之间有边连接。

// 数据保证无重边。

// 点的编号从 0
//  到 n−1
// 。

// 读入以一行 0 0
//  结束。

// 输出格式
// 每组数据输出一个结果，占一行，表示连通块的最大数量。

// 数据范围
// 1≤n≤10000
// ,
// 0≤m≤15000
// ,
// 0≤a,b<n
// 输入样例：
// 3 3
// 0 1
// 0 2
// 2 1
// 4 2
// 0 1
// 2 3
// 3 1
// 1 0
// 0 0
// 输出样例：
// 1
// 2
// 2

#include<iostream>
#include<cstring>
using namespace std;

const int N = 10010, M = 30010;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int root, ans;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u){
    dfn[u] = low[u] = ++timestamp;
    int cnt = 0;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjan(j);
            low[u] = min(low[u], low[j]);
            if(low[j] >= dfn[u]) cnt++; // 如果low[j] >= dfn[u]，说明u是个割点，删除u连通块数目加1
        }else low[u] = min(low[u], dfn[j]);
    }
    
    if(u != root && cnt) cnt++; // 如果u不是根节点，并且此时cnt不为0，则删除它之后与根节点之间会断开，相当于还有一个连通块
    
    ans = max(ans, cnt); // 删除割点获取连通块最大值
}

int main(){
    while(scanf("%d%d", &n, &m), n || m){
        memset(dfn, 0, sizeof dfn); // 初始化dfn，dfn除了记录数据的作用外还有判重的作用
        memset(h, -1, sizeof h);
        idx = timestamp = 0;
        
        while(m--){
            int a, b;
            scanf("%d%d", &a, &b);
            add(a, b), add(b, a);
        }
        
        ans = 0; // ans保存将割点删除后可以得出多少个连通块
        int cnt = 0; // 保存连通块的数目
        for(root = 0; root < n; root++)
            if(!dfn[root]){ // 如果dfn[root]为0，连通块数目加1
                cnt++;
                tarjan(root);
            }
            
        printf("%d\n", ans + cnt - 1);
    }
    
    return 0;
}