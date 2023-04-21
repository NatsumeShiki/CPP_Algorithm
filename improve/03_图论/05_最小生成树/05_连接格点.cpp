// 有一个 m
//  行 n
//  列的点阵，相邻两点可以相连。

// 一条纵向的连线花费一个单位，一条横向的连线花费两个单位。

// 某些点之间已经有连线了，试问至少还需要花费多少个单位才能使所有的点全部连通。

// 输入格式
// 第一行输入两个正整数 m
//  和 n
// 。

// 以下若干行每行四个正整数 x1,y1,x2,y2
// ，表示第 x1
//  行第 y1
//  列的点和第 x2
//  行第 y2
//  列的点已经有连线。

// 输入保证|x1−x2|+|y1−y2|=1
// 。

// 输出格式
// 输出使得连通所有点还需要的最小花费。

// 数据范围
// 1≤m,n≤1000

// 0≤已经存在的连线数≤10000
// 输入样例：
// 2 2
// 1 1 2 1
// 输出样例：
// 3

// 使用排序 4000ms
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1010, M = 1000010, K = 2010010, INF = 0x3f3f3f3f;
struct edge{
    int a, b, w;
    bool operator < (const edge &t) const{
        return w < t.w;
    }
}e[K];
int p[M];
int g[N][N];
int n, m, cnt, t, res;
int x1, y1, x2, y2;

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            g[i][j] = cnt++;
    for(int i = 0; i < cnt; i++) p[i] = i;
    while(scanf("%d%d%d%d", &x1, &y1, &x2, &y2) != -1){
        int a = g[x1][y1], b = g[x2][y2];
        e[t++] = {a, b, 0};
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            int a = g[i][j], b = g[i][j + 1], c = g[i + 1][j];
            if(j + 1 <= m) e[t++] = {a, b, 2};
            if(i + 1 <= n) e[t++] = {a, c, 1};
        }
    sort(e, e + t);
    for(int i = 0; i < t; i++){
        int a = find(e[i].a), b = find(e[i].b), w = e[i].w;
        if(a != b) {
            p[a] = b;
            res += w;
        }
    }
    
    cout << res << endl;
    
    return 0;
}

// 不使用排序 600ms
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1010, M = 1000010, K = 2010010, INF = 0x3f3f3f3f;
struct edge{
    int a, b, w;
    bool operator < (const edge &t) const{
        return w < t.w;
    }
}e[K];
int p[M];
int g[N][N];
int n, m, cnt, t, res;
int x1, y1, x2, y2;

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            g[i][j] = cnt++;
    for(int i = 0; i < cnt; i++) p[i] = i;
    while(scanf("%d%d%d%d", &x1, &y1, &x2, &y2) != -1){
        int a = g[x1][y1], b = g[x2][y2];
        e[t++] = {a, b, 0};
    }
    // for(int i = 1; i <= n; i++)
    //     for(int j = 1; j <= m; j++){
    //         int a = g[i][j], b = g[i][j + 1], c = g[i + 1][j];
    //         if(j + 1 <= m) e[t++] = {a, b, 2};
    //         if(i + 1 <= n) e[t++] = {a, c, 1};
    //     }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            int a = g[i][j], b = g[i + 1][j];
            if(i + 1 <= n) e[t++] = {a, b, 1};
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int a = g[i][j], b = g[i][j + 1];
            if(j + 1 <= m) e[t++] = {a, b, 2};
        }
    }
    // sort(e, e + t);
    for(int i = 0; i < t; i++){
        int a = find(e[i].a), b = find(e[i].b), w = e[i].w;
        if(a != b) {
            p[a] = b;
            res += w;
        }
    }
    
    cout << res << endl;
    
    return 0;
}