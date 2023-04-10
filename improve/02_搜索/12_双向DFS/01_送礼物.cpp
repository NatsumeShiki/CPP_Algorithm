// 达达帮翰翰给女生送礼物，翰翰一共准备了 N
//  个礼物，其中第 i
//  个礼物的重量是 G[i]
// 。

// 达达的力气很大，他一次可以搬动重量之和不超过 W
//  的任意多个物品。

// 达达希望一次搬掉尽量重的一些物品，请你告诉达达在他的力气范围内一次性能搬动的最大重量是多少。

// 输入格式
// 第一行两个整数，分别代表 W
//  和 N
// 。

// 以后 N
//  行，每行一个正整数表示 G[i]
// 。

// 输出格式
// 仅一个整数，表示达达在他的力气范围内一次性能搬动的最大重量。

// 数据范围
// 1≤N≤46
// ,
// 1≤W,G[i]≤231−1
// 输入样例：
// 20 5
// 7
// 5
// 4
// 18
// 1
// 输出样例：
// 19

/*
时间复杂度：2^(n/2) + 2^(n/2) * (n/2)
1.将所有物品按重量大小排序
2.将前K减物品能凑出的所有重量打表，然后排序判重
3.搜索剩下的N-K件物品的选择方式，然后在表中二分出不超过W的最大值
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
const int N = 46;
int n, m, k;
int w[N];
int weights[1 << 25], cnt = 1; // 因为0也是可以凑出来的所有cnt要从1开始，保证weights[0] = 0
int ans;

void dfs1(int u, int s){ // u是遍历到了第几个数，s是当前总和
    if(u == k){ // 如果遍历到了第k个数
        weights[cnt++] = s; // 将它的结果加到weights数组中
        return;
    }
    dfs1(u + 1, s); // 不使用w[u]
    if((LL)s + w[u] <= m) dfs1(u + 1, s + w[u]); // 使用w[u]
}

void dfs2(int u, int s){
    if(u >= n){ // 如果遍历到了最后
        int l = 0, r = cnt - 1; // 二分
        while(l < r){ // 获取与s相加不超过m的最大值
            int mid = l + r + 1 >> 1;
            if(weights[mid] <= m - s) l = mid;
            else r = mid - 1;
        }
        ans = max(ans, weights[l] + s); // 获取更大值
        return;
    }
    
    dfs2(u + 1, s); // 不使用w[u]
    if((LL)s + w[u] <= m) dfs2(u + 1, s + w[u]); // 使用w[u]
}

int main(){
    cin >> m >> n;
    for(int i = 0; i < n; i++) cin >> w[i];
    
    sort(w, w + n); // 排序
    reverse(w, w + n); // 从大到小
    
    k = n / 2; // 防止n=1时出现死循环
    dfs1(0, 0); // 从1-k搜索
    
    sort(weights, weights + cnt); // 从小到大排序
    // unique函数是将重复的元素放在容器末尾，下面这么做的结果是返回weights数组中元素的数量
    cnt = unique(weights, weights + cnt) - weights; 
    
    dfs2(k, 0); // 从第k个数开始遍历后面的数
    
    cout << ans << endl; // 输出结果
    
    return 0;
}