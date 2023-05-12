// 一些学校连接在一个计算机网络上，学校之间存在软件支援协议，每个学校都有它应支援的学校名单（学校 A
//  支援学校 B
// ，并不表示学校 B
//  一定要支援学校 A
// ）。

// 当某校获得一个新软件时，无论是直接获得还是通过网络获得，该校都应立即将这个软件通过网络传送给它应支援的学校。

// 因此，一个新软件若想让所有学校都能使用，只需将其提供给一些学校即可。

// 现在请问最少需要将一个新软件直接提供给多少个学校，才能使软件能够通过网络被传送到所有学校？

// 最少需要添加几条新的支援关系，使得将一个新软件提供给任何一个学校，其他所有学校就都可以通过网络获得该软件？

// 输入格式
// 第 1
//  行包含整数 N
// ，表示学校数量。

// 第 2..N+1
//  行，每行包含一个或多个整数，第 i+1
//  行表示学校 i
//  应该支援的学校名单，每行最后都有一个 0
//  表示名单结束（只有一个 0
//  即表示该学校没有需要支援的学校）。

// 输出格式
// 输出两个问题的结果，每个结果占一行。

// 数据范围
// 2≤N≤100
// 输入样例：
// 5
// 2 4 3 0
// 4 5 0
// 0
// 0
// 1 0
// 输出样例：
// 1
// 2

// 做法，通过tarjan和缩点操作后得到拓扑排序，获取入度和出度为0的连通块个数，第一个问题的答案就是入度为0的点的数量，第二个问题的答案是入度和出度为0的连通块个数的较大值
#include<iostream>
#include<cstring>
using namespace std;

const int N = 110, M = 10010;
int h[N], e[M], ne[M], idx;
int timestamp, dfn[N], low[N];
int n;
int stk[N], top;
bool in_stk[N];
int scc_cnt;
int din[N], dout[N];
int id[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u){
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u, in_stk[u] = true;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }else if(in_stk[j]) low[u] = min(low[u], dfn[j]);
    }
    
    if(dfn[u] == low[u]){
        int y;
        scc_cnt++;
        do{
            y = stk[top--];
            in_stk[y] = false;
            id[y] = scc_cnt;
        }while(y != u);
    }
}

int main(){
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i++){
        int t;
        while(cin >> t, t) add(i, t);
    }
    
    for(int i = 1; i <= n; i++)
        if(!dfn[i])
            tarjan(i);
    
    for(int i = 1; i <= n; i++)
        for(int j = h[i]; ~j; j = ne[j]){
            int k = e[j];
            int a = id[i], b = id[k];
            if(a != b) din[b]++, dout[a]++;
        }
    
    int res1 = 0, res2 = 0;
    for(int i = 1; i <= scc_cnt; i++){
        if(!din[i]) res1++;
        if(!dout[i]) res2++;
        // cout << din[i] << " " << dout[i] << endl;
    }
    if(scc_cnt == 1) printf("1\n0\n");
    else printf("%d\n%d\n", res1, max(res1, res2));
    
    return 0;
}