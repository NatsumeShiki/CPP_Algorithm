// 给定 n 个正整数 ai，请你输出这些数的乘积的约数个数，答案对 109+7 取模。

// 输入格式
// 第一行包含整数 n。

// 接下来 n 行，每行包含一个整数 ai。

// 输出格式
// 输出一个整数，表示所给正整数的乘积的约数个数，答案需对 109+7 取模。

// 数据范围
// 1≤n≤100,
// 1≤ai≤2×109
// 输入样例：
// 3
// 2
// 6
// 8
// 输出样例：
// 12

// 公式：如果一个数 N = p1^a1 * p2^a2 + ... + ps^as，p是底数，a是指数，那么约数个数就为 (a1 + 1) * (a2 + 1) * (a3 + 1) * ... * (as + 1)
#include<iostream>
#include<unordered_map>
using namespace std;

typedef long long LL;

const int mod = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    unordered_map<int, int> primes;
    while(n--){
        int x;
        cin >> x;
        for(int i = 2; i <= x / i; i++)
            while(x % i == 0){
                x /= i;
                primes[i]++;
            }
        if(x > 1) primes[x]++;
    }
    LL res = 1;
    for(auto prime : primes) res = res * (prime.second + 1) % mod;
    cout << res << endl;
    
    return 0;
}