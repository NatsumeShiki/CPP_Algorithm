// X星球的某个大奖赛设了 M 级奖励。

// 每个级别的奖金是一个正整数。

// 并且，相邻的两个级别间的比例是个固定值。

// 也就是说：所有级别的奖金数构成了一个等比数列。

// 比如：16,24,36,54，其等比值为：3/2。

// 现在，我们随机调查了一些获奖者的奖金数。

// 请你据此推算可能的最大的等比值。

// 输入格式
// 第一行为数字 N ，表示接下的一行包含 N 个正整数。

// 第二行 N 个正整数 Xi，用空格分开，每个整数表示调查到的某人的奖金数额。

// 输出格式
// 一个形如 A/B 的分数，要求 A、B 互质，表示可能的最大比例系数。

// 数据范围
// 0<N<100
// 0<Xi<1012
// 数据保证一定有解。

// 输入样例1：
// 3
// 1250 200 32
// 输出样例1：
// 25/4
// 输入样例2：
// 4
// 3125 32 32 200
// 输出样例2：
// 5/2
// 输入样例3：
// 3
// 549755813888 524288 2
// 输出样例3：
// 4/1

/*
a   a(p/q)   a(p/q)^2  ...  a(p/q)^(n-1)
b0  b1       b2        ...  b(n-1)
(b1/b0)  (b2/b0)       ...  b(n-1)/b0
(p-q)^a1  (p-q)^a2 ... (p-q)^a(n-1)
题目要求的就是 a1 a2 ... a(n-1) 的最大公约数
不妨设 (p/q)已经最简，此时p和q互质，(p/q)不能再拆分成次幂形式
(p/q)^k k最大  (p^k)/(q^k)
于是 f(p^x, p^y) = p(x, y)
    = p(x, y - x)
    = f(p^x, p(y - x))
    = f(p^x, p^y/p^x) 更相减损术
*/
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;
const int N = 110;
int n;
LL x[N], a[N], b[N]; // x保存原数据，a是分子数组，b是分母数组

LL gcd(LL a, LL b){ // 求最大公约数
    return b ? gcd(b, a % b) : a;
}

LL gcd_sub(LL a, LL b){ // 更相减损术
    if(a < b) swap(a, b); // 总是用大的减去小的，所以如果a小于b，就交换
    if(b == 1) return a;
    return gcd_sub(b, a / b);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> x[i];
    
    sort(x, x + n);
    
    int cnt = 0;
    for(int i = 1; i < n; i++)
        if(x[i] != x[i - 1]){ // 判重
            LL d = gcd(x[i], x[0]); // 获取 x[i]和x[0]的最大公约数
            a[cnt] = x[i] / d; // 将分子的最简存进a数组
            b[cnt] = x[0] / d; // 将分母的最简存进b数组
            cnt++;
        }
        
    LL up = a[0], down = b[0]; // up是a[0]的分子，down是b[0]的分母
    for(int i = 1; i < cnt; i++){ // 两两求最大公约数
        up = gcd_sub(up, a[i]);
        down = gcd_sub(down, b[i]);
    }
    
    cout << up << "/" << down << endl; // 最终输出
    
    return 0;
}