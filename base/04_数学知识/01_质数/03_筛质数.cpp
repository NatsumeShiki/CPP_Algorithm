// 给定一个正整数 n，请你求出 1∼n 中质数的个数。

// 输入格式
// 共一行，包含整数 n。

// 输出格式
// 共一行，包含一个整数，表示 1∼n 中质数的个数。

// 数据范围
// 1≤n≤106
// 输入样例：
// 8
// 输出样例：
// 4

// 时间复杂度 nlogeN < nlog2n 所以是O(nlogn)  
// 方法一：朴素做法
#include<iostream>
using namespace std;

const int N = 1000010;
int primes[N], cnt;
bool st[N];

void get_primes(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]){
            primes[cnt++] = n;
        }
        for(int j = i + i; j <= n; j += i) st[j] = true;
    }
}

int main(){
    int n;
    cin >> n;
    get_primes(n);
    
    cout << cnt << endl;
    
    return 0;
}


// 优化版
// 时间复杂度：1-n中有 N/lnN个 质数，所以理论上时间复杂度 O(NlnN/lnN) = O(N),但实际上是O(nloglogn),拿2^32来说，log2^32 = 32, log32 = 5,其实跟O(n)是一个级别的
// 方法二：埃氏筛法
#include<iostream>
using namespace std;

const int N = 1000010;
int primes[N], cnt;
bool st[N];

void get_primes(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]){
            primes[cnt++] = n;
            for(int j = i + i; j <= n; j += i) st[j] = true; // 差别就在于删除元素的时候只删除质数的倍数
        }
    }
}

int main(){
    int n;
    cin >> n;
    get_primes(n);
    
    cout << cnt << endl;
    
    return 0;
}

// 方法三：线性筛法
// 核心：n只会被最小质因子筛掉
#include<iostream>
using namespace std;

const int N = 1000010;
int primes[N], cnt;
bool st[N];

void get_primes(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] <= n / i; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break; // primes[j] 一定是i的最小质因子，primes[j] 一定是 primes[j] * i 的最小质因子
            // 如果 i % primes[j] != 0，primes[j]一定小于i的所有质因子，primes[j] 也一定是primes[j] * i的最小质因子
        }
    }
}

int main(){
    int n;
    cin >> n;
    get_primes(n);
    
    cout << cnt << endl;
    
    return 0;
}