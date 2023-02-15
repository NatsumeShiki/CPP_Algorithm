// 由于科协里最近真的很流行数字游戏。

// 某人又命名了一种取模数，这种数字必须满足各位数字之和 mod N
//  为 0
// 。

// 现在大家又要玩游戏了，指定一个整数闭区间 [a.b]
// ，问这个区间内有多少个取模数。

// 输入格式
// 输入包含多组测试数据，每组数据占一行。

// 每组数据包含三个整数 a,b,N
// 。

// 输出格式
// 对于每个测试数据输出一行结果，表示区间内各位数字和 mod N
//  为 0
//  的数的个数。

// 数据范围
// 1≤a,b≤231−1
// ,
// 1≤N<100
// 输入样例：
// 1 19 9
// 输出样例：
// 2

/*
动态规划
  状态表示f[i, j, k]
    集合：一共i位，最高位是j，所有位合起来mod P等于k的方案
    属性：Count
  状态计算：
    枚举第i-1位是x，x从0-9，前i-1位总和mod P是 (k - j) mod P 
    for(int j = 0; j <= 9; j++)
      for(int k = 0; k < P; k++)
        for(int x = 0; x <= 9; i++)
          f[i][j][k] += f[i - 1][x][(k - j) % P]
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 11, M = 110;
int P;
int f[N][10][M];

int mod(int x, int y){ // 为了是负数模一个数变成正数
    return (x % y + y) % y;
}

void init(){
    memset(f, 0, sizeof f); // 将f数组重置
    
    for(int i = 0; i <= 9; i++) f[1][i][i % P]++; // 只有1位，最高位是i，余数是 i % P 的方案有1一种
    
    for(int i = 2; i < N; i++) // 枚举一共有i位
        for(int j = 0; j <= 9; j++) // 枚举最高位
            for(int k = 0; k < P; k++) // 枚举余数
                for(int x = 0; x <= 9; x++) // 枚举次高位
                    f[i][j][k] += f[i - 1][x][mod(k - j, P)]; // 累加 一共i-1位，第i-1位是x，总和是sum，使得(j + sum) % P = k，于是sum = (k - j) % P
}

int dp(int n){
    if(!n) return 1; // n模上任何数都是0，所以是一种方案，返回1
    
    vector<int> nums;
    while(n) nums.push_back(n % 10), n /= 10;
    
    int res = 0; // 保存总方案数
    int last = 0; // last保存前i为总和
    for(int i = nums.size() - 1; i >= 0; i--){
        int x = nums[i];
        
        for(int j = 0; j < x; j++) // 枚举本位填什么数，0~x-1
            res += f[i + 1][j][mod(-last, P)]; // (last + sum) % P = 0，所以sum = (0 - last) % P
            
        last += x; // 累加前几位
        
        if(!i && last % P == 0) res++; // 如果到了最后一位，并且所有位总和mod P等于0，则该数本身是一种方案，累加上它
    }
    
    return res;
}

int main(){
    int l, r;
    while(cin >> l >> r >> P){
        init();
        
        cout << dp(r) - dp(l - 1) << endl;
    }
    
    return 0;
}