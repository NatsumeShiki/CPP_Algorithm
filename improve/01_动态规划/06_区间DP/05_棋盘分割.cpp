// 将一个 8×8
//  的棋盘进行如下分割：将原棋盘割下一块矩形棋盘并使剩下部分也是矩形，再将剩下的部分继续如此分割，这样割了 (n−1)
//  次后，连同最后剩下的矩形棋盘共有 n
//  块矩形棋盘。(每次切割都只能沿着棋盘格子的边进行)

// 1191_1.jpg

// 原棋盘上每一格有一个分值，一块矩形棋盘的总分为其所含各格分值之和。

// 现在需要把棋盘按上述规则分割成 n
//  块矩形棋盘，并使各矩形棋盘总分的均方差最小。

// 均方差formula.png ，其中平均值lala.png ，xi
//  为第 i
//  块矩形棋盘的总分。

// 请编程对给出的棋盘及 n
// ，求出均方差的最小值。

// 输入格式
// 第 1
//  行为一个整数 n
// 。

// 第 2
//  行至第 9
//  行每行为 8
//  个小于 100
//  的非负整数，表示棋盘上相应格子的分值。每行相邻两数之间用一个空格分隔。

// 输出格式
// 输出最小均方差值（四舍五入精确到小数点后三位）。

// 数据范围
// 1<n<15
// 输入样例：
// 3
// 1 1 1 1 1 1 1 3
// 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 0
// 1 1 1 1 1 1 0 3
// 输出样例：
// 1.633

/*
动态规划
  状态表示f[x1, y1, x2, y2, k]
    集合：将子矩阵(x1, y1)(x2, y2)切分成k部分的所有方案
    属性：(xi - x平均值) ^ 2 / n 的和 的最小值，i：1-n 
  状态计算：
    横着切n-1刀，每切一刀选择上面或者下面 f[x1, y1, i, y2] + 下边的(xi - x平均值) ^ 2 / n  f[i + 1, y1, x2, y2] + 上边的(xi - x平均值) ^ 2 / n 取最小值
    竖着切n-1刀，每切一刀选择左边或者右边
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 15, M = 9; // N表示切成N部分，M表示棋盘的大小
const double INF = 1e9; // 无穷大

int n, m = 8; // m是棋盘的边长，n是切成了n块
int s[M][M]; // 矩阵的前缀和
double f[M][M][M][M][N];
double X; // 平均值

double get(int x1, int y1, int x2, int y2){ // 计算 (xi - X) ^ 2 / n
    double sum = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1] - X;
    return sum * sum / n;
}

double dp(int x1, int y1, int x2, int y2, int k){
    double &v = f[x1][y1][x2][y2][k];
    if(v >= 0) return v; // 如果f[x1][y1][x2][y2][k]大于等于0，说明已经有了结果，直接返回
    if(k == 1) return v = get(x1, y1, x2, y2); // 如果k等于1，表示只有这一块，直接返回 (xi - X) ^ 2 / n 即可
    
    v = INF; // 先将他设置为无穷大
    for(int i = x1; i < x2; i++){ // 横着切
        v = min(v, dp(x1, y1, i, y2, k - 1) + get(i + 1, y1, x2, y2)); // 选择左边
        v = min(v, dp(i + 1, y1, x2, y2, k - 1) + get(x1, y1, i, y2)); // 选择右边继续切
    }
    for(int i = y1; i < y2; i++){ // 竖着切
        v = min(v, dp(x1, y1, x2, i, k - 1) + get(x1, i + 1, x2, y2)); // 选择上边
        v = min(v, dp(x1, i + 1, x2, y2, k - 1) + get(x1, y1, x2, i)); // 选择下边
    }
    
    return v; // 返回结果
}

int main(){
    cin >> n; 
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= m; j++){
            cin >> s[i][j];
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]; // 计算子矩阵的前缀和
        }
        
    memset(f, -1, sizeof f); // 将f设置为负数即可
    X = (double)s[m][m] / n; // 计算平均值
    
    printf("%.3lf\n", sqrt(dp(1, 1, 8, 8, n))); // 输出结果
    
    return 0;
}