// 农夫John发现了做出全威斯康辛州最甜的黄油的方法：糖。

// 把糖放在一片牧场上，他知道 N 只奶牛会过来舔它，这样就能做出能卖好价钱的超甜黄油。

// 当然，他将付出额外的费用在奶牛上。

// 农夫John很狡猾，就像以前的巴甫洛夫，他知道他可以训练这些奶牛，让它们在听到铃声时去一个特定的牧场。

// 他打算将糖放在那里然后下午发出铃声，以至他可以在晚上挤奶。

// 农夫John知道每只奶牛都在各自喜欢的牧场（一个牧场不一定只有一头牛）。

// 给出各头牛在的牧场和牧场间的路线，找出使所有牛到达的路程和最短的牧场（他将把糖放在那）。

// 数据保证至少存在一个牧场和所有牛所在的牧场连通。

// 输入格式
// 第一行: 三个数：奶牛数 N，牧场数 P，牧场间道路数 C。

// 第二行到第 N+1 行: 1 到 N 头奶牛所在的牧场号。

// 第 N+2 行到第 N+C+1 行：每行有三个数：相连的牧场A、B，两牧场间距 D，当然，连接是双向的。

// 输出格式
// 共一行，输出奶牛必须行走的最小的距离和。

// 数据范围
// 1≤N≤500
// ,
// 2≤P≤800
// ,
// 1≤C≤1450
// ,
// 1≤D≤255
// 输入样例：
// 3 4 5
// 2
// 3
// 4
// 1 2 1
// 1 3 5
// 2 3 7
// 2 4 3
// 3 4 5
// 输出样例：
// 8

// floyd 会TLE
#include<iostream>
#include<cstring>
using namespace std;

const int N = 510, M = 810;
int d[M][M];
int place[N];
int n, m, k;

int main(){
    cin >> n >> m >> k;
    memset(d, 0x3f, sizeof d);
    
    for(int i = 1; i <= n; i++) cin >> place[i];
    while(k--){
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = d[b][a] = min(d[a][b], c);
    }
    
    for(int i = 1; i <= m; i++) d[i][i] = 0;
    
    for(int x = 1; x <= m; x++)
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++)
                d[i][j] = min(d[i][j], d[i][x] + d[x][j]);
                
    int res = 0x3f3f3f3f;
    for(int i = 1; i <= m; i++){
        int ans = 0;
        for(int j = 1; j <= n; j++)
            ans += d[i][place[j]];
            
        res = min(res, ans);
    }
    
    cout << res << endl;
    
    
    return 0;
}

// 堆优化的dijkstra
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

#define x first
#define y second
typedef pair<int, int> PII;
typedef long long LL;
const int N = 810, M = 3000, INF = 0x3f3f3f3f;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
int n, m, k;
int place[N];

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(int start){
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, start});
    dist[start] = 0;
    
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
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &place[i]);
    memset(h, -1, sizeof h);
    while(k--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
    
    LL res = INF;
    for(int i = 1; i <= m; i++){
        dijkstra(i);
        LL ans = 0;
        for(int i = 1; i <= n; i++){
            int x = place[i];
            ans += dist[x];
        }
        res = min(res, ans);
    }
    
    printf("%d\n", res);
    
    return 0;
}

// spfa
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

typedef long long LL;
const int N = 810, M = 3000;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
int place[N];
int n, m, k;

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa(int start){
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    
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
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &place[i]);
    memset(h, -1, sizeof h);
    while(k--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
    
    LL res = 0x3f3f3f3f;
    for(int i = 1; i <= m; i++){
        spfa(i);
        LL ans = 0;
        for(int j = 1; j <= n; j++)
            ans += dist[place[j]];
        res = min(res, ans);
    }
    printf("%d\n", res);
    
    
    return 0;
}