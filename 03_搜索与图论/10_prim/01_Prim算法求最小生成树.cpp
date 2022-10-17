// 给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环，边权可能为负数。

// 求最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

// 给定一张边带权的无向图 G=(V,E)，其中 V 表示图中点的集合，E 表示图中边的集合，n=|V|，m=|E|。

// 由 V 中的全部 n 个顶点和 E 中 n−1 条边构成的无向连通子图被称为 G 的一棵生成树，其中边的权值之和最小的生成树被称为无向图 G 的最小生成树。

// 输入格式
// 第一行包含两个整数 n 和 m。

// 接下来 m 行，每行包含三个整数 u,v,w，表示点 u 和点 v 之间存在一条权值为 w 的边。

// 输出格式
// 共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

// 数据范围
// 1≤n≤500,
// 1≤m≤105,
// 图中涉及边的边权的绝对值均不超过 10000。

// 输入样例：
// 4 5
// 1 2 1
// 1 3 2
// 1 4 3
// 2 3 2
// 3 4 4
// 输出样例：
// 6

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N]; // 这个是用来保存无向图的
int dist[N]; // 保存这个点到集合的距离，与dijkstra不同，dijkstra保存的是到1的距离
bool st[N]; // 保存这个点是否已经在集合中了

int prim(){
    memset(dist, 0x3f, sizeof dist); // 将所有点到集合的距离都设置为无穷大
    
    int res = 0; // 这个是保存最小生成树最小的
    for(int i = 0; i < n; i++){
        int t = -1;
        // 这一步是为了查找不在集合中的离集合距离最小的点
        for(int j = 1; j <= n; j++)
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        // 如果这个点不是第一个点并且这个离集合最小的点距离是无穷大，说明这个点与集合是不连通了，也就说明了不存在最小生成树
        if(i && dist[t] == INF) return INF;
        if(i) res += dist[t]; // 将这个离集合最小的点的距离累加到res
        
        for(int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]); // 用这个点更新其他还没有在最小生成树的点离集合的距离
        // 注意：第56行和第58行不能对调位置，因为如果给定的边中存在负权值的自环，这样当t==j的时候会把自身的权值给更新了，最小生成树中是不能存在负权值的自环的
        //       否则将它的权值保存起来的话与结果就会不同，所以这两行顺序是固定的，必须先累加权值，在更新其他点与集合的距离
        st[t] = true; // 将这个点保存到最小生成树中
    }
    return res; // 返回这个最小生成树的权重
}

int main(){
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c); // 因为是无向图，所以g[a][b] 和 g[b][a]这两个都要更新，并且可能会出现重边，所以要取小的那一个
    }
    int t = prim();
    if(t == INF) cout << "impossible" << endl;
    else cout << t << endl;
    
    return 0;
}