// 给定一张无向图，求图中一个至少包含 3
//  个点的环，环上的节点不重复，并且环上的边的长度之和最小。

// 该问题称为无向图的最小环问题。

// 你需要输出最小环的方案，若最小环不唯一，输出任意一个均可。

// 输入格式
// 第一行包含两个整数 N
//  和 M
// ，表示无向图有 N
//  个点，M
//  条边。

// 接下来 M
//  行，每行包含三个整数 u，v，l
// ，表示点 u
//  和点 v
//  之间有一条边，边长为 l
// 。

// 输出格式
// 输出占一行，包含最小环的所有节点（按顺序输出），如果不存在则输出 No solution.。

// 数据范围
// 1≤N≤100
// ,
// 1≤M≤10000
// ,
// 1≤l<500
// 输入样例：
// 5 7
// 1 4 1
// 1 3 300
// 3 1 10
// 1 2 16
// 2 3 100
// 2 5 15
// 5 3 20
// 输出样例：
// 1 3 5 2

#include<iostream>
#include<cstring>
using namespace std;

const int N = 110, INF = 0x3f3f3f3f;
int n, m;
int d[N][N], g[N][N]; // d保存两个点之间的距离，g保存直接连接的两条边的距离
int pos[N][N]; // 保存两个点之间是哪个点
int path[N], cnt; // 保存方案

void get_path(int i, int j){
    if(pos[i][j] == 0) return; // 表示i和j直接没有点，他们是直接连接的，所以直接返回
    
    int k = pos[i][j]; // 保存中间的点
    get_path(i, k); // 向下递归
    path[cnt++] = k; 
    get_path(k, j);
}

int main(){
    
    cin >>  n >> m;
    memset(g, 0x3f, sizeof g);
    for(int i = 1; i <= n; i++) g[i][i] = 0;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    
    int res = INF;
    memcpy(d, g, sizeof d);
    for(int k = 1; k <= n; k++){
        for(int i = 1; i < k; i++) // 注意，为了不出现自环的情况，需要是 i -> j -> k
            for(int j = i + 1; j < k; j++)
                if((long long)d[i][j] + g[j][k] + g[k][i] < res){ // 获取最小值
                    res = d[i][j] + g[j][k] + g[k][i]; 
                    cnt = 0; // i -> k -> j -> i
                    path[cnt++] = i;
                    path[cnt++] = k;
                    path[cnt++] = j;
                    get_path(i, j);
                }
        // floyd算法获取两个点之间的距离
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    pos[i][j] = k;
                }
    }
    
    if(res == INF) puts("No solution.");
    else{
        for(int i = 0; i < cnt;i ++) cout << path[i] << " ";
        cout << endl;
    }
    
    return 0;
}