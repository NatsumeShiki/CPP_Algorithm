// 给定一个 n
//  个点 m
//  条边的有向图，图中可能存在重边和自环，所有边权均为正值。

// 请你求出 1
//  号点到 n
//  号点的最短距离，如果无法从 1
//  号点走到 n
//  号点，则输出 −1
// 。

// 输入格式
// 第一行包含整数 n
//  和 m
// 。

// 接下来 m
//  行每行包含三个整数 x,y,z
// ，表示存在一条从点 x
//  到点 y
//  的有向边，边长为 z
// 。

// 输出格式
// 输出一个整数，表示 1
//  号点到 n
//  号点的最短距离。

// 如果路径不存在，则输出 −1
// 。

// 数据范围
// 1≤n≤500
// ,
// 1≤m≤105
// ,
// 图中涉及边长均不超过10000。

// 输入样例：
// 3 3
// 1 2 2
// 2 3 1
// 1 3 4
// 输出样例：
// 3

#include<iostream>
#include<cstring>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int g[N][N];
int dist[N];
bool st[N];
int n, m;

void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i = 0; i < n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++)
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
                
        if(t == n) return;
        st[t] = true;
        
        for(int j = 1; j <= n; j++)
            if(!st[j])
                dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
}

int main(){
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    
    dijkstra();
    
    if(dist[n] == INF) puts("-1");
    else cout << dist[n] << endl;
    
    return 0;
}