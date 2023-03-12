// 给出 n
//  个点的一棵树，多次询问两点之间的最短距离。

// 注意：

// 边是无向的。
// 所有节点的编号是 1,2,…,n
// 。
// 输入格式
// 第一行为两个整数 n
//  和 m
// 。n
//  表示点数，m
//  表示询问次数；

// 下来 n−1
//  行，每行三个整数 x,y,k
// ，表示点 x
//  和点 y
//  之间存在一条边长度为 k
// ；

// 再接下来 m
//  行，每行两个整数 x,y
// ，表示询问点 x
//  到点 y
//  的最短距离。

// 树中结点编号从 1
//  到 n
// 。

// 输出格式
// 共 m
//  行，对于每次询问，输出一行询问结果。

// 数据范围
// 2≤n≤104
// ,
// 1≤m≤2×104
// ,
// 0<k≤100
// ,
// 1≤x,y≤n
// 输入样例1：
// 2 2 
// 1 2 100 
// 1 2 
// 2 1
// 输出样例1：
// 100
// 100
// 输入样例2：
// 3 2
// 1 2 10
// 3 1 15
// 1 2
// 3 2
// 输出样例2：
// 10
// 25

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

typedef pair<int, int> PII;
const int N = 20010, M = N * 2;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
int p[N];
int res[N];
int st[N];
vector<PII> query[N];

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int fa){
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(j == fa) continue;
        dist[j] = dist[u] + w[i];
        dfs(j, u);
    }
}

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void tarjan(int u){
    st[u] = 1;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(!st[j]){
            tarjan(j);
            p[j] = u;
        }
    }
    
    for(auto item : query[u]){
        int y = item.first, id = item.second;
        if(st[y] == 2){
            int anc = find(y);
            res[id] = dist[u] + dist[y] - dist[anc] * 2;
        }
    }
    
    st[u] = 2;
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        if(a != b){
            query[a].push_back({b, i});
            query[b].push_back({a, i});
        }
    }
    
    for(int i = 1; i <= n; i++) p[i] = i;
    
    dfs(1, -1);
    tarjan(1);
    
    for(int i = 0; i < m; i++) printf("%d\n", res[i]);
    
    
    return 0;
}