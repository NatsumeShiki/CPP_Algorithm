// 有 N
//  个村庄，编号 1
//  到 N
// 。

// 村庄之间有 M
//  条无向道路，第 i
//  条道路连接村庄 ai
//  和村庄 bi
// ，长度是 ci
// 。

// 所有村庄都是连通的。

// 共有 K
//  个村庄有商店，第 j
//  个有商店的村庄编号是 xj
// 。

// 然后给出 Q
//  个询问，第 k
//  个询问给出一个村庄的编号 yk
// ，问该村庄距离最近的商店有多远？

// 输入格式
// 第一行包含两个整数 N,M
// 。

// 接下来 M
//  行，每行包含三个整数 ai,bi,ci
// ，表示第 i
//  条道路连接村庄 ai
//  和村庄 bi
// ，长度是 ci
// 。

// 再一行包含整数 K
// 。

// 接下来 K
//  行，每行包含一个整数 xj
// ，表示第 j
//  个有商店的村庄编号是 xj
// 。

// 再一行包含整数 Q
// 。

// 接下来 Q
//  行，每行包含一个整数 yk
// ，表示询问编号为 yk
//  的村庄与其距离最近的商店之间的距离。

// 输出格式
// 对于每个询问，输出该询问的结果。

// 数据范围
// 2≤N≤105
// ,
// N−1≤M≤min(N(N−1)2,105)
// ,
// 1≤Q≤105
// ,
// 1≤K≤N
// ,
// 1≤ci≤10000
// 输入样例：
// 7 7
// 1 2 5
// 1 4 3
// 2 3 2
// 2 5 1
// 3 6 7
// 5 6 8
// 6 7 6
// 3
// 7
// 5
// 4
// 7
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 输出样例：
// 3
// 1
// 3
// 0
// 0
// 6
// 0

// 用一个虚拟点来构造该点到商店权值为0的边，然后以它为起点做dijkstra算法
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10, M = N * 3;
int h[N], e[M], w[M], ne[M], idx;
int dist[M];
bool st[M];
int n, m, k, q;
int vir;

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(int vir){
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, vir});
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        
        int ver = t.second, dis = t.first;
        if(st[ver]) continue;
        st[ver] = true;
        
        for(int i = h[ver]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] > dis + w[i]){
                dist[j] = dis + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int main(){
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    vir = n + 1;
    while(m--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
    
    scanf("%d", &k);
    while(k--){
        int x;
        scanf("%d", &x);
        add(vir, x, 0);
    }
    
    dijkstra(vir);
    scanf("%d", &q);
    while(q--){
        int x;
        scanf("%d", &x);
        printf("%d\n", dist[x]);
    }
    
    return 0;
}