// 阿尔吉侬是一只聪明又慵懒的小白鼠，它最擅长的就是走各种各样的迷宫。

// 今天它要挑战一个非常大的迷宫，研究员们为了鼓励阿尔吉侬尽快到达终点，就在终点放了一块阿尔吉侬最喜欢的奶酪。

// 现在研究员们想知道，如果阿尔吉侬足够聪明，它最少需要多少时间就能吃到奶酪。

// 迷宫用一个 R×C 的字符矩阵来表示。

// 字符 S 表示阿尔吉侬所在的位置，字符 E 表示奶酪所在的位置，字符 # 表示墙壁，字符 . 表示可以通行。

// 阿尔吉侬在 1 个单位时间内可以从当前的位置走到它上下左右四个方向上的任意一个位置，但不能走出地图边界。

// 输入格式
// 第一行是一个正整数 T，表示一共有 T 组数据。

// 每一组数据的第一行包含了两个用空格分开的正整数 R 和 C，表示地图是一个 R×C 的矩阵。

// 接下来的 R 行描述了地图的具体内容，每一行包含了 C 个字符。字符含义如题目描述中所述。保证有且仅有一个 S 和 E。

// 输出格式
// 对于每一组数据，输出阿尔吉侬吃到奶酪的最少单位时间。

// 若阿尔吉侬无法吃到奶酪，则输出“oop!”（只输出引号里面的内容，不输出引号）。

// 每组数据的输出结果占一行。

// 数据范围
// 1<T≤10,
// 2≤R,C≤200
// 输入样例：
// 3
// 3 4
// .S..
// ###.
// ..E.
// 3 4
// .S..
// .E..
// ....
// 3 4
// .S..
// ####
// ..E.
// 输出样例：
// 5
// 1
// oop!

// 自己写出来的
#include<iostream>
#include<queue>
using namespace std;

typedef pair<int, int> PII; // 保存坐标
const int N = 210; 
int maze[N][N]; // 保存迷宫，0表示可以走，-1表示不能走，后面更新是到达这一点需要的步数
int n, r, c; 
int startX, startY, targetX, targetY;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}; // 模拟四个方向
int get(){
    queue<PII> q; // 队列
    q.push({startX, startY}); // 先把起点存进去
    while(q.size()){ // 直到队列为空
        auto p = q.front(); // 取出队头
        q.pop(); // 删除队头
        int x = p.first, y = p.second; // 获取该点坐标
        if(x == targetX && y == targetY) return maze[x][y]; // 如果该位置坐标与终点重合，返回maze中该点的值
        for(int i = 0; i < 4; i++){ 
            int a = x + dx[i], b = y + dy[i]; // 获取下一步的位置
            if(a >= 0 && a < r && b >= 0 && b < c && maze[a][b] == 0){ // 如果它在迷宫内，并且这一点还没有走
                q.push({a, b}); // 把它存进队列中
                maze[a][b] = maze[x][y] + 1; // 修改到达该点的值
            }
        }
    }
    return 0; // 如果之前没有返回，说明走不通，返回0表示无法到达终点
}

int main(){
    cin >> n;
    while(n--){
        cin >> r >> c;
        char x;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++){
                cin >> x;
                if(x == '#'){ // 如果是#，表示是墙，走不通，赋值-1
                    maze[i][j] = -1;
                }else{ // 否则就走得通，赋值0
                    if(x == 'S'){ // 如果是S，就是初始位置
                        startX = i, startY = j; 
                    }else if(x == 'E'){ // 如果是E，就是终点
                        targetX = i, targetY = j;
                    }
                    maze[i][j] = 0;
                }
                
            }
        
        int res = get(); // get函数返回到达终点所要的步数
        if(res) cout << res << endl; // 如果步数是大于0的，说明走的通
        else cout << "oop!" << endl;
        
    }
    
    return 0;
}

// 大佬的代码
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;
const int N = 210;

int n, m;
char g[N][N];
int dist[N][N];

int bfs(PII start, PII end){
    queue<PII> q;
    memset(dist, -1, sizeof dist);
    
    dist[start.x][start.y] = 0;
    q.push(start);
    
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    while(q.size()){
        auto t = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int x = t.x + dx[i], y = t.y + dy[i];
            if(x < 0 || x >= n || y < 0 || y >= m) continue; // 出界
            if(g[x][y] == '#') continue; // 障碍物
            if(dist[x][y] != -1) continue; // 之前已经遍历过
            
            dist[x][y] = dist[t.x][t.y] + 1;
            
            if(end == make_pair(x, y)) return dist[x][y];
            
            q.push({x, y});
        }
    }
    
    return -1;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) scanf("%s", g[i]);
        
        PII start, end;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(g[i][j] == 'S') start = {i, j};
                else if(g[i][j] == 'E') end = {i, j};
                
        int distance = bfs(start, end);
        if(distance == -1) cout << "oop!" << endl;
        else cout << distance << endl;
    }
    
    return 0;
}