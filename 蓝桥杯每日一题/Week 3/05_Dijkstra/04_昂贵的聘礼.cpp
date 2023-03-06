// 年轻的探险家来到了一个印第安部落里。

// 在那里他和酋长的女儿相爱了，于是便向酋长去求亲。

// 酋长要他用 10000
//  个金币作为聘礼才答应把女儿嫁给他。

// 探险家拿不出这么多金币，便请求酋长降低要求。

// 酋长说：”嗯，如果你能够替我弄到大祭司的皮袄，我可以只要 8000
//  金币。如果你能够弄来他的水晶球，那么只要 5000
//  金币就行了。”

// 探险家就跑到大祭司那里，向他要求皮袄或水晶球，大祭司要他用金币来换，或者替他弄来其他的东西，他可以降低价格。

// 探险家于是又跑到其他地方，其他人也提出了类似的要求，或者直接用金币换，或者找到其他东西就可以降低价格。

// 不过探险家没必要用多样东西去换一样东西，因为不会得到更低的价格。

// 探险家现在很需要你的帮忙，让他用最少的金币娶到自己的心上人。

// 另外他要告诉你的是，在这个部落里，等级观念十分森严。

// 地位差距超过一定限制的两个人之间不会进行任何形式的直接接触，包括交易。

// 他是一个外来人，所以可以不受这些限制。

// 但是如果他和某个地位较低的人进行了交易，地位较高的的人不会再和他交易，他们认为这样等于是间接接触，反过来也一样。

// 因此你需要在考虑所有的情况以后给他提供一个最好的方案。

// 为了方便起见，我们把所有的物品从 1
//  开始进行编号，酋长的允诺也看作一个物品，并且编号总是 1
// 。

// 每个物品都有对应的价格 P
// ，主人的地位等级 L
// ，以及一系列的替代品 Ti
//  和该替代品所对应的”优惠” Vi
// 。

// 如果两人地位等级差距超过了 M
// ，就不能”间接交易”。

// 你必须根据这些数据来计算出探险家最少需要多少金币才能娶到酋长的女儿。

// 输入格式
// 输入第一行是两个整数 M，N
// ，依次表示地位等级差距限制和物品的总数。

// 接下来按照编号从小到大依次给出了 N
//  个物品的描述。

// 每个物品的描述开头是三个非负整数 P、L、X
// ，依次表示该物品的价格、主人的地位等级和替代品总数。

// 接下来 X
//  行每行包括两个整数 T
//  和 V
// ，分别表示替代品的编号和”优惠价格”。

// 输出格式
// 输出最少需要的金币数。

// 数据范围
// 1≤N≤100
// ,
// 1≤P≤10000
// ,
// 1≤L,M≤N
// ,
// 0≤X<N
// 输入格式
// 1 4
// 10000 3 2
// 2 8000
// 3 5000
// 1000 2 1
// 4 200
// 3000 2 1
// 4 200
// 50 2 0
// 输出格式
// 5250

// 使用邻接矩阵
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 110, M = N * N;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
int n, m;
int lay[N];
bool st[N];

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra(int l, int r){
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 0});
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        int ver = t.second, dis = t.first;
        if(st[ver]) continue;
        st[ver] = true;
        for(int i = h[ver]; ~i; i = ne[i]){
            int j = e[i];
            if(lay[j] < l || lay[j] > r) continue;
            if(dist[j] > dis + w[i]){
                dist[j] = dis + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    
    return dist[1];
}

int main(){
    cin >> m >> n;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i++){
        int p, l, x;
        cin >> p >> l >> x;
        lay[i] = l;
        add(0, i, p);
        while(x--){
            int t, v;
            cin >> t >> v;
            add(t, i, v);
        }
    }
    
    int res = 1e9;    
    for(int i = lay[1] - m; i <= lay[1]; i++) res = min(res, dijkstra(i, i + m));
    cout << res << endl;
    
    
    return 0;
}

// 使用邻接矩阵
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 110, INF = 0x3f3f3f3f;
int dist[N], w[N][N];
int n, m;
int level[N];
bool st[N];

void dijkstra(int l, int r){
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    
    dist[0] = 0;
    for(int i = 0; i < n + 1; i++){
        int t = -1;
        for(int j = 0; j <= n; j++)
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
                
        st[t] = true;
        if(t == 1) return;
        for(int j = 0; j <= n; j++)
            if(level[j] >= l && level[j] <= r)
                dist[j] = min(dist[j], dist[t] + w[t][j]);
    }
}

int main(){
    cin >> m >> n;
    memset(w, 0x3f, sizeof w);
    for(int i = 0; i <= n; i++) w[i][i] = 0;
    for(int i = 1; i <= n; i++){
        int p, l, x;
        cin >> p >> l >> x;
        level[i] = l;
        w[0][i] = min(w[0][i], p);
        while(x--){
            int t, v;
            cin >> t >> v;
            w[t][i] = min(w[t][i], v);
        }
    }
    
    int res = INF;    
    for(int i = level[1] - m; i <= level[1]; i++){
        dijkstra(i, i + m);
        res = min(res, dist[1]);
    }
    cout << res << endl;
    
    
    return 0;
}