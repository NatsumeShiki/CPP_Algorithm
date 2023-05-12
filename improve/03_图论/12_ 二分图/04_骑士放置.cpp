// 给定一个 N×M
//  的棋盘，有一些格子禁止放棋子。

// 问棋盘上最多能放多少个不能互相攻击的骑士（国际象棋的“骑士”，类似于中国象棋的“马”，按照“日”字攻击，但没有中国象棋“别马腿”的规则）。

// 输入格式
// 第一行包含三个整数 N,M,T
// ，其中 T
//  表示禁止放置的格子的数量。

// 接下来 T
//  行每行包含两个整数 x
//  和 y
// ，表示位于第 x
//  行第 y
//  列的格子禁止放置，行列数从 1
//  开始。

// 输出格式
// 输出一个整数表示结果。

// 数据范围
// 1≤N,M≤100
// 输入样例：
// 2 3 0
// 输出样例：
// 4

// 找到最大匹配，用n * m - k - res即为答案
#include<iostream>
#include<cstring>
using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;
const int N = 110;
bool g[N][N], st[N][N];
int n, m, k;
PII match[N][N];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int find(int x, int y){
    for(int i = 0; i < 8; i++){
        int a = x + dx[i], b = y + dy[i];
        if(a < 1 || a > n || b < 1 || b > m) continue;
        if(st[a][b] || g[a][b]) continue;
        st[a][b] = true;
        PII t = match[a][b];
        if(t.x == 0 || find(t.x, t.y)){
            match[a][b] = {x, y};
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        g[a][b] = true;
    }
    
    int res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if((i + j) % 2 || g[i][j]) continue;
            memset(st, 0, sizeof st);
            if(find(i, j)) res++;
        }

    cout << n * m - k - res << endl;
    
    return 0;
}