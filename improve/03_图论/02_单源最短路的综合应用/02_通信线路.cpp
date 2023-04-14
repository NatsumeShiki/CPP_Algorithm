// 在郊区有 N
//  座通信基站，P
//  条 双向 电缆，第 i
//  条电缆连接基站 Ai
//  和 Bi
// 。

// 特别地，1
//  号基站是通信公司的总站，N
//  号基站位于一座农场中。

// 现在，农场主希望对通信线路进行升级，其中升级第 i
//  条电缆需要花费 Li
// 。

// 电话公司正在举行优惠活动。

// 农产主可以指定一条从 1
//  号基站到 N
//  号基站的路径，并指定路径上不超过 K
//  条电缆，由电话公司免费提供升级服务。

// 农场主只需要支付在该路径上剩余的电缆中，升级价格最贵的那条电缆的花费即可。

// 求至少用多少钱可以完成升级。

// 输入格式
// 第 1
//  行：三个整数 N，P，K
// 。

// 第 2..P+1
//  行：第 i+1
//  行包含三个整数 Ai,Bi,Li
// 。

// 输出格式
// 包含一个整数表示最少花费。

// 若 1
//  号基站与 N
//  号基站之间不存在路径，则输出 −1
// 。

// 数据范围
// 0≤K<N≤1000
// ,
// 1≤P≤10000
// ,
// 1≤Li≤1000000
// 输入样例：
// 5 7 1
// 1 2 5
// 3 1 4
// 2 4 8
// 3 2 3
// 5 2 9
// 3 4 7
// 4 5 6
// 输出样例：
// 4

/*
定义在[0, 1000001]这个区间中的性质如下：
  对于区间中的某一个点x，求出从1走到N，最少经过的长度大于x的边的数量是否小于等于k

求出从1到N最少经过几条长度大于x的边，可以将所有边分类：如果边长大于x，则边权看成1，否则边权是0
可以用双端队列BFS来求从1到N的最短路
双端队列的性质是队列中的每个点的权值可以二分，而这道题满足这个性质
*/
#include<iostream>
#include<cstring>
#include<deque>
using namespace std;

const int N = 1010, M = 20010;
int n, m, k;
int h[N], e[M], w[M], ne[M], idx;
deque<int> q;
int dist[N];
bool st[N];

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
} 

bool check(int bound){
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    q.push_back(1);
    
    while(q.size()){
        int t = q.front();
        q.pop_front();
        
        if(st[t]) continue;
        st[t] = true;
        
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i], v = w[i] > bound;
            if(dist[j] > dist[t] + v){
                dist[j] = dist[t] + v;
                if(!v) q.push_front(j); // 如果权重是0，放在队头
                else q.push_back(j); // 否则放在队尾
            }
        }
    }
    
    return dist[n] <= k;
}

int main(){
    cin >> n >> m >> k;
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    // 这里设置左边界为0是因为如果k足够大，从1到N存在一条路长度是小于等于k的，此时花费为0
    // 设置右边界是因为如果1到N不连通，l就会一直更新到右端点，但是如果设置为1e6时是无法判断1到N是否连通，但是设置比1e6大的数，这样当最终到了右边界就说明不连通
    int l = 0, r = 1e6 + 1;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid; // 如果满足条件，说明存在长度mid的边的数量是小于等于k的
        else l = mid + 1;
    }
    
    if(r == 1e6 + 1) r = -1;
    cout << r << endl;
    
    
    return 0;
}