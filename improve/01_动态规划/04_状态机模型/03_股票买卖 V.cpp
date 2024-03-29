// 给定一个长度为 N
//  的数组，数组中的第 i
//  个数字表示一个给定股票在第 i
//  天的价格。

// 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

// 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1
//  天)。
// 输入格式
// 第一行包含整数 N
// ，表示数组长度。

// 第二行包含 N
//  个不超过 10000
//  的正整数，表示完整的数组。

// 输出格式
// 输出一个整数，表示最大利润。

// 数据范围
// 1≤N≤105
// 输入样例：
// 5
// 1 2 3 0 2
// 输出样例：
// 3
// 样例解释
// 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]，第一笔交易可得利润 2-1 = 1，第二笔交易可得利润 2-0 = 2，共得利润 1+2 = 3。

// 自己的代码
/*
动态规划
  状态表示f[i, 0] f[i, 1] f[i, 2]
    集合：
      f[i, 0] 从前i中选择，第i天持有股票
      f[i, 1] 从前i中选择，第i天是不持有股票的第一天
      f[i, 2] 从前i中选择，第i天是不持有股票>=2天
    属性：Max
  状态计算：
    手中有货 -> 手中有货 f[i - 1, 0]
    手中无货day>=2 -> 手中有货 f[i - 1, 2] - w
    手中有货 -> 手中无货day1 f[i - 1, 0] + w
    手中无货day1 -> 手中无货day>=2 f[i - 1, 1]
    手中无货day>=2 -> 手中无货day>=2 f[i - 1, 2]
    因此 f[i, 0] = max(f[i - 1, 0], f[i - 1, 2] - w)  f[i, 1] = f[i - 1, 0] + w  f[i, 2] = max(f[i - 1, 1], f[i - 1, 2])

*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int f[N][3];

int main(){
    int n;
    cin >> n;
    
    f[0][0] = -INF; // 第0天手中持有股票是不合法的，所以设置为无穷小
    
    for(int i = 1; i <= n; i++){
        int w;
        cin >> w;
        f[i][0] = max(f[i - 1][0], f[i - 1][2] - w);
        f[i][1] = f[i - 1][0] + w;
        f[i][2] = max(f[i - 1][1], f[i - 1][2]);
    }
    
    cout << max(f[n][1], f[n][2]) << endl;
    
    return 0;
}