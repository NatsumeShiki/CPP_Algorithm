// 给出 n
//  个点的一棵树，多次询问两点之间的最短距离。

// 注意：

// 边是无向的。
// 所有节点的编号是 1,2,…,n
// 。
// 输入格式
// 第一行为两个整数 n
//  和 m
// 。n
//  表示点数，m
//  表示询问次数；

// 下来 n−1
//  行，每行三个整数 x,y,k
// ，表示点 x
//  和点 y
//  之间存在一条边长度为 k
// ；

// 再接下来 m
//  行，每行两个整数 x,y
// ，表示询问点 x
//  到点 y
//  的最短距离。

// 树中结点编号从 1
//  到 n
// 。

// 输出格式
// 共 m
//  行，对于每次询问，输出一行询问结果。

// 数据范围
// 2≤n≤104
// ,
// 1≤m≤2×104
// ,
// 0<k≤100
// ,
// 1≤x,y≤n
// 输入样例1：
// 2 2 
// 1 2 100 
// 1 2 
// 2 1
// 输出样例1：
// 100
// 100
// 输入样例2：
// 3 2
// 1 2 10
// 3 1 15
// 1 2
// 3 2
// 输出样例2：
// 10
// 25

#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

typedef pair<int, int> PII;
const int N = 20010, M = N * 2;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
int dist[N], p[N], res[N], st[N]; // dist保存从根节点到该节点的距离，p保存该节点的祖宗节点，res保存每个查询的结果，st保存每个点的状态
// 0表示还未搜索到的点 1表示正在搜索的分支 2表示已经遍历过，并且回溯过了
vector<PII> query[N]; // first保存查询的另外一个点，second保存查询编号

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int fa){ // dfs函数用来获得每个点到根节点的距离
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(j == fa) continue;
        dist[j] = dist[u] + w[i];
        dfs(j, u);
    }
}

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void tarjan(int u){
    st[u] = 1; // 先将u设置为正在搜索的点
    for(int i = h[u]; ~i; i = ne[i]){ // 搜索u的孩子
        int j = e[i];
        if(!st[j]){ // 如果孩子还没有被搜索过
            tarjan(j); // 递归j
            p[j] = u; // 将j的父亲设置为u
        }
    }
    
    for(auto item : query[u]){ // 处理与u有关的查询
        int y = item.first, id = item.second; // 获取另一个点以及该查询的编号
        if(st[y] == 2){ // 如果另一个点已经遍历过并且已经回溯了，就可以计算两个点的最短距离
            int anc = find(y); // 查询y的祖宗节点，这个点就是这两个点的最近公共祖先
            res[id] = dist[u] + dist[y] - dist[anc] * 2; // 计算结果
        }
    }
    st[u] = 2; // 将该点设置为已经遍历过并且已经回溯
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    
    for(int i = 0; i < m; i++){ // 将所有要查询的都先保存起来
        int a, b;
        scanf("%d%d", &a, &b);
        if(a != b){ // 如果a等于b，那么a和b的距离就是0，在全局定义res本身就是0，所以可以不用保存
            query[a].push_back({b, i});
            query[b].push_back({a, i});
        }
    } 
    for(int i = 1; i <= n; i++) p[i] = i; // 将所有点的父节点都设置成自己
    
    dfs(1, -1); // 从1开始向下搜索
    tarjan(1);
    
    for(int i = 0; i < m; i++) printf("%d\n", res[i]);
    
    return 0;
}