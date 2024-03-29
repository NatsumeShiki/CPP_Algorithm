// 给定一个二分图，其中左半部包含 n1
//  个点（编号 1∼n1
// ），右半部包含 n2
//  个点（编号 1∼n2
// ），二分图共包含 m
//  条边。

// 数据保证任意一条边的两个端点都不可能在同一部分中。

// 请你求出二分图的最大匹配数。

// 二分图的匹配：给定一个二分图 G
// ，在 G
//  的一个子图 M
//  中，M
//  的边集 {E}
//  中的任意两条边都不依附于同一个顶点，则称 M
//  是一个匹配。

// 二分图的最大匹配：所有匹配中包含边数最多的一组匹配被称为二分图的最大匹配，其边数即为最大匹配数。

// 输入格式
// 第一行包含三个整数 n1
// 、 n2
//  和 m
// 。

// 接下来 m
//  行，每行包含两个整数 u
//  和 v
// ，表示左半部点集中的点 u
//  和右半部点集中的点 v
//  之间存在一条边。

// 输出格式
// 输出一个整数，表示二分图的最大匹配数。

// 数据范围
// 1≤n1,n2≤500
// ,
// 1≤u≤n1
// ,
// 1≤v≤n2
// ,
// 1≤m≤105
// 输入样例：
// 2 2 4
// 1 1
// 1 2
// 2 1
// 2 2
// 输出样例：
// 2

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 510, M = 100010;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];
int n1, n2, m;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++; 
}

bool find(int x){
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(!st[j]){
            st[j] = true;
            if(match[j] == 0 || find(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    scanf("%d%d%d", &n1, &n2, &m);
    memset(h, -1, sizeof h);
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    
    int res = 0;
    for(int i = 1; i <= n1; i++){
        memset(st, false, sizeof st);
        if(find(i)) res++;
    }
    
    printf("%d\n", res);
    
    return 0;
}