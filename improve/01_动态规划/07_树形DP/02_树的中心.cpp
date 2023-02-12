// 给定一棵树，树中包含 n
//  个结点（编号1
// ~n
// ）和 n−1
//  条无向边，每条边都有一个权值。

// 请你在树中找到一个点，使得该点到树中其他结点的最远距离最近。

// 输入格式
// 第一行包含整数 n
// 。

// 接下来 n−1
//  行，每行包含三个整数 ai,bi,ci
// ，表示点 ai
//  和 bi
//  之间存在一条权值为 ci
//  的边。

// 输出格式
// 输出一个整数，表示所求点到树中其他结点的最远距离。

// 数据范围
// 1≤n≤10000
// ,
// 1≤ai,bi≤n
// ,
// 1≤ci≤105
// 输入样例：
// 5 
// 2 1 1 
// 3 2 1 
// 4 3 1 
// 5 1 1
// 输出样例：
// 2

// 思路：随便取一个点开始向上和向下递归，求出求出每个点向上和向下的最大长度，去最大值，然后在每个最大值中取最小值
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010, M = N * 2, INF = 0x3f3f3f3f;
int n;
int h[N], e[M], w[M], ne[M], idx;
int d1[N], d2[N], p1[N], p2[N], up[N];
bool is_leaf[N]; // 保存某个节点是不是叶子结点
/*
d1[u]：存下u节点向下走的最长路径的长度
d2[u]：存下u节点向下走的次长路径的长度
p1[u]：存下u节点向下走的最长路径的子节点
p2[u]：存下u节点向下走的次长路径的子节点
up[u]：存下u节点向上走的最长路径的长度
*/

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dfs_d(int u, int father){
    d1[u] = d2[u] = -INF; // 先都定义成无穷小
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(j == father) continue;
        int d = dfs_d(j, u) + w[i];
        if(d >= d1[u]){ // 如果从j这个点下去的长度比d1[u]更长，更新
            d2[u] = d1[u], d1[u] = d;
            p2[u] = p1[u];
        }else if(d > d2[u]) d2[u] = d; // 比d2[u]更长
    }
    
    if(d1[u] == -INF){
        d1[u] = d2[u] = 0; // 如果d1[u]依然是无穷小，说明没有子节点可以让它更新，因此让最长和次长都设置成0
        is_leaf[u] = true;
    }
    
    return d1[u];
}

void dfs_u(int u, int father){
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(j == father) continue;
        
        if(p1[u] == j) up[j] = max(up[u], d2[u]) + w[i]; // 如果该j子节点是u节点向下取最大值的节点，就从次大的子节点和up[u]中取较大值
        else up[j] = max(up[u], d1[u]) + w[i]; // 否则从最大的子节点和up[u]中取较大值
        
        dfs_u(j, u);
    }
}

int main(){
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    
    dfs_d(1, -1); // 从节点1向下递归
    dfs_u(1, -1); // 从节点2向上递归
    
    int res = d1[1]; // 如果是根节点，则只有向下最长的路径
    for(int i = 1; i <= n; i++)
      if(is_leaf[i]) res = min(res, up[i]); // 如果是叶子节点，则只有向上的最长路径
      else res = min(res, max(d1[i], up[i])); // 在每个点的d1和up中取最大值，然后与res取较小值
    
    cout << res << endl;
    
    
    return 0;
}