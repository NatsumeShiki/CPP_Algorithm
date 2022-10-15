// 给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。

// 请你求出从 1 号点到 n 号点的最多经过 k 条边的最短距离，如果无法从 1 号点走到 n 号点，输出 impossible。

// 注意：图中可能 存在负权回路 。

// 输入格式
// 第一行包含三个整数 n,m,k。

// 接下来 m 行，每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

// 点的编号为 1∼n。

// 输出格式
// 输出一个整数，表示从 1 号点到 n 号点的最多经过 k 条边的最短距离。

// 如果不存在满足条件的路径，则输出 impossible。

// 数据范围
// 1≤n,k≤500,
// 1≤m≤10000,
// 1≤x,y≤n，
// 任意边长的绝对值不超过 10000。

// 输入样例：
// 3 3 1
// 1 2 1
// 2 3 1
// 1 3 3
// 输出样例：
// 3

#include<iostream>
#include<cstring>
using namespace std;

const int N = 510, M = 10010;
int n, m, k;
int dist[N], backup[N]; // dist是用来记录从1到这个点的距离，backup是用来记录第k次循环的时候第k-1时的dist的样子

struct Edge{
    int a, b, w;
}edges[M];

void bellman_ford(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i = 0; i < k; i++){
        memcpy(backup, dist, sizeof dist); // 将本次循环的dist备份一份，目的是防止下面这个循环中更新了某个点造成的串联的现象
        for(int j = 0; j < m; j++){
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w); // 如果dist[b] 小于 dist[a] + a到b的权值就更新dist[t]
        }
    }
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    bellman_ford();
    if(dist[n] > 0x3f3f3f3f / 2) cout << "impossible" << endl; // 点数不超过500， 每条线的权值不大于10000，所以如果所有权值都是-10000，那么最大也只是
                                                               // -500W，跟0x3f3f3f3f比相差很大，所以如果dist[n]大于0x3f3f3f3f / 2，就表示没有在k条
                                                               // 线的范围内查找到k，打印impossible
    else cout << dist[n] << endl;

    return 0;
}