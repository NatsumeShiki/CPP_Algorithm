// 翰翰和达达饲养了 N
//  只小猫，这天，小猫们要去爬山。

// 经历了千辛万苦，小猫们终于爬上了山顶，但是疲倦的它们再也不想徒步走下山了（呜咕>_<）。

// 翰翰和达达只好花钱让它们坐索道下山。

// 索道上的缆车最大承重量为 W
// ，而 N
//  只小猫的重量分别是 C1、C2……CN
// 。

// 当然，每辆缆车上的小猫的重量之和不能超过 W
// 。

// 每租用一辆缆车，翰翰和达达就要付 1
//  美元，所以他们想知道，最少需要付多少美元才能把这 N
//  只小猫都运送下山？

// 输入格式
// 第 1
//  行：包含两个用空格隔开的整数，N
//  和 W
// 。

// 第 2..N+1
//  行：每行一个整数，其中第 i+1
//  行的整数表示第 i
//  只小猫的重量 Ci
// 。

// 输出格式
// 输出一个整数，表示最少需要多少美元，也就是最少需要多少辆缆车。

// 数据范围
// 1≤N≤18
// ,
// 1≤Ci≤W≤108
// 输入样例：
// 5 1996
// 1
// 2
// 1994
// 12
// 29
// 输出样例：
// 2

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 20;
int n, w[N], W;
int sum[N];
int ans = N;
bool st[N];

void dfs(int u, int k){
    if(k >= ans) return; // 最优性剪枝
    if(u == n){ 
        ans = k;
        return;
    }
    
    for(int i = 0; i < k; i++)
        if(w[u] + sum[i] <= W){ // 可行性剪枝
            sum[i] += w[u];
            dfs(u + 1, k);
            sum[i] -= w[u];
        }
        
    sum[k] += w[u];
    dfs(u + 1, k + 1);
    sum[k] -= w[u];
}

int main(){
    cin >> n >> W;
    for(int i = 0; i < n; i++) cin >> w[i];
    
    sort(w, w + n);
    reverse(w, w + n); // 优化搜索顺序，先从重的猫开始放，减少分支
    
    dfs(0, 0);
    
    cout << ans << endl;
    
    return 0;
}