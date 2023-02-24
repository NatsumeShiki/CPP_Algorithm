// 给定一个长度为 n
//  的数列 a1,a2,…,an
// ，每次可以选择一个区间 [l,r]
// ，使下标在这个区间内的数都加一或者都减一。

// 求至少需要多少次操作才能使数列中的所有数都一样，并求出在保证最少次数的前提下，最终得到的数列可能有多少种。

// 输入格式
// 第一行输入正整数 n
// 。

// 接下来 n
//  行，每行输入一个整数，第 i+1
//  行的整数代表 ai
// 。

// 输出格式
// 第一行输出最少操作次数。

// 第二行输出最终能得到多少种结果。

// 数据范围
// 0<n≤105
// ,
// 0≤ai<2147483648
// 输入样例：
// 4
// 1
// 1
// 2
// 2
// 输出样例：
// 1
// 2

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int n;
int a[N];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = n; i > 1; i--) a[i] -= a[i - 1];
    
    LL pos = 0, neg = 0;
    for(int i = 2; i <= n; i++)
        if(a[i] > 0) pos += a[i];
        else neg -= a[i];
        
    cout << min(pos, neg) + abs(pos - neg) << endl;
    cout << abs(pos - neg) + 1 << endl;
    
    return 0;
}