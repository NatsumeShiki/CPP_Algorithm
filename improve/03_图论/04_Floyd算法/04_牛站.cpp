// 给定一张由 T
//  条边构成的无向图，点的编号为 1∼1000
//  之间的整数。

// 求从起点 S
//  到终点 E
//  恰好经过 N
//  条边（可以重复经过）的最短路。

// 注意: 数据保证一定有解。

// 输入格式
// 第 1
//  行：包含四个整数 N，T，S，E
// 。

// 第 2..T+1
//  行：每行包含三个整数，描述一条边的边长以及构成边的两个点的编号。

// 输出格式
// 输出一个整数，表示最短路的长度。

// 数据范围
// 2≤T≤100
// ,
// 2≤N≤106
// 输入样例：
// 2 6 6 4
// 11 4 6
// 4 4 8
// 8 4 9
// 6 6 8
// 2 6 9
// 3 8 9
// 输出样例：
// 10

/*
d[k, i, j] 表示从i到j，恰好经过k条边的最短路径
d[a + b, i, j] = min(d[a, i, k] + d[b, k, j]), k = 1 ~ n
*/
#include<iostream>
#include<cstring>
#include<map>
using namespace std;

const int N = 210; // 边数有100，所以点最多有200个
int k, n, m, S, E;
int g[N][N]; // 计算两个点之间的距离，在快速幂中用于分别计算两个点之间有1条边，两条边，四条边.....
int res[N][N]; // 计算最终两个点之间经过k条边的最短路径

void mul(int c[][N], int a[][N], int b[][N]){
    static int temp[N][N];
    memset(temp, 0x3f, sizeof temp);
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                temp[i][j] = min(temp[i][j], a[i][k] + b[k][j]); // 计算两个点之间的距离
                
    memcpy(c, temp, sizeof temp); // 复制会c数组中
}

void qmi(){
    memset(res, 0x3f, sizeof res); // 这个是最终两个点之间边数为k的距离
    for(int i = 1; i <= n; i++) res[i][i] = 0; // 经过0条边两个点之间的距离
    
    while(k){
        if(k & 1) mul(res, res, g); // 如果k&1是1，进行mul就得到了两点之间边数加二进制k的边数
        mul(g, g, g);
        k >>= 1;
    }
}

int main(){
    cin >> k >> m >> S >> E;
    memset(g, 0x3f, sizeof g); // 这个不设置g[i][i] = 0是因为如果题目要求边的距离为1，那么i到i一条边是无法到达的，此时结果是INF
    map<int, int> ids; // 用于离散化
    if(!ids.count(S)) ids[S] = ++n; // 存进ids
    if(!ids.count(E)) ids[E] = ++n;
    S = ids[S], E = ids[E]; // 映射下标
     
    while(m--){
        int a, b, c;
        cin >> c >> a >> b;
        if(!ids.count(a)) ids[a] = ++n;
        if(!ids.count(b)) ids[b] = ++n;
        a = ids[a], b = ids[b];
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    
    qmi(); // 快速幂
    
    cout << res[S][E] << endl;
    
    return 0;
}