// 农民 John 有很多牛，他想交易其中一头被 Don 称为 The Knight 的牛。

// 这头牛有一个独一无二的超能力，在农场里像 Knight 一样地跳（就是我们熟悉的象棋中马的走法）。

// 虽然这头神奇的牛不能跳到树上和石头上，但是它可以在牧场上随意跳，我们把牧场用一个 x，y
//  的坐标图来表示。

// 这头神奇的牛像其它牛一样喜欢吃草，给你一张地图，上面标注了 The Knight 的开始位置，树、灌木、石头以及其它障碍的位置，除此之外还有一捆草。

// 现在你的任务是，确定 The Knight 要想吃到草，至少需要跳多少次。

// The Knight 的位置用 K 来标记，障碍的位置用 * 来标记，草的位置用 H 来标记。

// 这里有一个地图的例子：

//              11 | . . . . . . . . . .
//              10 | . . . . * . . . . . 
//               9 | . . . . . . . . . . 
//               8 | . . . * . * . . . . 
//               7 | . . . . . . . * . . 
//               6 | . . * . . * . . . H 
//               5 | * . . . . . . . . . 
//               4 | . . . * . . . * . . 
//               3 | . K . . . . . . . . 
//               2 | . . . * . . . . . * 
//               1 | . . * . . . . * . . 
//               0 ----------------------
//                                     1 
//                 0 1 2 3 4 5 6 7 8 9 0 
// The Knight 可以按照下图中的 A,B,C,D…
//  这条路径用 5
//  次跳到草的地方（有可能其它路线的长度也是 5
// ）：

//              11 | . . . . . . . . . .
//              10 | . . . . * . . . . .
//               9 | . . . . . . . . . .
//               8 | . . . * . * . . . .
//               7 | . . . . . . . * . .
//               6 | . . * . . * . . . F<
//               5 | * . B . . . . . . .
//               4 | . . . * C . . * E .
//               3 | .>A . . . . D . . .
//               2 | . . . * . . . . . *
//               1 | . . * . . . . * . .
//               0 ----------------------
//                                     1
//                 0 1 2 3 4 5 6 7 8 9 0
// 注意： 数据保证一定有解。

// 输入格式
// 第 1
//  行： 两个数，表示农场的列数 C
//  和行数 R
// 。

// 第 2..R+1
//  行: 每行一个由 C
//  个字符组成的字符串，共同描绘出牧场地图。

// 输出格式
// 一个整数，表示跳跃的最小次数。

// 数据范围
// 1≤R,C≤150
// 输入样例：
// 10 11
// ..........
// ....*.....
// ..........
// ...*.*....
// .......*..
// ..*..*...H
// *.........
// ...*...*..
// .K........
// ...*.....*
// ..*....*..
// 输出样例：
// 5

#include<iostream>
#include<queue>
using namespace std;

typedef pair<int, int> PII;
#define x first
#define y second
const int N = 155;
char g[N][N];
bool st[N][N];
int dis[N][N];
int n, m;
int sx, sy, ex, ey;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int step;

void bfs(){
    queue<PII> q;
    q.push({sx, sy});
    while(q.size()){
        int cnt = q.size();
        step++;
        while(cnt--){
            PII t = q.front();
            q.pop();
            for(int i = 0; i < 8; i++){
                int a = t.x + dx[i], b = t.y + dy[i];
                if(a < 0 || a >= n || b < 0 || b >= m) continue;
                if(g[a][b] == '*' || st[a][b]) continue;
                st[a][b] = true;
                dis[a][b] = step;
                q.push({a, b});
                if(a == ex && b == ey) return;
            }
        }
    }
}

int main(){
    cin >> m >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
            if(g[i][j] == 'K') sx = i, sy = j;
            else if(g[i][j] == 'H') ex = i, ey = j;
        }
        
    bfs();
    cout << dis[ex][ey] << endl;
    
    return 0;
}

// 大佬的代码
#include<iostream>
#include<cstring>
using namespace std;

typedef pair<int, int> PII;
#define x first
#define y second
const int N = 155;
char g[N][N];
int dist[N][N];
PII q[N * N];
int n, m;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(){
    memset(dist, -1, sizeof dist);
    int hh = 0, tt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(g[i][j] == 'K'){
                q[0] = {i, j};
                dist[i][j] = 0;
            }
            
    while(hh <= tt){
        PII t = q[hh++];
        for(int i = 0; i < 8; i++){
            int a = t.x + dx[i], b = t.y + dy[i];
            if(a < 0 || a >= n || b < 0 || b >= m) continue;
            if(g[a][b] == '*' || dist[a][b] != -1) continue;
            dist[a][b] = dist[t.x][t.y] + 1;
            q[++tt] = {a, b};
            if(g[a][b] == 'H') return dist[a][b];
        }
    }
    
    return -1;
}

int main(){
    cin >> m >> n;
    for(int i = 0; i < n; i++) cin >> g[i];
        
    cout << bfs() << endl;
    
    return 0;
}