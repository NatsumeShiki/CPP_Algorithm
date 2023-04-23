// 给定一棵 N
//  个节点的树，要求增加若干条边，把这棵树扩充为完全图，并满足图的唯一最小生成树仍然是这棵树。

// 求增加的边的权值总和最小是多少。

// 注意： 树中的所有边权均为整数，且新加的所有边权也必须为整数。

// 输入格式
// 第一行包含整数 t
// ，表示共有 t
//  组测试数据。

// 对于每组测试数据，第一行包含整数 N
// 。

// 接下来 N−1
//  行，每行三个整数 X,Y,Z
// ，表示 X
//  节点与 Y
//  节点之间存在一条边，长度为 Z
// 。

// 输出格式
// 每组数据输出一个整数，表示权值总和最小值。

// 每个结果占一行。

// 数据范围
// 1≤N≤6000

// 1≤Z≤100
// 输入样例：
// 2
// 3
// 1 2 2
// 1 3 3
// 4
// 1 2 3
// 2 3 4
// 3 4 5 
// 输出样例：
// 4
// 17 

/*
将一颗生成树扩展成完全图，并且要求最小生成树是原本的那棵树，做法如下：
  1. 将边排序
  2. 从小到大枚举每一条边，如果他们还没有在一个连通块中，将a连通块中点的数量添加到b中，将a的祖宗节点的父节点设置为b的祖宗节点，
    然后需要将两个连通块中不相连的两个点连接，一共有 size[a] * size[b] - 1 条边需要连接，权值最小是 w + 1
添加的这条新边一定要比a和b这条边权值大，所以将两个连通块中每两个点权值设置为w+1，否则最小生成树会发生变化
*/
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 6010;
int n;
struct edge{
    int a, b, w;
    bool operator < (const edge &t) const{
        return w < t.w;
    }
}e[N];
int p[N], sz[N];

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 0; i < n - 1; i++){
            int a, b, w;
            cin >> a >> b >> w;
            e[i] = {a, b, w};
        }
        
        sort(e, e + n - 1);
        for(int i = 1; i <= n; i++) p[i] = i, sz[i] = 1; // 设置父节点和连通块中点的数量
        
        int res = 0;
        for(int i = 0; i < n - 1; i++){
            int a = find(e[i].a), b = find(e[i].b), w = e[i].w;
            if(a != b){
                res += (sz[a] * sz[b] - 1) * (w + 1); // 新添加的边权值总和
                sz[b] += sz[a];
                p[a] = b;
            }
        }
        
        cout << res << endl;
    }
    
    return 0;
}