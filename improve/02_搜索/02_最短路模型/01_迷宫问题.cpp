// 给定一个  n×n
//   的二维数组，如下所示：

// int maze[5][5] = {

// 0, 1, 0, 0, 0,

// 0, 1, 0, 1, 0,

// 0, 0, 0, 0, 0,

// 0, 1, 1, 1, 0,

// 0, 0, 0, 1, 0,

// };
// 它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。

// 数据保证至少存在一条从左上角走到右下角的路径。

// 输入格式
// 第一行包含整数 n。

// 接下来 n
//  行，每行包含 n
//  个整数 0 或 1，表示迷宫。

// 输出格式
// 输出从左上角到右下角的最短路线，如果答案不唯一，输出任意一条路径均可。

// 按顺序，每行输出一个路径中经过的单元格的坐标，左上角坐标为 (0,0)
// ，右下角坐标为 (n−1,n−1)
// 。

// 数据范围
// 0≤n≤1000
// 输入样例：
// 5
// 0 1 0 0 0
// 0 1 0 1 0
// 0 0 0 0 0
// 0 1 1 1 0
// 0 0 0 1 0
// 输出样例：
// 0 0
// 1 0
// 2 0
// 2 1
// 2 2
// 2 3
// 2 4
// 3 4
// 4 4

#include<iostream>
#include<queue>
using namespace std;

#define x first
#define y second
typedef pair<int, int> PII;
const int N = 1010;
int g[N][N];
bool st[N][N];
PII last[N][N];
int dis[N][N];
int n;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int step;

void bfs(int x, int y){
    queue<PII> q;
    q.push({x, y});
    while(q.size()){
        int cnt = q.size();
        step++;
        while(cnt--){
            PII t = q.front();
            q.pop();
            dis[t.x][t.y] = step; 
            for(int i = 0; i < 4; i++){
                int a = t.x + dx[i], b = t.y + dy[i];
                if(a < 0 || a >= n || b < 0 || b >= n) continue;
                if(g[a][b] == 1) continue;
                if(st[a][b]) continue;
                if(dis[a][b]) continue;
                st[a][b] = true;
                last[a][b] = {t.x, t.y};
                q.push({a, b});
            }
        }
    }
}

void back(int x, int y){
    PII t = last[x][y];
    if(t.x != -1 && t.y != -1)
        back(t.x, t.y);
    printf("%d %d\n", x, y);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n;i ++)
        for(int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
    last[0][0] = {-1, -1}; 
    bfs(0, 0);
    
    back(n - 1, n - 1);
    
    return 0;
}

// 大佬的代码 
#include<cstring>
#include<iostream>
using namespace std;
#define x first
#define y second

typedef pair<int, int> PII;
const int N = 1010;
int n;
int g[N][N];
PII q[N * N];
PII pre[N][N];

void bfs(int sx, int sy){
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    
    int hh = 0, tt = 0;
    q[0] = {sx, sy};
    
    memset(pre, -1, sizeof pre);
    pre[sx][sy] = {0, 0};
    while(hh <= tt){
        PII t = q[hh++];
        
        for(int i = 0; i < 4; i++){
            int a = t.x + dx[i], b = t.y + dy[i];
            if(a < 0 || a >= n || b < 0 || b >= n) continue;
            if(g[a][b]) continue;
            if(pre[a][b].x != -1) continue;
            
            q[++tt] = {a, b};
            pre[a][b] = t;
        }
    }
}

int main(){
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
            
    bfs(n - 1, n - 1);
    PII end(0, 0);
    
    while(true){
        printf("%d %d\n", end.x, end.y);
        if(end.x == n - 1 && end.y == n - 1) break;
        end = pre[end.x][end.y];
    }
    
    return 0;
}