// 7
//  月 17
//  日是 Mr.W 的生日，ACM-THU 为此要制作一个体积为 Nπ
//  的 M
//  层生日蛋糕，每层都是一个圆柱体。

// 设从下往上数第 i
//  层蛋糕是半径为 Ri
// ，高度为 Hi
//  的圆柱。

// 当 i<M
//  时，要求 Ri>Ri+1
//  且 Hi>Hi+1
// 。

// 由于要在蛋糕上抹奶油，为尽可能节约经费，我们希望蛋糕外表面（最下一层的下底面除外）的面积 Q
//  最小。

// 令 Q=Sπ
//  ，请编程对给出的 N
//  和 M
// ，找出蛋糕的制作方案（适当的 Ri
//  和 Hi
//  的值），使 S
//  最小。

// 除 Q
//  外，以上所有数据皆为正整数。

// 输入格式
// 输入包含两行，第一行为整数 N
// ，表示待制作的蛋糕的体积为 Nπ
// 。

// 第二行为整数 M
// ，表示蛋糕的层数为 M
// 。

// 输出格式
// 输出仅一行，是一个正整数 S
// （若无解则 S=0
// ）。

// 数据范围
// 1≤N≤10000
// ,
// 1≤M≤20
// 输入样例：
// 100
// 2
// 输出样例：
// 68

/*
剪枝：
1.自底向上搜，从大到小来枚举R，H
2. πr^2 * h = V
  所以第u层的半径必须大于等于u，但是必须比它的下一层小1，而且h至少为1，所以 πr^2 * 1 = v，因此u也必须小于 sqrt(n - v) 
  u <= R(u) <= min(R(u + 1) - 1, sqrt(n - v))
  第u层的高也是同样的道理，但是 πr^2 * h <= n - v，所以高必须小于等于 (n - v) / r / r
  u <= H(u) <= min(H(u + 1) - 1, (n - v) / R^2)
3.minv(u) 从第1层到第i层最小体积为多少
  mins(u) 从第1层到第i层最小表面积为多少
  v + minv(u) <= n
  s + mins(u) < ans
4.S(1~u) = ∑(2 * Rk * Hk) = 2/R(u+1) ∑(Rk * H * R(k + 1)) > 2/R(u+1) ∑ (Rk * Rk * Hk)
  n - V = ∑(Rk * Rk * Hk)
  S + S(1~u) >= 2(n-v) / R(u+1)
  所以 S + 2(n-v) / R(u+1) + 1 >= ans
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 25, INF = 1e9;

int n, m;
int minv[N], mins[N]; // 记录从第1-i层体积和面积最小是多少
int R[N], H[N];
int ans = INF;

void dfs(int u, int v, int s){ // u表示现在是第几层，v是当前体积和，s是表面积和
    if(v + minv[u] > n) return; // 体积超过n return
    if(s + mins[u] >= ans) return; // 表面积超过ans，说明这不是更优解
    if(s + 2 * (n - v) / R[u + 1] >= ans) return; // 第四个剪枝
    
    if(!u){ // 如果u变成了0
        if(v == n) ans = s; // 并且体积等于n，说明这种方案是更优解
        return;
    }
    
    for(int r = min(R[u + 1] - 1, (int)sqrt(n - v)); r >= u; r--) // 枚举半径r
        for(int h = min(H[u + 1] - 1, (n - v) / r / r); h >= u; h--){ // 枚举高度h
            int t = 0;
            if(u == m) t = r * r; // 如果是最后一层，把它的表面积算上
            R[u] = r, H[u] = h; // 设定半径和高度
            dfs(u - 1, v + r * r * h, s + 2 * r * h + t); // 向上递归
        }
}

int main(){
    cin >> n >> m;
    
    for(int i = 1; i <= m; i++){
        minv[i] = minv[i - 1] + i * i * i;
        mins[i] = mins[i - 1] + 2 * i * i;
    }
    
    R[m + 1] = H[m + 1] = INF; // m+1层半径和高度都是无穷大
    
    dfs(m, 0, 0);
    
    if(ans == INF) ans = 0; // ans == INF表示无解
    cout << ans << endl;
    
    return 0;
}