// 某国家有 n
//  个城市（编号 1∼n
// ）和 m
//  条双向铁路。

// 每条铁路连接两个不同的城市，没有两条铁路连接同一对城市。

// 除了铁路以外，该国家还有公路。

// 对于每对不同的城市 x,y
// ，当且仅当它们之间没有铁路时，它们之间会存在一条双向公路。

// 经过每条铁路或公路都需要花费 1
//  小时的时间。

// 现在有一列火车和一辆汽车同时离开城市 1
// ，它们的目的地都是城市 n
// 。

// 它们不会在途中停靠（但是可以在城市 n
//  停靠）。

// 火车只能沿铁路行驶，汽车只能沿公路行驶。

// 请你为它们规划行进路线，每条路线中可重复经过同一条铁路或公路，但是为了避免发生事故，火车和汽车不得同时到达同一个城市（城市 n
//  除外）。

// 请问，在这些条件的约束下，两辆车全部到达城市 n
//  所需的最少小时数，即求更慢到达城市 n
//  的那辆车所需的时间的最小值。

// 注意，两辆车允许但不必要同时到达城市 n
// 。

// 输入格式
// 第一行包含整数 n
//  和 m
// 。

// 接下来 m
//  行，每行包含两个整数 u,v
// ，表示城市 u
//  和城市 v
//  之间存在一条铁路。

// 输出格式
// 一个整数，表示所需的最少小时数。

// 如果至少有一辆车无法到达城市 n
// ，则输出 −1
// 。

// 数据范围
// 前 6
//  个测试点满足 2≤n≤10
// ，0≤m≤10
// 。
// 所有测试点满足 2≤n≤400
// ，0≤m≤n(n−1)2
// ，1≤u,v≤n
// 。

// 输入样例1：
// 4 2
// 1 3
// 3 4
// 输出样例1：
// 2
// 输入样例2：
// 4 6
// 1 2
// 1 3
// 1 4
// 2 3
// 2 4
// 3 4
// 输出样例2：
// -1
// 输入样例3：
// 5 5
// 4 2
// 3 5
// 4 5
// 5 1
// 1 2
// 输出样例3：
// 3

// 自己的做法，使用floyd
#include<iostream>
#include<cstring>
using namespace std;

const int N = 410, INF = 0x3f3f3f3f;
int d[N][N][2];
int n, m;

void floyd(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                d[i][j][0] = min(d[i][j][0], d[i][k][0] + d[k][j][0]);
                d[i][j][1] = min(d[i][j][1], d[i][k][1] + d[k][j][1]);
            }
}

int main(){
    cin >> n >> m;
    memset(d, 0x3f, sizeof d);
    for(int i = 1; i <= n; i++) d[i][i][0] = d[i][i][1] = 0;
    while(m--){
        int a, b;
        cin >> a >> b;
        d[a][b][0] = d[b][a][0] = 1;
    }
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++)
            if(d[i][j][0] == INF)
                d[i][j][1] = d[j][i][1] = 1;
                
    floyd();
    
    int res;
    if(d[1][n][0] == INF || d[1][n][1] == INF) res = -1;
    else res = max(d[1][n][0], d[1][n][1]);
    
    cout << res << endl;
    
    return 0;
}

// floyd
#include<iostream>
#include<cstring>
using namespace std;

const int N = 410, INF = 0x3f3f3f3f;
int f[N][N], g[N][N];
int n, m;

int floyd(int d[][N]){
    if(d[1][n] == 1) return 1;
    
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                
    return d[1][n];
}

int main(){
    cin >> n >> m;
    memset(f, 0x3f, sizeof f);
    memset(g, 0x3f, sizeof g);
    
    while(m--){
        int a, b;
        cin >> a >> b;
        f[a][b] = f[b][a] = 1;
    }
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i != j && f[i][j] == INF)
                g[i][j] = g[j][i] = 1;
                
    int res = max(floyd(f), floyd(g));
    if(res == INF) res = -1;
    
    cout << res << endl;
    
    return 0;
}

// 使用spfa
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 410, M = N * N, INF = 0x3f3f3f3f;
int h1[N], h2[N], e[M], ne[M], idx;
bool st[N], g[N][N];
int dist[N];
int n, m;

void add(int h[], int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int spfa(int h[], bool flag){
    if(!flag && g[1][n] || flag && !g[1][n]) return 1;
    
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    st[1] = true;
    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + 1){
                dist[j] = dist[t] + 1;
                if(!st[j]) {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
    
    return dist[n];
}

int main(){
    cin >> n >> m;
    memset(h1, -1, sizeof h1);
    memset(h2, -1, sizeof h2);
    while(m--){
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = true;
        add(h1, a, b), add(h1, b, a);
    }
    
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            if(!g[i][j])
                add(h2, i, j), add(h2, j, i);
    
    int res = max(spfa(h1, false), spfa(h2, true));
    if(res == INF) res = -1;
    
    cout << res << endl;
    
    return 0;
}