// 农夫约翰有一片 N∗M
//  的矩形土地。

// 最近，由于降雨的原因，部分土地被水淹没了。

// 现在用一个字符矩阵来表示他的土地。

// 每个单元格内，如果包含雨水，则用”W”表示，如果不含雨水，则用”.”表示。

// 现在，约翰想知道他的土地中形成了多少片池塘。

// 每组相连的积水单元格集合可以看作是一片池塘。

// 每个单元格视为与其上、下、左、右、左上、右上、左下、右下八个邻近单元格相连。

// 请你输出共有多少片池塘，即矩阵中共有多少片相连的”W”块。

// 输入格式
// 第一行包含两个整数 N
//  和 M
// 。

// 接下来 N
//  行，每行包含 M
//  个字符，字符为”W”或”.”，用以表示矩形土地的积水状况，字符之间没有空格。

// 输出格式
// 输出一个整数，表示池塘数目。

// 数据范围
// 1≤N,M≤1000
// 输入样例：
// 10 12
// W........WW.
// .WWW.....WWW
// ....WW...WW.
// .........WW.
// .........W..
// ..W......W..
// .W.W.....WW.
// W.W.W.....W.
// .W.W......W.
// ..W.......W.
// 输出样例：
// 3

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

#define x first
#define y second
typedef pair<int, int> PII;
const int N = 1010;
char g[N][N];
bool st[N][N];
int n, m;
int dx[8] = {-1, 0, 1, 0, -1, 1, 1, -1}, dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

void floodFill(int x, int y){
    queue<PII> q;
    q.push({x, y});
    while(q.size()){
        PII t = q.front();
        q.pop();
        for(int i = 0; i < 8; i++){
            int a = t.x + dx[i], b = t.y + dy[i];
            if(g[a][b] == 'W' && !st[a][b]){
                st[a][b] = true;
                q.push({a, b});
            }
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n;i ++) scanf("%s", g[i]);
    
    int cnt = 0;
    for(int i = 0; i < n;i ++)
        for(int j = 0; j < m; j++)
            if(g[i][j] == 'W' && !st[i][j]){
                floodFill(i, j);
                cnt++;
            }
            
    printf("%d\n", cnt);
    
    return 0;
}

// 大佬的代码
#include<iostream>
#include<cstring>
using namespace std;

#define x first
#define y second
typedef pair<int, int> PII;
const int N = 1010;
char g[N][N];
bool st[N][N];
PII q[N * N];
int n, m;
int dx[8] = {-1, 0, 1, 0, -1, 1, 1, -1}, dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

void floodFill(int x, int y){
    int hh = 0, tt = 0;
    q[hh] = {x, y};
    
    while(hh <= tt){
        PII t = q[hh++];
        for(int i = t.x - 1; i <= t.x + 1; i++)
            for(int j = t.y - 1; j <= t.y + 1; j++){
                if(i == t.x && j == t.y) continue;
                if(i < 0 || i >= n || j < 0 || j >= m) continue;
                if(g[i][j] == '.' || st[i][j]) continue;
                st[i][j] = true;
                q[++tt] = {i, j};
            }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n;i ++) scanf("%s", g[i]);
    
    int cnt = 0;
    for(int i = 0; i < n;i ++)
        for(int j = 0; j < m; j++)
            if(g[i][j] == 'W' && !st[i][j]){
                floodFill(i, j);
                cnt++;
            }
            
    printf("%d\n", cnt);
    
    return 0;
}