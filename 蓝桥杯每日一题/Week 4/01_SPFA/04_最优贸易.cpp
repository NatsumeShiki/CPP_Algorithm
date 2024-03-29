// C
//   国有 n
//  个大城市和 m
//  条道路，每条道路连接这 n
//  个城市中的某两个城市。

// 任意两个城市之间最多只有一条道路直接相连。

// 这 m
//  条道路中有一部分为单向通行的道路，一部分为双向通行的道路，双向通行的道路在统计条数时也计为 1
//  条。

// C
//  国幅员辽阔，各地的资源分布情况各不相同，这就导致了同一种商品在不同城市的价格不一定相同。

// 但是，同一种商品在同一个城市的买入价和卖出价始终是相同的。

// 商人阿龙来到 C
//  国旅游。

// 当他得知“同一种商品在不同城市的价格可能会不同”这一信息之后，便决定在旅游的同时，利用商品在不同城市中的差价赚一点旅费。

// 设 C
//  国 n
//  个城市的标号从 1∼n
// ，阿龙决定从 1
//  号城市出发，并最终在 n
//  号城市结束自己的旅行。

// 在旅游的过程中，任何城市可以被重复经过多次，但不要求经过所有 n
//  个城市。

// 阿龙通过这样的贸易方式赚取旅费：他会选择一个经过的城市买入他最喜欢的商品——水晶球，并在之后经过的另一个城市卖出这个水晶球，用赚取的差价当做旅费。

// 因为阿龙主要是来 C
//  国旅游，他决定这个贸易只进行最多一次，当然，在赚不到差价的情况下他就无需进行贸易。

// 现在给出 n
//  个城市的水晶球价格，m
//  条道路的信息（每条道路所连接的两个城市的编号以及该条道路的通行情况）。

// 请你告诉阿龙，他最多能赚取多少旅费。

// 注意：本题数据有加强。

// 输入格式
// 第一行包含 2
//  个正整数 n
//  和 m
// ，中间用一个空格隔开，分别表示城市的数目和道路的数目。

// 第二行 n
//  个正整数，每两个整数之间用一个空格隔开，按标号顺序分别表示这 n
//  个城市的商品价格。

// 接下来 m
//  行，每行有 3
//  个正整数，x，y，z
// ，每两个整数之间用一个空格隔开。

// 如果 z=1
// ，表示这条道路是城市 x
//  到城市 y
//  之间的单向道路；如果 z=2
// ，表示这条道路为城市 x
//  和城市 y
//  之间的双向道路。

// 输出格式
// 一个整数，表示答案。

// 数据范围
// 1≤n≤100000
// ,
// 1≤m≤500000
// ,
// 1≤各城市水晶球价格≤100
// 输入样例：
// 5 5
// 4 3 5 6 1
// 1 2 1
// 1 4 1
// 2 3 2
// 3 5 1
// 4 5 2
// 输出样例：
// 5

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10, M = 2e6 + 10;
int n, m;
int w[N];
int hs[N], ht[N], e[M], ne[M], idx;
int dmin[N], dmax[N];
int q[N];
bool st[N];

void add(int h[], int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void spfa(int h[], int dist[], int type){
    int hh = 0, tt = 1;
    if(type == 0){
        memset(dist, 0x3f, sizeof dmin);
        dist[1] = w[1];
        q[0] = 1;
    }else{
        memset(dist, -0x3f, sizeof dmax);
        dist[n] = w[n];
        q[0] = n;
    }
    
    while(hh != tt){
        int t = q[hh++];
        if(hh == N) hh = 0;
        st[t] = false;
        
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(type == 0 && dist[j] > min(dist[t], w[j]) || type == 1 && dist[j] < max(dist[t], w[j])){
                if(type == 0) dist[j] = min(dist[t], w[j]);
                else dist[j] = max(dist[t], w[j]);
                
                if(!st[j]){
                    q[tt++] = j;
                    if(tt == N) tt = 0;
                    st[j] = true;
                }
            }
        }
    }
    
    cout << hh << " " << tt << endl;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
    
    memset(hs, -1, sizeof hs);
    memset(ht, -1, sizeof ht);
    
    while(m--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(hs, a, b), add(ht, b, a);
        if(c == 2) add(hs, b, a), add(ht, a, b);
    }
    
    spfa(hs, dmin, 0);
    spfa(ht, dmax, 1);
    
    int res = 0;
    for(int i = 1; i <= n; i++) res = max(res, dmax[i] - dmin[i]);
    
    printf("%d\n", res);
    
    return 0;
}

#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 1e5 + 10, M = 2e6 + 10;
int n, m;
int w[N];
int hs[N], ht[N], e[M], ne[M], idx;
int dmin[N], dmax[N];
bool st[N];

void add(int h[], int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void spfa(int h[], int dist[], int type){
    queue<int> q;
    if(type == 0){
        memset(dist, 0x3f, sizeof dmin);
        dist[1] = w[1];
        q.push(1);
    }else{
        memset(dist, -0x3f, sizeof dmax);
        dist[n] = w[n];
        q.push(n);
    }
    
    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;
        
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(type == 0 && dist[j] > min(dist[t], w[j]) || type == 1 && dist[j] < max(dist[t], w[j])){
                if(type == 0) dist[j] = min(dist[t], w[j]);
                else dist[j] = max(dist[t], w[j]);
                
                if(!st[j]){
                    // q[tt++] = j;
                    q.push(j);
                    // if(tt == N) tt = 0;
                    st[j] = true;
                }
            }
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
    
    memset(hs, -1, sizeof hs);
    memset(ht, -1, sizeof ht);
    
    while(m--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(hs, a, b), add(ht, b, a);
        if(c == 2) add(hs, b, a), add(ht, a, b);
    }
    
    spfa(hs, dmin, 0);
    spfa(ht, dmax, 1);
    
    int res = 0;
    for(int i = 1; i <= n; i++) res = max(res, dmax[i] - dmin[i]);
    
    printf("%d\n", res);
    
    return 0;
}