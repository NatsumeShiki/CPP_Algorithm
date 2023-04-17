// 1944 年，特种兵麦克接到国防部的命令，要求立即赶赴太平洋上的一个孤岛，营救被敌军俘虏的大兵瑞恩。

// 瑞恩被关押在一个迷宫里，迷宫地形复杂，但幸好麦克得到了迷宫的地形图。

// 迷宫的外形是一个长方形，其南北方向被划分为 N
//  行，东西方向被划分为 M
//  列， 于是整个迷宫被划分为 N×M
//  个单元。

// 每一个单元的位置可用一个有序数对 (单元的行号, 单元的列号) 来表示。

// 南北或东西方向相邻的 2
//  个单元之间可能互通，也可能有一扇锁着的门，或者是一堵不可逾越的墙。

// 注意： 门可以从两个方向穿过，即可以看成一条无向边。

// 迷宫中有一些单元存放着钥匙，同一个单元可能存放 多把钥匙，并且所有的门被分成 P
//  类，打开同一类的门的钥匙相同，不同类门的钥匙不同。

// 大兵瑞恩被关押在迷宫的东南角，即 (N,M)
//  单元里，并已经昏迷。

// 迷宫只有一个入口，在西北角。

// 也就是说，麦克可以直接进入 (1,1)
//  单元。

// 另外，麦克从一个单元移动到另一个相邻单元的时间为 1
// ，拿取所在单元的钥匙的时间以及用钥匙开门的时间可忽略不计。

// 试设计一个算法，帮助麦克以最快的方式到达瑞恩所在单元，营救大兵瑞恩。

// 输入格式
// 第一行有三个整数,分别表示 N,M,P
//  的值。

// 第二行是一个整数 k
// ，表示迷宫中门和墙的总数。

// 接下来 k
//  行，每行包含五个整数，Xi1,Yi1,Xi2,Yi2,Gi
// ：当 Gi≥1
//  时，表示 (Xi1,Yi1)
//  单元与 (Xi2,Yi2)
//  单元之间有一扇第 Gi
//  类的门，当 Gi=0
//  时，表示 (Xi1,Yi1)
//  单元与 (Xi2,Yi2)
//  单元之间有一面不可逾越的墙。

// 接下来一行，包含一个整数 S
// ，表示迷宫中存放的钥匙的总数。

// 接下来 S
//  行，每行包含三个整数 Xi1,Yi1,Qi
// ，表示 (Xi1,Yi1)
//  单元里存在一个能开启第 Qi
//  类门的钥匙。

// 输出格式
// 输出麦克营救到大兵瑞恩的最短时间。

// 如果问题无解，则输出 -1。

// 数据范围
// |Xi1−Xi2|+|Yi1−Yi2|=1
// ,
// 0≤Gi≤P
// ,
// 1≤Qi≤P
// ,
// 1≤N,M,P≤10
// ,
// 1≤k≤150
// 输入样例：
// 4 4 9
// 9
// 1 2 1 3 2
// 1 2 2 2 0
// 2 1 2 2 0
// 2 1 3 1 0 
// 2 3 3 3 0
// 2 4 3 4 1
// 3 2 3 3 0
// 3 3 4 3 0
// 4 3 4 4 0
// 2
// 2 1 2 
// 4 2 1
// 输出样例：
// 14

/*
动态规划
  状态表示 d[x, y, state]
    集合：所有从起点走到(x, y)这个格子，且当前已经拥有的钥匙是state的所有路线的集合
    属性：最短距离
  状态计算
    1. (x, y)这里有一些钥匙，那么可以直接将所有钥匙拿起，state | key
      d[x, y, state | key] = min(d[x, y, state | key], d[x, y, state])
    2. 向上下左右四个方向走，(1)没有门和墙 (2)有门，且有匹配的钥匙
      d[a, b, state] = min(d[a, b, state], d[x, y, state] + 1)
*/
#include<iostream>
#include<deque>
#include<cstring>
#include<set>
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
// N保存的是矩阵的边长，M保存的是矩阵中格子的数目，E表示边的数量 n(n-1) * 2 * 2 = 4 * 10 * 9 = 360 ，用二进制1的位置表示是否持有钥匙
const int N = 11, M = N * N, E = 450, P = 1 << 10;

int n, m, p, k;
int h[M], e[E], w[E], ne[E], idx;
int g[N][N], key[M]; // g数组用于映射一维坐标，key表示一维表示的坐标下有哪些钥匙
int dist[M][P]; // 一维表示点的坐标，二维表示持有的钥匙
bool st[M][P]; // 表示某个位置并且拥有钥匙的状态是否已经是true

set<PII> edges; // 保存两个点之间是否已经右边

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void build(){
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    
    for(int i = 1; i <= n; i++) // 枚举横
        for(int j = 1; j <= m; j++) // 枚举纵
            for(int u = 0; u < 4; u++){ // 枚举四个方向
                int x = i + dx[u], y = j + dy[u]; // 获取偏移后的坐标
                if(!x || x > n || !y || y > m) continue; // 越界continue
                int a = g[i][j], b = g[x][y]; // 映射成一维的
                if(edges.count({a, b}) == 0) add(a, b, 0); // 如果它们之间edges没有存储边，说明可以双向通过
            }
}

int bfs(){
    memset(dist, 0x3f, sizeof dist); // 将距离初始化成无穷大
    dist[1][0] = 0; // 一维坐标1位置，没有钥匙，它的距离是0
    
    deque<PII> q; // 双端队列
    q.push_back({1, 0}); // 将初始状态存进去
    
    while(q.size()){
        PII t = q.front();
        q.pop_front();
        
        if(st[t.x][t.y]) continue; // 如果已经走到这里过了，continue
        st[t.x][t.y] = true; // 否则设置成走到这里过了
        
        if(t.x == n * m) return dist[t.x][t.y]; // 如果一维坐标是n*m，说明已经走到了终点
        
        if(key[t.x]){ // 如果这里有钥匙
            int state = t.y | key[t.x]; // 获取现有的钥匙和这里的钥匙或的结果
            if(dist[t.x][state] > dist[t.x][t.y]){ // 如果更新后距离更小
                dist[t.x][state] = dist[t.x][t.y]; // 更新距离
                q.push_front({t.x, state}); // 因为在这里可以拿也可以不拿，但是拿了肯定是没有坏处的，距离也不会增加，相当于权值是0，所以添加到队列的头部
            }
        }
        
        for(int i = h[t.x]; ~i; i = ne[i]){
            int j = e[i]; // 获取下一个坐标
            if(w[i] && !(t.y >> w[i] - 1 & 1)) continue; // 如果这个位置需要钥匙，但是该状态下没有该钥匙，continue
            if(dist[j][t.y] > dist[t.x][t.y] + 1){ // 如果有钥匙，并且距离更小
                dist[j][t.y] = dist[t.x][t.y] + 1; // 更新距离
                q.push_back({j, t.y}); // 因为要走一步，所以存进到队列的尾部
            }
        }
    }
    
    return -1;
}

int main(){
    
    cin >> n >> m >> p >> k;
    for(int i = 1, t = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            g[i][j] = t++; // 将二维坐标映射成一维的
            
    memset(h, -1, sizeof h);
    while(k--){
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        int a = g[x1][y1], b = g[x2][y2]; // 获取映射成一维的两个坐标
        edges.insert({a, b}), edges.insert({b, a}); // 存到edges表示他们之间已经有边了
        if(c) add(a, b, c), add(b, a, c); // 如果c不是0，说明a和b之间可以双向通过
    }
    
    build();
    
    int s;
    cin >> s; 
    while(s--){ // 读入钥匙的坐标和id
        int x, y, id;
        cin >> x >> y >> id;
        key[g[x][y]] |= 1 << id - 1; // 在一维坐标下添加钥匙的id
    }
    
    cout << bfs() << endl;
    
    return 0;
}