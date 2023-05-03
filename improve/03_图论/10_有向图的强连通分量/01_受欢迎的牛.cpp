// 每一头牛的愿望就是变成一头最受欢迎的牛。

// 现在有 N
//  头牛，编号从 1
//  到 N
// ，给你 M
//  对整数 (A,B)
// ，表示牛 A
//  认为牛 B
//  受欢迎。

// 这种关系是具有传递性的，如果 A
//  认为 B
//  受欢迎，B
//  认为 C
//  受欢迎，那么牛 A
//  也认为牛 C
//  受欢迎。

// 你的任务是求出有多少头牛被除自己之外的所有牛认为是受欢迎的。

// 输入格式
// 第一行两个数 N,M
// ；

// 接下来 M
//  行，每行两个数 A,B
// ，意思是 A
//  认为 B
//  是受欢迎的（给出的信息有可能重复，即有可能出现多个 A,B
// ）。

// 输出格式
// 输出被除自己之外的所有牛认为是受欢迎的牛的数量。

// 数据范围
// 1≤N≤104
// ,
// 1≤M≤5×104
// 输入样例：
// 3 3
// 1 2
// 2 1
// 2 3
// 输出样例：
// 1
// 样例解释
// 只有第三头牛被除自己之外的所有牛认为是受欢迎的。

#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

const int N = 10010, M = 50010;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
bool in_stk[N];
int id[N], scc_cnt, sz[N];
int dout[N];
int stk[N], top;

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
        ++scc_cnt;
        int y;
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
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    
    for(int i = 1; i <= n; i++)
        if(!dfn[i])
            tarjan(i);
    
    for(int i = 1; i <= n; i++)
        for(int j = h[i]; ~j; j = ne[j]){
            int k = e[j];
            int a = id[i], b = id[k];
            if(a != b) dout[a]++;
        }
        
    int zeros = 0, sum = 0;
    for(int i = 1; i <= scc_cnt; i++)
        if(!dout[i]){
            zeros++;
            sum += sz[i];
            if(zeros > 1){
                sum = 0;
                break;
            }
        }
        
    printf("%d\n", sum);
    
    return 0;
}