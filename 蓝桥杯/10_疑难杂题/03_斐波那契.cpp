// 斐波那契数列大家都非常熟悉。它的定义是：

// f(x)=1....(x=1,2)

// f(x)=f(x−1)+f(x−2)....(x>2)
// 对于给定的整数 n 和 m，我们希望求出：

// f(1)+f(2)+…+f(n) 的值。

// 但这个值可能非常大，所以我们把它对 f(m) 取模。

// 但这个数字依然很大，所以需要再对 p 求模。

// 输入格式
// 输入包含多组数据。

// 每组数据占一行，包含三个整数 n,m,p。

// 输出格式
// 每组数据输出一个整数，表示答案。

// 每个数占一行。

// 数据范围
// 0<n,m,p<1018
// 测试数据不超过100组

// 输入样例1：
// 2 3 5
// 输出样例1：
// 0
// 输入样例2：
// 15 11 29
// 输出样例2：
// 25

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

LL p;

LL qmul(LL a, LL b){
    LL res = 0;
    while(b){
        if(b & 1) res = (res + a) % p;
        a = (a + a) % p;
        b >>= 1;
    }
    return res;
}

void mul(LL c[][2], LL a[][2], LL b[][2]){ // c = a * b
    static LL t[2][2];
    memset(t, 0, sizeof t);
    
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                t[i][j] = (t[i][j] + qmul(a[i][k], b[k][j])) % p;
                
    memcpy(c, t, sizeof t);
}

LL F(LL n){
    if(!n) return 0;
    
    LL f[2][2] = {1, 1};
    LL a[2][2] = {{0, 1}, {1, 1}};
    for(LL k = n - 1; k; k >>= 1){
        if(k & 1) mul(f, f, a);
        mul(a, a, a);
    }
    
    return f[0][0];
}

LL H(LL m, LL k){
    if(k % 2) return F(m - k) - 1;
    else{
        if(k == 0 || m == 2  && m - k == 1) return F(m) - 1;
        else return F(m) - F(m - k) - 1;
    }
}

LL G(LL n, LL m){ // (F(n) - 1) mod F(m)
    if(m % 2 == 0){
        if(n / m % 2 == 0){ // n / m 是偶数
            if(n % m == 0) return F(m) - 1;
            else return F(n % m) - 1;
        }else{ // n / m是奇数
             return H(m, n % m);
        }
    }else{ // m是奇数
        if(n / m % 2 == 0 && n / 2 / m % 2 == 0){ // n / m是偶数，n / (2m)是偶数
            if(n % m == 0) return F(m) - 1;
            else return F(n % m) - 1;
        }else if(n / m % 2 == 0 && n / 2 / m % 2){ // n / m是偶数，n / (2m)是奇数
            if(m == 2 && n % m == 1) return F(m) - 1;
            else return F(m) - F(n % m) - 1;
        }else if(n / m % 2 && n / 2 / m % 2 == 0){ // n / m是奇数，n / (2m)是偶数
            return H(m, n % m);
        }else{ // n / m 是奇数，n / (2m)是偶数
            if(n % m % 2){
                if(m == 2 && m - n % m == 1) return F(m) - 1;
                else return F(m) - F(m - n % m) - 1;
            }else{
                return F(m - n % m) - 1;
            }
        }
    }
}

int main(){
    
    LL n, m;
    
    while(cin >> n >> m >> p) cout << (G(n + 2, m) % p + p) % p << endl;
    
    return 0;
}