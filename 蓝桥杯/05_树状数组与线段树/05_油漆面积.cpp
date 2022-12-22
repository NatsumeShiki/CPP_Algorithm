// X星球的一批考古机器人正在一片废墟上考古。

// 该区域的地面坚硬如石、平整如镜。

// 管理人员为方便，建立了标准的直角坐标系。

// 每个机器人都各有特长、身怀绝技。

// 它们感兴趣的内容也不相同。

// 经过各种测量，每个机器人都会报告一个或多个矩形区域，作为优先考古的区域。

// 矩形的表示格式为 (x1,y1,x2,y2)，代表矩形的两个对角点坐标。

// 为了醒目，总部要求对所有机器人选中的矩形区域涂黄色油漆。

// 小明并不需要当油漆工，只是他需要计算一下，一共要耗费多少油漆。

// 其实这也不难，只要算出所有矩形覆盖的区域一共有多大面积就可以了。

// 注意，各个矩形间可能重叠。

// 输入格式
// 第一行，一个整数 n，表示有多少个矩形。

// 接下来的 n 行，每行有 4 个整数 x1,y1,x2,y2，空格分开，表示矩形的两个对角顶点坐标。

// 输出格式
// 一行一个整数，表示矩形覆盖的总面积。

// 数据范围
// 1≤n≤10000,
// 0≤x1,x2,y2,y2≤10000
// 数据保证 x1<x2 且 y1<y2。

// 输入样例1：
// 3
// 1 5 10 10
// 3 1 20 20
// 2 7 15 17
// 输出样例1：
// 340
// 输入样例2：
// 3
// 5 2 10 6
// 2 7 12 10
// 8 1 15 15
// 输出样例2：
// 128

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 10010;
int n;
struct Segment{
    int x, y1, y2;
    int k;
    bool operator < (const Segment &t) const{
        return x < t.x;
    }
}seg[N * 2];
struct Node{
    int l, r;
    int cnt, len;
}tr[N * 4];

void pushup(int u){
    if(tr[u].cnt > 0) tr[u].len = tr[u].r - tr[u].l + 1;
    else if(tr[u].l == tr[u].r) tr[u].len = 0;
    else tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
}

void build(int u, int l, int r){
    tr[u] = {l, r};
    if(l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

void modify(int u, int l, int r, int k){
    if(tr[u].l >= l && tr[u].r <= r){
        tr[u].cnt += k;
        pushup(u);
    }else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u << 1, l, r, k);
        if(r > mid) modify(u << 1 | 1, l, r, k);
        pushup(u);
    }
}

int main(){
    scanf("%d", &n);
    int m = 0;
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        seg[m++] = {x1, y1, y2, 1};
        seg[m++] = {x2, y1, y2, -1};
    }
    
    sort(seg, seg + m);
    
    build(1, 0, 10000);
    
    int res = 0;
    for(int i = 0; i < m; i++){
        if(i > 0) res += tr[1].len * (seg[i].x - seg[i - 1].x);
        modify(1, seg[i].y1, seg[i].y2 - 1, seg[i].k);
    }
    
    printf("%d\n", res);
    
    return 0;
}