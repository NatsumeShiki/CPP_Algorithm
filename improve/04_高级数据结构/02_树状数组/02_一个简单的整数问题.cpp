// 给定长度为 N
//  的数列 A
// ，然后输入 M
//  行操作指令。

// 第一类指令形如 C l r d，表示把数列中第 l?r
//  个数都加 d
// 。

// 第二类指令形如 Q x，表示询问数列中第 x
//  个数的值。

// 对于每个询问，输出一个整数表示答案。

// 输入格式
// 第一行包含两个整数 N
//  和 M
// 。

// 第二行包含 N
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
// Q 4
// Q 1
// Q 2
// C 1 6 3
// Q 2
// 输出样例：
// 4
// 1
// 2
// 5

/*
在树状数组的基础上添加了差分，在l~r区间内每个数都添加上一个数，等价于直接保存原数组的差分数组，即add(i, a[i] - a[i - 1])
那么添加操作：add(l, c), add(r + 1, -c)
查询操作：sum(a)
*/
#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 1e6 + 10;
int a[N];
LL tr[N];
int n, m;

int lowbit(int x){
    return x & -x;
}

void add(int x, int c){
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

LL sum(int x){
    LL res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        add(i, a[i] - a[i - 1]);
    }
    
    while(m--){
        char op;
        int a, b, c;
        cin >> op >> a;
        if(op == 'C'){
            scanf("%d%d", &b, &c);
            add(a, c), add(b + 1, -c);
        }else printf("%lld\n", sum(a));
    }
    
    return 0;
}