// 给定一个 n
//  个结点（编号 1∼n
// ）构成的二叉树，其根结点为 1
//  号点。

// 进行 m
//  次询问，每次询问两个结点之间的最短路径长度。

// 树中所有边长均为 1
// 。

// 输入格式
// 第一行包含一个整数 T
// ，表示共有 T
//  组测试数据。

// 每组数据第一行包含两个整数 n,m
// 。

// 接下来 n
//  行，每行包含两个整数，其中第 i
//  行的整数表示结点 i
//  的子结点编号。如果没有子结点则输出 −1
// 。

// 接下来 m
//  行，每行包含两个整数，表示要询问的两个结点的编号。

// 输出格式
// 每组测试数据输出 m
//  行，代表查询的两个结点之间的最短路径长度。

// 数据范围
// 1≤T≤10
// ,
// 1≤n,m≤1000
// 输入样例：
// 1
// 8 4
// 2 3
// 4 5
// 6 -1
// -1 -1
// -1 7
// -1 -1
// 8 -1
// -1 -1
// 1 6
// 4 6
// 4 5
// 8 1
// 输出样例：
// 2
// 4
// 2
// 4

#include<iostream>
#include<cstring>
using namespace std;

const int N = 1010;
int l[N], r[N], p[N];
int dist[N];
int n, m;

void dfs(int u, int d){
    dist[u] = d;
    if(l[u] != -1) dfs(l[u], d + 1);
    if(r[u] != -1) dfs(r[u], d + 1);
}

int get_lca(int a, int b){
    if(dist[a] > dist[b]) swap(a, b);
    while(dist[a] != dist[b]) b = p[b];
    while(a != b) a = p[a], b = p[b];
    return a;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            cin >> l[i] >> r[i];
            if(l[i] != -1) p[l[i]] = i;
            if(r[i] != -1) p[r[i]] = i;
        }
        
        dfs(1, 0);
        while(m--){
            int a, b;
            cin >> a >> b;
            int lca = get_lca(a, b);
            cout << dist[a] + dist[b] - dist[lca] * 2 << endl;
        }
    }
    
    return 0;
}