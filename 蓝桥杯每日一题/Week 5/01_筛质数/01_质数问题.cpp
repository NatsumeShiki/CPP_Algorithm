// 给定两个整数 n
//  和 k
// ，请你判断在 [2,n]
//  的范围内是否存在不少于 k
//  个质数，满足可以表示为两个相邻质数与 1
//  的和。

// 例如，19
//  满足条件，因为 19=7+11+1
// 。

// 输入格式
// 第一行包含整数 T
// ，表示共有 T
//  组测试数据。

// 每组数据占一行，包含两个整数 n
//  和 k
// 。

// 输出格式
// 每组数据输出占一行，如果存在不少于 k
//  个质数满足条件则输出 YES，否则输出 NO。

// 数据范围
// 1≤T≤30
// ,
// 2≤n≤1000
// ,
// 0≤k≤1000
// 输入样例：
// 5
// 27 2
// 45 7
// 2 0
// 15 1
// 17 1
// 输出样例：
// YES
// NO
// YES
// YES
// YES

#include<iostream>
#include<cstring>
using namespace std;

const int N = 1010;
int primes[N];
bool ans[N];
bool st[N];
int n, k, t, cnt;

int main(){
    for(int i = 2; i <= 1000; i++){
        if(!st[i]){
            st[i] = true;
            primes[cnt++] = i;
            for(int j = i + i; j <= 1000; j += i)
                st[j] = true;
        }
    }
    for(int i = 2; i < cnt; i++){
        for(int j = 1; j < i; j++)
            if(primes[j - 1] + primes[j] + 1 == primes[i]){
                ans[i] = true;
                break;
            }
    }
    cin >> t;
    while(t--){
        cin >> n >> k;
        int res = 0;
        for(int i = 0; i < cnt;i ++){
            if(ans[i]) res++;
            if(primes[i] > n) break;
        }
        if(res >= k) puts("YES");
        else puts("NO");
    }
    
    
    return 0;
}

// 大佬的写法
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1010;
int primes[N], cnt;
bool st[N];

void get_primes(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] <= n / i; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main(){
    get_primes(N - 1);
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >>k;
        int res = 0;
        for(int i = 2; i <= n; i++){
            if(st[i]) continue;
            for(int j = 1; j < cnt; j++)
                if(primes[j - 1] + primes[j] + 1 == i){
                    res++;
                    break;
                }
        }
        if(res >= k) puts("YES");
        else puts("NO");
    }
    
    return 0;
}#include<iostream>
#include<cstring>
using namespace std;

const int N = 1010;
int primes[N], cnt;
bool st[N];

void get_primes(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] <= n / i; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main(){
    get_primes(N - 1);
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >>k;
        int res = 0;
        for(int i = 2; i <= n; i++){
            if(st[i]) continue;
            for(int j = 1; j < cnt; j++)
                if(primes[j - 1] + primes[j] + 1 == i){
                    res++;
                    break;
                }
        }
        if(res >= k) puts("YES");
        else puts("NO");
    }
    
    return 0;
}