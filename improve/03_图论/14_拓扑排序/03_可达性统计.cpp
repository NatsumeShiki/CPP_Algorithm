// 给定一张 N
//  个点 M
//  条边的有向无环图，分别统计从每个点出发能够到达的点的数量。

// 输入格式
// 第一行两个整数 N,M
// ，接下来 M
//  行每行两个整数 x,y
// ，表示从 x
//  到 y
//  的一条有向边。

// 输出格式
// 输出共 N
//  行，表示每个点能够到达的点的数量。

// 数据范围
// 1≤N,M≤30000
// ,
// 1≤x,y≤N
// 输入样例：
// 10 10
// 3 8
// 2 3
// 2 5
// 5 9
// 5 9
// 2 3
// 3 9
// 4 8
// 2 10
// 4 9
// 输出样例：
// 1
// 6
// 3
// 3
// 2
// 1
// 1
// 1
// 1
// 1

/*
先使用拓扑排序得到拓扑序列，然后从后往前枚举，枚举每个点所能到达的点，将这些点能到达的点都 |= 这个点，就可以求出结果
但这样做时间复杂度是 O(nm)，是9 * 10^8，会TLE，但是使用biset时间复杂度是 O(nm / 32)，就是 3 * 10^7 可以
*/
#include<iostream>
#include<cstring>
#include<bitset>
using namespace std;

const int N = 30010;
int h[N], e[N], ne[N], idx;
int d[N];
int q[N];
int n, m;
bitset<N> f[N]; // 用二进制保存没个点能到达的点

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort(){
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
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        d[b]++;
    }
    
    topsort();
    for(int i = n - 1; i >= 0; i--){ // 从后往前枚举拓扑序列
        int j = q[i]; // 获取这个点
        f[j][j] = 1; // 它自己可以到达自己
        for(int k = h[j]; ~k; k = ne[k]) // 枚举所有可以到达的点
            f[j] |= f[e[k]]; // 将他能到达的点或等到这个点上
    }
    for(int i = 1; i <= n; i++) printf("%d\n", f[i].count()); // 输出这个01串中1的数量
    
    return 0;
}