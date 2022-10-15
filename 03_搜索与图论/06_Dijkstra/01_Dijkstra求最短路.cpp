// 给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，所有边权均为正值。

// 请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 −1。

// 输入格式
// 第一行包含整数 n 和 m。

// 接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

// 输出格式
// 输出一个整数，表示 1 号点到 n 号点的最短距离。

// 如果路径不存在，则输出 −1。

// 数据范围
// 1≤n≤500,
// 1≤m≤105,
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
#include<algorithm>

using namespace std;

const int N = 510;
int n, m;
int g[N][N]; // 记录权重
int dist[N]; // 用来记录从1到这个点的最短距离
bool st[N]; // 用来记录某个点是否已经确定了最短距离

int dijkstra(){
    memset(dist, 0x3f, sizeof dist); // 将1到所有点的距离都改成无穷大
    dist[1] = 0; // 1到1距离是0
    for(int i = 0; i < n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++) // 这个循环的目的是为了查找一个还没有确定最小距离，并且dist是最小的那个边
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        if(t == n) break; // 这个表示此时的路径已经是最短的了，可以退出循环
        st[t] = true; // 将这个点设置成已经是最最短路径了
        for(int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]); // 通过这个点更新所有点，如果此时的dist[j] 是大于 dist[t] + 权值 的，表示通过t这个点到j点距离会更短
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main(){
    cin >> n >> m;
    memset(g, 0x3f, sizeof g); // 把邻接矩阵所有值都改成最大值
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c); // 因为可能会出现重边，所以要保留小的那一个
    }
    
    int t = dijkstra();
    
    cout << t << endl;
    
    
    return 0;
}