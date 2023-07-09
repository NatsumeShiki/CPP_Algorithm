// 给定一个非负整数序列 a
// ，初始长度为 N
// 。

// 有 M
//  个操作，有以下两种操作类型：

// A x：添加操作，表示在序列末尾添加一个数 x
// ，序列的长度 N
//  增大 1
// 。
// Q l r x：询问操作，你需要找到一个位置 p
// ，满足 l≤p≤r
// ，使得：a[p] xor a[p+1] xor … xor a[N] xor x
//  最大，输出这个最大值。
// 输入格式
// 第一行包含两个整数 N，M
// ，含义如问题描述所示。

// 第二行包含 N
//  个非负整数，表示初始的序列 A
// 。

// 接下来 M
//  行，每行描述一个操作，格式如题面所述。

// 输出格式
// 每个询问操作输出一个整数，表示询问的答案。

// 每个答案占一行。

// 数据范围
// N,M≤3×105,0≤a[i]≤107
// 。

// 输入样例：
// 5 5
// 2 6 4 3 6
// A 1 
// Q 3 5 4 
// A 4 
// Q 5 7 0 
// Q 3 6 6 
// 输出样例：
// 4
// 5
// 6

#include<iostream>
#include<cstring>
using namespace std;

const int N = 600010, M = N * 25;
int n, m;
int s[N];
int tr[M][2], max_id[M];
int root[N], idx;

void insert(int i, int k, int p, int q){
    if(k < 0){
        max_id[q] = i;
        return;
    }
    int v = s[i] >> k & 1;
    if(p) tr[q][v ^ 1] = tr[p][v ^ 1];
    tr[q][v] = ++idx;
    insert(i, k - 1, tr[p][v], tr[q][v]);
    max_id[q] = max(max_id[tr[q][0]], max_id[tr[q][1]]);
}

int query(int root, int C, int L){
    int p = root;
    for(int i = 23; i >= 0; i--){
        int v = C >> i & 1;
        if(max_id[tr[p][v ^ 1]] >= L) p = tr[p][v ^ 1];
        else p = tr[p][v];
    }
    
    return C ^ s[max_id[p]];
}

int main(){
    scanf("%d%d", &n, &m);
    
    max_id[0] = -1;
    root[0] = ++idx;
    insert(0, 23, 0, root[0]);
    
    for(int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);
        s[i] = s[i - 1] ^ x;
        root[i] = ++idx;
        insert(i, 23, root[i - 1], root[i]);
    }
    
    char op[2];
    int l, r, x;
    while(m--){
        scanf("%s", op);
        if(*op == 'A'){
            scanf("%d", &x);
            n++;
            s[n] = s[n - 1] ^ x;
            root[n] = ++idx;
            insert(n, 23, root[n - 1], root[n]);
        }else{
            scanf("%d%d%d", &l, &r, &x);
            printf("%d\n", query(root[r - 1], s[n] ^ x, l - 1));
        }
    }
    
    return 0;
}