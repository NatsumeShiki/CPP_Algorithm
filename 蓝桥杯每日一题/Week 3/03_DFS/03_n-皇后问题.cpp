// n−
// 皇后问题是指将 n
//  个皇后放在 n×n
//  的国际象棋棋盘上，使得皇后不能相互攻击到，即任意两个皇后都不能处于同一行、同一列或同一斜线上。

// 1_597ec77c49-8-queens.png

// 现在给定整数 n
// ，请你输出所有的满足条件的棋子摆法。

// 输入格式
// 共一行，包含整数 n
// 。

// 输出格式
// 每个解决方案占 n
//  行，每行输出一个长度为 n
//  的字符串，用来表示完整的棋盘状态。

// 其中 . 表示某一个位置的方格状态为空，Q 表示某一个位置的方格上摆着皇后。

// 每个方案输出完成后，输出一个空行。

// 注意：行末不能有多余空格。

// 输出方案的顺序任意，只要不重复且没有遗漏即可。

// 数据范围
// 1≤n≤9
// 输入样例：
// 4
// 输出样例：
// .Q..
// ...Q
// Q...
// ..Q.

// ..Q.
// Q...
// ...Q
// .Q..

#include<iostream>
using namespace std;

const int N = 10, M = 20;
bool col[N], row[N], deg[M], rdeg[M];
char g[N][N];
int n;

void dfs(int x, int y, int cnt){
    if(y == n) x++, y = 0;
    if(x == n){
        if(cnt == n){
            for(int i = 0; i < n; i++) cout << g[i] << endl;
            cout << endl;
        }
        return;
    }
    
    dfs(x, y + 1, cnt);
    
    if(!row[x] && !col[y] && !deg[x + y] && !rdeg[x - y + n]){
        row[x] = col[y] = deg[x + y] = rdeg[x - y + n] = true;
        g[x][y] = 'Q';
        dfs(x, y + 1, cnt + 1);
        g[x][y] = '.';
        row[x] = col[y] = deg[x + y] = rdeg[x - y + n] = false;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            g[i][j] = '.';
    
    dfs(0, 0, 0);
    
    return 0;
}