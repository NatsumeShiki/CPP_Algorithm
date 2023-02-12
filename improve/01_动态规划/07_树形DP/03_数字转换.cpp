// 如果一个数 x
//  的约数之和 y
// （不包括他本身）比他本身小，那么 x
//  可以变成 y
// ，y
//  也可以变成 x
// 。

// 例如，4
//  可以变为 3
// ，1
//  可以变为 7
// 。

// 限定所有数字变换在不超过 n
//  的正整数范围内进行，求不断进行数字变换且不出现重复数字的最多变换步数。

// 输入格式
// 输入一个正整数 n
// 。

// 输出格式
// 输出不断进行数字变换且不出现重复数字的最多变换步数。

// 数据范围
// 1≤n≤50000
// 输入样例：
// 7
// 输出样例：
// 3
// 样例解释
// 一种方案为：4→3→1→7
// 。

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 50010;
int n;
int h[N], e[N], ne[N], idx;
int sum[N];
bool st[N];
int ans;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u){
    int d1 = 0, d2 = 0;
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        int d = dfs(j) + 1;
        if(d >= d1) d2 = d1, d1 = d;
        else if(d > d2) d2 = d;
    }
    
    ans = max(ans, d1 + d2);
    return d1;
}

int main(){
    cin >> n;
    // 求约数的方法：如果从1-n枚举每一个数，然后在枚举1-sqrt(n)，求出它们的约数和，时间复杂度是O(n * sqrt(n))，会TLE，所以这里反过来
    // 枚举1-n里面的每一个数，看看可以是谁的约数，然后累加，最终可以求出来
    for(int i = 1; i <= n; i++)
        for(int j = 2; j <= n / i; j++)
            sum[i * j] += i;
            
    memset(h, -1, sizeof h);
    for(int i = 2; i <= n; i++) // 从2开始是因为sum[1] = 0，不存在
        if(i > sum[i]){
            add(sum[i], i);
            st[i] = true; // st[i]为true表示它不是根节点
        }
        
    for(int i = 1; i <= n; i++)
        if(!st[i]) // 因为可能有多颗数，所以如果st[i]为false，那么就有一颗以i为根节点的树
            dfs(i);
            
    cout << ans << endl;
  
    return 0;
}