// 一天Extense在森林里探险的时候不小心走入了一个迷宫，迷宫可以看成是由 n∗n
//  的格点组成，每个格点只有2种状态，.和#，前者表示可以通行后者表示不能通行。

// 同时当Extense处在某个格点时，他只能移动到东南西北(或者说上下左右)四个方向之一的相邻格点上，Extense想要从点A走到点B，问在不走出迷宫的情况下能不能办到。

// 如果起点或者终点有一个不能通行(为#)，则看成无法办到。

// 注意：A、B不一定是两个不同的点。

// 输入格式
// 第1行是测试数据的组数 k
// ，后面跟着 k
//  组输入。

// 每组测试数据的第1行是一个正整数 n
// ，表示迷宫的规模是 n∗n
//  的。

// 接下来是一个 n∗n
//  的矩阵，矩阵中的元素为.或者#。

// 再接下来一行是 4 个整数 ha,la,hb,lb
// ，描述 A
//  处在第 ha
//  行, 第 la
//  列，B
//  处在第 hb
//  行, 第 lb
//  列。

// 注意到 ha,la,hb,lb
//  全部是从 0 开始计数的。

// 输出格式
// k行，每行输出对应一个输入。

// 能办到则输出“YES”，否则输出“NO”。

// 数据范围
// 1≤n≤100
// 输入样例：
// 2
// 3
// .##
// ..#
// #..
// 0 0 2 2
// 5
// .....
// ###.#
// ..#..
// ###..
// ...#.
// 0 0 4 0
// 输出样例:
// YES
// NO

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 110;
char g[N][N];
bool st[N][N];
int sx, sy, ex, ey;
int n;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

bool dfs(int x, int y){
    if(x == ex && y == ey) return true;
    bool flag = false;
    for(int i = 0; i < 4; i++){
        int a = x + dx[i], b = y + dy[i];
        if(a < 0 || a >= n || b < 0 || b >= n) continue;
        if(g[a][b] == '#') continue;
        if(st[a][b]) continue;
        st[a][b] = true;
        flag |= dfs(a, b);
        if(flag) break;
    }
    return flag;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        memset(st, 0, sizeof st);
        scanf("%d", &n);
        for(int i = 0; i < n ;i++) scanf("%s", g[i]);
        scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
        if(g[sx][sy] == '#' || g[ex][ey] == '#') puts("NO");
        else if(dfs(sx, sy)) puts("YES");
        else puts("NO");
    }
    
    
    return 0;
}