// 有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。

// 你站在其中一块黑色的瓷砖上，只能向相邻（上下左右四个方向）的黑色瓷砖移动。

// 请写一个程序，计算你总共能够到达多少块黑色的瓷砖。

// 输入格式
// 输入包括多个数据集合。

// 每个数据集合的第一行是两个整数 W 和 H，分别表示 x 方向和 y 方向瓷砖的数量。

// 在接下来的 H 行中，每行包括 W 个字符。每个字符表示一块瓷砖的颜色，规则如下

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

// 自己写的代码
// 这道题可以使用dfs或者bfs，下面使用dfs
// 思路就是从起点开始，走上下左右四个方向，没走到一个黑格子，就把它变成红格子，res记录共有多少个黑格子连在一起
#include<iostream>
using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;
const int N = 30;
char g[N][N]; // 记录地图
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int res = 0; // 保存共有多少个黑格子和起点是连在一起的
int n, m;

void dfs(int x, int y){
    res++; // 黑格子数 +1
    g[x][y] = '#'; // 把它变成红格子
    for(int i = 0; i < 4; i++){ // 遍历四个方向
        int a = x + dx[i], b = y + dy[i]; // 获取坐标
        if(a >= 0 && a < m && b >= 0 && b < n && g[a][b] == '.') // 如果坐标在地图内并且这个格子是黑格子
            dfs(a, b); // 就继续向下搜索
    }
}

int main(){
    while(cin >> n >> m, n){ // 有多组数据
        for(int i = 0; i < m; i++) cin >> g[i];
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(g[i][j] == '@'){ // 数据保证只有一个@
                    res = 0; // 先把res重置为0
                    dfs(i, j);
                }
                    
        cout <<res << endl;
    }
    
    return 0;
}

// 使用bfs
#include<iostream>
#include<queue>
using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;
const int N = 30;
char g[N][N];
int n, m;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int bfs(int startX, int startY){
    queue<PII> q;
    q.push({startX, startY});
    int res = 1;
    while(q.size()){
        auto t = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int a = t.x + dx[i], b = t.y + dy[i];
            if(a >= 0 && a < m && b >= 0 && b < n && g[a][b] == '.'){
                res++;
                q.push({a, b});
                g[a][b] = '#';
            }
        }
    }
    return res;
}

int main(){
    while(cin >> n >> m, n){
        for(int i = 0; i < m; i++) cin >> g[i];
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(g[i][j] == '@')
                    cout << bfs(i, j) << endl;
    }
    
    return 0;
}

// 大佬的bfs
#include<iostream>
#include<queue>
using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;
const int N = 25;
char g[N][N];
int n, m;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int bfs(int sx, int sy){
    queue<PII> q;
    q.push({sx, sy});
    g[sx][sy] = '#';
    int res = 0;
    
    while(q.size()){
        auto t = q.front();
        q.pop();
        res++;
        for(int i = 0; i < 4; i++){
            int a = t.x + dx[i], b = t.y + dy[i];
            if(a < 0 || a >= n || b < 0 || b >= m || g[a][b] != '.') continue;
            q.push({a, b});
            g[a][b] = '#';
        }
    }
    return res;
}

int main(){
    while(cin >> m >> n, n || m){
        for(int i = 0; i < n; i++) cin >> g[i];
        int x, y;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(g[i][j] == '@')
                    x = i, y = j;
        cout << bfs(x, y) << endl;
    }
    
    return 0;
}

// 大佬的dfs
#include<iostream>
using namespace std;

const int N = 25;
char g[N][N];
int n, m;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int dfs(int x, int y){
    int res = 1;
    g[x][y] = '#';
    for(int i = 0; i < 4; i++){
        int a = x + dx[i], b = y + dy[i];
        if(a >= 0 && a < n && b >= 0 && b < m && g[a][b] == '.')
            res += dfs(a, b);
    }
    return res;
}

int main(){
    while(cin >> m >> n, n || m){
        for(int i = 0; i < n; i++) cin >> g[i];
        int x, y;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(g[i][j] == '@')
                    x = i, y = j;
        cout << dfs(x, y) << endl;
    }
    
    return 0;
}