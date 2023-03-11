// 平面上遍布着 n
//  座城市，编号 1∼n
// 。

// 第 i
//  座城市的位置坐标为 (xi,yi)
// 。

// 不同城市的位置有可能重合。

// 现在要通过建立发电站和搭建电线的方式给每座城市都通电。

// 一个城市如果建有发电站，或者通过电线直接或间接的与建有发电站的城市保持连通，则该城市通电。

// 在城市 i
//  建立发电站的花费为 ci
//  元。

// 在城市 i
//  与城市 j
//  之间搭建电线所需的花费为每单位长度 ki+kj
//  元。

// 电线只能沿上下左右四个方向延伸，电线之间可以相互交叉，电线都是双向的。

// 每根电线都是由某个城市沿最短路线搭建到另一个城市。

// 也就是说，如果在城市 i
//  与城市 j
//  之间搭建电线，则电线的长度为 |xi−xj|+|yi−yj|
// 。

// 请问，如何合理设计通电方案，可以使得所有城市都成功通电，且花费最少？

// 输出最少花费和具体方案。

// 如果方案不唯一，则输出任意一种合理方案均可。

// 输入格式
// 第一行包含整数 n
// 。

// 接下来 n
//  行，其中第 i
//  行包含两个整数 xi,yi
// ，用来描述城市 i
//  的横纵坐标。

// 再一行包含 n
//  个整数 c1,c2,…,cn
// ，用来描述每个城市建立发电站的花费。

// 最后一行包含 n
//  个整数 k1,k2,…,kn
// 。

// 输出格式
// 第一行输出所需要的最少花费。

// 第二行输出一个整数 v
// ，表示需要建立发电站的数量。

// 第三行输出 v
//  个整数，表示建立发电站的城市编号，注意输出编号要在范围 [1,n]
//  内。且输出编号不应重复。输出编号顺序随意。

// 第四行输出一个整数 e
// ，表示需要搭建的电线数量。

// 接下来 e
//  行，每行输出两个整数 a,b
// ，表示要在城市 a
//  和 b
//  之间搭建电线。注意，任意两个城市之间最多只需要搭建一根电线，也就是说，对于每个 (a,b)
// ，不要有多余的 (a,b)
//  或 (b,a)
//  输出。a
//  和 b
//  不能相同，且要在范围 [1,n]
//  内。输出电线顺序随意。

// 如果答案不唯一，输出任意合理方案即可。

// 数据范围
// 对于前三个测试点，1≤n≤3
// 。
// 对于全部测试点，1≤n≤2000
// ，1≤xi,yi≤106
// ，1≤ci,ki≤109
// 。

// 输入样例1：
// 3
// 2 3
// 1 1
// 3 2
// 3 2 3
// 3 2 3
// 输出样例1：
// 8
// 3
// 1 2 3 
// 0
// 输入样例2：
// 3
// 2 1
// 1 2
// 3 3
// 23 2 23
// 3 2 3
// 输出样例2：
// 27
// 1
// 2 
// 2
// 1 2
// 2 3

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

#define x first
#define y second

typedef long long LL;
typedef pair<int, int> PII;
const int N = 2010;

int n;
int wk[N], wc[N], fa[N];
PII p[N];
LL dist[N];
bool st[N];
vector<int> ans1;
vector<PII> ans2;

LL get_dist(int a, int b){
    int dx = abs(p[a].x - p[b].x);
    int dy = abs(p[a].y - p[b].y);
    return (LL)(dx + dy) * (wk[a] + wk[b]);
}

LL prim(){
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    st[0] = true;
    
    for(int i = 1; i <= n; i++) dist[i] = wc[i];
    LL res = 0;
    
    for(int i = 0; i < n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++)
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        res += dist[t];
        st[t] = true;
        if(!fa[t]) ans1.push_back(t);
        else ans2.push_back({fa[t], t});
        for(int j = 1; j <= n; j++)
            if(dist[j] > get_dist(t, j)){
                dist[j] = get_dist(t, j);
                fa[j] = t;
            }
    }
    
    return res;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d%d", &p[i].x, &p[i].y);
    for(int i = 1; i <= n; i++) scanf("%d", &wc[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &wk[i]);
    
    printf("%lld\n", prim());
    printf("%d\n", (int)ans1.size());
    for(int x : ans1) printf("%d ", x);
    printf("\n%d\n", (int)ans2.size());
    for(auto& [x, y] : ans2)
        printf("%d %d\n", x, y);

    
    return 0;
}