// 给定一个正整数数列 a1,a2,…,an
// ，每一个数都在 0?p?1
//  之间。

// 可以对这列数进行两种操作：

// 添加操作：向序列后添加一个数，序列长度变成 n+1
// ；
// 询问操作：询问这个序列中最后 L
//  个数中最大的数是多少。
// 程序运行的最开始，整数序列为空。

// 一共要对整数序列进行 m
//  次操作。

// 写一个程序，读入操作的序列，并输出询问操作的答案。

// 输入格式
// 第一行有两个正整数 m,p
// ，意义如题目描述；

// 接下来 m
//  行，每一行表示一个操作。

// 如果该行的内容是 Q L，则表示这个操作是询问序列中最后 L
//  个数的最大数是多少；

// 如果是 A t，则表示向序列后面加一个数，加入的数是 (t+a) mod p
// 。其中，t
//  是输入的参数，a
//  是在这个添加操作之前最后一个询问操作的答案（如果之前没有询问操作，则 a=0
// ）。

// 第一个操作一定是添加操作。对于询问操作，L>0
//  且不超过当前序列的长度。

// 输出格式
// 对于每一个询问操作，输出一行。该行只有一个数，即序列中最后 L
//  个数的最大数。

// 数据范围
// 1≤m≤2×105
// ,
// 1≤p≤2×109
// ,
// 0≤t<p
// 输入样例：
// 10 100
// A 97
// Q 1
// Q 1
// A 17
// Q 2
// A 63
// Q 1
// Q 1
// Q 3
// A 99
// 输出样例：
// 97
// 97
// 97
// 60
// 60
// 97
// 样例解释
// 最后的序列是 97,14,60,96
// 。

#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 200010;
int m, p;
struct Node{ // 线段树中每个节点存储的东西
    int l, r; // 左右两个端点表示它保存l到r之间数的最大值
    int v; // 区间[l, r]的最大值
}tr[N * 4];

void pushup(int u){ // 更新u节点所表示范围内的数的最大值
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

void build(int u, int l, int r){ // 建树
    tr[u] = {l, r}; // u节点保存的左右端点是l到r
    if(l == r) return; // 如果l等于r了，不用再往下建树了
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r); // 递归向下建树，u << 1 | 1意思是u / 2 + 1，用这种方法意思是u << 1不管u是奇数还是偶数，u<<1都是偶数，也就是向下取整了
}

int query(int u, int l, int r){ // 查询操作，查询l到r区间内的最大值
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].v; // 如果u节点的左右两个端点包含在l到r之间了，直接返回它所表示区间内的最大值即可
    int mid = tr[u].l + tr[u].r >> 1; // 获取中间节点下标
    int v = 0; // 保存最大值
    if(l <= mid) v = query(u << 1, l, r); // 如果l小于等于mid，就表示左半部分需要递归
    if(r > mid) v = max(v, query(u << 1 | 1, l, r)); // 如果r大于mid，就表示右半部分需要递归
    
    return v; // 返回查询区间内的最大值
}

void modify(int u, int x, int v){ // 修改操作
    if(tr[u].l == x && tr[u].r == x) tr[u].v = v; // 如果已经递归到了只有一个节点，直接修改它即可
    else{
        int mid = tr[u].l + tr[u].r >> 1; // 获取中点
        if(x <= mid) modify(u << 1, x, v); // 如果x在中点左边，递归左边修改
        else modify(u << 1 | 1, x, v); // 如果x在中点右边，递归右边修改
        pushup(u); // 修改完了之后需要向上修改最大值
    }
}

int main(){
    int n = 0, last = 0;
    scanf("%d%d", &m, &p);
    build(1, 1, m); // 建树，l是1，r是m，因为共有m个操作，如果都是插入那么最右边就是m
    
    int x;
    char op[2];
    while(m--){
        scanf("%s%d", op, &x);
        if(*op == 'Q'){ // 如果是查询操作
            last = query(1, n - x + 1, n); // 将n - x + 1 到 n之间的最大值保存在last中
            printf("%d\n", last);
        }else{ // 如果是修改操作
            modify(1, n + 1, ((LL)last + x) % p); // 从编号为1开始查找n+1所在节点，修改最大值
            n++;
        }
    }
    
    
    return 0;
}