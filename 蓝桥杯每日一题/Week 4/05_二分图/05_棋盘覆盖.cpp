// 给定一个 N
//  行 N
//  列的棋盘，已知某些格子禁止放置。

// 求最多能往棋盘上放多少块的长度为 2
// 、宽度为 1
//  的骨牌，骨牌的边界与格线重合（骨牌占用两个格子），并且任意两张骨牌都不重叠。

// 输入格式
// 第一行包含两个整数 N
//  和 t
// ，其中 t
//  为禁止放置的格子的数量。

// 接下来 t
//  行每行包含两个整数 x
//  和 y
// ，表示位于第 x
//  行第 y
//  列的格子禁止放置，行列数从 1
//  开始。

// 输出格式
// 输出一个整数，表示结果。

// 数据范围
// 1≤N≤100
// ,
// 0≤t≤100
// 输入样例：
// 8 0
// 输出样例：
// 32

#include<iostream>
#include<cstring>
using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;

const int N = 110;
bool g[N][N], st[N][N];
int n, t;
PII match[N][N];

int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

bool find(int x, int y){
    for(int i = 0; i < 4; i++){
        int a = x + dx[i], b = y + dy[i];
        if(a < 1 || a > n || b < 1 || b > n) continue;
        if(g[a][b]) continue;
        if(!st[a][b]){
            PII t = match[a][b];
            st[a][b] = true;
            if(t.x == 0 || find(t.x, t.y)){
                match[a][b] = {x, y};
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        g[a][b] = true;
    }
    
    int res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if((i + j) % 2 && !g[i][j]) {
                memset(st, 0, sizeof st);
                if(find(i, j)) res++;
            }
        }
        
    cout << res << endl;
    
    return 0;
}