// 德克萨斯纯朴的民众们这个夏天正在遭受巨大的热浪！！！

// 他们的德克萨斯长角牛吃起来不错，可是它们并不是很擅长生产富含奶油的乳制品。

// 农夫John此时身先士卒地承担起向德克萨斯运送大量的营养冰凉的牛奶的重任，以减轻德克萨斯人忍受酷暑的痛苦。

// John已经研究过可以把牛奶从威斯康星运送到德克萨斯州的路线。

// 这些路线包括起始点和终点一共有 T
//  个城镇，为了方便标号为 1
//  到 T
// 。

// 除了起点和终点外的每个城镇都由 双向道路 连向至少两个其它的城镇。

// 每条道路有一个通过费用（包括油费，过路费等等）。

// 给定一个地图，包含 C
//  条直接连接 2
//  个城镇的道路。

// 每条道路由道路的起点 Rs
// ，终点 Re
//  和花费 Ci
//  组成。

// 求从起始的城镇 Ts
//  到终点的城镇 Te
//  最小的总费用。

// 输入格式
// 第一行: 4
//  个由空格隔开的整数: T,C,Ts,Te
// ;

// 第 2
//  到第 C+1
//  行: 第 i+1
//  行描述第 i
//  条道路，包含 3
//  个由空格隔开的整数: Rs,Re,Ci
// 。

// 输出格式
// 一个单独的整数表示从 Ts
//  到 Te
//  的最小总费用。

// 数据保证至少存在一条道路。

// 数据范围
// 1≤T≤2500
// ,
// 1≤C≤6200
// ,
// 1≤Ts,Te,Rs,Re≤T
// ,
// 1≤Ci≤1000
// 输入样例：
// 7 11 5 4
// 2 4 2
// 1 4 3
// 7 2 2
// 3 4 3
// 5 7 5
// 7 3 3
// 6 1 1
// 6 3 4
// 2 4 3
// 5 6 3
// 7 2 1
// 输出样例：
// 7

// 朴素dijistra
#include<iostream>
#include<cstring>
using namespace std;

const int N = 2510;
int g[N][N];
int n, c, ts, te;
int dist[N];
bool st[N];

void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[ts] = 0;
    for(int i = 0; i < n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++)
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
                
        st[t] = true;
        for(int j = 1; j <= n; j++)
            if(!st[j])
                dist[j] = min(dist[t] + g[t][j], dist[j]);
    }
}

int main(){
    cin >> n >> c >> ts >> te;
    memset(g, 0x3f, sizeof g);
    while(c--){
        int a, b, d;
        cin >> a >> b >> d;
        g[a][b] = g[b][a] = min(g[a][b], d);
    }
    
    dijkstra();
    
    cout << dist[te] << endl;
    
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
const int N = 2510, M = 6210 * 2;
int h[N], e[M], w[M], ne[M], idx;
bool st[N];
int dist[N];
int t, c, ts, te;

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, ts});
    dist[ts] = 0;
    
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
    scanf("%d%d%d%d", &t, &c, &ts, &te);
    memset(h, -1, sizeof h);
    while(c--){
        int a, b, d;
        scanf("%d%d%d", &a, &b, &d);
        add(a, b, d);
        add(b, a, d);
    }
    
    dijkstra();
    
    cout << dist[te] << endl;
    
    return 0;
}

// spfa
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 2510, M = 6210 * 2;
int h[N], e[M], ne[M], w[M], idx;
int t, c, ts, te;
bool st[N];
int dist[N];

void add(int a, int b, int d){
    e[idx] = b, w[idx] = d, ne[idx] = h[a], h[a] = idx++;
}

void spfa(){
    memset(dist, 0x3f, sizeof dist);
    queue<int> q;
    q.push(ts);
    dist[ts] = 0;
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
    cin >> t >> c >> ts >> te;
    memset(h, -1, sizeof h);
    while(c--){
        int a, b, d;
        cin >> a >> b >> d;
        add(a, b, d);
        add(b, a, d);
    }
    
    spfa();
    
    cout << dist[te] << endl;
    
    
    return 0;
}