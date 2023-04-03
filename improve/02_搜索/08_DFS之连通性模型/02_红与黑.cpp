// 有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。

// 你站在其中一块黑色的瓷砖上，只能向相邻（上下左右四个方向）的黑色瓷砖移动。

// 请写一个程序，计算你总共能够到达多少块黑色的瓷砖。

// 输入格式
// 输入包括多个数据集合。

// 每个数据集合的第一行是两个整数 W
//  和 H
// ，分别表示 x
//  方向和 y
//  方向瓷砖的数量。

// 在接下来的 H
//  行中，每行包括 W
//  个字符。每个字符表示一块瓷砖的颜色，规则如下

// 1）‘.’：黑色的瓷砖；
// 2）‘#’：红色的瓷砖；
// 3）‘@’：黑色的瓷砖，并且你站在这块瓷砖上。该字符在每个数据集合中唯一出现一次。

// 当在一行中读入的是两个零时，表示输入结束。

// 输出格式
// 对每个数据集合，分别输出一行，显示你从初始位置出发能到达的瓷砖数(记数时包括初始位置的瓷砖)。

// 数据范围
// 1≤W,H≤20
// 输入样例：
// 6 9 
// ....#. 
// .....# 
// ...... 
// ...... 
// ...... 
// ...... 
// ...... 
// #@...# 
// .#..#. 
// 0 0
// 输出样例：
// 45

#include<iostream>
#include<cstring>
using namespace std;

const int N = 25;
char g[N][N];
bool st[N][N];
int n, m;
int x, y;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int cnt;

void dfs(int x, int y){
    for(int i = 0; i < 4; i++){
        int a = x + dx[i], b = y + dy[i];
        if(a < 0 || a >= n || b < 0 || b >= m) continue;
        if(st[a][b] || g[a][b] == '#') continue;
        st[a][b] = true;
        cnt++;
        dfs(a, b);
    }
}

int main(){
    while(cin >> m >> n, m || n){
        memset(st, 0, sizeof st);
        cnt = 1;
        for(int i = 0; i < n;i ++)
            for(int j = 0; j < m; j++){
                cin >> g[i][j];
                if(g[i][j] == '@') x = i, y = j;
            }
        st[x][y] = true;
        dfs(x, y);
        cout << cnt << endl;
    }
    return 0;
}

#include<iostream>
#include<cstring>
using namespace std;

const int N = 25;
char g[N][N];
int n, m;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int dfs(int x, int y){
    int res = 1;
    g[x][y] = '#';
    for(int i = 0; i < 4; i++){
        int a = x + dx[i], b = y + dy[i];
        if(a < 0 || a >= n || b < 0 || b >= m || g[a][b] == '#') continue;
        res += dfs(a, b);
    }
    return res;
}

int main(){
    while(cin >> m >> n, m || n){
        int x, y;
        for(int i = 0; i < n;i ++)
            for(int j = 0; j < m; j++){
                cin >> g[i][j];
                if(g[i][j] == '@') x = i, y = j;
            }
        cout << dfs(x, y) << endl;
    }
    return 0;
}