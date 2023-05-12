// 有两台机器 A，B
//  以及 K
//  个任务。

// 机器 A
//  有 N
//  种不同的模式（模式 0?N?1
// ），机器 B
//  有 M
//  种不同的模式（模式 0?M?1
// ）。

// 两台机器最开始都处于模式 0
// 。

// 每个任务既可以在 A
//  上执行，也可以在 B
//  上执行。

// 对于每个任务 i
// ，给定两个整数 a[i]
//  和 b[i]
// ，表示如果该任务在 A
//  上执行，需要设置模式为 a[i]
// ，如果在 B
//  上执行，需要模式为 b[i]
// 。

// 任务可以以任意顺序被执行，但每台机器转换一次模式就要重启一次。

// 求怎样分配任务并合理安排顺序，能使机器重启次数最少。

// 输入格式
// 输入包含多组测试数据。

// 每组数据第一行包含三个整数 N,M,K
// 。

// 接下来 K
//  行，每行三个整数 i,a[i]
//  和 b[i]
// ，i
//  为任务编号，从 0
//  开始。

// 当输入一行为 0
//  时，表示输入终止。

// 输出格式
// 每组数据输出一个整数，表示所需的机器最少重启次数，每个结果占一行。

// 数据范围
// N,M<100,K<1000

// 0≤a[i]<N

// 0≤b[i]<M
// 输入样例：
// 5 5 10
// 0 1 1
// 1 1 2
// 2 1 3
// 3 1 4
// 4 2 1
// 5 2 2
// 6 2 3
// 7 2 4
// 8 3 3
// 9 4 3
// 0
// 输出样例：
// 3

/*
最小点覆盖：这个概念针对任意无向图都是成立的，是指我们从图中选出最少的点集，使得所有的边中的两个端点至少有一个端点在该点集中
在二分图中，最小点覆盖n == 最大匹配数m
这道题只需要求出最大匹配数即可
*/
// 一开始将所有模式为0的略去，因为两台机器初始状态都是0，需要模式为0的任务形同虚设
#include<iostream>
#include<cstring>
using namespace std;

const int N = 110;
int n, m, k;
bool g[N][N], st[N];
int match[N];

bool find(int x){
    for(int i = 1; i < m; i++)
        if(!st[i] && g[x][i]){
            st[i] = true;
            int t = match[i];
            if(t == 0 || find(t)){
                match[i] = x;
                return true;
            }
        }
    return false;
}

int main(){
    while(cin >> n, n){
        cin >> m >> k;
        memset(g, 0, sizeof g);
        memset(match, 0, sizeof match);
        
        while(k--){
            int t, a, b;
            cin >> t >> a >> b;
            if(!a || !b) continue;
            g[a][b] = true;
        }
        
        int res = 0;
        for(int i = 1; i < n; i++){
            memset(st, 0, sizeof st);
            if(find(i)) res++;
        }
        cout << res << endl;
    }
    
    return 0;
}