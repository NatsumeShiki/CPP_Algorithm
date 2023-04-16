// 有一天，琪琪想乘坐公交车去拜访她的一位朋友。

// 由于琪琪非常容易晕车，所以她想尽快到达朋友家。

// 现在给定你一张城市交通路线图，上面包含城市的公交站台以及公交线路的具体分布。

// 已知城市中共包含 n
//  个车站（编号1
// ~n
// ）以及 m
//  条公交线路。

// 每条公交线路都是 单向的，从一个车站出发直接到达另一个车站，两个车站之间可能存在多条公交线路。

// 琪琪的朋友住在 s
//  号车站附近。

// 琪琪可以在任何车站选择换乘其它公共汽车。

// 请找出琪琪到达她的朋友家（附近的公交车站）需要花费的最少时间。

// 输入格式
// 输入包含多组测试数据。

// 每组测试数据第一行包含三个整数 n,m,s
// ，分别表示车站数量，公交线路数量以及朋友家附近车站的编号。

// 接下来 m
//  行，每行包含三个整数 p,q,t
// ，表示存在一条线路从车站 p
//  到达车站 q
// ，用时为 t
// 。

// 接下来一行，包含一个整数 w
// ，表示琪琪家附近共有 w
//  个车站，她可以在这 w
//  个车站中选择一个车站作为始发站。

// 再一行，包含 w
//  个整数，表示琪琪家附近的 w
//  个车站的编号。

// 输出格式
// 每个测试数据输出一个整数作为结果，表示所需花费的最少时间。

// 如果无法达到朋友家的车站，则输出 -1。

// 每个结果占一行。

// 数据范围
// n≤1000,m≤20000
// ,
// 1≤s≤n
// ,
// 0<w<n
// ,
// 0<t≤1000
// 输入样例：
// 5 8 5
// 1 2 2
// 1 5 3
// 1 3 4
// 2 4 7
// 2 5 6
// 2 3 5
// 3 5 1
// 4 5 1
// 2
// 2 3
// 4 3 4
// 1 2 3
// 1 3 4
// 2 3 2
// 1
// 1
// 输出样例：
// 1
// -1

// 我的做法是把所有起点都存进队列中，然后做一遍spfa就得到了最短路
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1010, M = 20010;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
int n, m, s, k;
queue<int> q;

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa(){
    while(q.size()){
        int t = q.front();
        q.pop();
        
        
        st[t] = false;
        
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                if(!st[j]){
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
}

int main(){
    while(cin >> n){
        memset(h, -1, sizeof h);
        memset(dist, 0x3f, sizeof dist);
        idx = 0;
        
        scanf("%d%d", &m, &s);
        while(m--){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
        }
        
        scanf("%d", &k);
        while(k--){
            int x;
            scanf("%d", &x);
            q.push(x);
            dist[x] = 0;
        }
        
        spfa();
        
        if(dist[s] == 0x3f3f3f3f) puts("-1");
        else printf("%d\n", dist[s]);
    }
    
    return 0;
}

/*
大佬的思路是创建一个虚拟原点，然后连接这个原点到所有起点，再做一次spfa或者dijkstra即可
原问题：从每个起点出发，到达终点的所有路线的距离的最小值
加上虚拟原点之后的问题：从虚拟原点出发，到达终点的所有路线的距离的最小值
*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = 21010; // 这里M要注意起点数量是最大是n，所以需要开大一点
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
int n, m, s, k;

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(){
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    dist[0] = 0;
    heap.push({0, 0});
    while(heap.size()){
        PII t = heap.top();
        heap.pop();
        
        int ver = t.second;
        if(st[ver]) continue;
        st[ver] = true;
        for(int i = h[ver]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[ver] + w[i]){
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int main(){
    while(cin >> n){
        memset(h, -1, sizeof h);
        memset(st, 0, sizeof st);
        memset(dist, 0x3f, sizeof dist);
        idx = 0;
        
        scanf("%d%d", &m, &s);
        while(m--){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
        }
        
        scanf("%d", &k);
        while(k--){
            int x;
            scanf("%d", &x);
            add(0, x, 0);
        }
        
        dijkstra();
        
        if(dist[s] == 0x3f3f3f3f) puts("-1");
        else printf("%d\n", dist[s]);
    }
    
    return 0;
}