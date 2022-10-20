// 给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，所有边权均为非负值。

// 请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 −1。

// 输入格式
// 第一行包含整数 n 和 m。

// 接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

// 输出格式
// 输出一个整数，表示 1 号点到 n 号点的最短距离。

// 如果路径不存在，则输出 −1。

// 数据范围
// 1≤n,m≤1.5×105,
// 图中涉及边长均不小于 0，且不超过 10000。
// 数据保证：如果最短路存在，则最短路的长度不超过 109。

// 输入样例：
// 3 3
// 1 2 2
// 2 3 1
// 1 3 4
// 输出样例：
// 3


#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

typedef pair<int , int> PII;

const int N = 150010;
int n, m;
int h[N]; // 邻接表
int w[N]; // 保存权重
int e[N], ne[N], idx;
int dist[N]; // 保存从1到某个点的距离
bool st[N]; // 保存某个点是否已经是最短路径了

void add(int a, int b, int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    priority_queue<PII, vector<PII>, greater<PII>> heap; // 这个PII中第一个表示dist，第二个表示下标
    heap.push({0, 1}); // 优先队里按照dist升序排列，所以top是dist最小的那个数
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        
        int ver = t.second, distance = t.first;
        if(st[ver]) continue; // 如果这个点已经是最短了，就进行下一次循环
        st[ver] = true; // 将这个设置为已经变为最短路径了
        for(int i = h[ver]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > distance + w[i]){ // 如果从1到j这个点距离小于从1到i这个点 + 从i到j的权值，就更新
                dist[j] = distance + w[i];
                heap.push({dist[j], j}); // 将这个点放进优先队列
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    
    while(m--){
        int a, b, c;
        // cin >> a >> b >> c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    
    int t = dijkstra();
    
    cout << t << endl;
    
    return 0;
}