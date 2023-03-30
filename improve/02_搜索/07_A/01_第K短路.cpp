// 给定一张 N
//  个点（编号 1,2…N
// ），M
//  条边的有向图，求从起点 S
//  到终点 T
//  的第 K
//  短路的长度，路径允许重复经过点或边。

// 注意： 每条最短路中至少要包含一条边。

// 输入格式
// 第一行包含两个整数 N
//  和 M
// 。

// 接下来 M
//  行，每行包含三个整数 A,B
//  和 L
// ，表示点 A
//  与点 B
//  之间存在有向边，且边长为 L
// 。

// 最后一行包含三个整数 S,T
//  和 K
// ，分别表示起点 S
// ，终点 T
//  和第 K
//  短路。

// 输出格式
// 输出占一行，包含一个整数，表示第 K
//  短路的长度，如果第 K
//  短路不存在，则输出 −1
// 。

// 数据范围
// 1≤S,T≤N≤1000
// ,
// 0≤M≤104
// ,
// 1≤K≤1000
// ,
// 1≤L≤100
// 输入样例：
// 2 2
// 1 2 5
// 2 1 4
// 1 2 2
// 输出样例：
// 14

#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>

#define x first
#define y second

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

const int N = 1010, M = 200010;

int n, m, S, T, K;
int h[N], rh[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];

void add(int h[], int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(){
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, T});
    
    memset(dist, 0x3f, sizeof dist);
    dist[T] = 0;
    
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        
        int ver = t.y;
        if(st[ver]) continue;
        st[ver] = true;
        
        for(int i = rh[ver]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[ver] + w[i]){
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int astar(){
    priority_queue<PIII, vector<PIII>, greater<PIII>> heap;
    heap.push({dist[S], {0, S}});
    
    int cnt = 0;
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        
        int ver = t.y.y, distance = t.y.x;
        if(ver == T) cnt++;
        if(cnt == K) return distance;
        
        for(int i = h[ver]; ~i; i = ne[i]){
            int j = e[i];
            heap.push({distance + w[i] + dist[j], {distance + w[i], j}});
        }
    }
    
    return -1;
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);
    
    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(h, a, b, c);
        add(rh, b, a, c);
    }
    scanf("%d%d%d", &S, &T, &K);
    if(S == T) K++;
    
    dijkstra();
    printf("%d\n", astar());
    
    return 0;
}