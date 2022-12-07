// 给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环，边权可能为负数。

// 求最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

// 给定一张边带权的无向图 G=(V,E)，其中 V 表示图中点的集合，E 表示图中边的集合，n=|V|，m=|E|。

// 由 V 中的全部 n 个顶点和 E 中 n−1 条边构成的无向连通子图被称为 G 的一棵生成树，其中边的权值之和最小的生成树被称为无向图 G 的最小生成树。

// 输入格式
// 第一行包含两个整数 n 和 m。

// 接下来 m 行，每行包含三个整数 u,v,w，表示点 u 和点 v 之间存在一条权值为 w 的边。

// 输出格式
// 共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

// 数据范围
// 1≤n≤105,
// 1≤m≤2∗105,
// 图中涉及边的边权的绝对值均不超过 1000。

// 输入样例：
// 4 5
// 1 2 1
// 1 3 2
// 1 4 3
// 2 3 2
// 3 4 4
// 输出样例：
// 6


// Kruskal算法：适用于稀疏图，将所有的边保存起来，按权重从小到大排序，然后做法很像并查集的连通块，将所有点的根节点都设置成它自己，定义变量res保存
//              最小生成树的权值，变量cnt保存这个连通块中点的数量，然后将边从小到大遍历，如果这条边的两个点不在一个连通块中，将一个点的根节点设置
//              为另一个点的子节点，然后将它们的权值累加到res，cnt数目++，最终判断cnt的数目是否小于n-1，如果小于n-1说明有节点不在连通块中，繁殖就存在
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200010;
int n, m;
int p[N]; // 保存这个节点的根节点
struct Edge{
    int a, b, w;
    // 定义两个Edge的比较规则，用于排序
    bool operator<(const Edge &W)const{
        return w < W.w;
    }
}edges[N];

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    sort(edges, edges + m); // 将edge按照权值从小到大排序
    for(int i = 1; i <= n; i++) p[i] = i; // 将每个节点的根节点设置成它自己
    
    int res = 0, cnt = 0; // res保存最小生成树的权值，cnt保存连通块中点的数量
    for(int i = 0; i < m; i++){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b); // 查找两个点的根节点
        if(a != b){ // 如果两个节点的根节点不同，说明二者不在一个连通块中
            p[a] = b; // 将a的根节点设置成b的根节点的子节点
            res += w; // 累加权值
            cnt++; // 连通块中点的数目+1
        }
    }
    if(cnt < n - 1) cout << "impossible" << endl; // 如果连通块中点的数目小于n-1，说明有点不在连通块中，也就没有最小生成树
    else cout << res << endl; // 有最小生成树，输出权值
    
    return 0;
}
