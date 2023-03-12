// 某个局域网内有 n
//  台计算机和 k
//  条 双向 网线，计算机的编号是 1∼n
// 。由于搭建局域网时工作人员的疏忽，现在局域网内的连接形成了回路，我们知道如果局域网形成回路那么数据将不停的在回路内传输，造成网络卡的现象。

// 注意：

// 对于某一个连接，虽然它是双向的，但我们不将其当做回路。本题中所描述的回路至少要包含两条不同的连接。
// 两台计算机之间最多只会存在一条连接。
// 不存在一条连接，它所连接的两端是同一台计算机。
// 因为连接计算机的网线本身不同，所以有一些连线不是很畅通，我们用 f(i,j)
//  表示 i,j
//  之间连接的畅通程度，f(i,j)
//  值越小表示 i,j
//  之间连接越通畅。

// 现在我们需要解决回路问题，我们将除去一些连线，使得网络中没有回路且不影响连通性（即如果之前某两个点是连通的，去完之后也必须是连通的），并且被除去网线的 Σf(i,j)
//  最大，请求出这个最大值。

// 输入格式
// 第一行两个正整数 n,k
// 。

// 接下来的 k
//  行每行三个正整数 i,j,m
//  表示 i,j
//  两台计算机之间有网线联通，通畅程度为 m
// 。

// 输出格式
// 一个正整数，表示被除去网线的 Σf(i,j)
//  的最大值。

// 数据范围
// 1≤n≤100

// 0≤k≤200

// 1≤f(i,j)≤1000
// 输入样例：
// 5 5
// 1 2 8
// 1 3 1
// 1 5 3
// 2 4 5
// 3 4 2
// 输出样例：
// 8

#include<iostream>
#include<cstring>
using namespace std;

const int N = 110;
int g[N][N];
int dist[N];
bool st[N];
int n, k;

int prim(){
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    for(int i = 0; i < n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++)
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
                
        st[t] = true;
        if(i && dist[t] != 0x3f3f3f3f) res += dist[t];
        for(int j = 1; j <= n; j++)
            dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}

int main(){
    cin >> n >> k;
    memset(g, 0x3f, sizeof g);
    for(int i = 1; i <= n; i++) g[i][i] = 0;
    int sum = 0;
    while(k--){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = c;
        sum += c;
    }
    
    int res = prim();
    cout << sum - res << endl;
    
    return 0;
}