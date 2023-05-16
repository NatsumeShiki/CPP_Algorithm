// 农民John每年有很多栅栏要修理。

// 他总是骑着马穿过每一个栅栏并修复它破损的地方。

// John是一个与其他农民一样懒的人。

// 他讨厌骑马，因此从来不两次经过一个栅栏。

// 你必须编一个程序，读入栅栏网络的描述，并计算出一条修栅栏的路径，使每个栅栏都恰好被经过一次。

// John能从任何一个顶点(即两个栅栏的交点)开始骑马，在任意一个顶点结束。

// 每一个栅栏连接两个顶点，顶点用 1
//  到 500
//  标号(虽然有的农场并没有 500
//  个顶点)。

// 一个顶点上可连接任意多( ≥1
//  )个栅栏。

// 所有栅栏都是连通的(也就是你可以从任意一个栅栏到达另外的所有栅栏)。

// 你的程序必须输出骑马的路径(用路上依次经过的顶点号码表示)。

// 我们如果把输出的路径看成是一个500进制的数，那么当存在多组解的情况下，输出500进制表示法中最小的一个 (也就是输出第一个数较小的，如果还有多组解，输出第二个数较小的，等等)。

// 输入数据保证至少有一个解。

// 输入格式
// 第 1
//  行:一个整数 F
// ，表示栅栏的数目;

// 第 2
//  到 F+1
//  行:每行两个整数 i,j
//  表示这条栅栏连接 i
//  与 j
//  号顶点。

// 输出格式
// 输出应当有 F+1
//  行，每行一个整数，依次表示路径经过的顶点号。

// 注意数据可能有多组解，但是只有上面题目要求的那一组解是认为正确的。

// 数据范围
// 1≤F≤1024
// ,
// 1≤i,j≤500
// 输入样例：
// 9
// 1 2
// 2 3
// 3 4
// 4 2
// 4 5
// 2 5
// 5 6
// 5 7
// 4 6
// 输出样例：
// 1
// 2
// 3
// 4
// 2
// 5
// 4
// 6
// 5
// 7

// 无向图输出欧拉路径字典序最小的一条路径，结论就是开始搜索时优先搜索序号较小的点
#include<iostream>
#include<cstring>
using namespace std;

const int N = 510;
int n = 500, m; // 点的序号是在1-500里面随机的，所以直接把n设置为500
int g[N][N]; // 从i到j的路径的条数
int ans[1100], cnt;
int d[N]; // 度数

void dfs(int u){
    for(int i = 1; i <= n; i++)
        if(g[u][i]){ // 如果从u到i有路可以走
            g[u][i]--, g[i][u]--; // 将这条路径删除
            dfs(i); // 向下搜索i
        }
    ans[++cnt] = u;
}

int main(){
    cin >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        g[a][b]++, g[b][a]++; // 从a到b的路径和从b到a的路径条数加1
        d[a]++, d[b]++; // a和b的度数都加1
    }
    
    int start = 1; 
    while(!d[start]) start++;
    // 数据保证已经有解，存在欧拉回路，那么让第一个度数为奇数的点作为起点
    // 之所以不在循环里面直接dfs，是因为如果这张图本身就是一个环，此时每个点入度等于出度，此时从最小的有度数的点开始
    for(int i = 1; i <= n; i++)
        if(d[i] % 2){
            start = i;
            break;
        }
        
    dfs(start);
    
    for(int i = cnt; i; i--) printf("%d\n", ans[i]);
    
    return 0;
}