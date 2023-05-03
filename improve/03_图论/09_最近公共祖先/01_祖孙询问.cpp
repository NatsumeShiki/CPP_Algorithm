// 给定一棵包含 n
//  个节点的有根无向树，节点编号互不相同，但不一定是 1∼n
// 。

// 有 m
//  个询问，每个询问给出了一对节点的编号 x
//  和 y
// ，询问 x
//  与 y
//  的祖孙关系。

// 输入格式
// 输入第一行包括一个整数 表示节点个数；

// 接下来 n
//  行每行一对整数 a
//  和 b
// ，表示 a
//  和 b
//  之间有一条无向边。如果 b
//  是 −1
// ，那么 a
//  就是树的根；

// 第 n+2
//  行是一个整数 m
//  表示询问个数；

// 接下来 m
//  行，每行两个不同的正整数 x
//  和 y
// ，表示一个询问。

// 输出格式
// 对于每一个询问，若 x
//  是 y
//  的祖先则输出 1
// ，若 y
//  是 x
//  的祖先则输出 2
// ，否则输出 0
// 。

// 数据范围
// 1≤n,m≤4×104
// ,
// 1≤每个节点的编号≤4×104
// 输入样例：
// 10
// 234 -1
// 12 234
// 13 234
// 14 234
// 15 234
// 16 234
// 17 234
// 18 234
// 19 234
// 233 19
// 5
// 234 233
// 233 12
// 233 13
// 233 15
// 233 19
// 输出样例：
// 1
// 0
// 0
// 0
// 2

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 40010, M = N * 2;
int n, m;
int h[N], e[M], ne[M], idx;
int depth[N], fa[N][16]; // 2^16 = 65536 > 40000，所以只需要预处理出来最多向上跳2^15即可 depth数组表示该点的层数

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int root){ // 预处理depth和fa数组，宽度优先遍历
    memset(depth, 0x3f, sizeof depth); // 先将所有点的层数设置为无穷大
    depth[0] = 0, depth[root] = 1; // 0的层数为0，是哨兵，根节点层数为1
    queue<int> q;
    q.push(root);
    while(q.size()){
        int t = q.front();
        q.pop();
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(depth[j] > depth[t] + 1){ // 如果j的层数比他的父节点层数加1还大，说明需要更新
                depth[j] = depth[t] + 1;
                q.push(j);
                fa[j][0] = t; // j的父节点为t
                for(int k = 1; k <= 15; k++) // 处理跳2^1 - 2^15的点
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
}

int lca(int a, int b){ // 获取最近公共祖先
    if(depth[a] < depth[b]) swap(a, b); // 如果a的深度比b小，就交换，方便后面的代码
    for(int k = 15; k >= 0; k--) // 找到与b同一层的a的祖先
        if(depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    if(a == b) return a; // 如果a等于b，说明最近公共祖先就是b
    for(int k = 15; k >= 0; k--) // a和b同时往上跳
        if(fa[a][k] != fa[b][k]){ // 如果跳2^k它们的祖先不相同，说明还没有找到最近公共祖先
            a = fa[a][k]; // a和b同时向上跳2^k
            b = fa[b][k];
        }
    // 最后跳到了a和b的最近公共祖先的下一层
    return fa[a][0];  // 因此返回fa[a][0]就是a和b的最近公共祖先
}

int main(){
    scanf("%d", &n);
    int root = 0;
    memset(h, -1, sizeof h);
    
    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        if(b == -1) root = a;
        else add(a, b), add(b, a);
    }
    
    bfs(root); 
    
    scanf("%d", &m);
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        int p = lca(a, b);
        if(p == a) puts("1");
        else if(p == b) puts("2");
        else puts("0");
    }
    
    return 0;
}