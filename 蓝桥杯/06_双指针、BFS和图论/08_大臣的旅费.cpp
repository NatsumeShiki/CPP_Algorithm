// 很久以前，T王国空前繁荣。

// 为了更好地管理国家，王国修建了大量的快速路，用于连接首都和王国内的各大城市。

// 为节省经费，T国的大臣们经过思考，制定了一套优秀的修建方案，使得任何一个大城市都能从首都直接或者通过其他大城市间接到达。

// 同时，如果不重复经过大城市，从首都到达每个大城市的方案都是唯一的。

// J是T国重要大臣，他巡查于各大城市之间，体察民情。

// 所以，从一个城市马不停蹄地到另一个城市成了J最常做的事情。

// 他有一个钱袋，用于存放往来城市间的路费。

// 聪明的J发现，如果不在某个城市停下来修整，在连续行进过程中，他所花的路费与他已走过的距离有关，在走第x千米到第x+1千米这一千米中（x是整数），他花费的路费是x+10这么多。也就是说走1千米花费11，走2千米要花费23。

// J大臣想知道：他从某一个城市出发，中间不休息，到达另一个城市，所有可能花费的路费中最多是多少呢？

// 输入格式
// 输入的第一行包含一个整数 n，表示包括首都在内的T王国的城市数。

// 城市从 1 开始依次编号，1 号城市为首都。

// 接下来 n−1 行，描述T国的高速路（T国的高速路一定是 n−1 条）。

// 每行三个整数 Pi,Qi,Di，表示城市 Pi 和城市 Qi 之间有一条双向高速路，长度为 Di 千米。

// 输出格式
// 输出一个整数，表示大臣J最多花费的路费是多少。

// 数据范围
// 1≤n≤105,
// 1≤Pi,Qi≤n,
// 1≤Di≤1000
// 输入样例：
// 5 
// 1  2  2 
// 1  3  1 
// 2  4  5 
// 2  5  4 
// 输出样例：
// 135

/*
这道题目的就是为了查找这个数的直径
方法：
  1：任取一点x
  2：从x开始向各个点遍历，保存各个点到x的距离
  3：获取距离x最大的那个点u，u就是直径的一个端点
  4：从u开始向各个点遍历
  5：获取距离u最大的距离
  6：这个距离就是数的直径
计算费用:f(s) = 10 + 1 + 10 + 2 + ... + 10 + s
             = 10s + s(s + 1) / 2
这里就不证明了
*/
// 方法一：使用vector保存邻接表
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;

int n;
struct Edge{
    int id, w; // 保存边和权值
};
vector<Edge> h[N]; // 保存各个点可以直接到达哪些点
int dist[N]; // 保存距离u的距离

void dfs(int u, int father, int distance){
    dist[u] = distance;
    
    for(auto node : h[u])
        if(node.id != father)
            dfs(node.id, u, distance + node.w);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        h[a].push_back({b, c}); // 保存的是无向图，所以a可以到b，b也可以到a
        h[b].push_back({a, c});
    }
    
    dfs(1, -1, 0); // 先随便从一点开始遍历，比如从1开始
    
    int u = 1; // 查找距离1最远的那个点
    for(int i = 1; i <= n; i++)
        if(dist[i] > dist[u])
            u = i; // 最终u就保存那个下标
            
    dfs(u, -1, 0); // 然后再从u开始深度遍历
    
    for(int i = 1; i <= n; i++) // 然后找一个点距离u最远
        if(dist[i] > dist[u])
            u = i;
    
    int s = dist[u]; // 这一段距离就是直径
    printf("%lld\n", s * 10 + s * (s + 1ll) / 2); // 最后使用公式即可，注意，两个s相乘可能会爆int，所以需要longlong，在1后面加ll，可以类型提升
    return 0;
}


// 使用数组模拟邻接表
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5 + 10, M = 2 * N;
int e[M], h[N], ne[M], w[M], idx;
int n;
int dist[N];

void add(int a, int b, int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
    
}

void dfs(int u, int father, int dis){
    dist[u] = dis;
    
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i], x = w[i];
        if(j != father)
            dfs(j, u, dis + x);
    }
}

int main(){
    memset(h, -1, sizeof h);
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    
    dfs(1, -1, 0);
    int u = 1;
    for(int i = 1; i <= n; i++)
        if(dist[i] > dist[u])
            u = i;
            
    dfs(u, -1, 0);
    for(int i = 1; i <= n; i++)
        if(dist[i] > dist[u])
            u = i;
            
    int s = dist[u];
    cout << s * 10 + (long long)s * (s + 1) / 2;
    
    return 0;
}