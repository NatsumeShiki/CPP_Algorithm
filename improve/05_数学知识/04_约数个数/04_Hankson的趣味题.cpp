// Hanks 博士是 BT（Bio-Tech，生物技术）领域的知名专家，他的儿子名叫 Hankson。

// 现在，刚刚放学回家的 Hankson 正在思考一个有趣的问题。

// 今天在课堂上，老师讲解了如何求两个正整数 c1
//  和 c2
//  的最大公约数和最小公倍数。

// 现在 Hankson 认为自己已经熟练地掌握了这些知识，他开始思考一个“求公约数”和“求公倍数”之类问题的“逆问题”，这个问题是这样的：

// 已知正整数 a0,a1,b0,b1
// ，设某未知正整数 x
//  满足：

// x
//  和 a0
//  的最大公约数是 a1
// ；
// x
//  和 b0
//  的最小公倍数是 b1
// 。
// Hankson 的“逆问题”就是求出满足条件的正整数 x
// 。

// 但稍加思索之后，他发现这样的 x
//  并不唯一，甚至可能不存在。

// 因此他转而开始考虑如何求解满足条件的 x
//  的个数。

// 请你帮助他编程求解这个问题。

// 输入格式
// 输入第一行为一个正整数 n
// ，表示有 n
//  组输入数据。

// 接下来的 n
//  行每行一组输入数据，为四个正整数 a0，a1，b0，b1
// ，每两个整数之间用一个空格隔开。

// 输入数据保证 a0
//  能被 a1
//  整除，b1
//  能被 b0
//  整除。

// 输出格式
// 输出共 n
//  行。

// 每组输入数据的输出结果占一行，为一个整数。

// 对于每组数据：若不存在这样的 x
// ，请输出 0
// ；

// 若存在这样的 x
// ，请输出满足条件的 x
//  的个数；

// 数据范围
// 1≤n≤2000
// ,
// 1≤a0,a1,b0,b1≤2?109
// 输入样例：
// 2
// 41 1 96 288
// 95 1 37 1776
// 输出样例：
// 6
// 2

/*
先初始化质数，然后将d分解质因数成p1^c1 + p2^c2 + ... + pn^cn 的形式，然后使用dfs将所有的约数都保存在一个数组中，
a和x的最大公约数是b，c和x的最小公倍数是d，那么只需要满足 gcd(a, x) == b && c * x / gcd(c, x) == d 这个条件就说明x这个数是满足要求的，res++
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 50010;
int primes[N], cnt;
bool st[N];
struct Factor{
    int p, s;
}factor[1601];
int fcnt;
int dividor[N], dcnt;
int n;

void init(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= n; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

void dfs(int u, int p){
    if(u == fcnt){
        dividor[dcnt++] = p;
        return;
    }
    for(int i = 0; i <= factor[u].s; i++){
        dfs(u + 1, p);
        p *= factor[u].p;
    }
}

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    init(N - 1);
    
    cin >> n;
    while(n--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        fcnt = 0;
        int t = d;
        for(int i = 0; primes[i] <= t / primes[i]; i++){
            int p = primes[i];
            if(t % p == 0){
                int s = 0;
                while(t % p == 0) t /= p, s++;
                factor[fcnt++] = {p, s};
            }
        }
        
        if(t > 1) factor[fcnt++] = {t, 1};
        
        dcnt = 0;
        dfs(0, 1);
        
        int res = 0;
        for(int i = 0; i < dcnt; i++){
            int x = dividor[i];
            if(gcd(a, x) == b && (LL)c * x / gcd(c, x) == d) res++;
        }
        cout << res << endl;
    }
    
    
    return 0;
}