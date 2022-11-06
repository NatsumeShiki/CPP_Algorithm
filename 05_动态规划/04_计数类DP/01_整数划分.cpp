// 一个正整数 n 可以表示成若干个正整数之和，形如：n=n1+n2+…+nk，其中 n1≥n2≥…≥nk,k≥1。

// 我们将这样的一种表示称为正整数 n 的一种划分。

// 现在给定一个正整数 n，请你求出 n 共有多少种不同的划分方法。

// 输入格式
// 共一行，包含一个整数 n。

// 输出格式
// 共一行，包含一个整数，表示总划分数量。

// 由于答案可能很大，输出结果请对 109+7 取模。

// 数据范围
// 1≤n≤1000
// 输入样例:
// 5
// 输出样例：
// 7

/*
方法一：
这道题可以类比成背包问题
状态表示f[i][j]:
  集合：从1-i选择物品，每件物品有无数个，每个物品体积是1-n，选择的体积刚好等于j
  属性：sum
属性计算：
  可以分成第i件物品选择0件，即f[i-1][j]，表示从1~i-1选择，体积等于j
  第i件物品选择1件，即f[i-1][j-i]，第i件物品选择2件，即f[i-1][j-2i].....第i件物品选择s件，即f[i-1][j-si]，s是能选择的i物品最大值
  然后再求和，f[i][j] = f[i-1][j] + f[i-1][j-i] + f[i-1][j-2i] + ... + f[i-1][j-si]
  此时时间复杂度是 O(nlog(n^2))，勉强能过
  但是还可以再优化，跟完全背包问题类似
  f[i][j] = f[i-1][j] + f[i-1][j-i] + f[i-1][j-2i] + ... + f[i-1][j-si]
  f[i][j-i] =           f[i-1][j]   + f[i-1][j-2i] + ... + f[i-1][j-si]
  所以 f[i][j] = f[i-1][j] + f[i][j-i]
*/
#include<iostream>
using namespace std;

const int N = 1010, mod = 1e9 + 7;
int f[N][N];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++) f[i][0] = 1; // 表示从1-i件物品选择体积为0的方法有1种，那就是什么都不选
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= n; j++){
            f[i][j] = f[i - 1][j] % mod; // 如果j是小于i的，就不需要加上f[i][j-i]，直接等于f[i-1][j]即可
            if(j >= i) f[i][j] = (f[i - 1][j] + f[i][j - i]) % mod; // 如果j是大于等于i的，就使用公式
        }
    cout << f[n][n] << endl; // 表示从1-n物品中选择体积为n的方法数
    
    return 0;
}

// 一维数组
#include<iostream>
using namespace std;

const int N = 1010, mod = 1e9 + 7;
int n, f[N];

int main(){
    cin >> n;
    f[0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            f[j] = (f[j] + f[j - i]) % mod;
    cout << f[n] << endl;
    
    return 0;
}

/*
方法二：
状态表示f[i][j]:
  集合：所有总和是i，由j个数相加的方案
  属性：sum
状态计算：
  可以分成两种情况，一种是这j个数中最小值是1，另一种情况是所有数都严格大于1
  如果最小值是1，那么有f[i-1][j-1]种情况，表示去掉最后一个1之后，它的总和是i-1，然后它是由j-1个数加起来的结果
  如果所有数都是大于1的，有f[i-1][j]种情况，表示把这j个数，每个数都减去1，那么总和就是i-j，然后它还是j个数相加没变
  所以 f[i][j] = f[i - 1][j - 1] + f[i - j][j]
通过这种做法后需要做 ans = f[n, 1] + f[n, 2] + ... f[n, n]，表示和是n的时候，它由一个数、两个数、三个数、....、n个数相加得到的结果，把这些结果求和，就表示
和为n的时候的方案总数
*/
#include<iostream>
using namespace std;

const int N = 1010, mod = 1e9 + 7;
int f[N][N];

int main(){
    int n;
    cin >> n;
    f[0][0] = 1; // 当和是0的时候，由0个数相加，它的方案数是1，这个是边界条件
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++) // j <= i 意思是总和为i，那么最多由i个1相加，所以j必须小于等于i
            f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % mod;
    int res = 0;
    for(int i = 1; i <= n; i++)res = (res + f[n][i]) % mod; // 最后求和模mod
    cout << res << endl;
    
    return 0;
}