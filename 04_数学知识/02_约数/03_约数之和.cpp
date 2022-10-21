// 给定 n 个正整数 ai，请你输出这些数的乘积的约数之和，答案对 109+7 取模。

// 输入格式
// 第一行包含整数 n。

// 接下来 n 行，每行包含一个整数 ai。

// 输出格式
// 输出一个整数，表示所给正整数的乘积的约数之和，答案需对 109+7 取模。

// 数据范围
// 1≤n≤100,
// 1≤ai≤2×109
// 输入样例：
// 3
// 2
// 6
// 8
// 输出样例：
// 252

// 公式：如果一个数 N = p1^a1 * p2^a2 + ... + ps^as，p是底数，a是指数，
//       那么约数之和 = (p1 ^ 0 + p1 ^ 1 + ... + p1 ^ a1)(p2 ^ 0 + p2 ^ 1 + ... + p2 ^ a1)...(pk ^ 0 + pk ^ 1 + ... + pk ^ ak)
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
    for(auto prime : primes) {
        int p = prime.first, a = prime.second;
        LL t = 1;
        // p^0 + p^1 + p^2 + ... + p^a
        // 令t = 1，每次 t = t * p + 1，第一次得到 p^1 + 1，也就是 p^1 + p^0，第二次得到 p^2 + p^1 + 0，也就是 p^2 + p^1 + p^0
        // 所以这样操作a次后，就可以得到 p^0 + p^1 + p^2 + ... + p^a
        while(a--) t = (t * p + 1) % mod;
        res = res * t % mod;
    }
    cout << res << endl;
    
    return 0;
}