// 城市C是一个非常繁忙的大都市，城市中的道路十分的拥挤，于是市长决定对其中的道路进行改造。

// 城市C的道路是这样分布的：

// 城市中有 n
//  个交叉路口，编号是 1∼n
// ，有些交叉路口之间有道路相连，两个交叉路口之间最多有一条道路相连接。

// 这些道路是 双向 的，且把所有的交叉路口直接或间接的连接起来了。

// 每条道路都有一个分值，分值越小表示这个道路越繁忙，越需要进行改造。

// 但是市政府的资金有限，市长希望进行改造的道路越少越好，于是他提出下面的要求：

// 1．改造的那些道路能够把所有的交叉路口直接或间接的连通起来。

// 2．在满足要求1的情况下，改造的道路尽量少。

// 3．在满足要求1、2的情况下，改造的那些道路中分值最大值尽量小。

// 作为市规划局的你，应当作出最佳的决策，选择哪些道路应当被修建。

// 输入格式
// 第一行有两个整数 n,m
//  表示城市有 n
//  个交叉路口，m
//  条道路。

// 接下来 m
//  行是对每条道路的描述，每行包含三个整数u,v,c
//  表示交叉路口 u
//  和 v
//  之间有道路相连，分值为 c
// 。

// 输出格式
// 两个整数 s,max
// ，表示你选出了几条道路，分值最大的那条道路的分值是多少。

// 数据范围
// 1≤n≤300
// ,
// 1≤m≤8000
// ,
// 1≤c≤10000
// 输入样例：
// 4 5
// 1 2 3
// 1 4 5
// 2 4 7
// 2 3 6
// 3 4 8
// 输出样例：
// 3 6


// prim算法
#include<iostream>
#include<cstring>
using namespace std;

const int N = 310;
int w[N][N];
bool st[N];
int dist[N];
int n, m;

int prim(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    int res = 0;
    for(int i = 1; i <= n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++)
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
                
        res = max(res, dist[t]); // 注意这里需要取最大值，因为可能还没在连通块中的一个点离另一个点很近，当另一个点添加进去后这个点距离连通块距离会最小
        st[t] = true; 
        for(int j = 1; j <= n; j++) dist[j] = min(dist[j], w[t][j]);
    }
    
    return res;
}

int main(){
    cin >> n >> m;
    memset(w, 0x3f, sizeof w);
    for(int i = 1; i <= n; i++) w[i][i] = 0;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        w[a][b] = w[b][a] = c;
    }
    
    cout << n - 1 << " " <<  prim() << endl;
    
    return 0;
}

// kruskal算法
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 310, M = 8010;
int n, m;
int p[N];
struct edge{
    int a, b, w;
    bool operator < (const edge& t){
        return w < t.w;
    }
}e[M];

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = {a, b, c};
    }
    
    sort(e, e + m);
    
    int res, cnt = 0;;
    for(int i = 0; i < m; i++){
        int a = find(e[i].a), b = find(e[i].b), w = e[i].w;
        if(a != b) {
            res = w;
            cnt++;
            p[a] = b;
        }
    }
    
    cout << cnt << " " << res << endl;
    
    return 0;
}