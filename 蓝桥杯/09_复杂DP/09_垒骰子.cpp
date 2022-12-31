// 赌圣atm晚年迷恋上了垒骰子，就是把骰子一个垒在另一个上边，不能歪歪扭扭，要垒成方柱体。

// 经过长期观察，atm 发现了稳定骰子的奥秘：有些数字的面贴着会互相排斥！

// 我们先来规范一下骰子：1 的对面是 4，2 的对面是 5，3 的对面是 6。

// 假设有 m 组互斥现象，每组中的那两个数字的面紧贴在一起，骰子就不能稳定的垒起来。

// atm想计算一下有多少种不同的可能的垒骰子方式。

// 两种垒骰子方式相同，当且仅当这两种方式中对应高度的骰子的对应数字的朝向都相同。

// 由于方案数可能过多，请输出模 109+7 的结果。

// 输入格式
// 第一行包含两个整数 n,m，分别表示骰子的数目和排斥的组数。

// 接下来 m 行，每行两个整数 a,b，表示 a 和 b 数字不能紧贴在一起。

// 输出格式
// 共一个数，表示答案模 109+7 的结果。

// 数据范围
// 1≤n≤109,
// 1≤m≤36,
// 1≤a,b≤6
// 输入样例：
// 2 1
// 1 2
// 输出样例：
// 544

/*
f[i][j]表示由i个筛子垒在一起，做上面的数字是j的所有合法方案的集合
状态计算：当确定上面是哪个点数后，可以转四面，所以是 f[i-1][1] * 4 + ... + f[i-1][6] * 4，但是这是在没有限制的条件下
如果第i个上面是4，那么i-1个上面就不能是2，第i个上面是5，那么i-1个上面就不能是1，所以可以使用矩阵乘法和快速幂
*/
#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 6, mod = 1e9 + 7;
int n, m;

int get_op(int x){ // 获得一个点数的对面的点
    if(x >= 3) return x - 3;
    return x + 3;
}

void mul(int c[][N], int a[][N], int b[][N]){ // C = A * B，两个二维矩阵相乘
    static int t[N][N];
    memset(t, 0, sizeof t);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++)  
                t[i][j] = (t[i][j] + (LL)a[i][k] * b[k][j]) % mod;
    memcpy(c, t, sizeof t);
}

int main(){
    cin >> n >> m;
    
    int a[N][N];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            a[i][j] = 4;
    
    while(m--){
        int x, y;
        cin >> x >> y;
        x--, y--;
        a[x][get_op(y)] = 0; // 添加限制
        a[y][get_op(x)] = 0;
    }
    
    int f[N][N] = {4, 4, 4, 4, 4, 4}; // F[1]
    for(int k = n - 1; k; k >>= 1){
        if(k & 1) mul(f, f, a); // F = F * A
        mul(a, a, a); // A = A * A
    }
    
    int res = 0;
    for(int i = 0; i < N; i++) res = (res + f[0][i]) % mod;
    
    cout << res << endl;
    
    return 0;
}