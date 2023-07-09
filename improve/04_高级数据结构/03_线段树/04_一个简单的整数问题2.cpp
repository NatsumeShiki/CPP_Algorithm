// 给定一个长度为 N
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
区间修改区间查询，使用懒标记
给区间同时增加一个值时，修改懒标记add，经过pushdown操作可以将所以子节点都加上一个数
*/
#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int n, m;
int a[N];
struct node{
    int l, r;
    LL sum, add;
}tr[N * 4];

void pushup(int u){
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u){
    node &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if(root.add){ // 如果此时root的懒标记不为0
        left.add += root.add, left.sum += (LL)(left.r - left.l + 1) * root.add; // 将root的懒标记向下递给它的子节点，修改子节点的懒标记，并且修改子节点区间内的sum
        right.add += root.add, right.sum += (LL)(right.r - right.l + 1) * root.add;
        root.add = 0; 
    }
}

void build(int u, int l, int r){
    if(l == r) tr[u] = {l, r, a[l], 0};
    else{
        tr[u]  = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int d){
    if(tr[u].l >= l && tr[u].r <= r) {
        tr[u].sum += (LL)(tr[u].r - tr[u].l + 1) * d; // 给这个区间的sum每个数累加上d
        tr[u].add += d; // 修改懒标记
    }
    else{
        pushdown(u); // 先将u的懒标记向下传递，然后在向下修改
        int mid = tr[u].l + tr[u].r >> 1; 
        if(l <= mid) modify(u << 1, l, r, d);
        if(r > mid) modify(u << 1 | 1, l, r, d);
        pushup(u);
    }
}

LL query(int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    pushdown(u); // 先将u的懒标记向下传递
    int mid = tr[u].l + tr[u].r >> 1;
    LL res = 0;
    if(l <= mid) res += query(u << 1, l, r);
    if(r > mid) res += query(u << 1 | 1, l, r);
    return res;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(1, 1, n);
    
    while(m--){
        char op[2];
        int l, r, d;
        scanf("%s%d%d", op, &l, &r);
        if(op[0] == 'C'){
            scanf("%d", &d);
            modify(1, l, r, d);
        }else{
            printf("%lld\n", query(1, l, r));
        }
    }
    
    return 0;
}