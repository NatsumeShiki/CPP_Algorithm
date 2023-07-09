// 给定长度为 N
//  的数列 A
// ，以及 M
//  条指令，每条指令可能是以下两种之一：

// 1 x y，查询区间 [x,y]
//  中的最大连续子段和，即 maxx≤l≤r≤y
// {∑i=lrA[i]
// }。
// 2 x y，把 A[x]
//  改成 y
// 。
// 对于每个查询指令，输出一个整数表示答案。

// 输入格式
// 第一行两个整数 N,M
// 。

// 第二行 N
//  个整数 A[i]
// 。

// 接下来 M
//  行每行 3
//  个整数 k,x,y
// ，k=1
//  表示查询（此时如果 x>y
// ，请交换 x,y
// ），k=2
//  表示修改。

// 输出格式
// 对于每个查询指令输出一个整数表示答案。

// 每个答案占一行。

// 数据范围
// N≤500000,M≤100000
// ,
// ?1000≤A[i]≤1000
// 输入样例：
// 5 3
// 1 2 -3 4 5
// 1 2 3
// 2 2 -1
// 1 3 2
// 输出样例：
// 2
// -1

/*
1.单点修改 pushup
2.查询 区间内的最大字段和
struct node{
  int l, r;  区间左右端点
  int tmax;  最大连续字段和
  int lmax;  最大前缀和
  int rmax;  最大后缀和
  int sum;   区间和
}

tmax = max(leftson.tmax, rightson.tmax, leftson.rmax + rightson.lmax) 
计算最大连续子段和有三种情况，左孩子的最大连续子段和，右孩子的最大连续子段和，左孩子的最大右缀合加上右孩子的最大前缀和
lmax = max(leftson.lmax, leftson.sum + rightson.lmax)
计算最大前缀和有两种情况，左孩子的最大前缀和，左孩子的区间和加上右孩子的最大前缀和
*/
#include<iostream>
#include<cstring>
using namespace std;

using namespace std;
const int N = 500010;
int n, m;
int w[N];
struct node{
    int l, r;
    int sum, lmax, rmax, tmax;
}tr[N * 4];

void pushup(node &u, node &l, node &r){ // 根据u的左孩子和右孩子，修改u的值
    u.sum = l.sum + r.sum; // u的区间和等于左孩子的区间和加上右孩子的区间和
    u.lmax = max(l.lmax, l.sum + r.lmax); // u的前缀和等于左孩子的前缀和和左孩子区间和加上右孩子前缀和的较大值
    u.rmax = max(r.rmax, r.sum + l.rmax); // u的后缀和等于右孩子的右缀和和右孩子区间和加上左孩子后缀和的较大值
    u.tmax = max(max(l.tmax, r.tmax), l.rmax + r.lmax); // u的最大连续子段和等于左孩子的最大连续子段和和右孩子的最大连续子段和和左孩子的前缀和加右孩子的后缀和的最大值
}

void pushup(int u){
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r){ // 建树
    if(l == r) tr[u] = {l, r, w[r], w[r], w[r], w[r]}; // 如果l等于r，直接更新u的结果
    else{
        tr[u] = {l, r}; // 更新u的左右端点
        int mid = l + r >> 1; // 取中点
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r); // 向下建树
        pushup(u); // 再根据左右孩子更新u
    }
}

int modify(int u, int x, int v){
    if(tr[u].l == x && tr[u].r == x) tr[u] = {x, x, v, v, v, v}; // 如果找到了这个点，直接更新
    else{
        int mid = tr[u].l + tr[u].r >> 1; // 获取u的中点
        if(x <= mid) modify(u << 1, x, v); // 如果x在左孩子，修改左孩子
        else modify(u << 1 | 1, x, v); // 如果x在右孩子，修改右孩子
        pushup(u); // 修改父节点
    }
}

node query(int u, int l, int r){ // 查询l到r区间内的最大连续子段和
    if(tr[u].l >= l && tr[u].r <= r) return tr[u]; // 如果u节点的左右端点在l和r之间，返回u节点
    else{
        int mid = tr[u].l + tr[u].r >> 1; // 获取u节点的中点
        if(r <= mid) return query(u << 1, l, r); // 如果r小于等于mid，则查询的范围都在左孩子中，递归左孩子
        else if(l > mid) return query(u << 1 | 1, l, r); // 如果l大于mid，则查询的范围都在右孩子中，递归右孩子
        else{ // 如果既包含左孩子，又包含右孩子
            auto left = query(u << 1, l, r); // 获取left节点
            auto right = query(u << 1 | 1, l, r); // 获取right节点
            node res; // 结果
            pushup(res, left, right); // 修改res的值
            return res; // 返回结果
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &w[i]); // 保存一开始每个下标存储的值
    build(1, 1, n);
    
    int k, x, y;
    while(m--){
        scanf("%d%d%d", &k, &x, &y);
        if(k == 1){
            if(x > y) swap(x, y);
            printf("%d\n", query(1, x, y).tmax);
        }else modify(1, x, y);
    }
    
    return 0;
}