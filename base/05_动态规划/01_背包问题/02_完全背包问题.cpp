// 有 N 种物品和一个容量是 V 的背包，每种物品都有无限件可用。

// 第 i 种物品的体积是 vi，价值是 wi。

// 求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
// 输出最大价值。

// 输入格式
// 第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

// 接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 种物品的体积和价值。

// 输出格式
// 输出一个整数，表示最大价值。

// 数据范围
// 0<N,V≤1000
// 0<vi,wi≤1000
// 输入样例
// 4 5
// 1 2
// 2 4
// 3 4
// 4 5
// 输出样例：
// 10

// 方式一：朴素做法 使用三重循环，把第i个物品分成拿0个，拿1个，拿2个，......拿k-1个，拿k个，直到 k * v[i] > j 为止，每次判断价值与上一轮的结果
// 使用这种方法不一定能过，因为最差的情况下v[i]=1，此时是 n * j^2，也就是1000^3=1e9，可能有些案例会超时
// #include<iostream>
// using namespace std;

// const int N = 1010;
// int f[N][N], v[N], w[N];

// int main(){
//     int n, m;
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
//     for(int i = 1; i <= n; i++){
//         for(int j = 0; j <= m; j++){
//             for(int t = 0; t * v[i] <= j; t++){
//                 f[i][j] = max(f[i][j], f[i - 1][j - t * v[i]] + t * w[i]);
//             }
//         }
//     }
//     cout << f[n][m] << endl;
//     return 0;
// }

/*
f[i][j] = max(f[i-1][j], f[i-1][j-v[i]] + w, f[i-1][j-v[i] * 2] + 2w, f[i-1][j-v[i] * 3] + 3w, ......)
f[i][j-v[i]] = max(      f[i-1][j-v[i]],     f[i-1][j-v[i] * 2] + w,  f[i-1][j-v[i] * 3] + 2w, ......)
由上面可以推出来 f[i][j] = max(f[i-1][j], f[i][j-v[i]] + w)
*/
// 方式二：二重循环
// #include<iostream>
// using namespace std;

// const int N = 1010;
// int f[N][N], v[N], w[N];

// int main(){
//     int n, m;
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
//     for(int i = 1; i <= n; i++){
//         for(int j = 0; j <= m; j++){
//             f[i][j] = f[i-1][j];
//             if(j >= v[i]) f[i][j] = max(f[i][j], f[i][j-v[i]] + w[i]);
//         }
//     }
//     cout << f[n][m] << endl;
//     return 0;
// }

// 方式三：一维数组(最优解)
/*
跟01背包一样，都是使用滚动数组，差就差在完全背包问题 f[j] = max(f[j], f[j-v[i]] + w[i])，此时使用的是第i轮的结果，而01背包问题使用的是第i-1轮的结果
在方式二中我们推出来：f[i][j] = max(f[i-1][j], f[i][j-v[i]] + w)，而01背包问题是 f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i])
这也就导致了完全背包不需要从后往前，它需要的正是第i轮的结果，所以j从v[i]往m遍历即可
*/
#include<iostream>
using namespace std;

const int N = 1010;
int f[N], v[N], w[N];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    for(int i = 1; i <= n; i++)
        for(int j = v[i]; j <= m; j++)
            f[j] = max(f[j], f[j-v[i]] + w[i]);
    cout << f[m] << endl;
    return 0;
}