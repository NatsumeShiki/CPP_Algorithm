// 一条单向的铁路线上，依次有编号为 1,?2,?…,?n
// ?的 n
//  个火车站。

// 每个火车站都有一个级别，最低为 1
//  级。

// 现有若干趟车次在这条线路上行驶，每一趟都满足如下要求：如果这趟车次停靠了火车站 x
// ，则始发站、终点站之间所有级别大于等于火车站 x
//  的都必须停靠。（注意：起始站和终点站自然也算作事先已知需要停靠的站点）?

// 例如，下表是 5
//  趟车次的运行情况。

// 其中，前 4
//  趟车次均满足要求，而第 5
//  趟车次由于停靠了 3
//  号火车站（2
//  级）却未停靠途经的 6
//  号火车站（亦为 2
//  级）而不满足要求。

// 1163900-20170818013814084-1540659827.jpg

// 现有 m
//  趟车次的运行情况（全部满足要求），试推算这 n
//  个火车站至少分为几个不同的级别。

// 输入格式
// 第一行包含 2
//  个正整数 n,m
// ，用一个空格隔开。

// 第 i+1
//  行（1≤i≤m
// ）中，首先是一个正整数 si
// （2≤si≤n
// ），表示第 i
//  趟车次有 si
//  个停靠站；接下来有 si
//  个正整数，表示所有停靠站的编号，从小到大排列。

// 每两个数之间用一个空格隔开。输入保证所有的车次都满足要求。

// 输出格式
// 输出只有一行，包含一个正整数，即 n
//  个火车站最少划分的级别数。

// 数据范围
// 1≤n,m≤1000
// 输入样例：
// 9 3 
// 4 1 3 5 6 
// 3 3 5 6 
// 3 1 5 9 
// 输出样例：
// 3

/*
1000趟列车，车站最多有1000站，如果停靠了500站，不停靠500站，那么时间复杂度是 O(500 * 500 * 1000) = 2.5 * 10^8，空间也是这么大，不可行
所以使用虚拟点，将一趟车站中不停靠的车站放在左边，停靠的车站放在右边，中间创建虚拟点ver，将左边的点与虚拟点连一条权值为0的边，虚拟点到右边连接一条权值为1
的边，这样就降到了 (n + m) * 1000，可行 
*/
#include<iostream>
#include<cstring>
using namespace std;

const int N = 2010, M = 1000010;
int h[N], e[M], w[M], ne[M], idx;
int d[N]; // 入度数量
int q[N]; // 队列
int n, m;
bool st[N]; // 保存一趟列车中车站停靠的点
int dist[N]; // 保存车站的等级

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    d[b]++; // b的入度加1
}

void topsort(){
    int hh = 0, tt = -1;
    for(int i = 1; i <= n + m; i++)
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
    for(int i = 1; i <= m; i++){
        int cnt;
        scanf("%d", &cnt);
        memset(st, 0, sizeof st);
        int start = n, end = 1; // 保存车站的起点和终点
        while(cnt--){ // 输入cnt个停靠的车站
            int stop;
            scanf("%d", &stop);
            start = min(start, stop); // 起点取最小值
            end = max(end, stop); // 终点取最大值
            st[stop] = true; // stop车站为true
        }
        
        int ver = n + i; // 这一趟列车虚拟点为n+i
        for(int j = start; j <= end; j++) // 从start到end枚举每个车站
            if(!st[j]) add(j, ver, 0); // 如果这一站不停靠，连接权值为0的点
            else add(ver, j, 1); // 如果停靠，连接权值为1的点
    }
    
    topsort(); // 拓扑排序
    for(int i = 1; i <= n; i++) dist[i] = 1; // 先将每个车站等级设置为1
    for(int i = 0; i < n + m; i++){ // 枚举每个点
        int j = q[i]; // 获取这个点编号
        for(int k = h[j]; ~k; k = ne[k]) // 枚举它的邻边
            dist[e[k]] = max(dist[e[k]], dist[j] + w[k]); // 邻边终点的等级比j大w[k]，取最大值
    }
    int res = 0; // 最后取车站等级的最大值输出
    for(int i = 1; i <= n; i++) res = max(res, dist[i]);
    
    printf("%d\n", res);
    
    return 0;
}