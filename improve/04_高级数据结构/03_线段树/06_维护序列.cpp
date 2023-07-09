// 老师交给小可可一个维护数列的任务，现在小可可希望你来帮他完成。

// 有长为 N
//  的数列，不妨设为 a1,a2,…,aN
// 。

// 有如下三种操作形式：

// 把数列中的一段数全部乘一个值；
// 把数列中的一段数全部加一个值；
// 询问数列中的一段数的和，由于答案可能很大，你只需输出这个数模 P
//  的值。
// 输入格式
// 第一行两个整数 N
//  和 P
// ；

// 第二行含有 N
//  个非负整数，从左到右依次为 a1,a2,…,aN
// ；

// 第三行有一个整数 M
// ，表示操作总数；

// 从第四行开始每行描述一个操作，输入的操作有以下三种形式：

// 操作 1
// ：1 t g c，表示把所有满足 t≤i≤g
//  的 ai
//  改为 ai×c
// ；
// 操作 2
// ：2 t g c，表示把所有满足 t≤i≤g
//  的 ai
//  改为 ai+c
// ；
// 操作 3
// ：3 t g，询问所有满足 t≤i≤g
//  的 ai
//  的和模 P
//  的值。
// 同一行相邻两数之间用一个空格隔开，每行开头和末尾没有多余空格。

// 输出格式
// 对每个操作 3
// ，按照它在输入中出现的顺序，依次输出一行一个整数表示询问结果。

// 数据范围
// 1≤N,M≤105
// ,
// 1≤t≤g≤N
// ,
// 0≤c,ai≤109
// ,
// 1≤P≤109
// 输入样例：
// 7 43
// 1 2 3 4 5 6 7
// 5
// 1 2 5 5
// 3 2 4
// 2 3 7 9
// 3 1 3
// 3 4 7
// 输出样例：
// 2
// 35
// 8
// 样例解释
// 初始时数列为 {1,2,3,4,5,6,7}
// ；

// 经过第 1
//  次操作后，数列为 {1,10,15,20,25,6,7}
// ；

// 对第 2
//  次操作，和为 10+15+20=45
// ，模 43
//  的结果是 2
// ；

// 经过第 3
//  次操作后，数列为 {1,10,24,29,34,15,16}
// ；

// 对第 4
//  次操作，和为 1+10+24=35
// ，模 43
//  的结果是 35
// ；

// 对第 5
//  次操作，和为 29+34+15+16=94
// ，模 43
//  的结果是 8
// 。

/*
这道题需要保存两个懒标记，分别是mul和add
现在需要讨论的是，如果u节点同时有mul和add两个懒标记，则需要先进行哪个的运算
如果先加后乘，比如说(((x + a) * b) + c) * d，在同时存在两个懒标记，要在进行加和乘的操作，很复杂
如果先乘后加，比如说(x * a + b) * c + d，那么结果就是 x * ac + bc + d，比较方便，因此采用这种方法

题目的修改两个种，为了合并成为一种，有下面这种方法
如果是乘 *c + d, d = 0，那么 x * c + d = x * c
如果是加 *c + d, c = 1，那么 x * c + d = x * 1 + d = x + d
*/
#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 100010;
int n, m, p;
int w[N];
struct node{
    int l, r;
    int sum, add, mul;
}tr[N * 4];

void pushup(int u){
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % p; // 计算两个子区间的和
}

// 对u节点进行乘和加运算
void eval(node &t, int add, int mul){
    t.sum = ((LL)t.sum * mul + (LL)(t.r - t.l + 1) * add) % p; // 先乘后加
    t.mul = (LL)t.mul * mul % p; // 修改节点的mul懒标记，(x * a + b) * c + d = x * ac + bc * d，所以t的mul懒标记只需要乘以c
    t.add = ((LL)t.add * mul + add) % p; // 修改节点的add懒标记，需要先乘后加
}

void pushdown(int u){ // 先修改两个子节点的sum和懒标记
    eval(tr[u << 1], tr[u].add, tr[u].mul);
    eval(tr[u << 1 | 1], tr[u].add, tr[u].mul);
    tr[u].add = 0, tr[u].mul = 1; // 清空u的懒标记
}

void build(int u, int l, int r){ // 建树
    if(l == r) tr[u] = {l, r, w[l], 0, 1}; 
    else{
        tr[u] = {l, r, 0, 0, 1};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int add, int mul){ // 修改操作
    if(tr[u].l >= l && tr[u].r <= r) eval(tr[u], add, mul); // 如果区间全覆盖，直接修改sum和懒标记
    else{
        pushdown(u); // 先将u的懒标记向下传递
        int mid = tr[u].l + tr[u].r >> 1; // 修改子区间
        if(l <= mid) modify(u << 1, l, r, add, mul);
        if(r > mid) modify(u << 1 | 1, l, r, add, mul);
        pushup(u); // 向上修改sum
    }
}

int query(int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int sum = 0;
    if(l <= mid) sum = query(u << 1, l, r);
    if(r > mid) sum = (sum + query(u << 1 | 1, l, r)) % p;
    return sum;
}

int main(){
    scanf("%d%d", &n, &p);
    for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
    build(1, 1, n);
    
    scanf("%d", &m);
    while(m--){
        int t, l, r, d;
        scanf("%d%d%d", &t, &l, &r);
        if(t == 1){
            scanf("%d", &d);
            modify(1, l, r, 0, d);
        }else if(t == 2){
            scanf("%d", &d);
            modify(1, l, r, d, 1);
        }else printf("%d\n", query(1, l, r));
    }
    
    
    return 0;
}