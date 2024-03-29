// 鲍勃喜欢玩电脑游戏，特别是战略游戏，但有时他找不到解决问题的方法，这让他很伤心。

// 现在他有以下问题。

// 他必须保护一座中世纪城市，这条城市的道路构成了一棵树。

// 每个节点上的士兵可以观察到所有和这个点相连的边。

// 他必须在节点上放置最少数量的士兵，以便他们可以观察到所有的边。

// 你能帮助他吗？

// 例如，下面的树：

// 1463_1.jpg.gif

// 只需要放置 1
//  名士兵（在节点 1
//  处），就可观察到所有的边。

// 输入格式
// 输入包含多组测试数据，每组测试数据用以描述一棵树。

// 对于每组测试数据，第一行包含整数 N
// ，表示树的节点数目。

// 接下来 N
//  行，每行按如下方法描述一个节点。

// 节点编号：(子节点数目) 子节点 子节点 …

// 节点编号从 0
//  到 N−1
// ，每个节点的子节点数量均不超过 10
// ，每个边在输入数据中只出现一次。

// 输出格式
// 对于每组测试数据，输出一个占据一行的结果，表示最少需要的士兵数。

// 数据范围
// 0<N≤1500
// ,
// 一个测试点所有 N
//  相加之和不超过 300650
// 。

// 输入样例：
// 4
// 0:(1) 1
// 1:(2) 2 3
// 2:(0)
// 3:(0)
// 5
// 3:(3) 1 4 2
// 1:(1) 0
// 2:(0)
// 0:(0)
// 4:(0)
// 输出样例：
// 1
// 2

#include<iostream>
#include<cstring>
using namespace std;

const int N = 1510;
int h[N], e[N], ne[N], idx;
bool st[N];
int n, T;
int f[N][2];

int add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u){
    f[u][1] = 1;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        dfs(j);
        f[u][0] += f[j][1];
        f[u][1] += min(f[j][0], f[j][1]);
    }
}

int main(){
    while(cin >> n){
        memset(h, -1, sizeof h);
        memset(st, false, sizeof st);
        memset(f, 0, sizeof f);
        idx = 0;
        for(int i = 0; i < n; i++){
            int id, cnt;
            scanf("%d:(%d)", &id, &cnt);
            while(cnt--){
                int ver;
                cin >> ver;
                add(id, ver);
                st[ver] = true;
            }
        }
        
        int root = 0;
        while(st[root]) root++;
        dfs(root);
        cout << min(f[root][0], f[root][1]) << endl;;
    }
    
    return 0;
}