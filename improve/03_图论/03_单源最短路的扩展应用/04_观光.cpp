// “您的个人假期”旅行社组织了一次比荷卢经济联盟的巴士之旅。

// 比荷卢经济联盟有很多公交线路。

// 每天公共汽车都会从一座城市开往另一座城市。

// 沿途汽车可能会在一些城市（零或更多）停靠。

// 旅行社计划旅途从 S
//  城市出发，到 F
//  城市结束。

// 由于不同旅客的景点偏好不同，所以为了迎合更多旅客，旅行社将为客户提供多种不同线路。

// 游客可以选择的行进路线有所限制，要么满足所选路线总路程为 S
//  到 F
//  的最小路程，要么满足所选路线总路程仅比最小路程多一个单位长度。

// 3463_1.png

// 如上图所示，如果 S=1，F=5
// ，则这里有两条最短路线 1→2→5,1→3→5
// ，长度为 6
// ；有一条比最短路程多一个单位长度的路线 1→3→4→5
// ，长度为 7
// 。

// 现在给定比荷卢经济联盟的公交路线图以及两个城市 S
//  和 F
// ，请你求出旅行社最多可以为旅客提供多少种不同的满足限制条件的线路。

// 输入格式
// 第一行包含整数 T
// ，表示共有 T
//  组测试数据。

// 每组数据第一行包含两个整数 N
//  和 M
// ，分别表示总城市数量和道路数量。

// 接下来 M
//  行，每行包含三个整数 A,B,L
// ，表示有一条线路从城市 A
//  通往城市 B
// ，长度为 L
// 。

// 需注意，线路是 单向的，存在从 A
//  到 B
//  的线路不代表一定存在从 B
//  到 A
//  的线路，另外从城市 A
//  到城市 B
//  可能存在多个不同的线路。

// 接下来一行，包含两个整数 S
//  和 F
// ，数据保证 S
//  和 F
//  不同，并且 S、F
//  之间至少存在一条线路。

// 输出格式
// 每组数据输出一个结果，每个结果占一行。

// 数据保证结果不超过 109
// 。

// 数据范围
// 2≤N≤1000
// ,
// 1≤M≤10000
// ,
// 1≤L≤1000
// ，
// 1≤A,B,S,F≤N
// 输入样例：
// 2
// 5 8
// 1 2 3
// 1 3 2
// 1 4 5
// 2 3 1
// 2 5 3
// 3 4 2
// 3 5 4
// 4 5 3
// 1 5
// 5 6
// 2 3 1
// 3 2 1
// 3 1 10
// 4 5 2
// 5 2 7
// 5 2 7
// 4 1
// 输出样例：
// 3
// 2

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1010, M = 10010;
struct Ver{ // ver表示点，type表示是最短距离还是次短长度，0是最短长度，dist是距离
    int ver, type, dist;
    bool operator> (const Ver &W) const{ // heap是小根堆，需要重载大于号
        return dist > W.dist;
    }
};
int h[N], e[M], w[M], ne[M], idx;
int dist[N][2], cnt[N][2];
bool st[N][2];
int n, m, S, T;

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra(){
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);
    memset(dist, 0x3f, sizeof dist);
    dist[S][0] = 0, cnt[S][0] = 1; // 起点的最短距离是0，最短距离路径数为1
    priority_queue<Ver, vector<Ver>, greater<Ver>> heap;
    heap.push({S, 0, 0});
    
    while(heap.size()){
        Ver t = heap.top();
        heap.pop();
        
        int ver = t.ver, type = t.type, distance = t.dist, count = cnt[ver][type];
        if(st[ver][type]) continue;
        st[ver][type] = true;
        
        for(int i = h[ver]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j][0] > distance + w[i]){ // 如果距离比最短长度更小
                dist[j][1] = dist[j][0], cnt[j][1] = cnt[j][0]; // 把最短的距离和路径数更新成次短的
                heap.push({j, 1, dist[j][1]}); // push进堆中
                dist[j][0] = distance + w[i], cnt[j][0] = count; // 更近最短距离和路径数
                heap.push({j, 0, dist[j][0]}); // push进堆中
            }else if(dist[j][0] == distance + w[i]) cnt[j][0] += count; // 如果长度等于最短距离，累加路径数
            else if(dist[j][1] > distance + w[i]){ // 如果比次短距离小
                dist[j][1] = distance + w[i], cnt[j][1] = count; // 更新距离和路径数
                heap.push({j, 1, dist[j][1]});
            }else if(dist[j][1] == distance + w[i]) cnt[j][1] += count; // 如果距离等于次短长度，累计路径数
        }
    }
    
    int res = cnt[T][0]; // 保存最短路径数
    if(dist[T][0] + 1 == dist[T][1]) res += cnt[T][1]; // 如果最短路径距离加1等于次短距离，累加
    return res;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        memset(h, -1, sizeof h);
        idx = 0;
        while(m--){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
        }
        
        scanf("%d%d", &S, &T);
        
        printf("%d\n", dijkstra());
    }
    
    return 0;
}