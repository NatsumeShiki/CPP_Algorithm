// 由于无敌的凡凡在2005年世界英俊帅气男总决选中胜出，Yali Company总经理Mr.Z心情好，决定给每位员工发奖金。

// 公司决定以每个人本年在公司的贡献为标准来计算他们得到奖金的多少。

// 于是Mr.Z下令召开 m
//  方会谈。

// 每位参加会谈的代表提出了自己的意见：“我认为员工 a
//  的奖金应该比 b
//  高！”

// Mr.Z决定要找出一种奖金方案，满足各位代表的意见，且同时使得总奖金数最少。

// 每位员工奖金最少为100元，且必须是整数。

// 输入格式
// 第一行包含整数 n,m
// ，分别表示公司内员工数以及参会代表数。

// 接下来 m
//  行，每行 2
//  个整数 a,b
// ，表示某个代表认为第 a
//  号员工奖金应该比第 b
//  号员工高。

// 输出格式
// 若无法找到合理方案，则输出“Poor Xed”；

// 否则输出一个数表示最少总奖金。

// 数据范围
// 1≤n≤10000
// ,
// 1≤m≤20000
// ,
// 1≤a,b≤n
// 输入样例：
// 2 1
// 1 2
// 输出样例：
// 201

#include<iostream>
#include<cstring>
using namespace std;

const int N = 10010, M = 20010;
int n, m;
int h[N], e[M], ne[M], idx;
int q[N]; // 队列
int d[N], dist[N]; // d保存入度数，dist保存金钱

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort(){
    int hh = 0, tt = -1;
    for(int i = 1; i <= n; i++) // 将入度为0的点都放进队列
        if(!d[i])
            q[++tt] = i;
    
    while(hh <= tt){ // 直到队列为空
        int t = q[hh++];
        for(int i = h[t]; ~i; i = ne[i]){ // 遍历邻边
            int j = e[i]; // 将邻边入度减1
            if(--d[j] == 0) // 如果这是入度为0，放进队列
                q[++tt] = j;
        }
    }
    
    return tt == n - 1; // 如果tt != n - 1，说明存在环，无拓扑序列
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        add(b, a); // 建立一条从b到a的边，表示dist[a] >= dist[b] + 1
        d[a]++; // a的入度加1
    }
    
    if(!topsort()) puts("Poor Xed"); // 如果拓扑排序返回false，说明存在环，不能满足要求
    else {
        for(int i = 1; i <= n; i++) dist[i] = 100; // 先将每个人的最小金钱设置为100
        for(int i = 0; i < n; i++){ // 从小到大遍历拓扑排序里面的值
            int j = q[i]; // 获取这个人的序号
            for(int k = h[j]; ~k; k = ne[k]) // 遍历它的邻边，所有它的邻边的金钱都必须比他大1元
                dist[e[k]] = max(dist[e[k]], dist[j] + 1); // 所以取较大值
        }
        int res = 0;
        for(int i = 1; i <= n; i++) res += dist[i]; // 获取金钱总数
        printf("%d\n", res);
    }
    
    return 0;
}