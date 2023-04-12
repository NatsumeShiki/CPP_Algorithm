// 在 n
//  个人中，某些人的银行账号之间可以互相转账。

// 这些人之间转账的手续费各不相同。

// 给定这些人之间转账时需要从转账金额里扣除百分之几的手续费，请问 A
//  最少需要多少钱使得转账后 B
//  收到 100 元。

// 输入格式
// 第一行输入两个正整数 n,m
// ，分别表示总人数和可以互相转账的人的对数。

// 以下 m
//  行每行输入三个正整数 x,y,z
// ，表示标号为 x
//  的人和标号为 y
//  的人之间互相转账需要扣除 z%
//  的手续费 ( z<100
//  )。

// 最后一行输入两个正整数 A,B
// 。

// 数据保证 A
//  与 B
//  之间可以直接或间接地转账。

// 输出格式
// 输出 A
//  使得 B
//  到账 100 元最少需要的总费用。

// 精确到小数点后 8 位。

// 数据范围
// 1≤n≤2000
// ,
// m≤105
// 输入样例：
// 3 3
// 1 2 1
// 2 3 2
// 1 3 3
// 1 3
// 输出样例：
// 103.07153164


// 朴素dijkstra
#include<iostream>
#include<cstring>
using namespace std;

const int N = 2010;
double d[N][N];
double dist[N];
bool st[N];
int n, m;
int S, T;

void dijkstra(){
    for(int i = 1; i <= n; i++) dist[i] = 0x3f3f3f3f;
    
    dist[T] = 100;
    for(int i = 0; i < n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++)
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
                
        st[t] = true;
        for(int j = 1; j <= n; j++) 
            if(dist[j] > dist[t] / d[t][j])
                dist[j] = dist[t] / d[t][j];
    }
}

int main(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i != j) d[i][j] = 0x3f3f3f3f;
    
    scanf("%d%d", &n, &m);
    while(m--){
        int a, b;
        double c;
        scanf("%d%d%lf", &a, &b, &c);
        c = 100 - c;
        c /= 100;
        d[a][b] = d[b][a] = max(d[a][b], c);
    }
    scanf("%d%d", &S, &T);
    dijkstra();
    
    printf("%.8lf\n", dist[S]);
    
    return 0;
}

// 堆优化dijkstra
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

#define x first
#define y second
typedef pair<double, int> PDI;
const int N = 2010, M = 1e6 + 10;
int h[N], e[M], ne[M], idx;
double w[M];
int n, m;
int S, T;
double dist[N];
bool st[N];

void add(int a, int b, double c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(){
    for(int i = 1; i <= n; i++) dist[i] = 0x3f3f3f3f;
    priority_queue<PDI, vector<PDI>, greater<PDI>> heap;
    heap.push({100, T});
    dist[T] = 100;
    
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        
        int ver = t.y;
        double dis = t.x;
        
        if(st[ver]) continue;
        for(int i = h[ver]; ~i; i = ne[i]){
            int j = e[i];
            double c = w[i];
            if(dist[j] > dis / c){
                dist[j] = dis / c;
                heap.push({dist[j], j});
            }
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while(m--){
        int a, b;
        double c;
        scanf("%d%d%lf", &a, &b, &c);
        c = 100 - c;
        c /= 100;
        add(a, b, c);
        add(b, a, c);
    }
    scanf("%d%d", &S, &T);
    
    dijkstra();
    
    printf("%.8lf\n", dist[S]);
    
    return 0;
}

// 大佬的朴素dijkstra，思路是将S-T乘起来取最大值，最后再用100除以它就可以
#include<iostream>
#include<cstring>
using namespace std;

const int N = 2010;

int n, m, S, T;
double g[N][N];
double dist[N];
bool st[N];

void dijkstra(){
    dist[S] = 1;
    for(int i = 0; i < n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++)
            if(!st[j] && (t == -1 || dist[j] > dist[t]))        
                t = j;
        st[t] = true;
        for(int j = 1; j <= n; j++)
            dist[j] = max(dist[j], dist[t] * g[t][j]);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    while(m--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        double z = (100.0 - c) / 100;
        g[a][b] = g[b][a] = max(g[a][b], z);
    }
    
    scanf("%d%d", &S, &T);
    
    dijkstra();
    
    printf("%.8lf\n", 100 / dist[T]);
    
    return 0;
}