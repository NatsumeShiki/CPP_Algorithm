// n
//  个小朋友站成一排，等着吃水果。

// 一共有 m
//  种水果，每种水果的数量都足够多。

// 现在，要给每个小朋友都发一个水果，要求：在所有小朋友都拿到水果后，恰好有 k
//  个小朋友拿到的水果和其左边相邻小朋友拿到的水果不同（最左边的小朋友当然不算数，即最左边的小朋友不包含在 k
//  个小朋友内）。

// 请你计算，一共有多少种不同的分发水果的方案。

// 输入格式
// 一行，三个整数 n,m,k
// 。

// 输出格式
// 一个整数，表示合理的分发水果的方案总数量对 998244353
//  取模后的结果。

// 数据范围
// 前 5
//  个测试点满足 1≤n,m≤5
// 。
// 所有测试点满足 1≤n,m≤2000
// ，0≤k≤n−1
// 。

// 输入样例1：
// 3 3 0
// 输出样例1：
// 3
// 输入样例2：
// 3 2 1
// 输出样例2：
// 4

/*
DP
  状态表示f[i, j]
    集合：表示前i个小朋友中，恰好有j个小朋友拿到的苹果跟左边小朋友不一样的所有方案
    属性：Count
  状态计算：
    i与左边不同 f[i - 1][j - 1] * (m - 1)
    i与左边相同 f[i - 1][j] * 1
*/
#include<iostream>
using namespace std;

const int N = 2010, mod = 998244353;
int f[N][N];
int n, m, k;

int main(){
    cin >> n >> m >> k;
    f[1][0] = m; // 一个小朋友，0个拿到的与左边不同，则第1个小朋友可以拿m中水果
    for(int i = 2; i <= n; i++)
        for(int j = 0; j <= k && j < i; j++)
            f[i][j] = (f[i - 1][j - 1] * (m - 1ll) % mod + f[i - 1][j]) % mod;
    
    cout << f[n][k] << endl;
    
    return 0;
}