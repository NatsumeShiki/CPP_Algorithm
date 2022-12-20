// 给定 n 个数组成的一个数列，规定有两种操作，一是修改某个元素，二是求子数列 [a,b] 的连续和。

// 输入格式
// 第一行包含两个整数 n 和 m，分别表示数的个数和操作次数。

// 第二行包含 n 个整数，表示完整数列。

// 接下来 m 行，每行包含三个整数 k,a,b （k=0，表示求子数列[a,b]的和；k=1，表示第 a 个数加 b）。

// 数列从 1 开始计数。

// 输出格式
// 输出若干行数字，表示 k=0 时，对应的子数列 [a,b] 的连续和。

// 数据范围
// 1≤n≤100000,
// 1≤m≤100000，
// 1≤a≤b≤n,
// 数据保证在任何时候，数列中所有元素之和均在 int 范围内。

// 输入样例：
// 10 5
// 1 2 3 4 5 6 7 8 9 10
// 1 1 5
// 0 1 3
// 0 4 8
// 1 7 5
// 0 4 8
// 输出样例：
// 11
// 30
// 35

// 树状数组
#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int n, m;
int a[N], tr[N];

int lowbit(int x){
    return x & -x;
}

void add(int x, int v){
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += v;
}

int query(int x){
    int res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) add(i, a[i]);
    
    while(m--){
        int k, x, y;
        scanf("%d%d%d", &k, &x, &y);
        if(k == 0) printf("%d\n", query(y) - query(x - 1));
        else add(x, y);
    }
    
    return 0;
}

// 线段树
/*
左孩子：u << 1，右孩子：u << 1 | 1
线段树的查询操作：从根节点开始，查看是否tr[u].l >= l && tr[u].r <= r，如果成立，就累加上，然后查看是否还有需要加的部分，如果有，就继续向下递归
修改操作：从根节点开始向下递归，直到找到那个位置，然后加上一个v，再回溯执行pushup操作，修改它们的sum值
*/
#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int w[N];
struct Node
{
    int l, r;
    int sum;
}tr[N * 4];

void pushup(int u){ // 给u位置赋sum值
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(int u, int l, int r){
    if(l == r) tr[u] = {l, r, w[r]}; // 查看是不是叶子，如果是叶子，那么可以直接赋值
    else { // 如果是根节点
        tr[u] = {l, r}; // 先把它的左右区间赋值
        int mid = l + r >> 1; // 然后计算中间值 
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r); // 然后向下递归，build下面的
        pushup(u); // 最后再执行pushup函数来给他的sum赋值
    }
}

int query(int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum; // 如果这一段是在要查询的[l,r]中，则直接返回
    int mid = tr[u].l + tr[u].r >> 1; // 否则，先求该区间的中间值
    int sum = 0; // sum来保存
    if(l <= mid) sum += query(u << 1, l, r); // 如果l是小于mid，那么肯定有值是在做区间，所以继续向左下递归，把结果累加到sum上
    if(r > mid) sum += query(u << 1 | 1, l, r); // 如果r是大于mid，就说明有值在右区间，所以向右下递归，把结果累加到sum上
    return sum; // sum就是结果
}

void modify(int u, int x, int v){
    if(tr[u].l == tr[u].r) tr[u].sum += v; // 如果查询到了叶子，就修改它的sum
    else{ // 否则二分向下递归，在指定的叶子节点修改
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
    build(1, 1, n);
    
    int k, a, b;
    while(m--){
        scanf("%d%d%d", &k, &a, &b);
        if(k == 0) printf("%d\n",  query(1, a, b));
        else modify(1, a, b);
    }
    
    return 0;
}