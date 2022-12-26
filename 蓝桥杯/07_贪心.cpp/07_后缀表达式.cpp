// 给定 N 个加号、M 个减号以及 N+M+1 个整数 A1,A2,⋅⋅⋅,AN+M+1，小明想知道在所有由这 N 个加号、M 个减号以及 N+M+1 个整数凑出的合法的后缀表达式中，结果最大的是哪一个？

// 请你输出这个最大的结果。

// 例如使用 123+−，则 “23+1−” 这个后缀表达式结果是 4，是最大的。

// 输入格式
// 第一行包含两个整数 N 和 M。

// 第二行包含 N+M+1 个整数 A1,A2,⋅⋅⋅,AN+M+1。

// 输出格式
// 输出一个整数，代表答案。

// 数据范围
// 0≤N,M≤105,
// −109≤Ai≤109
// 输入样例：
// 1 1
// 1 2 3
// 输出样例：
// 4

/*
1. 如果 m == 0 全部加起来
2. 如果 m > 0，n == 0，通过组合，这m个负号可以变成 1-m个负号
3. 如果 m > 0，n > 0，通过组合，n个正号可以变成 1-m+n个正号 比如果 b - (a0 - a1 - a2 - a3 + a4)
所以至少减一个数，加一个数，减去最小值，加上最大值，然后其他的数可以做到加上正数，减去负数，也就是可以加上所有数的绝对值，这也就是最大值
*/
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;
const int N = 2e5 + 10;
int n, m;
int a[N];

int main(){
    cin >> n >> m;
    int k = n + m + 1;
    for(int i = 0; i < k; i++) cin >> a[i];
    
    LL res = 0;
    if(!m){
        for(int i = 0; i < k; i++) res += a[i];
    }else{
        sort(a, a + k);
        
        res = a[k - 1] - a[0];
        for(int i = 1; i < k - 1; i++) res += abs(a[i]);
    }
    
    cout << res << endl;
    
    return 0;
}