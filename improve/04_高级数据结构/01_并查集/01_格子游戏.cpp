// Alice和Bob玩了一个古老的游戏：首先画一个 n×n
//  的点阵（下图 n=3
//  ）。

// 接着，他们两个轮流在相邻的点之间画上红边和蓝边：

// 1.png

// 直到围成一个封闭的圈（面积不必为 1
// ）为止，“封圈”的那个人就是赢家。因为棋盘实在是太大了，他们的游戏实在是太长了！

// 他们甚至在游戏中都不知道谁赢得了游戏。

// 于是请你写一个程序，帮助他们计算他们是否结束了游戏？

// 输入格式
// 输入数据第一行为两个整数 n
//  和 m
// 。n
// 表示点阵的大小，m
//  表示一共画了 m
//  条线。

// 以后 m
//  行，每行首先有两个数字 (x,y)
// ，代表了画线的起点坐标，接着用空格隔开一个字符，假如字符是 D
// ，则是向下连一条边，如果是 R
//  就是向右连一条边。

// 输入数据不会有重复的边且保证正确。

// 输出格式
// 输出一行：在第几步的时候结束。

// 假如 m
//  步之后也没有结束，则输出一行“draw”。

// 数据范围
// 1≤n≤200
// ，
// 1≤m≤24000
// 输入样例：
// 3 5
// 1 1 D
// 1 1 R
// 1 2 D
// 2 1 R
// 2 2 D
// 输出样例：
// 4

// 将每个坐标映射成一个点，当这两个点在连接之前已经在一个连通块中了，就说明形成了环
#include<iostream>
#include<cstring>
using namespace std;

const int N = 210, M = 40010;
int g[N][N];
int p[M];
int n, m;

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main(){
    cin >> n >> m;
    int cnt = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            g[i][j] = cnt++;
    for(int i = 1; i < cnt; i++) p[i] = i;
    
    int i;
    for(i = 1; i <= m; i++){
        int x, y;
        char c;
        cin >> x >> y >> c;
        int a = g[x][y], b;
        if(c == 'D') b = g[x + 1][y];
        else b = g[x][y + 1];
        int pa = find(a), pb = find(b);
        if(pa == pb) break;
        else p[pa] = pb;
    }
    
    if(i >= m) puts("draw");
    else cout << i << endl;
    
    return 0;
}

#include<iostream>
#include<cstring>
using namespace std;

const int N = 40010;
int n, m;
int p[N];

int get(int x, int y){
    return x * n + y;
}

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n * n; i++) p[i] = i;
    int res = 0;
    for(int i = 1; i <= m; i++){
        int x, y;
        char d;
        cin >> x >> y >> d;
        x--, y--;
        int a = get(x, y);
        int b;
        if(d == 'D') b = get(x + 1, y);
        else b = get(x, y + 1);
        
        int pa = find(a), pb = find(b);
        if(pa == pb){
            res = i;
            break;
        }
        p[pa] = pb;
    }
    
    if(!res) puts("draw");
    else cout << res << endl;
    
    return 0;
}