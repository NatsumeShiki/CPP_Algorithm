// 给定一张 L
//  个点、P
//  条边的有向图，每个点都有一个权值 f[i]
// ，每条边都有一个权值 t[i]
// 。

// 求图中的一个环，使“环上各点的权值之和”除以“环上各边的权值之和”最大。

// 输出这个最大值。

// 注意：数据保证至少存在一个环。

// 输入格式
// 第一行包含两个整数 L
//  和 P
// 。

// 接下来 L
//  行每行一个整数，表示 f[i]
// 。

// 再接下来 P
//  行，每行三个整数 a，b，t[i]
// ，表示点 a
//  和 b
//  之间存在一条边，边的权值为 t[i]
// 。

// 输出格式
// 输出一个数表示结果，保留两位小数。

// 数据范围
// 2≤L≤1000
// ,
// 2≤P≤5000
// ,
// 1≤f[i],t[i]≤1000
// 输入样例：
// 5 7
// 30
// 10
// 10
// 5
// 10
// 1 2 3
// 2 3 2
// 3 4 5
// 3 5 2
// 4 5 5
// 5 1 3
// 5 2 2
// 输出样例：
// 6.00

/*
类似使用某种方式重新规定权值，或是将点的权值加到边的权值，或是将边的权值加到点的权值上，然后做spfa或者最小生成树等算法，叫做01分数规划
要获得∑fi / ∑ti 最大
使用二分
∑fi / ∑ti > mid
∑fi > mid * ∑ti
∑fi - mid * ∑ti > 0
∑(fi - mid * ti) > 0 等价于判断图中是否存在正环
*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1010, M = 5010;
int h[N], e[M], wt[M], ne[M], idx;
int wf[N]; // 点的权值
int n, m;
bool st[N];
double dist[N];
int cnt[N];

void add(int a, int b, int c){
    e[idx] = b, wt[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool check(double mid){
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);
    
    queue<int> q;
    for(int i = 1; i <= n; i++){ // 将所有点加入到队列中
        q.push(i);
        st[i] = true;
    }
    
    while(q.size()){
        int t = q.front();
        q.pop();
        
        st[t] = false;
        
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] < dist[t] + wf[t] - mid * wt[i]){ // 如果j点的距离可以取更大的值
                dist[j] = dist[t] + wf[t] - mid * wt[i]; // 更新距离
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n) return true; // 如果遍历边的次数大于等于n，说明存在正环，返回true
                if(!st[j]){
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i++) cin >> wf[i];
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    
    double l = 0, r = 1010; // 二分
    while(r - l > 1e-4){ // 一般如果要求小数点后取两位，则边界是1e-4，小数点后取三位，边界是1e-5
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    printf("%.2lf\n", l);
    
    return 0;
}