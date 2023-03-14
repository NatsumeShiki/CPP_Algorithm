// 给定两个整数 L
//  和 U
// ，你需要在闭区间 [L,U]
//  内找到距离最接近的两个相邻质数 C1
//  和 C2
// （即 C2−C1
//  是最小的），如果存在相同距离的其他相邻质数对，则输出第一对。

// 同时，你还需要找到距离最远的两个相邻质数 D1
//  和 D2
// （即 D1−D2
//  是最大的），如果存在相同距离的其他相邻质数对，则输出第一对。

// 输入格式
// 每行输入两个整数 L
//  和 U
// ，其中 L
//  和 U
//  的差值不会超过 106
// 。

// 输出格式
// 对于每个 L
//  和 U
// ，输出一个结果，结果占一行。

// 结果包括距离最近的相邻质数对和距离最远的相邻质数对。（具体格式参照样例）

// 如果 L
//  和 U
//  之间不存在质数对，则输出 There are no adjacent primes.。

// 数据范围
// 1≤L<U≤231−1
// 输入样例：
// 2 17
// 14 17
// 输出样例：
// 2,3 are closest, 7,11 are most distant.
// There are no adjacent primes.

#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 1e6 + 10;
int primes[N], cnt;
bool st[N];

void get_primes(int n){
    memset(st, 0, sizeof st);
    cnt = 0;
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] <= n / i; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main(){
    int l, r;
    while(cin >> l >> r){
        get_primes(50000);
        memset(st, 0, sizeof st);
        
        for(int i = 0; i < cnt; i++){
            LL p = primes[i];
            for(LL j = max(p * 2, (l + p - 1) / p * p); j <= r; j += p)
                st[j - l] = true;
        }
        
        cnt = 0;
        for(int i = 0; i <= r - l; i++)
            if(!st[i] && i + l >= 2)
                primes[cnt++] = i + l;
                
        if(cnt < 2) puts("There are no adjacent primes.");
        else{
            int minp = 0, maxp = 0;
            for(int i = 0; i + 1 < cnt; i++){
                int d = primes[i + 1] - primes[i];
                if(d < primes[minp + 1] - primes[minp]) minp = i;
                if(d > primes[maxp + 1] - primes[maxp]) maxp = i;
            }
            
            printf("%d,%d are closest, %d,%d are most distant.\n", 
                primes[minp], primes[minp + 1], primes[maxp], primes[maxp + 1]);
        }
    }
    
    return 0;
}