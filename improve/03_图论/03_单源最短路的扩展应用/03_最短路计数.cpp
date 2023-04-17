// 给出一个 N
//  个顶点 M
//  条边的无向无权图，顶点编号为 1
//  到 N
// 。

// 问从顶点 1
//  开始，到其他每个点的最短路有几条。

// 输入格式
// 第一行包含 2
//  个正整数 N,M
// ，为图的顶点数与边数。

// 接下来 M
//  行，每行两个正整数 x,y
// ，表示有一条顶点 x
//  连向顶点 y
//  的边，请注意可能有自环与重边。

// 输出格式
// 输出 N
//  行，每行一个非负整数，第 i
//  行输出从顶点 1
//  到顶点 i
//  有多少条不同的最短路，由于答案有可能会很大，你只需要输出对 100003
//  取模后的结果即可。

// 如果无法到达顶点 i
//  则输出 0
// 。

// 数据范围
// 1≤N≤105
// ,
// 1≤M≤2×105
// 输入样例：
// 5 7
// 1 2
// 1 3
// 2 4
// 3 4
// 2 3
// 4 5
// 4 5
// 输出样例：
// 1
// 1
// 1
// 2
// 4

/*
1. bfs 每个点只入队一次，只出队一次
2. dijkstra 每个点第一次出队的序列必定满足拓扑序
3. bellford(spfa) 本身不具备拓扑序
*/
// bfs写法
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1e5 + 10, M = N * 4, mod = 100003;
int h[N], e[M], ne[M], idx;
int n, m;
int dist[N]; // 保存到点的最短路径
int cnt[N]; // 保存到点最短路径的条数

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(){
    memset(dist, 0x3f, sizeof dist);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    cnt[1] = 1;
    while(q.size()){
        int t = q.front();
        q.pop();
        
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + 1){ // 如果dist[j] > dist[t] + 1，说明当前的dist[j]不是到j点的最短路径，所以要更新路径和路径数量，此时需要入队
                dist[j] = dist[t] + 1;
                cnt[j] = cnt[t];
                q.push(j);
            }else if(dist[j] == dist[t] + 1){ // 如果相等，说明它可能是最短路径，此时要把路径条数累加，但是不需要入队
                cnt[j] = (cnt[j] + cnt[t]) % mod;
            }
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    
    bfs();
    
    for(int i = 1; i <= n; i++) printf("%d\n", cnt[i]);
    
    return 0;
}

// dijkstra写法
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10, M = N * 4, mod = 100003;
int h[N], e[M], ne[M], idx;
int n, m;
int dist[N];
int cnt[N];
bool st[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    dist[1] = 0;
    cnt[1] = 1;
    
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        
        int ver = t.second;
        for(int i = h[ver]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[ver] + 1){
                dist[j] = dist[ver] + 1;
                cnt[j] = cnt[ver];
                heap.push({dist[j], j});
            }else if(dist[j] == dist[ver] + 1){
                cnt[j] = (cnt[j] + cnt[ver]) % mod;
            }
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    
    dijkstra();
    
    for(int i = 1; i <= n; i++) printf("%d\n", cnt[i]);
    
    return 0;
}