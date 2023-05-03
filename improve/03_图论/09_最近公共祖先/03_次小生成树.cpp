// 给定一张 N
//  个点 M
//  条边的无向图，求无向图的严格次小生成树。

// 设最小生成树的边权之和为 sum
// ，严格次小生成树就是指边权之和大于 sum
//  的生成树中最小的一个。

// 输入格式
// 第一行包含两个整数 N
//  和 M
// 。

// 接下来 M
//  行，每行包含三个整数 x，y，z
// ，表示点 x
//  和点 y
//  之前存在一条边，边的权值为 z
// 。

// 输出格式
// 包含一行，仅一个数，表示严格次小生成树的边权和。(数据保证必定存在严格次小生成树)

// 数据范围
// N≤105,M≤3×105
// ,
// 1≤x,y≤N
// ,
// 0≤z≤106
// 输入样例：
// 5 6
// 1 2 1
// 1 3 2
// 2 4 3
// 3 5 4
// 3 4 3
// 4 5 6
// 输出样例：
// 11

// 定理：对于一张无向图，如果存在最小生成树和（严格）次小生成树，那么对于任何一颗最小生成树，都存在一颗（严格）次小生成树，使得这两颗树只有一条边不同
// 做法：用kruskal处理出来一颗树，然后枚举每一条非树的边，在有这条边组成回路的树中查找最大的边权，然后在 树的权值和 + 非树边的边权 - 最大的权值 得到最小值
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10, M = 3e5 + 10, INF = 0x3f3f3f3f;
int n, m;
struct Edge{
    int a, b, w;
    bool used;
    bool operator < (const Edge &t) const{
        return w < t.w;
    }
}edge[M];
int p[N]; // 保存祖宗节点
int h[N], e[M], w[M], ne[M], idx;
int depth[N], fa[N][17], d1[N][17], d2[N][17]; // depth保存该点在第几层，fa保存从i点向上跳2^j的点
// d1[i][j]保存从i点向上跳2^j的路径上的最大边权，d2[i][j]保存从i点向上跳2^j的路径上的次大边权

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

LL kruskal(){
    for(int i = 1; i <= n; i++) p[i] = i; //先将每个点的父亲节点都设置成自己
    sort(edge, edge + m); // 给边按照权值从小到大排序
    LL res = 0; // 保存树的权值和
    for(int i = 0; i < m; i++){ // 枚举每一条边
        int a = find(edge[i].a), b = find(edge[i].b), w = edge[i].w;
        if(a != b){ // 如果a和b不在一个连通块中
            p[a] = b; // 将a的祖宗节点的父节点设置为b的祖宗节点
            res += w;
            edge[i].used = true; // 该边设置为树边
        }
    }
    return res;
}

void build(){
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++) 
        if(edge[i].used){ // 如果edge[i].used为true，表示该边为树边
            int a = edge[i].a, b = edge[i].b, w = edge[i].w;
            add(a, b, w), add(b, a, w);
        }
}

void bfs(){ // 获取每个点的depth，fa，d1，d2
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[1] = 1; // 哨兵0的层数为0，根节点1的层数为1
    queue<int> q;
    q.push(1);
    while(q.size()){
        int t = q.front();
        q.pop();
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(depth[j] > depth[t] + 1){
                depth[j] = depth[t] + 1;
                q.push(j);
                fa[j][0] = t; // j的父节点为t
                d1[j][0] = w[i], d2[j][0] = -INF; // j向上走一步的最大权值为w[i]，因为次大权值不存在，所以设置为无穷小
                for(int k = 1; k <= 16; k++){ // 枚举j向上走2^1 - 2^16 步，这里一定要从小到大枚举，因为后面的需要用到前面的
                    int anc = fa[j][k - 1]; // 获取j向上走2^(k-1)的点
                    fa[j][k] = fa[anc][k - 1]; // 获取j向上走2^k的点
                    int distance[4] = {d1[j][k - 1], d2[j][k - 1], d1[anc][k - 1], d2[anc][k - 1]}; // 保存从j向上走2^(k-1)再走2^(k-1)两条路径上的最大和次大权值
                    d1[j][k] = d2[j][k] = -INF; // 设置从j向上走2^k的最大和次大权值为无穷小
                    for(int u = 0; u < 4; u++){ // 枚举这四条边
                        int d = distance[u]; // 更新最大和次大权值
                        if(d > d1[j][k]) d2[j][k] = d1[j][k], d1[j][k] = d;
                        else if(d != d1[j][k] && d > d2[j][k]) d2[j][k] = d;
                    }
                }
            }
        }
    }
}

int lca(int a, int b, int w){
    static int distance[N * 2]; // 静态数组distance保存找到a和b的最近公共祖先路径上的权值
    int cnt = 0; // cnt保存权值数量
    if(depth[a] < depth[b]) swap(a, b); // 如果a层数比b小，交换
    for(int k = 16; k >= 0; k--) // 先将a和b置于同一层
        if(depth[fa[a][k]] >= depth[b]){ // 如果a向上走2^k步后的层数大于等于b的层数，说明可以走
            distance[cnt++] = d1[a][k]; // 将最大和次大权值保存进distance
            distance[cnt++] = d2[a][k];
            a = fa[a][k]; // a向上走
        }
    if(a != b){ // 如果a不等于b
        for(int k = 16; k >= 0; k--) // 枚举向上走2^k步
            if(fa[a][k] != fa[b][k]){ // 如果向上走2^k步节点不同，说明没有走到最近公共祖先
                distance[cnt++] = d1[a][k]; // 保存权值
                distance[cnt++] = d2[a][k];
                distance[cnt++] = d1[b][k];
                distance[cnt++] = d2[b][k];
                a = fa[a][k], b = fa[b][k]; // a和b都向上走
            }
        distance[cnt++] = d1[a][0]; // 将a和b向上走1步的权值保存进数组
        distance[cnt++] = d1[b][0];
    }
    
    int dist1 = -INF, dist2 = -INF; // 保存最大和次大权值
    for(int i = 0; i < cnt; i++){ // 枚举每一个权值
        int d = distance[i]; // 更新
        if(d > dist1) dist2 = dist1, dist1 = d;
        else if(d != dist1 && d > dist2) dist2 = d;
    }
    
    if(w > dist1) return w - dist1; // 如果w是大于dist1的，就返回w-dist1
    if(w > dist2) return w - dist2; // 如果w是大于dist2的，就返回w-dist2
    return INF; // 否则返回无穷大表示不存在这条边
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){ // 先将所有边都保存起来
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edge[i] = {a, b, c};
    }
    LL sum = kruskal(); // 使用kruskal算法获得树，并且获取数的权值和
    build(); // 建树
    bfs(); 
    
    LL res = 1e18; // 最后结果要取最小值，所以res设置为无穷大
    for(int i = 0; i < m; i++) 
        if(!edge[i].used){ // 枚举每一条非树边
            int a = edge[i].a, b = edge[i].b, w = edge[i].w;
            res = min(res, sum + lca(a, b, w)); // 获取次小生成树的权值和，lca返回a和b两个节点以及连接它们的非树边组成的环，得到环里面的最大权值，用w减去它，再加上sum的到次小生成树权值和
        }
    printf("%lld\n", res);
    
    return 0;
}