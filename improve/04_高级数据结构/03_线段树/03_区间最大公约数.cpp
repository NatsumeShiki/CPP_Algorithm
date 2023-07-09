// 给定一个长度为 N
//  的数列 A
// ，以及 M
//  条指令，每条指令可能是以下两种之一：

// C l r d，表示把 A[l],A[l+1],…,A[r]
//  都加上 d
// 。
// Q l r，表示询问 A[l],A[l+1],…,A[r]
//  的最大公约数(GCD
// )。
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
// N≤500000,M≤100000
// ,
// 1≤A[i]≤1018
// ,
// |d|≤1018
// ,
// 保证数据在计算过程中不会超过 long long 范围。

// 输入样例：
// 5 5
// 1 3 5 7 9
// Q 1 5
// C 1 5 1
// Q 1 5
// C 3 3 6
// Q 2 4
// 输出样例：
// 1
// 2
// 4

/*
用a数组存储数据
node里面存储区间的最大公约数和差分b[i]的和
a1, a2, ... an的最大公约数等于a1, a2 - a1, ... an - a(n-1)的最大公约数
所以修改区间里面的数，只需要将l和r+1的值改变即可
也就是说查询的结果是gcd(a[l], gcd(b[l + 1], b[l + 2], ... , b[r]))
*/
// 我的代码
#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 500010;
LL a[N];
int n, m;
struct node{
    int l, r;
    LL sum, d;
}tr[N * 4];

LL gcd(LL a, LL b){
    return b == 0 ? a : gcd(b, a % b);
}

void pushup(node &u, node &l, node &r){
    u.sum = l.sum + r.sum;
    u.d = gcd(l.d, r.d);
}

void pushup(int u){
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r){
    if(l == r) tr[u] = {l, r, a[l] - a[l - 1], a[l] - a[l - 1]};
    else{
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }        
}

void modify(int u, int x, LL v){
    if(tr[u].l == x && tr[u].r == x) tr[u] = {x, x, tr[u].sum + v, tr[u].d + v};
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

LL query1(int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].d;
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        LL res = 0;
        if(l <= mid) res = gcd(res, query1(u << 1, l, r));
        if(r > mid) res = gcd(res, query1(u << 1 | 1, l, r));
        return res;
    }
}

LL query2(int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        LL res = 0;
        if(l <= mid) res += query2(u << 1, l, r);
        if(r > mid) res += query2(u << 1 | 1, l, r);
        return res;
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    build(1, 1, n);
    
    while(m--){
        char op[2];
        int l, r;
        LL d;
        scanf("%s%d%d", op, &l, &r);
        if(op[0] == 'C'){
            scanf("%lld", &d);
            modify(1, l, d);
            if(r + 1 <= n) modify(1, r + 1, -d);
        }else{
            printf("%lld\n", abs(gcd(query2(1, 1, l), query1(1, l + 1, r))));
        }
    }
    
    return 0;
}

// 线段树 + 树状数组
#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 500010;
LL a[N];
int n, m;
struct node{
    int l, r;
    LL d;
}tr[N * 4];
LL tr1[N];

LL lowbit(LL x){
    return x & -x;
}

void add(int x, LL c){
    for(int i = x; i <= n; i += lowbit(i)) tr1[i] += c;
}

LL sum(int x){
    LL res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tr1[i];
    return res;
}

LL gcd(LL a, LL b){
    return b == 0 ? a : gcd(b, a % b);
}

void pushup(node &u, node &l, node &r){
    u.d = gcd(l.d, r.d);
}

void pushup(int u){
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r){
    if(l == r) tr[u] = {l, r, a[l] - a[l - 1]};
    else{
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }        
}

void modify(int u, int x, LL v){
    if(tr[u].l == x && tr[u].r == x) tr[u] = {x, x, tr[u].d + v};
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

LL query(int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].d;
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        LL res = 0;
        if(l <= mid) res = gcd(res, query(u << 1, l, r));
        if(r > mid) res = gcd(res, query(u << 1 | 1, l, r));
        return res;
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]), add(i, a[i] - a[i - 1]);
    build(1, 1, n);
    
    while(m--){
        char op[2];
        int l, r;
        LL d;
        scanf("%s%d%d", op, &l, &r);
        if(op[0] == 'C'){
            scanf("%lld", &d);
            modify(1, l, d), add(l, d);
            if(r + 1 <= n) modify(1, r + 1, -d), add(r + 1, -d);
        }else{
            printf("%lld\n", abs(gcd(sum(l), query(1, l + 1, r))));
        }
    }
    
    return 0;
}

// y总的代码
#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 500010;
int n, m;
LL w[N];
struct node{
    int l, r;
    LL sum, d;
}tr[N * 4];

LL gcd(LL a, LL b){
    return b ? gcd(b, a % b) : a;
}

void pushup(node &u, node &l, node &r){
    u.sum = l.sum + r.sum;
    u.d = gcd(l.d, r.d);
}

void pushup(int u){
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r){
    if(l == r){
        LL b = w[l] - w[l - 1];
        tr[u] = {l, r, b, b}; 
    }else{
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, LL v){
    if(tr[u].l == x && tr[u].r == x){
        LL b = tr[u].sum + v;
        tr[u] = {x, x, b, b};
    }else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

node query(int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u];
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(r <= mid) return query(u << 1, l, r);
        else if(l > mid) return query(u << 1 | 1, l, r);
        else{
            auto left = query(u << 1, l, r);
            auto right = query(u << 1 | 1, l, r);
            node res;
            pushup(res, left, right);
            return res;
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", &w[i]);
    build(1, 1, n);
    
    int l, r;
    LL d;
    char op[2];
    while(m--){
        scanf("%s%d%d", op, &l, &r);
        if(*op == 'Q'){
            auto left = query(1, 1, l);
            node right({0, 0, 0, 0});
            if(l + 1 <= r) right = query(1, l + 1, r);
            printf("%lld\n", abs(gcd(left.sum, right.d)));
        }else{
            scanf("%lld\n", &d);
            modify(1, l, d);
            if(r + 1 <= n) modify(1, r + 1, -d);
        }
    }
    
    
    return 0;
}