// 你有一张某海域 N×N
//  像素的照片，”.”表示海洋、”#”表示陆地，如下所示：

// .......
// .##....
// .##....
// ....##.
// ..####.
// ...###.
// .......
// 其中”上下左右”四个方向上连在一起的一片陆地组成一座岛屿，例如上图就有 2
//  座岛屿。

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

// 以下 N
//  行 N
//  列，包含一个由字符”#”和”.”构成的 N×N
//  字符矩阵，代表一张海域照片，”#”表示陆地，”.”表示海洋。

// 照片保证第 1
//  行、第 1
//  列、第 N
//  行、第 N
//  列的像素都是海洋。

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

#include<iostream>
#include<queue>
using namespace std;

#define x first
#define y second
typedef pair<int, int> PII;
const int N = 1010;
char g[N][N];
bool st[N][N];
int n;

int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};

void bfs(int x, int y, int &total, int &bound){
    queue<PII> q;
    q.push({x, y});
    st[x][y] = true;
    
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        total++;
        bool is_flag = false;
        for(int i = 0; i < 4; i++){
            int a = t.x + dx[i], b = t.y + dy[i];
            if(a < 0 || a >= n || b < 0 || b >= n) continue;
            if(st[a][b]) continue;
            if(g[a][b] == '.'){
                is_flag = true;
                continue;
            }
            q.push({a, b});
            st[a][b] = true;
        }
        if(is_flag) bound++;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> g[i];
    
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            if(!st[i][j] && g[i][j] == '#'){
                int total = 0, bound = 0;
                bfs(i, j, total, bound);
                if(total == bound) cnt++;
            }
        }
     cout << cnt << endl;
    
    return 0;
}