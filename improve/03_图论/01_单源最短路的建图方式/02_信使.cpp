// 战争时期，前线有 n
//  个哨所，每个哨所可能会与其他若干个哨所之间有通信联系。

// 信使负责在哨所之间传递信息，当然，这是要花费一定时间的（以天为单位）。

// 指挥部设在第一个哨所。

// 当指挥部下达一个命令后，指挥部就派出若干个信使向与指挥部相连的哨所送信。

// 当一个哨所接到信后，这个哨所内的信使们也以同样的方式向其他哨所送信。信在一个哨所内停留的时间可以忽略不计。

// 直至所有 n
//  个哨所全部接到命令后，送信才算成功。

// 因为准备充足，每个哨所内都安排了足够的信使（如果一个哨所与其他 k
//  个哨所有通信联系的话，这个哨所内至少会配备 k
//  个信使）。

// 现在总指挥请你编一个程序，计算出完成整个送信过程最短需要多少时间。

// 输入格式
// 第 1
//  行有两个整数 n
//  和 m
// ，中间用 1
//  个空格隔开，分别表示有 n
//  个哨所和 m
//  条通信线路。

// 第 2
//  至 m+1
//  行：每行三个整数 i、j、k
// ，中间用 1
//  个空格隔开，表示第 i
//  个和第 j
//  个哨所之间存在 双向 通信线路，且这条线路要花费 k
//  天。

// 输出格式
// 一个整数，表示完成整个送信过程的最短时间。

// 如果不是所有的哨所都能收到信，就输出-1。

// 数据范围
// 1≤n≤100
// ,
// 1≤m≤200
// ,
// 1≤k≤1000
// 输入样例：
// 4 4
// 1 2 4
// 2 3 7
// 2 4 1
// 3 4 6
// 输出样例：
// 11

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

#define x first
#define y second
typedef pair<int, int> PII;
const int N = 110, M = 410;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
int n, m;

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    
    while(heap.size()){
        PII t = heap.top();
        heap.pop();
        
        int ver = t.y, dis = t.x;
        if(st[ver]) continue;
        st[ver] = true;
        
        for(int i = h[ver]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] > dis + w[i]){
                dist[j] = dis + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    
    dijkstra();
    
    int res = 0;
    for(int i = 1; i <= n; i++) {
        if(dist[i] == 0x3f3f3f3f) {
            res = -1;
            break;
        }
        res = max(res, dist[i]);
    }
    cout << res << endl;
    
    return 0;
}