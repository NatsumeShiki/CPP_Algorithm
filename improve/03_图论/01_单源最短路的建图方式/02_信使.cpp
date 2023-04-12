// 战争时期，前线有 n
//  个哨所，每个哨所可能会与其他若干个哨所之间有通信联系。

// 信使负责在哨所之间传递信息，当然，这是要花费一定时间的（以天为单位）。

// 指挥部设在第一个哨所。

// 当指挥部下达一个命令后，指挥部就派出若干个信使向与指挥部相连的哨所送信。

// 当一个哨所接到信后，这个哨所内的信使们也以同样的方式向其他哨所送信。信在一个哨所内停留的时间可以忽略不计。

// 直至所有 n
//  个哨所全部接到命令后，送信才算成功。

// 因为准备充足，每个哨所内都安排了足够的信使（如果一个哨所与其他 k
//  个哨所有通信联系的话，这个哨所内至少会配备 k
//  个信使）。

// 现在总指挥请你编一个程序，计算出完成整个送信过程最短需要多少时间。

// 输入格式
// 第 1
//  行有两个整数 n
//  和 m
// ，中间用 1
//  个空格隔开，分别表示有 n
//  个哨所和 m
//  条通信线路。

// 第 2
//  至 m+1
//  行：每行三个整数 i、j、k
// ，中间用 1
//  个空格隔开，表示第 i
//  个和第 j
//  个哨所之间存在 双向 通信线路，且这条线路要花费 k
//  天。

// 输出格式
// 一个整数，表示完成整个送信过程的最短时间。

// 如果不是所有的哨所都能收到信，就输出-1。

// 数据范围
// 1≤n≤100
// ,
// 1≤m≤200
// ,
// 1≤k≤1000
// 输入样例：
// 4 4
// 1 2 4
// 2 3 7
// 2 4 1
// 3 4 6
// 输出样例：
// 11

// 我的思路是从后往前搜索，起始时有100元，经过转换最早到达起点即为所需要的最少钱
// 朴素dijkstra
#include<iostream>
#include<cstring>
using namespace std;

const int N = 2010;
double d[N][N];
double dist[N];
bool st[N];
int n, m;
int S, T;

void dijkstra(){
    for(int i = 1; i <= n; i++) dist[i] = 0x3f3f3f3f;
    
    dist[T] = 100;
    for(int i = 0; i < n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++)
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
                
        st[t] = true;
        for(int j = 1; j <= n; j++) 
            if(dist[j] > dist[t] / d[t][j])
                dist[j] = dist[t] / d[t][j];
    }
}

int main(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i != j) d[i][j] = 0x3f3f3f3f;
    
    scanf("%d%d", &n, &m);
    while(m--){
        int a, b;
        double c;
        scanf("%d%d%lf", &a, &b, &c);
        c = 100 - c;
        c /= 100;
        d[a][b] = d[b][a] = max(d[a][b], c);
    }
    scanf("%d%d", &S, &T);
    dijkstra();
    
    printf("%.8lf\n", dist[S]);
    
    return 0;
}

// 朴素dijkstra
#include<iostream>
#include<cstring>
using namespace std;

const int N = 110;
int g[N][N];
bool st[N];
int dist[N];
int n, m;

void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i = 0; i < n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++)
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
            
        st[t] = true;
        for(int j = 1; j <= n; j++)
            if(!st[j])
                dist[j] = min(dist[t] + g[t][j], dist[j]);
    }
}

int main(){
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    
    dijkstra();
    
    int res = 0;
    for(int i = 1; i <= n; i++)
        if(dist[i] == 0x3f3f3f3f){
            res = -1;
            break;
        }
        else res = max(res, dist[i]);
        
    cout << res << endl;
    
    return 0;
}

// 堆优化dijkstra
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

#define x first
#define y second
typedef pair<int, int> PII;
const int N = 110, M = 410;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
int n, m;

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    
    while(heap.size()){
        PII t = heap.top();
        heap.pop();
        
        int ver = t.y, dis = t.x;
        if(st[ver]) continue;
        st[ver] = true;
        
        for(int i = h[ver]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] > dis + w[i]){
                dist[j] = dis + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    
    dijkstra();
    
    int res = 0;
    for(int i = 1; i <= n; i++) {
        if(dist[i] == 0x3f3f3f3f) {
            res = -1;
            break;
        }
        res = max(res, dist[i]);
    }
    cout << res << endl;
    
    return 0;
}

// spfa
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 110, M = 410;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
int n, m;

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    while(q.size()){
        int t = q.front();
        q.pop();    
    
        st[t] = false;
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                if(!st[j]){
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    
    dijkstra();
    
    int res = 0;
    for(int i = 1; i <= n; i++) 
        if(dist[i] == 0x3f3f3f3f){
            res = -1;
            break;
        }else res = max(res, dist[i]);
        
    cout << res << endl;
    
    
    return 0;
}

// floyd
#include<iostream>
#include<cstring>
using namespace std;

const int N = 110, INF = 0x3f3f3f3f;
int d[N][N];
int n, m;

int main(){
    memset(d, 0x3f, sizeof d);
    cin >> n >> m;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = d[b][a] = min(d[a][b], c);
    }
    
    for(int i = 1; i <= n; i++) d[i][i] = 0;
    
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                
    int res = 0;
    for(int i = 1; i <= n; i++)
        if(d[1][i] == INF){
            res = -1;
            break;
        }else res = max(res, d[1][i]);
    
    cout << res << endl;
    
    return 0;
}