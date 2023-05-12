// 一个有向图 G=(V,E)
//  称为半连通的 (Semi-Connected)，如果满足：∀u,v∈V
// ，满足 u→v
//  或 v→u
// ，即对于图中任意两点 u,v
// ，存在一条 u
//  到 v
//  的有向路径或者从 v
//  到 u
//  的有向路径。

// 若 G′=(V′,E′)
//  满足，E′
//  是 E
//  中所有和 V′
//  有关的边，则称 G′
//  是 G
//  的一个导出子图。

// 若 G′
//  是 G
//  的导出子图，且 G′
//  半连通，则称 G′
//  为 G
//  的半连通子图。

// 若 G′
//  是 G
//  所有半连通子图中包含节点数最多的，则称 G′
//  是 G
//  的最大半连通子图。

// 给定一个有向图 G
// ，请求出 G
//  的最大半连通子图拥有的节点数 K
// ，以及不同的最大半连通子图的数目 C
// 。

// 由于 C
//  可能比较大，仅要求输出 C
//  对 X
//  的余数。

// 输入格式
// 第一行包含三个整数 N,M,X
// 。N,M
//  分别表示图 G
//  的点数与边数，X
//  的意义如上文所述；

// 接下来 M
//  行，每行两个正整数 a,b
// ，表示一条有向边 (a,b)
// 。

// 图中的每个点将编号为 1
//  到 N
// ，保证输入中同一个 (a,b)
//  不会出现两次。

// 输出格式
// 应包含两行。

// 第一行包含一个整数 K
// ，第二行包含整数 C mod X
// 。

// 数据范围
// 1≤N≤105
// ,
// 1≤M≤106
// ,
// 1≤X≤108
// 输入样例：
// 6 6 20070603
// 1 2
// 2 1
// 1 3
// 2 4
// 5 6
// 6 4
// 输出样例：
// 3
// 3

/*
1.tarjan
2.缩点，建图，要给边判重
3.按拓扑图递推
将图变成几个连通块后建成一个拓扑图，在这个拓扑图中链最长的是最大半连通图
*/
#include<iostream>
#include<cstring>
#include<unordered_set>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10, M = 2e6 + 10;
int h[N], hs[N], e[M], ne[M], idx; // h是图，hs是变成连通块后的拓扑图
int n, m, mod;
int timestamp, dfn[N], low[N];
int stk[N], top;
bool in_stk[N];
int scc_cnt, sz[N], id[N];
LL f[N], g[N]; // f保存拓扑图中递推到第i个连通块的半连通图的最多节点是多少，g保存拓扑图中递推到第i个连通块的半连通图的路径有多少
/* i -> j
if(f[j] < f[i] + sz[j]) f[j] = f[i] + sz[j], g[j] = g[i]; 如果从i到j这条路，j此时的点的数量没有从i到j的数量多，更新，并且到j的路径条数等于到i的路径条数
else if(f[j] == f[i]) g[j] += g[i]; 如果从i到j这条路，j此时的点的数量等于从i到j的数量，则到j的路径条数累加上到i的路径条数
*/

void add(int h[], int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u){
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u, in_stk[u] = true;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }else if(in_stk[j]) low[u] = min(low[u], dfn[j]);
    }
    
    if(low[u] == dfn[u]){
        int y;
        scc_cnt++;
        do{
            y = stk[top--];
            in_stk[y] = false;
            id[y] = scc_cnt;
            sz[scc_cnt]++;
        }while(y != u);
    }
}


int main(){
    scanf("%d%d%d", &n, &m, &mod);
    memset(h, -1, sizeof h);
    memset(hs, -1, sizeof hs);
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        add(h, a, b);
    }
    
    for(int i = 1; i <= n; i++)
        if(!dfn[i])
            tarjan(i);
    
    unordered_set<LL> set; // 用于判重 u->v u * 100000 + v，因为点数为100000，所以这种方法可以完美的错开
    for(int i = 1; i <= n; i++)
        for(int j = h[i]; ~j; j = ne[j]){
            int k = e[j];
            int a = id[i], b = id[k];
            LL hash = a * 100000 + b;
            if(a != b && !set.count(hash)) { // 如果a和b不在一个连通块中并且还没有a到b这条边
                add(hs, a, b);
                set.insert(hash);
            }
        }
        
    for(int i = scc_cnt; i; i--){
        if(!f[i]){ // 如果f[i]等于0，表示i点是起点，入度为0，此时它的数量就是这个连通块中点的数量，路径条数只有1条
            f[i] = sz[i];
            g[i] = 1;
        }
        for(int j = hs[i]; ~j; j = ne[j]){ // 枚举i能到的其他连通块
            int k = e[j];
            if(f[k] < f[i] + sz[k]){ // 如果从i到k这条路，k此时的点的数量没有从i到k的数量多，更新，并且到k的路径条数等于到i的路径条数
                f[k] = f[i] + sz[k];
                g[k] = g[i]; 
            }else if(f[k] == f[i] + sz[k]) g[k] = (g[k] + g[i]) % mod; // 如果从i到k这条路，k此时的点的数量等于从i到k的数量，则到k的路径条数累加上到i的路径条数
        }
    }
    
    int maxf = 0, sum = 0; // maxf保存最大半连通图中点的数量
    for(int i = 1; i <= scc_cnt; i++) // 枚举每一个连通块
        if(f[i] > maxf){ // 如果数量大于当前最多的数量
            maxf = f[i], sum = g[i]; // 更新这个最大的半连通块中点的数量，路径条数是g[i]
        }else if(f[i] == maxf) sum = (sum + g[i]) % mod; //  如果数量等于当前最多的数量，累加路径数量
    
    printf("%d\n%d\n", maxf, sum);
    
    return 0;
}