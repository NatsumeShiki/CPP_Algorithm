// 给定一个由 n
//  个点和 m
//  条边构成的图。

// 不保证给定的图是连通的。

// 图中的一部分边的方向已经确定，你不能改变它们的方向。

// 剩下的边还未确定方向，你需要为每一条还未确定方向的边指定方向。

// 你需要保证在确定所有边的方向后，生成的图是一个有向无环图（即所有边都是有向的且没有有向环的图）。

// 输入格式
// 第一行包含整数 T
// ，表示共有 T
//  组测试数据。

// 每组数据第一行包含两个整数 n,m
// 。

// 接下来 m
//  行，每行包含三个整数 t,x,y
// ，用来描述一条边的信息，其中 t
//  表示边的状态，如果 t=0
// ，则表示边是无向边，如果 t=1
// ，则表示边是有向边。x,y
//  表示这条边连接的两个端点，如果是有向边则边的方向是从 x
//  指向 y
// 。

// 保证图中没有重边（给定了 (x,y)
// ，就不会再次出现 (x,y)
//  或出现 (y,x)
// ）和自环（不会出现 x=y
//  的情况）。

// 输出格式
// 对于每组数据，如果无法构造出有向无环图，则输出一行 NO。

// 否则，先输出一行 YES，随后 m
//  行，每行包含两个整数 x,y
// ，用来描述最终构造成的有向无环图中的每条边的具体方向（x
//  指向 y
// ），边的先后顺序随意。

// 注意，已经确定方向的边，不能更改方向。

// 如果答案不唯一，输出任意合理方案均可。

// 数据范围
// 对于前三个测试点，1≤n,m≤10
// 。
// 对于全部测试点，1≤T≤20000
// ，2≤n≤2×105
// ，1≤m≤min(2×105,n(n−1)2)
// ，0≤t≤1
// ，1≤x,y≤n
// 。
// 保证在一个测试点中，所有 n
//  的和不超过 2×105
// ，所有 m
//  的和不超过 2×105
// 。

// 输入样例：
// 4
// 3 1
// 0 1 3
// 5 5
// 0 2 1
// 1 1 5
// 1 5 4
// 0 5 2
// 1 3 5
// 4 5
// 1 1 2
// 0 4 3
// 1 3 1
// 0 2 3
// 1 2 4
// 4 5
// 1 4 1
// 1 1 3
// 0 1 2
// 1 2 4
// 1 3 2
// 输出样例：
// YES
// 3 1
// YES
// 2 1
// 1 5
// 5 4
// 2 5
// 3 5
// YES
// 1 2
// 3 4
// 3 1
// 3 2
// 2 4
// NO

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 200010, M = N;
int n, m;
int h[N], e[M], ne[M], idx;
int q[N], d[N];

struct Edge{
    int a, b;
}edge[M];
int pos[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort(){
    int hh = 0, tt = -1;
    for(int i = 1; i <= n; i++)
        if(!d[i])
            q[++tt] = i;
            
    while(hh <= tt){
        int t = q[hh++];
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(--d[j] == 0)
                q[++tt] = j;
        }
    }
    
    return tt == n - 1;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        memset(h, -1, sizeof h);
        idx = 0;
        memset(d, 0, sizeof d);
        
        int cnt = 0;
        cin >> n >> m;
        while(m--){
            int t, a, b;
            scanf("%d%d%d", &t, &a, &b);
            if(!t) edge[cnt++] = {a, b};
            else {
                add(a, b);
                d[b]++;
            }
        }
        
        if(!topsort()) puts("NO");
        else{
            puts("YES");
            for(int i = 1; i <= n; i++)
                for(int j = h[i]; ~j; j = ne[j])
                    printf("%d %d\n", i, e[j]);
                    
            for(int i = 0; i < n; i++) pos[q[i]] = i;
            for(int i = 0; i < cnt; i++){
                int a = edge[i].a, b = edge[i].b;
                if(pos[a] > pos[b]) swap(a, b);
                printf("%d %d\n", a, b);
            }
        }
    }
    
    return 0;
}