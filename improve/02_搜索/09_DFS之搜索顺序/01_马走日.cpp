// 马在中国象棋以日字形规则移动。

// 请编写一段程序，给定 n∗m
//  大小的棋盘，以及马的初始位置 (x，y)
// ，要求不能重复经过棋盘上的同一个点，计算马可以有多少途径遍历棋盘上的所有点。

// 输入格式
// 第一行为整数 T
// ，表示测试数据组数。

// 每一组测试数据包含一行，为四个整数，分别为棋盘的大小以及初始位置坐标 n,m,x,y
// 。

// 输出格式
// 每组测试数据包含一行，为一个整数，表示马能遍历棋盘的途径总数，若无法遍历棋盘上的所有点则输出 0。

// 数据范围
// 1≤T≤9
// ,
// 1≤m,n≤9
// ,
// 1≤n×m≤28
// ,
// 0≤x≤n−1
// ,
// 0≤y≤m−1
// 输入样例：
// 1
// 5 4 0 0
// 输出样例：
// 32

#include<iostream>
#include<cstring>
using namespace std;

const int N = 15;
bool st[N][N];
int n, m, x, y;
int cnt = 0;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void dfs(int x, int y, int step){
    if(step == n * m){
        cnt++;
        return;
    }
    for(int i = 0; i < 8; i++){
        int a = x + dx[i], b = y + dy[i];
        if(a < 0 || a >= n || b < 0 || b >= m) continue;
        if(st[a][b]) continue;
        st[a][b] = true;
        dfs(a, b, step + 1);
        st[a][b] = false;
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        memset(st, 0, sizeof st);
        cin >> n >> m >> x >> y;
        cnt = 0;
        st[x][y] = true;
        dfs(x, y, 1);
        cout << cnt << endl;
    }
    
    
    return 0;
}