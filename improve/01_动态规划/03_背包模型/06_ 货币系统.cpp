// 给你一个n种面值的货币系统，求组成面值为m的货币有多少种方案。

// 输入格式
// 第一行，包含两个整数n和m。

// 接下来n行，每行包含一个整数，表示一种货币的面值。

// 输出格式
// 共一行，包含一个整数，表示方案数。

// 数据范围
// n≤15,m≤3000
// 输入样例：
// 3 10
// 1
// 2
// 5
// 输出样例：
// 10

/*
f[i][j]可以分成两种
  1.从前i中面值的钱凑齐j元的方案数 f[i - 1][j]
  2.使用一张i面值的钱凑齐j元的方案数 f[i][j - money]，因为一种面值的钱可能使用多张，所以是使用第i次计算的结果
最后 f[i][j]可以表示成 f[i - 1][j] + f[i][j - money]，首先要把f[0][0]设置为1，表示从前0种钱凑齐0元钱的方案有1种，那就是什么都不选
*/
// 自己的代码 二维
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 20, M = 3010;
LL f[N][M];
int n, m;

int main(){
    cin >> n >> m;
    f[0][0] = 1;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        for(int j = 0; j <= m; j++){
            f[i][j] = f[i - 1][j];
            if(j >= x) f[i][j] += f[i][j - x];
        }
    }
    
    cout << f[n][m] << endl;
    
    return 0;
}

// 自己的代码 一维
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 20, M = 3010;
LL f[M];
int n, m;

int main(){
    cin >> n >> m;
    
    f[0] = 1;
    while(n--){
        int x;
        cin >> x;
        
        for(int j = x; j <= m; j++)
            f[j] += f[j - x];
    }
    
    cout << f[m] << endl;
    
    return 0;
}