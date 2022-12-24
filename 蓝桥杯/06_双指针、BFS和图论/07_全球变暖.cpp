// 你有一张某海域 N×N 像素的照片，”.”表示海洋、”#”表示陆地，如下所示：

// .......
// .##....
// .##....
// ....##.
// ..####.
// ...###.
// .......
// 其中”上下左右”四个方向上连在一起的一片陆地组成一座岛屿，例如上图就有 2 座岛屿。

// 由于全球变暖导致了海面上升，科学家预测未来几十年，岛屿边缘一个像素的范围会被海水淹没。

// 具体来说如果一块陆地像素与海洋相邻(上下左右四个相邻像素中有海洋)，它就会被淹没。

// 例如上图中的海域未来会变成如下样子：

// .......
// .......
// .......
// .......
// ....#..
// .......
// .......
// 请你计算：依照科学家的预测，照片中有多少岛屿会被完全淹没。

// 输入格式
// 第一行包含一个整数N。

// 以下 N 行 N 列，包含一个由字符”#”和”.”构成的 N×N 字符矩阵，代表一张海域照片，”#”表示陆地，”.”表示海洋。

// 照片保证第 1 行、第 1 列、第 N 行、第 N 列的像素都是海洋。

// 输出格式
// 一个整数表示答案。

// 数据范围
// 1≤N≤1000
// 输入样例1：
// 7
// .......
// .##....
// .##....
// ....##.
// ..####.
// ...###.
// .......
// 输出样例1：
// 1
// 输入样例2：
// 9
// .........
// .##.##...
// .#####...
// .##.##...
// .........
// .##.#....
// .#.###...
// .#..#....
// .........
// 输出样例2：
// 1

// 看了大佬的思路之后自己写出来的
#include<iostream>
#include<queue>
using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;
const int N = 1010;
char g[N][N]; // 保存地图
bool st[N][N]; // 判重数组，如果这个点遍历过了，设置为true
int n;

int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0}; // 模拟四个方向
bool bfs(int x, int y){
    queue<PII> q; // 保存这个岛屿中的点
    q.push({x, y}); // 把初始这个点放进队列中
    st[x][y] = true; // 把初始点设置为true
    
    int total = 0; // 保存共有多少个格子
    int bound = 0; // 保存多少个格子会被淹没，如果最后total == bound，表示所有格子都会淹没
    
    while(q.size()){
        auto t = q.front();
        q.pop();
        total++;
        int x = t.x, y = t.y;
        bool flag = false; // 保存这个格子是否会被淹没，默认是指为false
        for(int i = 0; i < 4; i++){
            int a = x + dx[i], b = y + dy[i];
            if(a < 0 || a >= n || b < 0 || b >= n) continue; // 越界
            if(g[a][b] == '.') { // 如果某个方向上的点是海洋
                flag = true; // 就把它设置为会被淹没
                continue;
            }
            
            if(!st[a][b]) { // 如果这个点还没有被遍历过
                st[a][b] = true; // 设置为遍历了
                q.push({a, b}); // 并且把它放进队列中
            }
        }
        if(flag) bound++; // 如果flag最终为true，表明这个格子会被淹没，让bound加1
    }
    return total == bound; // 最终如果total == bount为true，表明这个岛屿会被完全淹没
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> g[i];
    int cnt = 0; // 保存会淹没多少个岛屿
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            if(!st[i][j] && g[i][j] == '#'){ // 如果这个点还没有遍历过并且这个点是陆地
                if(bfs(i, j)) // 进入bfs，如果返回true，表明这个岛屿会被完全淹没
                    cnt++;
            }
        }
    cout << cnt << endl;
    
    return 0;
}

// 大佬的代码
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 1010;

int n;
char g[N][N];
bool st[N][N];
PII q[N * N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(int sx, int sy, int &total, int &bound){
    
    int hh = 0, tt = 0;
    q[0] = {sx, sy};
    st[sx][sy] = true;
    
    while(hh <= tt){
        PII t = q[hh++];
        
        total++;
        bool is_bound = false;
        for(int i = 0; i < 4; i++){
            int x = t.x + dx[i], y = t.y + dy[i];
            if(x < 0 || x >= n || y < 0 || y >= n) continue; // 出界
            if(st[x][y]) continue;
            if(g[x][y] == '.'){
                is_bound = true;
                continue;
            }
            
            q[++tt] = {x, y};
            st[x][y] = true;
        }
        
        if(is_bound) bound++;
    }
    
}

int main(){
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) scanf("%s", g[i]);
    
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            if(!st[i][j] && g[i][j] == '#'){
                int total = 0, bound = 0;
                bfs(i, j, total, bound);
                if(total == bound) cnt++;
            }
        }
    
    printf("%d\n", cnt);
    
    return 0;
}