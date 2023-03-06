// 农夫约翰正在一个新的销售区域对他的牛奶销售方案进行调查。

// 他想把牛奶送到 T
//  个城镇，编号为 1∼T
// 。

// 这些城镇之间通过 R
//  条道路 (编号为 1
//  到 R
// ) 和 P
//  条航线 (编号为 1
//  到 P
// ) 连接。

// 每条道路 i
//  或者航线 i
//  连接城镇 Ai
//  到 Bi
// ，花费为 Ci
// 。

// 对于道路，0≤Ci≤10,000
// ;然而航线的花费很神奇，花费 Ci
//  可能是负数(−10,000≤Ci≤10,000
// )。

// 道路是双向的，可以从 Ai
//  到 Bi
// ，也可以从 Bi
//  到 Ai
// ，花费都是 Ci
// 。

// 然而航线与之不同，只可以从 Ai
//  到 Bi
// 。

// 事实上，由于最近恐怖主义太嚣张，为了社会和谐，出台了一些政策：保证如果有一条航线可以从 Ai
//  到 Bi
// ，那么保证不可能通过一些道路和航线从 Bi
//  回到 Ai
// 。

// 由于约翰的奶牛世界公认十分给力，他需要运送奶牛到每一个城镇。

// 他想找到从发送中心城镇 S
//  把奶牛送到每个城镇的最便宜的方案。

// 输入格式
// 第一行包含四个整数 T,R,P,S
// 。

// 接下来 R
//  行，每行包含三个整数（表示一个道路）Ai,Bi,Ci
// 。

// 接下来 P
//  行，每行包含三个整数（表示一条航线）Ai,Bi,Ci
// 。

// 输出格式
// 第 1..T
//  行：第 i
//  行输出从 S
//  到达城镇 i
//  的最小花费，如果不存在，则输出 NO PATH。

// 数据范围
// 1≤T≤25000
// ,
// 1≤R,P≤50000
// ,
// 1≤Ai,Bi,S≤T
// 输入样例：
// 6 3 3 4
// 1 2 5
// 3 4 5
// 5 6 10
// 3 5 -100
// 4 6 -100
// 1 3 -10
// 输出样例：
// NO PATH
// NO PATH
// 5
// 0
// -95
// -100

#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;
const int N = 25010, M = 150010, INF = 0x3f3f3f3f;

int n, mr, mp, S;
int h[N], e[M], w[M], ne[M], idx;
int id[N];
vector<int> block[N];
int bcnt;
int dist[N], din[N];
bool st[N];
queue<int> q;

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int bid){
    id[u] = bid;
    block[bid].push_back(u);
    
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(!id[j]) dfs(j, bid);
    }
}

void dijkstra(int bid){
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    for(auto ver : block[bid]) heap.push({dist[ver], ver});
    
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        
        int ver = t.y, distance = t.x;
        if(st[ver]) continue;
        st[ver] = true;
        
        for(int i = h[ver]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[ver] + w[i]){
                dist[j] = dist[ver] + w[i];
                if(id[j] == id[ver]) heap.push({dist[j], j});
            }
            
            if(id[j] != id[ver] && --din[id[j]] == 0) q.push(id[j]);
        }
    }
}

void topsort(){
    memset(dist, 0x3f, sizeof dist);
    dist[S] = 0;
    
    for(int i = 1; i <= bcnt; i++)
        if(!din[i])
            q.push(i);
            
    while(q.size()){
        int t = q.front();
        q.pop();
        dijkstra(t);
    }
}

int main(){
    scanf("%d%d%d%d", &n, &mr, &mp, &S);
    
    memset(h, -1, sizeof h);
    while(mr--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    
    for(int i = 1; i <= n; i++)
        if(!id[i])
            dfs(i, ++bcnt);
            
    while(mp--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        din[id[b]]++;
    }
    
    topsort();
    
    for(int i = 1; i <= n; i++)
        if(dist[i] > INF / 2) puts("NO PATH");
        else printf("%d\n", dist[i]);
    
    return 0;
}