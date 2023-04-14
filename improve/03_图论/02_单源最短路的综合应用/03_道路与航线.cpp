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

/*
1.如果边权非负，那么可以使用dijkstra，时间复杂度是mlogn
2.如果是拓扑图，那么不管边权是正是负，均可按拓扑扫描，时间复杂度是线性的

步骤：
1 先输入所以双向道路，然后dfs找出所有连通块，计算两个数组：id[]存储每个点属于哪个连通块；vector<int> block[]存储每个连通块里有哪些点
2 输入所有航线，同时统计出每个连通块的入度
3 按照拓扑排序依次处理每个连通块，先将所有入度为0的连通块的编号加入队列中
4 每次从队头取出一个连通块的编号bid
5 每该block[bid]中的所有点加入堆中，然后对堆中所有点跑dijkstra算法
6 每次取出堆中距离最小的点ver
7 然后遍历ver的所有邻点j，如果id[ver] == id[j]，那么如果j能被更新，则将j插入堆中；如果id[ver] != id[j]，则将id[j]这个连通块的入度减1，如果减成0了，
  则将其插入拓扑排序的队列中
*/

#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 25010, M = 150010, INF = 0x3f3f3f3f;

int n, mr, mp, S; // mr是陆地的边，mp是航路的边，S是起始点
int h[N], e[M], w[M], ne[M], idx;
int id[N];
vector<int> block[N]; // 记录每个连通块中有哪些点
int bcnt; // 连通块的数量
int dist[N], din[N]; // dist:每个点到起点的距离 din:每个连通块的入度
bool st[N]; 
queue<int> q; // 定义在外面是因为有两个函数要使用这个变量

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int bid){
    id[u] = bid; // 先给u这个点赋值id
    block[bid].push_back(u); // 将它插入到这个id的连通块中
    
    for(int i = h[u]; ~i; i = ne[i]){ // 向下搜索它的邻点
        int j = e[i];
        if(!id[j]) dfs(j, bid);
    }
}

void dijkstra(int bid){
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    for(auto ver : block[bid]) heap.push({dist[ver], ver}); // 将这个连通块中所以点都插入heap中
    
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        
        int ver = t.y, distance = t.x;
        if(st[ver]) continue;
        st[ver] = true;
        
        for(int i = h[ver]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[ver] + w[i]){ // 如果这个点到起点距离可以被更新
                dist[j] = dist[ver] + w[i]; // 更新距离
                if(id[j] == id[ver]) heap.push({dist[j], j}); // 插入队列中
            }
            if(id[j] != id[ver] && -- din[id[j]] == 0) q.push(id[j]); // 如果id不相同，1说明存在一条航路，把航路的终点的id减1，如果为0，则存进q数组中
        }
    }
}

void topsort(){
    memset(dist, 0x3f, sizeof dist); 
    dist[S] = 0;
    
    for(int i = 1; i <= bcnt; i++)
        if(!din[i]) // 如果入度为0，则插入q中
            q.push(i);
            
    while(q.size()){ // 直到q为空
        int t = q.front(); // 获取队头
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
        if(!id[i]) // 如果第i个点还没有赋值id
            dfs(i, ++bcnt); // dfs将与它连接的所有点赋值id
            
    while(mp--){ 
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        din[id[b]]++; // 航路，给对应连通块的如果加1
    } 
    topsort(); // 拓扑排序
    
    for(int i = 1; i <= n; i++)
        if(dist[i] > INF / 2) puts("NO PATH");
        else printf("%d\n", dist[i]);
    
    return 0;
}