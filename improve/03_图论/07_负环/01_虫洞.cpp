// 农夫约翰在巡视他的众多农场时，发现了很多令人惊叹的虫洞。

// 虫洞非常奇特，它可以看作是一条 单向 路径，通过它可以使你回到过去的某个时刻（相对于你进入虫洞之前）。

// 农夫约翰的每个农场中包含 N
//  片田地，M
//  条路径（双向）以及 W
//  个虫洞。

// 现在农夫约翰希望能够从农场中的某片田地出发，经过一些路径和虫洞回到过去，并在他的出发时刻之前赶到他的出发地。

// 他希望能够看到出发之前的自己。

// 请你判断一下约翰能否做到这一点。

// 下面我们将给你提供约翰拥有的农场数量 F
// ，以及每个农场的完整信息。

// 已知走过任何一条路径所花费的时间都不超过 10000
//  秒，任何虫洞将他带回的时间都不会超过 10000
//  秒。

// 输入格式
// 第一行包含整数 F
// ，表示约翰共有 F
//  个农场。

// 对于每个农场，第一行包含三个整数 N,M,W
// 。

// 接下来 M
//  行，每行包含三个整数 S,E,T
// ，表示田地 S
//  和 E
//  之间存在一条路径，经过这条路径所花的时间为 T
// 。

// 再接下来 W
//  行，每行包含三个整数 S,E,T
// ，表示存在一条从田地 S
//  走到田地 E
//  的虫洞，走过这条虫洞，可以回到 T
//  秒之前。

// 输出格式
// 输出共 F
//  行，每行输出一个结果。

// 如果约翰能够在出发时刻之前回到出发地，则输出 YES，否则输出 NO。

// 数据范围
// 1≤F≤5

// 1≤N≤500
// ,
// 1≤M≤2500
// ,
// 1≤W≤200
// ,
// 1≤T≤10000
// ,
// 1≤S,E≤N
// 输入样例：
// 2
// 3 3 1
// 1 2 2
// 1 3 4
// 2 3 1
// 3 1 3
// 3 2 1
// 1 2 3
// 2 3 4
// 3 1 8
// 输出样例：
// NO
// YES

/*
求负环的常用方法，基于SPFA
  1.统计每个点入队的次数，如果某个点入队n次，则说明存在负环 O(n^2)
  2.统计当前每个点的最短路中所包含的边数，如果某点的最短路所包含的边数大于等于n则也说明存在环 O(n)

trick: 当所有点的入队次数超过2n时，我们就认为图中很大可能是存在负环的，这个是取巧做法
*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 510, M = 5210;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
int n, m, k;
int cnt[N]; // 保存到这个点的边数

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa(){
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);
    memset(dist, 0, sizeof dist); // 初始值是任意值都可以，所以这一行可以删掉
    
    queue<int> q; // 将所有点都入队因为可能会有多个连通块
    for(int i = 1; i <= n; i++){
        st[i] = true;
        q.push(i);
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
                if(cnt[j] > n) return true;
                if(!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        memset(h, -1, sizeof h);
        idx = 0;
        while(m--){
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, c), add(b, a, c);
        }
        while(k--){
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, -c);
        }
        
        if(spfa()) puts("YES");
        else puts("NO");
    }
    
    return 0;
}