// 农夫约翰要把他的牛奶运输到各个销售点。

// 运输过程中，可以先把牛奶运输到一些销售点，再由这些销售点分别运输到其他销售点。

// 运输的总距离越小，运输的成本也就越低。

// 低成本的运输是农夫约翰所希望的。

// 不过，他并不想让他的竞争对手知道他具体的运输方案，所以他希望采用费用第二小的运输方案而不是最小的。

// 现在请你帮忙找到该运输方案。

// 注意：：

// 如果两个方案至少有一条边不同，则我们认为是不同方案；
// 费用第二小的方案在数值上一定要严格大于费用最小的方案；
// 答案保证一定有解；
// 输入格式
// 第一行是两个整数 N,M
// ，表示销售点数和交通线路数；

// 接下来 M
//  行每行 3
//  个整数 x,y,z
// ，表示销售点 x
//  和销售点 y
//  之间存在线路，长度为 z
// 。

// 输出格式
// 输出费用第二小的运输方案的运输总距离。

// 数据范围
// 1≤N≤500
// ,
// 1≤M≤104
// ,
// 1≤z≤109
// ,
// 数据中可能包含重边。

// 输入样例：
// 4 4
// 1 2 100
// 2 4 200
// 2 3 250
// 3 4 100
// 输出样例：
// 450

/*
次小生成树
  定义：给一个带权的图，把图的所有生成树权值从小到大排序，第二小的成为次小生成树

方法1：先求最小生成树，在枚举删去最小生成树中的边求解。时间复杂度 O(mlogm + nm)
方法2：先求最小生成树，然后依次枚举非树边，然后将该边加入树中，同时从树中去掉一条边，使得最终的图仍是一棵树，则一定可以求出次小生成树

方法2正确性的证明：
  设T为图G的一颗生成树，对于非树边a和鼠标b插入边a，并删除边b的操作记为(+a, -b)
  如果T+a-b之后，仍是一颗生成树，称(+a, -b)是T的一个可行交换
  称由T进行一次可行变换所得到的新的生成树集合称为T的邻集
  定理：次小生成树一定在最小生成树的邻集中

本题使用方法2，步骤：
第一步 求最小生成树，同时标记每条边是树边还是非树边；同时把最小生成树建立出来  O(mlogm)
第二步 预处理任意两点间的边权的最大值dist1[a][b]和次大值dist[a][b] O(n^2)
第三步 依次枚举所有非树边，求min(sum + w - dist[a][b])，满足w > dist[a][b] O(m) 
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
const int N = 510, M = 10010;

int n, m;
struct Edge{
    int a, b, w;
    bool f; // 保存该边是不是最小生成树的边，如果是则为true
    bool operator < (const Edge &t) const{
        return w < t.w;
    }
}edge[M];
int p[N];
int dist1[N][N], dist2[N][N]; // 最小生成树中两个点之间边权的最大和次大的值
int h[N], e[N * 2], w[N * 2], ne[N * 2], idx; // 最小生成树里面的邻接表

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void dfs(int u, int fa, int maxd1, int maxd2, int d1[], int d2[]){
    d1[u] = maxd1, d2[u] = maxd2; // 保存从初始点到该点的最大值和次大值
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(j != fa){
            int td1 = maxd1, td2 = maxd2; 
            if(w[i] > td1) td2 = td1, td1 = w[i];
            else if(w[i] < td1 && w[i] > td2) td2 = w[i]; // 这里不能等于，否则可能会得到相同权值和的数
            dfs(j, u, td1, td2, d1, d2);
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++){
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edge[i] = {a, b, w};
    }
    
    sort(edge, edge + m);
    for(int i = 1; i <= n; i++) p[i] = i;
    
    LL sum = 0; // sum保存最小生成树的边权的和
    for(int i = 0; i < m; i++){
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        int pa = find(a), pb = find(b);
        if(pa != pb){ // 如果两个连通块不在一起，则这条边是最小生成树的边
            p[pa] = pb;
            sum += w; 
            add(a, b, w), add(b, a, w);
            edge[i].f = true; 
        }
    }
    
    for(int i = 1; i <= n; i++) dfs(i, -1, -1e9, -1e9, dist1[i], dist2[i]); // 求从每个点出发到其他点之间边权的最大值和次大值
    
    LL res = 1e18;
    for(int i = 0; i < m; i++)
        if(!edge[i].f){ // 如果这条边不是树边
            int a = edge[i].a, b = edge[i].b, w = edge[i].w;
            LL t;
            if(w > dist1[a][b]) t = sum + w - dist1[a][b]; // 如果w比a到b的树边里面最大的值还要大，计算权值和
            else if(w > dist2[a][b]) t = sum + w - dist2[a][b]; // 如果w比a到b的树边里面次大的值还要大，计算权值和
            res = min(res, t); // 获得最小值
        }
        
    printf("%lld\n", res);
    
    return 0;
}