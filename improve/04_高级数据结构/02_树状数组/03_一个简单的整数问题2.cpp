// // 给定一个长度为 N
//  的数列 A
// ，以及 M
//  条指令，每条指令可能是以下两种之一：

// C l r d，表示把 A[l],A[l+1],…,A[r]
//  都加上 d
// 。
// Q l r，表示询问数列中第 l?r
//  个数的和。
// 对于每个询问，输出一个整数表示答案。

// 输入格式
// 第一行两个整数 N,M
// 。

// 第二行 N
//  个整数 A[i]
// 。

// 接下来 M
//  行表示 M
//  条指令，每条指令的格式如题目描述所示。

// 输出格式
// 对于每个询问，输出一个整数表示答案。

// 每个答案占一行。

// 数据范围
// 1≤N,M≤105
// ,
// |d|≤10000
// ,
// |A[i]|≤109
// 输入样例：
// 10 5
// 1 2 3 4 5 6 7 8 9 10
// Q 4 4
// Q 1 10
// Q 2 4
// C 3 6 3
// Q 2 4
// 输出样例：
// 4
// 55
// 9
// 15

/*
这道题在上一道的基础上又扩展了一点，原来是区间加，单点求和，现在是区间加区间求和
1.变差分 b[]
a[l ~ r] + c  ->  b[l] += c b[r + 1] -= c
2.a1 + ... + ax
= for(int i = 1; i <= n; i++) + a[i]
= for(int i = 1; i <= n; i++)
  for(int j = 1; j <= i; j++)
  ++b[j]

     b1 b2 b3 ... bx
  1  b1 ...       bx
  2  b1 b2 ...    bx
  3  b1 b2 b3 ... bx
    .
    .
    .
  x  b1 b2 b3 ... bx  

可以得出公式 (b1 + b2 + ... + bx) * (x + 1) - (1 * b1 + 2 * b2 + 3 * b3 + ... + x * bx)
所以可以维护两个数组
tr1：bi的前缀和
tr2：bi * i的前缀和
*/
#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int n, m;
int a[N];
LL tr1[N], tr2[N];

int lowbit(int x){
    return x & -x;
}

void add(LL tr[], int x, LL c){
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

LL sum(LL tr[], int x){
    LL res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

LL prefix_sum(int x){
    return sum(tr1, x) * (x + 1) - sum(tr2, x);
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        add(tr1, i, a[i] - a[i - 1]); // tr1[i] += a[i] - a[i - 1]
        add(tr2, i, (LL)(a[i] - a[i - 1]) * i); // tr2[i] += (a[i] - a[i - 1]) * i
    }

    while(m--){
        char op[2];
        int l, r, c;
        scanf("%s%d%d", op, &l, &r);
        if(op[0] == 'C'){
            scanf("%d", &c);
            add(tr1, l, c), add(tr1, r + 1, -c); // tr1[l] += c tr1[r + 1] -= c
            add(tr2, l, c * l), add(tr2, r + 1, -c * (r + 1)); // tr2[l] += l * c tr2[r + 1] += (r + 1) * c
        }else printf("%lld\n", prefix_sum(r) - prefix_sum(l - 1)); 
    }
    
    return 0;
}