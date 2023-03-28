// 给定一个 N
//  行 M
//  列的 01
//  矩阵 A
// ，A[i][j]
//  与 A[k][l]
//  之间的曼哈顿距离定义为：

// dist(A[i][j],A[k][l])=|i−k|+|j−l|
// 输出一个 N
//  行 M
//  列的整数矩阵 B
// ，其中：

// B[i][j]=min1≤x≤N,1≤y≤M,A[x][y]=1dist(A[i][j],A[x][y])
// 输入格式
// 第一行两个整数 N,M
// 。

// 接下来一个 N
//  行 M
//  列的 01
//  矩阵，数字之间没有空格。

// 输出格式
// 一个 N
//  行 M
//  列的矩阵 B
// ，相邻两个整数之间用一个空格隔开。

// 数据范围
// 1≤N,M≤1000
// 输入样例：
// 3 4
// 0001
// 0011
// 0110
// 输出样例：
// 3 2 1 0
// 2 1 0 0
// 1 0 0 1

#include<iostream>
#include<queue>
using namespace std;

typedef pair<int, int> PII;
#define x first
#define y second
const int N = 1010;
char g[N][N];
int dist[N][N];
bool st[N][N];
int n, m;
queue<PII> q;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

void bfs(){
    while(q.size()){
        PII t = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int a = t.x + dx[i], b = t.y + dy[i];
            if(a < 0 || a >= n || b < 0 || b >= m) continue;
            if(st[a][b]) continue;
            st[a][b] = true;
            dist[a][b] = dist[t.x][t.y] + 1;
            q.push({a, b});
        }
    }
}


int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n;i ++)
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
            if(g[i][j] == '1') {
                q.push({i, j});
                st[i][j] = true;
            }
        }
        
    bfs();
        
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) 
            printf("%d ", dist[i][j]);
        puts("");
    }
    
    
    return 0;
}