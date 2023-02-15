// Windy 定义了一种 Windy 数：不含前导零且相邻两个数字之差至少为 2
//  的正整数被称为 Windy 数。

// Windy 想知道，在 A
//  和 B
//  之间，包括 A
//  和 B
// ，总共有多少个 Windy 数？

// 输入格式
// 共一行，包含两个整数 A
//  和 B
// 。

// 输出格式
// 输出一个整数，表示答案。

// 数据范围
// 1≤A≤B≤2×109
// 输入样例1：
// 1 10
// 输出样例1：
// 9
// 输入样例2：
// 25 50
// 输出样例2：
// 20

/*
动态规划
  状态表示f[i, j]
    集合：所有最高位是j，并且一共有i位的满足题目要求的集合
    属性：Count
  状态计算
    枚举后面i-1位，第i-1位与i位差距大等于2
    for(int k = 0; k <= 9; k++)
      if(abs(k - j) >= 2)
        f[i][j] += f[i - 1][k]
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 11;
int f[N][10];

void init(){ // 预处理所有满足题目要求的数
    for(int i = 0; i <= 9; i++) f[1][i] = 1;
    
    for(int i = 2; i < N; i++)
        for(int j = 0; j <= 9; j++)
            for(int k = 0; k <= 9; k++)
                if(abs(j - k) >= 2)
                    f[i][j] += f[i - 1][k];
}

int dp(int n){
    if(!n) return 0; // 如果n等于0，上界是0，而题目要求从1开始，所以返回0
    
    vector<int> nums;
    while(n) nums.push_back(n % 10), n /= 10;
    int res = 0, last = -2; // last要设置与0-9差距都为2的值，所以可以是小于等于-2，也可以是大于等于11
    for(int i = nums.size() - 1; i >= 0; i--){
        int x = nums[i];
        
        for(int j = i == nums.size() - 1; j < x; j++) // 要特别处理第一位，如果第一位不能放0，最小从1开始
            if(abs(j - last) >= 2) // 如果差距大等于2
                res += f[i + 1][j]; // 累加上方案
        
        if(abs(x - last) < 2) break; // 如果当前位于last差距不大等于2，不符合题目要求，则右侧方案不满足，break
        last = x; // 否则，把last设置成该层的x
        
        if(!i) res++; // 如果到了下标为0，此条件依然满足，表示该数本身也是成立的，比如说2468
    }
    // 这个是要处理如果有前导0的情况
    for(int i = 1; i < nums.size(); i++) // 枚举一共有i位，不能等于nums.size()，因为第一位已经从1~x-1都在上面计算过了
        for(int j = 1; j <= 9; j++) // 枚举最高位
            res += f[i][j]; 
    
    return res;
}

int main(){
    
    init();
    
    int l, r;
    cin >> l >> r;
    cout << dp(r) - dp(l - 1) << endl;
    
    return 0;
}