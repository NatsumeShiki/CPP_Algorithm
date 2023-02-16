// 单身！

// 依然单身！

// 吉哥依然单身！

// DS 级码农吉哥依然单身！

// 所以，他平生最恨情人节，不管是 214
//  还是 77
// ，他都讨厌！

// 吉哥观察了 214
//  和 77
//  这两个数，发现：

// 2+1+4=7

// 7+7=7×2

// 77=7×11
// 最终，他发现原来这一切归根到底都是因为和 7
//  有关！

// 所以，他现在甚至讨厌一切和 7
//  有关的数！

// 什么样的数和 7
//  有关呢？

// 如果一个整数符合下面三个条件之一，那么我们就说这个整数和 7
//  有关：

// 整数中某一位是 7
// ；
// 整数的每一位加起来的和是 7
//  的整数倍；
// 这个整数是 7
//  的整数倍。
// 现在问题来了：吉哥想知道在一定区间内和 7
//  无关的整数的平方和。

// 输入格式
// 第一行包含整数 T
// ，表示共有 T
//  组测试数据。

// 每组数据占一行，包含两个整数 L
//  和 R
// 。

// 输出格式
// 对于每组数据，请计算 [L,R]
//  中和 7
//  无关的数字的平方和，并将结果对 109+7
//  取模后输出。

// 数据范围
// 1≤T≤50
// ,
// 1≤L≤R≤1018
// 输入样例：
// 3
// 1 9
// 10 11
// 17 17
// 输出样例：
// 236
// 221
// 0

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 20, P = 1e9 + 7;

struct F{
    int s0, s1, s2;
}f[N][10][7][7];

int power7[N], power9[N];

int mod(LL x, int y){
    return (x % y + y) % y;
}

void init(){
    for(int i = 0; i <= 9; i++){
        if(i == 7) continue;
        auto &v = f[1][i][i % 7][i % 7];
        v.s0++;
        v.s1 += i;
        v.s2 += i * i;
    }
    
    LL power = 10;
    for(int i = 2; i < N; i++, power *= 10)
        for(int j = 0; j <= 9; j++){
            if(j == 7) continue;
            for(int a = 0; a < 7; a++)
                for(int b = 0; b < 7; b++)
                    for(int k = 0; k <= 9; k++){
                        if(k == 7) continue;
                        auto &v1 = f[i][j][a][b], &v2 = f[i - 1][k][mod(a - j * (power % 7), 7)][mod(b - j, 7)];
                        v1.s0 = (v1.s0 + v2.s0) % P;
                        v1.s1 = (v1.s1 + j * (power % P) % P * v2.s0 + v2.s1) % P;
                        v1.s2 = (v1.s2 +
                                 j * j * (power % P) % P * (power % P) % P * v2.s0 % P +
                                 2 * j * (power % P) % P * v2.s1 % P +
                                 v2.s2) % P;
                    }
        }
        
    power7[0] = power9[0] = 1;
    for(int i = 1; i < N; i++){
        power7[i] = power7[i - 1] * 10 % 7;
        power9[i] = power9[i - 1] * 10ll % P;
    }
}

F get(int i, int j, int a, int b){
    int s0 = 0, s1 = 0, s2 = 0;
    for(int x = 0; x < 7; x++)
        for(int y = 0; y < 7; y++){
            if(x == a || y == b) continue;
            auto v = f[i][j][x][y];
            s0 = (s0 + v.s0) % P;
            s1 = (s1 + v.s1) % P;
            s2 = (s2 + v.s2) % P;
        }
    return {s0, s1, s2};
}

int dp(LL n){
    if(!n) return 0;
    
    LL backup_n = n % P;
    vector<int> nums;
    while(n) nums.push_back(n % 10), n /= 10;
    
    int res = 0;
    LL last_a = 0, last_b = 0;
    for(int i = nums.size() - 1; i >= 0; i--){
        int x = nums[i];
        for(int j = 0; j < x; j++){
            if(j == 7) continue;
            int a = mod(-last_a % 7 * power7[i + 1], 7);
            int b = mod(-last_b, 7);
            
            auto v = get(i + 1, j, a, b);
            res = (res + 
                   (last_a % P) * (last_a % P) % P * power9[i + 1] % P * power9[i + 1] % P * v.s0 % P + 
                   2 * (last_a % P) % P * power9[i + 1] % P * v.s1 % P +
                   v.s2) % P;
        }
        
        if(x == 7) break;
        last_a = last_a * 10 + x;
        last_b += x;
        
        if(!i && last_a % 7 && last_b % 7) res = (res + backup_n * backup_n) % P;
    }
    return res;
}

int main(){
    init();
    
    int T;
    cin >> T;
    while(T--){
        LL l, r;
        cin >> l >> r;
        cout << mod(dp(r) - dp(l - 1), P) << endl;
    }
}