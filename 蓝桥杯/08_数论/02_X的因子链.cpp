// 输入正整数 X，求 X 的大于 1 的因子组成的满足任意前一项都能整除后一项的严格递增序列的最大长度，以及满足最大长度的序列的个数。

// 输入格式
// 输入包含多组数据，每组数据占一行，包含一个正整数表示 X。

// 输出格式
// 对于每组数据，输出序列的最大长度以及满足最大长度的序列的个数。

// 每个结果占一行。

// 数据范围
// 1≤X≤220
// 输入样例：
// 2
// 3
// 4
// 10
// 100
// 输出样例：
// 1 1
// 1 1
// 2 1
// 2 2
// 4 6

/*
先把题目的意思给翻译一下吧，给一个数x，让你求这个x有多少个因子可以组成一个序列，满足这个序列长度最长，并且后一个数可以整除以后一个数
最后输出这个序列的最长长度，以及满足这个最大长度的方案数是多少
直接说结论，任何一个数都可以变成 p1^a1 * p2^a2 * ... * pn^an
然后这个长度的最大值就是 a1 + a2 + ... + an
方案数是 (a1 + a2 + ... + an)! / (a1! * a2! * ... * an!)
*/
#include<iostream>
using namespace std;

typedef long long LL;
const int N = (1 << 20) + 10;
int primes[N], cnt; // 保存素数
int minp[N]; // 保存每个数的最小因子
bool st[N]; // 判重数组

void get_primes(int n){ // 线性筛法
    for(int i = 2; i <= n; i++){
        if(!st[i]) { // 如果这个数st为false，表明这个数是个素数
            primes[cnt++] = i; // 放进primes数组中
            minp[i] = i; // 并且这个数的最小因子就是它本身
        }
        for(int j = 0; i * primes[j] <= n; j++){
            int t = primes[j] * i;
            st[t] = true;
            minp[t] = primes[j]; // 这个数的最小因子就是primes[j]，i是肯定大于primes[j]的
            if(i % primes[j] == 0) break;
        }
    }
}

int main(){
    get_primes(N - 1); // 获取每个数的最小因子以及素数的集合
    
    int fact[30], sum[30]; // fact保存p1 p2 ... pn，sum数组保存 a1 a2 ... an
    
    int x;
    while(scanf("%d", &x) != -1){ // 直到读到文件的末尾
        int k = 0, tot = 0; // k是记录有多少个这个数，tot记录a1 a2 ... an的总和
        while(x > 1){ 
            int p = minp[x]; // 先获得x的最小因子
            fact[k] = p, sum[k] = 0; // 放进fact中，设置sum[k]为0，记录数量
            while(x % p == 0){ // 直到x除p的余数不为0
                x /= p; // x除以他
                sum[k]++; // 这个数的数量加1
                tot++; // 总数加1
            }
            k++; // k指针向后走
        }
        
        LL res = 1; // res记录方案的总数
        for(int i = 1; i <= tot; i++) res *= i; // 先求(a1 + a2 + ... + an)!
        for(int i = 0; i < k; i++)
            for(int j = 1; j <= sum[i]; j++) // 然后用res除以每个数个数的阶乘
                res /= j;
            
        cout << tot << " " << res << endl; // 最终输出即可
        
    }

    return 0;
}