// 有一棵二叉苹果树，如果树枝有分叉，一定是分两叉，即没有只有一个儿子的节点。

// 这棵树共 N
//  个节点，编号为 1
//  至 N
// ，树根编号一定为 1
// 。

// 我们用一根树枝两端连接的节点编号描述一根树枝的位置。

// 一棵苹果树的树枝太多了，需要剪枝。但是一些树枝上长有苹果，给定需要保留的树枝数量，求最多能留住多少苹果。

// 这里的保留是指最终与1号点连通。

// 输入格式
// 第一行包含两个整数 N
//  和 Q
// ，分别表示树的节点数以及要保留的树枝数量。

// 接下来 N−1
//  行描述树枝信息，每行三个整数，前两个是它连接的节点的编号，第三个数是这根树枝上苹果数量。

// 输出格式
// 输出仅一行，表示最多能留住的苹果的数量。

// 数据范围
// 1≤Q<N≤100
// .
// N≠1
// ,
// 每根树枝上苹果不超过 30000
//  个。

// 输入样例：
// 5 2
// 1 3 1
// 1 4 10
// 2 3 20
// 3 5 20
// 输出样例：
// 21

// f[i, j] 以i为根节点的子树中，选j条边的最大价值，类似于有依赖的背包问题
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, M = N * 2;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
int f[N][N];

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int father){
    for(int i = h[u]; ~i; i = ne[i]){ // 物品组
        if(e[i] == father) continue;
        
        dfs(e[i], u);
        
        for(int j = m; j >= 0; j--) // 体积 从大到小是因为如果从小到大会把u - j这根树枝重复计算
            for(int k = 0; k < j; k++) // 决策
                f[u][j] = max(f[u][j], f[u][j - k - 1] + f[e[i]][k] + w[i]);
    }
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    
    dfs(1, -1);
    cout << f[1][m] << endl; // 以1为根节点，有m根树枝的苹果最大值
    
    
    return 0;
}