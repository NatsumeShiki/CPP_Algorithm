// 银河中的恒星浩如烟海，但是我们只关注那些最亮的恒星。

// 我们用一个正整数来表示恒星的亮度，数值越大则恒星就越亮，恒星的亮度最暗是 1
// 。

// 现在对于 N
//  颗我们关注的恒星，有 M
//  对亮度之间的相对关系已经判明。

// 你的任务就是求出这 N
//  颗恒星的亮度值总和至少有多大。

// 输入格式
// 第一行给出两个整数 N
//  和 M
// 。

// 之后 M
//  行，每行三个整数 T,A,B
// ，表示一对恒星 (A,B)
//  之间的亮度关系。恒星的编号从 1
//  开始。

// 如果 T=1
// ，说明 A
//  和 B
//  亮度相等。
// 如果 T=2
// ，说明 A
//  的亮度小于 B
//  的亮度。
// 如果 T=3
// ，说明 A
//  的亮度不小于 B
//  的亮度。
// 如果 T=4
// ，说明 A
//  的亮度大于 B
//  的亮度。
// 如果 T=5
// ，说明 A
//  的亮度不大于 B
//  的亮度。

// 输出格式
// 输出一个整数表示结果。

// 若无解，则输出 −1
// 。

// 数据范围
// N≤100000,M≤100000
// 输入样例：
// 5 7 
// 1 1 2 
// 2 3 2 
// 4 4 1 
// 3 4 5 
// 5 4 5 
// 2 3 5 
// 4 5 1 
// 输出样例：
// 11

#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10, M = 6e5 + 10;
int h[N], hs[N], e[M], w[M], ne[M], idx;
int n, m;
int timestamp, dfn[N], low[N];
int stk[N], top;
bool in_stk[N];
int scc_cnt, id[N], sz[N];
int dist[N];

void add(int h[], int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u){
    dfn[u] = low[u] = timestamp++;
    stk[++top] = u, in_stk[u] = true;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }else if(in_stk[j]) low[u] = min(low[u], dfn[j]);
    }
    
    if(low[u] == dfn[u]){
        int y;
        scc_cnt++;
        do{
            y = stk[top--];
            in_stk[y] = false;
            id[y] = scc_cnt;
            sz[scc_cnt]++;
        }while(y != u);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    memset(hs, -1, sizeof h);
    while(m--){
        int t, a, b;
        scanf("%d%d%d", &t, &a, &b);
        if(t == 1) add(h, a, b, 0), add(h, b, a, 0);
        else if(t == 2) add(h, a, b, 1);
        else if(t == 3) add(h, b, a, 0);
        else if(t == 4) add(h, b, a, 1);
        else add(h, a, b, 0);
    }
    
    for(int i = 1; i <= n; i++) add(h, 0, i, 1); // 从0向所有点连接一条权值为1的边
    
    tarjan(0); // 从0开始做tarjan算法，一定可以遍历到的所有点
    
    bool success = true;
    for(int i = 0; i <= n; i++)
        for(int j = h[i]; ~j; j = ne[j]){
            int k = e[j];
            int a = id[i], b = id[k];
            if(a == b){ // 如果i和k在一个连通块中，并且连接他们二者的边的权值大于0，表示无解
                if(w[j] > 0){
                    success = false;
                    break;
                }
            }else add(hs, a, b, w[j]); // 否则，建边
            if(!success) break;
        }
        
    if(!success) puts("-1");
    else{
        LL res = 0;
        for(int i = scc_cnt; i; i--){ // 这里不把起点的dist设置为1是因为最后一个连通块一定是0,0的dist就是0，它的下一个连通块的dist是1，是正确的
            for(int j = hs[i]; ~j; j = ne[j]){
                int k = e[j];
                dist[k] = max(dist[k], dist[i] + w[j]); // 在本身的dist和从i到k的dist加上权值取较大值
            }
        }
        
        for(int i = 1; i <= n; i++) res += (LL)dist[i] * sz[i]; // 最后将每个连通块距离第一个连通块距离乘以连通块中点的数量累加到res
        
        printf("%lld\n", res);
    }
    
    return 0;
}