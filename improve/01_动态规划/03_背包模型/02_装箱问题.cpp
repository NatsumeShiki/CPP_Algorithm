// 有一个箱子容量为 V，同时有 n 个物品，每个物品有一个体积（正整数）。

// 要求 n 个物品中，任取若干个装入箱内，使箱子的剩余空间为最小。

// 输入格式
// 第一行是一个整数 V，表示箱子容量。

// 第二行是一个整数 n，表示物品数。

// 接下来 n 行，每行一个正整数（不超过10000），分别表示这 n 个物品的各自体积。

// 输出格式
// 一个整数，表示箱子剩余空间。

// 数据范围
// 0<V≤20000,
// 0<n≤30
// 输入样例：
// 24
// 6
// 8
// 3
// 12
// 7
// 9
// 7
// 输出样例：
// 0

// 自己的写法 二维，f数组使用bool
/*
闫氏Dp法
集合：f[i,j]表示从前i个物品选，体积不超过j的集合
属性：bool
状态计算：
  1.不选择第i个物品 f[i - 1,j]
  2.选择第i个物品 f[i - 1][j - v[i]]
  二者有一为true则为true

最后，从所有 f[n][V] - f[n][0] 查找第一个为true的，此时的它就是在前n个物品中选择，体积最大为j，所以输出 V - j 表示箱子的剩余体积
注意，一开始要设置 f[0][0]为true，表示从前0个物品中选择，体积为0的方案是存在的
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 35, M = 20010;
bool f[N][M];

int main(){
    int V, n;
    cin >> V >> n;
    
    f[0][0] = true;
    for(int i = 1; i <= n; i++){
        int v;
        cin >> v;
        for(int j = 0; j <= V; j++){
            f[i][j] = f[i - 1][j];
            if(j >= v) f[i][j] |= f[i - 1][j - v];
        }
    }
        
    int res = V;
    for(int i = V; i >= 0; i--)
        if(f[n][i]){
            res = V - i;
            break;
        }
        
    cout << res << endl;
    
    return 0;
}

// 自己的写法 一维，f数组使用bool
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20010;
bool f[N];

int main(){
    int V, n;
    cin >> V >> n;
    
    f[0] = true;
    for(int i = 1; i <= n; i++){
        int v;
        cin >> v;
        for(int j = V; j >= v; j--)
            f[j] |= f[j - v];
    }
        
    int res = V;
    for(int i = V; i >= 0; i--)
        if(f[i]){
            res = V - i;
            break;
        }
    cout << res << endl;
    
    return 0;
}

// 自己的写法 二维，f数组是int
/*
闫氏Dp法
集合：f[i,j]表示从前i个物品选，体积不超过j的集合
属性：Max
状态计算：
  1.不选择第i个物品 f[i - 1,j]
  2.选择第i个物品 f[i - 1][j - v[i]] + v[i]
最终输出 V - f[n][V]，f[n][V]表示从前n个物品选，体积不超过V的最大体积，用V减去它表示剩余的体积
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 35, M = 20010;
int f[N][M];

int main(){
    int V, n;
    cin >> V >> n;
    
    for(int i = 1; i <= n; i++){
        int v;
        cin >> v;
        for(int j = 0; j <= V; j++){
            f[i][j] = f[i - 1][j];
            if(j >= v) f[i][j] = max(f[i][j], f[i - 1][j - v] + v);
        }
    }
    
    cout << V - f[n][V] << endl;
    
    return 0;
}

// 自己的写法 一维，f数组是int
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20010;
int f[N];

int main(){
    int V, n;
    cin >> V >> n;
    
    for(int i = 1; i <= n; i++){
        int v;
        cin >> v;
        for(int j = V; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v] + v);
    }
            
    cout << V - f[V] << endl;
    
    return 0;
}

// 大佬的代码
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20010;

int m, n;
int f[N];

int main(){
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        for(int j = m; j >= v; j--) f[j] = max(f[j], f[j - v] + v);
    }
    
    cout << m - f[m] << endl;
    
    
    return 0;
}