// 发展采矿业当然首先得有矿井，小 FF 花了上次探险获得的千分之一的财富请人在岛上挖了 n
//  口矿井，但他似乎忘记了考虑矿井供电问题。

// 为了保证电力的供应，小 FF 想到了两种办法：

// 在矿井 i
//  上建立一个发电站，费用为 vi
// （发电站的输出功率可以供给任意多个矿井）。
// 将这口矿井 i
//  与另外的已经有电力供应的矿井 j
//  之间建立电网，费用为 pi,j
// 。
// 小 FF 希望你帮他想出一个保证所有矿井电力供应的最小花费方案。

// 输入格式
// 第一行包含一个整数 n
// ，表示矿井总数。

// 接下来 n
//  行，每行一个整数，第 i
//  个数 vi
//  表示在第 i
//  口矿井上建立发电站的费用。

// 接下来为一个 n×n
//  的矩阵 P
// ，其中 pi,j
//  表示在第 i
//  口矿井和第 j
//  口矿井之间建立电网的费用。

// 数据保证 pi,j=pj,i
// ，且 pi,i=0
// 。

// 输出格式
// 输出一个整数，表示让所有矿井获得充足电能的最小花费。

// 数据范围
// 1≤n≤300
// ,
// 0≤vi,pi,j≤105
// 输入样例：
// 4
// 5
// 4
// 4
// 3
// 0 2 2 2
// 2 0 3 3
// 2 3 0 4
// 2 3 4 0
// 输出样例：
// 9

// 从0到每个点建立一条边，权值是建立这个站的消费
#include<iostream>
#include<cstring>
using namespace std;

const int N = 310;
int dist[N];
bool st[N];
int d[N][N];
int n;

int prim(){
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    int res = 0;
    for(int i = 0; i <= n; i++){
        int t = -1;              
        for(int j = 0; j <= n; j++)
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
                
        st[t] = true;
        res += dist[t];
        
        for(int j = 1; j <= n; j++) dist[j] = min(dist[j], d[t][j]);
    }
    
    return res;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        d[0][i] = d[i][0] = x;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &d[i][j]);
    
    cout << prim() << endl;
    
    return 0;
}