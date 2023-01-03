// 组合数 Cmn 表示的是从 n 个物品中选出 m 个物品的方案数。 

// 举个例子，从 (1, 2, 3) 三个物品中选择两个物品可以有 (1, 2), (1, 3), (2, 3) 这三种选择方法。 

// 根据组合数的定义，我们可以给出计算组合数 Cmn 的一般公式：

// Cmn=n!m!(n−m)!
// 其中 n! = 1 × 2 × ⋅ ⋅ ⋅ × n。 

// 小葱想知道如果给定 n, m 和 k ，对于所有的 0 ≤ i ≤ n, 0 ≤ j ≤ min(i, m) 有多少对 (i, j) 满足 Cji 是 k 的倍数。

// 输入格式
// 第一行有两个整数 t, k ，其中 t 代表该测试点总共有多少组测试数据，k 的意义见问题描述。

// 接下来 t 行每行两个整数 n, m，其中 n, m 的意义见问题描述。

// 输出格式
// 共 t 行，每行一个整数代表所有的 0 ≤ i ≤ n, 0 ≤ j ≤ min(i, m) 有多少对 (i, j) 满足 Cji 是 k 的倍数。

// 数据范围
// 1≤n,m≤2000,2≤k≤21,1≤t≤104
// 输入样例：
// 1 2
// 3 3
// 输出样例：
// 1

// 先把1-2000里面的C(n, m)%k预处理出来，然后用前缀和求出有多少个数，最后O(1)的时间复杂度求出有多少对
// C(n, m) = C(n - 1, m) + C(n - 1, m - 1) 从n个数里面去m个数，如果第i个数不选择，就是C(n - 1, m)，如果选择就是C(n - 1, m - 1)
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2010;
int c[N][N];
int s[N][N];

int main(){
    int t, k;
    cin >> t >> k;
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j <= i; j++){ // 预处理 C(n, m) % k的值
            if(!j) c[i][j] = 1 % k; 
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
        }
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            if(j <= i && c[i][j] == 0) s[i][j] = 1; // 如果c[i][j] == 0，表示可以整除k，所以设置1表示有一个数符合条件
            if(i - 1 >= 0) s[i][j] += s[i - 1][j]; // s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j] 前缀和公式
            if(j - 1 >= 0) s[i][j] += s[i][j - 1];
            if(i - 1 >= 0 && j - 1 >= 0) s[i][j] -= s[i - 1][j - 1];
        }
        
    while(t--){ // O(1)时间复杂度求有多少对符合条件
        int n, m;
        cin >> n >> m;
        cout << s[n][m] << endl;
    }
    
    return 0;
}