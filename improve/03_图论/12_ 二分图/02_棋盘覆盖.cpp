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

// 匈牙利算法
#include<iostream>
#include<cstring>
using namespace std;

typedef pair<int, int> PII;
const int N = 110;
bool g[N][N], st[N][N]; // g用来保存那个点不能使用，st是临时数组，用于匹配
int n, t;
PII match[N][N]; // 保存与(i, j)匹配的那个点
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

bool find(int x, int y){
    for(int i = 0; i < 4; i++){ // 遍历四个方向
        int a = x + dx[i], b = y + dy[i];
        if(a < 1 || a > n || b < 1 || b > n) continue; // 越界conitnue
        if(g[a][b] || st[a][b]) continue; // 如果这个点不能使用或者这个点已经与别的点匹配了，continue
        PII t = match[a][b]; // 得到与(a, b)这个点匹配的点
        st[a][b] = true; // 设置(a, b)已经使用了
        if(t.first == 0 || find(t.first, t.second)){ // 如果此时t.x还没有使用或者可以个t这个点找到别的匹配方案
            match[a][b] = {x, y}; // 与(a, b)匹配的点是(i, j)
            return true; // 返回true，表示找到了匹配的点
        }
    }
    return false; // 没有找到匹配的点，返回false
}

int main(){
    cin >> n >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        g[a][b] = true;
    }
    
    int res = 0;
    for(int i  = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if((i + j) % 2 && !g[i][j]){ // 如果(i + j)是奇数并且(i, j)这个点可以使用
                memset(st, 0, sizeof st); // 先将临时数组st清0
                if(find(i, j)) res++; // 如果可以找到与(i, j)匹配的点，结果加1
            }
                
    cout << res << endl;
    
    return 0;
}