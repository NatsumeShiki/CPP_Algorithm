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
using namespace std;

const int N = 20;
int c[N], n, w;
int res = 18;
int car[N];

void dfs(int u, int ans){
    if(u == n + 1){
        res = min(res, ans);
        return;
    }
    
    for(int i = 1; i <= ans + 1; i++){
        if(car[i] + c[u] <= w){
            car[i] += c[u];
            if(i == ans + 1) {
                if(i > res) return; // 没有加上这个剪枝操作就TLE了
                dfs(u + 1, ans + 1);
            }
            else dfs(u + 1, ans);
            car[i] -= c[u];
        }
    }
}

int main(){
    cin >> n >> w;
    for(int i = 1; i <= n; i++) cin >> c[i];
    
    // 将猫的重量从大到小进行排序这一步操作也是必要的，因为它减少了dfs的可能性，同样也是一种剪枝操作
    sort(c + 1, c + n + 1);
    reverse(c + 1, c + n + 1);
    
    dfs(1, 0);
    
    cout << res << endl;
    
    return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 20;
int sum[N], w[N];
int n, m;
int ans = N;

void dfs(int u, int k){
    // 最优性剪枝
    if(k >= ans) return;
    if(u == n){
        ans = k;
        return;
    }
    
    for(int i = 0; i < k; i++)
        if(sum[i] + w[u] <= m){ // 可行性剪枝
            sum[i] += w[u];
            dfs(u + 1, k);
            sum[i] -= w[u];
        }
        
    sum[k] = w[u];
    dfs(u + 1, k + 1);
    sum[k] = 0;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> w[i];
    sort(w, w + n);
    reverse(w, w + n);
    
    dfs(0, 0);
    
    cout << ans << endl;
    
    return 0;
}