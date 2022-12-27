// 城市中人们总是拿着号码牌，不停寻找，不断匹配，可是谁也不知道自己等的那个人是谁。

// 可是燕姿不一样，燕姿知道自己等的人是谁，因为燕姿数学学得好！

// 燕姿发现了一个神奇的算法：假设自己的号码牌上写着数字 S，那么自己等的人手上的号码牌数字的所有正约数之和必定等于 S。

// 所以燕姿总是拿着号码牌在地铁和人海找数字（喂！这样真的靠谱吗）。

// 可是她忙着唱《绿光》，想拜托你写一个程序能够快速地找到所有自己等的人。

// 输入格式
// 输入包含 k 组数据。

// 对于每组数据，输入包含一个号码牌 S。

// 输出格式
// 对于每组数据，输出有两行。

// 第一行包含一个整数 m，表示有 m 个等的人。

// 第二行包含相应的 m 个数，表示所有等的人的号码牌。

// 注意：你输出的号码牌必须按照升序排列。

// 数据范围
// 1≤k≤100,
// 1≤S≤2×109
// 输入样例：
// 42
// 输出样例：
// 3
// 20 26 41

/*
先说明一些知识
N = p1^a1 * p2^a2 * ... * pn^an
约数个数 (a1 + 1)(a2 + 1)...(an + 1)
约数之和 (1 + p1 + p1^2 + ... + p1^an)(1 + p2 + ... + p2^n)...(1 + ... + pn^an)

可以通过枚举来求
for(p = 2 3 5 7 ...)
  for(a = 1 2 3 ...)
    if(s % (1 + ... + pn^an) == 0 )
      dfs()
但是这样还是有可能会TLE，所以需要仅一步优化

S = (1 + pi + ... + pi^n)(...)...  pi^2 < S
S = (1 + pi)(1 + pj + ...)...      pi^2 < S
所以可以质数满足 P^2 <= S
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 50000;
int primes[N], cnt;
bool st[N];

int ans[N], len;

bool is_prime(int x){ // 判断一个数是不是质数
    if(x < N) return !st[x]; // 如果它是在N以内的，那么之前的get_primes函数已经获得了某一个数是不是质数，直接在st中获取即可
    for(int i = 0; primes[i] <= x / primes[i]; i++) // 否则，就用每一个质数，看看这个数能不能被整除，如果可以说明不是质数
        if(x % primes[i] == 0)
            return false;
    return true; // 所有N以内的质数都判断了之后还是走到了这里说明这个数是个质数
}

void get_primes(int n){ // 获取n以内的质数
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= n; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}
// last记录上一个使用的质数，按照从小到大的顺序，prod是记录p1^a1 * p2^a2 * ... * pn^an，获得最终组成的那个数
void dfs(int last, int prod, int s){
    if(s == 1){ // 比如书7是质数，那么上一个搜索必然是用 7 / 7，得到1，然后这里判断出来s == 1，就把7放进去即可
        ans[len++] = prod;
        return;
    }
    
    if(s - 1 > (last < 0 ? 1 : primes[last]) && is_prime(s - 1)) // 如果s-1是大于上一个质数，并且s-1是质数，就累乘放进ans数组中即可
        ans[len++] = prod * (s - 1);
        
    for(int i = last + 1; primes[i] <= s / primes[i]; i++){ // 从上一个质数后面开始
        int p = primes[i];
        for(int j = 1 + p, t = p; j <= s; t *= p, j += t) // j是(1 + ... + pn^an)， t记录 pn是几次方
            if(s % j == 0) // 如果s可以整除以j，就像下搜索
                dfs(i, prod * t, s / j);
    }
}

int main(){
    get_primes(N - 1); // 现获取 sqrt(2e9) 以内的质数，这里用50000
    
    int s;
    while(cin >> s){
        len = 0;
        dfs(-1, 1, s);
        
        cout << len << endl;
        if(len){
            sort(ans, ans + len);
            for(int i = 0; i < len; i++)
                cout << ans[i] << " ";
            cout << endl;
        }
    }
    
    return 0;
}