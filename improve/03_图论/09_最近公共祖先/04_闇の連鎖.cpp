// 传说中的暗之连锁被人们称为 Dark。

// Dark 是人类内心的黑暗的产物，古今中外的勇者们都试图打倒它。

// 经过研究，你发现 Dark 呈现无向图的结构，图中有 N
//  个节点和两类边，一类边被称为主要边，而另一类被称为附加边。

// Dark 有 N–1
//  条主要边，并且 Dark 的任意两个节点之间都存在一条只由主要边构成的路径。

// 另外，Dark 还有 M
//  条附加边。

// 你的任务是把 Dark 斩为不连通的两部分。

// 一开始 Dark 的附加边都处于无敌状态，你只能选择一条主要边切断。

// 一旦你切断了一条主要边，Dark 就会进入防御模式，主要边会变为无敌的而附加边可以被切断。

// 但是你的能力只能再切断 Dark 的一条附加边。

// 现在你想要知道，一共有多少种方案可以击败 Dark。

// 注意，就算你第一步切断主要边之后就已经把 Dark 斩为两截，你也需要切断一条附加边才算击败了 Dark。

// 输入格式
// 第一行包含两个整数 N
//  和 M
// 。

// 之后 N–1
//  行，每行包括两个整数 A
//  和 B
// ，表示 A
//  和 B
//  之间有一条主要边。

// 之后 M
//  行以同样的格式给出附加边。

// 输出格式
// 输出一个整数表示答案。

// 数据范围
// N≤100000,M≤200000
// ，数据保证答案不超过231−1
// 输入样例：
// 4 1
// 1 2
// 2 3
// 1 4
// 3 4
// 输出样例：
// 3

/*
树状差分，给a和b的d都加1，a和b的最近公共祖先的d值减等2，如果d等于0，表示删除哪条附加边都可以，所以结果加等m，如果d等于1，表示必须删除一条附加边，所以
结果加等1，如果d大于2，表示必须删除2条以上的附加边，没有方案
*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 100010, M = N * 2;
int n, m;
int h[N], e[M], ne[M], idx;
int depth[N], fa[N][17];
int d[N];
int ans;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(){
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[1] = 1;
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
                fa[j][0] = t;
                for(int k = 1; k <= 16; k++)
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
}

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    for(int k = 16; k >= 0; k--)
        if(depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    if(a == b) return a;
    for(int k = 16; k >= 0; k--)
        if(fa[a][k] != fa[b][k]){
            a = fa[a][k];
            b = fa[b][k];
        }
    return fa[a][0];
}

int dfs(int u, int fa){
    int res = d[u]; // 先保存u节点的权值
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(j != fa){
            int s = dfs(j, u); // 获取孩子节点的权值和
            if(s == 0) ans += m; // 如果为0，表示删除那一条附加边都可以，结果加等m
            else if(s == 1) ans++; // 如果为1，表示只能删除一条附加边，结果加等1
            res += s; // 将孩子节点的权值和累加到res上
        }
    }
    return res; // 返回权值和
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    
    bfs(); // 获取depth和fa数组
    
    for(int i = 0; i < m; i++){ // 枚举每一条附加边
        int a, b;
        scanf("%d%d", &a, &b);
        int p = lca(a, b);
        d[a]++, d[b]++, d[p] -= 2; // 给附加边两个点的权值加等1，最近公共祖先减等2
    } 
    dfs(1, -1); // 从根节点dfs累加方案到ans
    printf("%d\n", ans);
    
    return 0;
}