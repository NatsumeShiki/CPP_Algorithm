// 科协里最近很流行数字游戏。

// 某人命名了一种不降数，这种数字必须满足从左到右各位数字呈非下降关系，如 123
// ，446
// 。

// 现在大家决定玩一个游戏，指定一个整数闭区间 [a,b]
// ，问这个区间内有多少个不降数。

// 输入格式
// 输入包含多组测试数据。

// 每组数据占一行，包含两个整数 a
//  和 b
// 。

// 输出格式
// 每行给出一组测试数据的答案，即 [a,b]
//  之间有多少不降数。

// 数据范围
// 1≤a≤b≤231−1
// 输入样例：
// 1 9
// 1 19
// 输出样例：
// 9
// 18


/*
动态规划
  状态表示f[i, j]
    集合：所有最高位是j，并且一共有i位的不降数的集合
    属性：count
  状态计算：
    枚举后面i-1位，最高位大于等于j，把方案数累加
      一共有i位，第i位是j
      for(int k = j; k <= 9; k++)
        f[i][j] += f[i - 1][k]

        /           \
  0~a(n-1)-1    a(n-1)
              /        \ 
      0~a(n-2)-1       a(n-2)
                  .
                  .
                  .
                  0~a(0)-1         a(0)
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 15; // 2 ^ 31 十进制有十位，所以设置比10大
int f[N][10]; // 一共有i为，并且最高位是j的方案数

void init(){ // 初始化
    for(int i = 0; i <= 9; i++) f[1][i] = 1; // 一共有1位，并且最高位是i的方案有1种，就是它本身
    
    for(int i = 2; i < N; i++) // 枚举一共有几位
        for(int j = 0; j <= 9; j++) // 枚举最高位是j
            for(int k = j; k <= 9; k++) // 次高位从j开始枚举到9
                f[i][j] += f[i - 1][k]; // 累加
}

int dp(int n){
    if(!n) return 1; // 如果n为0，方案有1中，直接返回
    
    vector<int> nums; // 存放n的每一位
    while(n) nums.push_back(n % 10), n /= 10;
    
    int res = 0; // 记录方案总数
    int last = 0; // 记录枚举到了第i位，此时它最小可以从多少开始枚举
    for(int i = nums.size() - 1; i >= 0; i--){
        int x = nums[i]; 
        for(int j = last; j < x; j++) // 从last开始枚举，到x-1
            res += f[i + 1][j]; // 累加方案，下标从0开始，所以下标为i的位置一共有i+1位
            
        if(x < last) break; // 如果x小于last，表示右侧方案是不成立的，所以直接break
        last = x; // 将last定义为该位的最大值
        
        if(!i) res++; // 如果到了下标为0的位置，也就是右侧方案走到了这一步，没有经过前面的break，就说明从前到后是始终是不递减的，则它本身就是一种方案，比如说1234567
    }
    
    return res; // 返回方案总数
}

int main(){
    init();
    
    int l, r;
    while(cin >> l >> r) cout << dp(r) - dp(l - 1) << endl;
    
    return 0;
}