// 当排队等候喂食时，奶牛喜欢和它们的朋友站得靠近些。

// 农夫约翰有 N
//  头奶牛，编号从 1
//  到 N
// ，沿一条直线站着等候喂食。

// 奶牛排在队伍中的顺序和它们的编号是相同的。

// 因为奶牛相当苗条，所以可能有两头或者更多奶牛站在同一位置上。

// 如果我们想象奶牛是站在一条数轴上的话，允许有两头或更多奶牛拥有相同的横坐标。

// 一些奶牛相互间存有好感，它们希望两者之间的距离不超过一个给定的数 L
// 。

// 另一方面，一些奶牛相互间非常反感，它们希望两者间的距离不小于一个给定的数 D
// 。

// 给出 ML
//  条关于两头奶牛间有好感的描述，再给出 MD
//  条关于两头奶牛间存有反感的描述。

// 你的工作是：如果不存在满足要求的方案，输出-1；如果 1
//  号奶牛和 N
//  号奶牛间的距离可以任意大，输出-2；否则，计算出在满足所有要求的情况下，1
//  号奶牛和 N
//  号奶牛间可能的最大距离。

// 输入格式
// 第一行包含三个整数 N,ML,MD
// 。

// 接下来 ML
//  行，每行包含三个正整数 A,B,L
// ，表示奶牛 A
//  和奶牛 B
//  至多相隔 L
//  的距离。

// 再接下来 MD
//  行，每行包含三个正整数 A,B,D
// ，表示奶牛 A
//  和奶牛 B
//  至少相隔 D
//  的距离。

// 输出格式
// 输出一个整数，如果不存在满足要求的方案，输出-1；如果 1
//  号奶牛和 N
//  号奶牛间的距离可以任意大，输出-2；否则，输出在满足所有要求的情况下，1
//  号奶牛和 N
//  号奶牛间可能的最大距离。

// 数据范围
// 2≤N≤1000
// ,
// 1≤ML,MD≤104
// ,
// 1≤L,D≤106
// 输入样例：
// 4 2 1
// 1 3 10
// 2 4 20
// 2 3 3
// 输出样例：
// 27

/*
1. x[b] - x[a] <= L  x[b] <= x[a] + L  [a] -> [b]  L
2. x[b] - x[a] >= D  x[a] <= x[b] - D  [b] -> [a] -D
3. x[i] <= x[i + 1]                    [i] -> [i + 1] 0  1 <= i <= n
这三个条件还没有满足 从某个点出发可以走到所有的点，所以创建一个虚拟源点0，因为题目表示的是相对位置，所以可以假设所有坐标都在0的右边
因此从0到所有点建立一条长度为0的边，但是可能会有环，所以先判断有没有环，再做一遍spfa，此时可以直接把1放在0的位置不变，判读dist[n]是否为
无穷大，如果是，则表示他们之间的距离可以无穷大
*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1010, M = 22010, INF = 0x3f3f3f3f;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
int n, ml, md;
int cnt[N];

void add(int a, int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa(int sz){
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);
    
    queue<int> q;
    for(int i = 1; i <= sz;i ++){ // 从1到sz都入队
        q.push(i);
        st[i] = true;
        dist[i] = 0;
    }
    
    while(q.size()){
        int t = q.front();
        q.pop();
        
        st[t] = false;
        
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n) return true;
                if(!st[j]){
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> ml >> md;
    memset(h, -1, sizeof h);
    while(ml--){
        int a, b, c;
        cin >> a >> b >> c; 
        if(a > b) swap(a, b); // x[b] - x[a] <= c
        add(a, b, c);
    }
    while(md--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a > b) swap(a, b); // x[b] - x[a] >= c
        add(b, a, -c);
    }
    for(int i = 1; i < n;i ++) add(i + 1, i, 0); // [i + 1] -> [i] 0
    
    if(spfa(n)) puts("-1"); // 先判断有没有环
    else {
        spfa(1); // 只将1入队
        if(dist[n] == INF) cout << -2 << endl; // 判断n距离1是否为无穷大
        else cout << dist[n] << endl;
    }
    
    return 0;
}