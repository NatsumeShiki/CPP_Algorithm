// 重庆城里有 n
//  个车站，m
//  条 双向 公路连接其中的某些车站。

// 每两个车站最多用一条公路连接，从任何一个车站出发都可以经过一条或者多条公路到达其他车站，但不同的路径需要花费的时间可能不同。

// 在一条路径上花费的时间等于路径上所有公路需要的时间之和。

// 佳佳的家在车站 1
// ，他有五个亲戚，分别住在车站 a,b,c,d,e
// 。

// 过年了，他需要从自己的家出发，拜访每个亲戚（顺序任意），给他们送去节日的祝福。

// 怎样走，才需要最少的时间？

// 输入格式
// 第一行：包含两个整数 n,m
// ，分别表示车站数目和公路数目。

// 第二行：包含五个整数 a,b,c,d,e
// ，分别表示五个亲戚所在车站编号。

// 以下 m
//  行，每行三个整数 x,y,t
// ，表示公路连接的两个车站编号和时间。

// 输出格式
// 输出仅一行，包含一个整数 T
// ，表示最少的总时间。

// 数据范围
// 1≤n≤50000
// ,
// 1≤m≤105
// ,
// 1<a,b,c,d,e≤n
// ,
// 1≤x,y≤n
// ,
// 1≤t≤100
// 输入样例：
// 6 6
// 2 3 4 5 6
// 1 2 8
// 2 3 3
// 3 4 4
// 4 5 5
// 5 6 2
// 1 6 7
// 输出样例：
// 21

/*
1.先预处理出1,a,b,c,d,e出发到其他所有点的单源最短路径
2.DFS所有拜访顺序，5！，对于每一种拜访顺序，可以通过查表的方式算出最短距离
时间复杂度是 O(mlogn + 5!)
*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 50010, M = 2e5 + 10, INF = 0x3f3f3f3f;
int h[N], e[M], w[M], ne[M], idx;
int dist[6][N]; // dist记录单源最短路径
bool st[N];
int n, m;
int source[6]; // 记录六个出发点

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(int start, int dist[]){
    memset(dist, 0x3f, N * 4);
    dist[start] = 0;
    memset(st, 0, sizeof st);
    
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, start});
    
    while(heap.size()){
        auto t = heap.top();
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

int dfs(int u, int start, int distance){
    if(u == 6) return distance; // 如果u是6，说明所有点都经过了
    
    int res = INF;
    for(int i = 1; i <= 5; i++)
        if(!st[i]){ // 如果第i个点还没有经过
            int next = source[i]; // 记录这个点
            st[i] = true; // 将它设置为true
            res = min(res, dfs(u + 1, i, distance + dist[start][next])); // 向下递归，获取最小值
            st[i] = false; // 还原状态
        }
        
    return res;
}

int main(){
    scanf("%d%d", &n, &m);
    source[0] = 1; // 从1号点出发
    for(int i = 1; i <= 5; i++) scanf("%d", &source[i]);
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
    
    
    for(int i = 0; i < 6; i++) dijkstra(source[i], dist[i]); // 进行六次dijkstra
    
    memset(st, 0, sizeof st); // 重置st，用于dfs
    printf("%d\n", dfs(1, 0, 0)); // 获取最小值
    
    return 0;
}