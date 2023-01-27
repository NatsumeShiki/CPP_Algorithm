// 小明手里有n元钱全部用来买书，书的价格为10元，20元，50元，100元。

// 问小明有多少种买书方案？（每种书可购买多本）

// 输入格式
// 一个整数 n，代表总共钱数。

// 输出格式
// 一个整数，代表选择方案种数。

// 数据范围
// 0≤n≤1000
// 输入样例1：
// 20
// 输出样例1：
// 2
// 输入样例2：
// 15
// 输出样例2：
// 0
// 输入样例3：
// 0
// 输出样例3：
// 1

/*
动态规划：
  状态表示f[i, j]
    集合：所有只从前i个物品中选，且总体积恰好是j的方案的集合
    属性：Count
  状态计算：
    第i个物品选0个 f[i - 1][j]
    第i个物品选1个 f[i - 1][j - v]
    第i个物品选2个 f[i - 1][j - 2v]
    .
    .
    .
    第i个物品选s个 f[i - 1][j - sv]
    所以 f[i][j] = f[i - 1][j] + f[i - 1][j - v] + f[i - 1][j - 2v] + ... + f[i - 1][j - sv]
         f[i][j - v] =           f[i - 1][j - v] + f[i - 1][j - 2v] + ... + f[i - 1][j - sv]
    因此 f[i][j] = f[i - 1][j] + f[i][j - v]    
*/
// 自己的做法 二维
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5, M = 1010;
int f[N][M];
int v[5] = {0, 10, 20, 50, 100};

int main(){
    int n;
    cin >> n;
    
    f[0][0] = 1;
    for(int i = 1; i <= 4; i++)
        for(int j = 0; j <= n; j++){
            f[i][j] = f[i - 1][j];
            if(j >= v[i]) f[i][j] += f[i][j - v[i]];
        }
    cout << f[4][n] << endl;
    return 0;
}

// 自己的代码 一维
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int f[N];
int v[5] = {0, 10, 20, 50, 100};

int main(){
    int n;
    cin >> n;
    
    f[0] = 1;
    for(int i = 1; i <= 4; i++){
        for(int j = v[i]; j <= n; j++)
            f[j] += f[j - v[i]];
    }
    
    cout << f[n] << endl;
    
    return 0;
}

// 大佬的二维
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int v[5] = {0, 10, 20, 50, 100};
int f[5][N];

int main(){
    int m;
    cin >> m;
    
    f[0][0] = 1;
    for(int i = 1; i <= 4; i++)
        for(int j = 0; j <= m; j++){
            f[i][j] = f[i - 1][j];
            if(j >= v[i]) f[i][j] += f[i][j - v[i]];
        }
        
    cout << f[4][m] << endl;
    
    return 0;
}

// 大佬的一维
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int v[4] = {10, 20, 50, 100};
int f[N];

int main(){
    int m;
    cin >> m;
    
    f[0] = 1;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j <= m; j++)
            if(j >= v[i]) 
                f[j] += f[j - v[i]];
        
        
    cout << f[m] << endl;
    
    return 0;
}