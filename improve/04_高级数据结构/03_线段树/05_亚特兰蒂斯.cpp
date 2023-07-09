// 有几个古希腊书籍中包含了对传说中的亚特兰蒂斯岛的描述。

// 其中一些甚至包括岛屿部分地图。

// 但不幸的是，这些地图描述了亚特兰蒂斯的不同区域。

// 您的朋友 Bill 必须知道地图的总面积。

// 你自告奋勇写了一个计算这个总面积的程序。

// 输入格式
// 输入包含多组测试用例。

// 对于每组测试用例，第一行包含整数 n
// ，表示总的地图数量。

// 接下来 n
//  行，描绘了每张地图，每行包含四个数字 x1,y1,x2,y2
// （不一定是整数），(x1,y1)
//  和 (x2,y2)
//  分别是地图的左上角位置和右下角位置。

// 注意，坐标轴 x
//  轴从上向下延伸，y
//  轴从左向右延伸。

// 当输入用例 n=0
//  时，表示输入终止，该用例无需处理。

// 输出格式
// 每组测试用例输出两行。

// 第一行输出 Test case #k，其中 k
//  是测试用例的编号，从 1
//  开始。

// 第二行输出 Total explored area: a，其中 a
//  是总地图面积（即此测试用例中所有矩形的面积并，注意如果一片区域被多个地图包含，则在计算总面积时只计算一次），精确到小数点后两位数。

// 在每个测试用例后输出一个空行。

// 数据范围
// 1≤n≤10000
// ,
// 0≤x1<x2≤100000
// ,
// 0≤y1<y2≤100000

// 注意，本题 n
//  的范围上限加强至 10000
// 。

// 输入样例：
// 2
// 10 10 20 20
// 15 15 25 25.5
// 0
// 输出样例：
// Test case #1
// Total explored area: 180.00 

// 样例解释
// 样例所示地图覆盖区域如下图所示，两个矩形区域所覆盖的总面积，即为样例的解。


/*
操作1：将某个区间[l, r] 加 k
操作2：这个区间中，长度大于0的区间总长是多少

线段树中的节点信息
1.cnt：当前区间整个被覆盖次数
2.len：不考虑祖先节点cnt的前提下，cnt > 0的区间总长

1.永远只考虑根节点的信息 ——> 说明query时不需要pushdown
2.所有操作均是成对出现，且先加后减
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 100010;
int n;
struct Segment{ // 存储线段
    double x, y1, y2;
    int k; // 用于区分是矩形的前面还是后面
    bool operator < (const Segment &t)const{ // 排序，根据x坐标进行从小到大排序
        return x < t.x;
    }
}seg[N * 2]; // 每个矩形都有前面和后面，因此数组开N * 2
struct Node{ // 线段树的节点
    int l, r; // 区间的左右端点
    int cnt; // 区间被覆盖的次数
    double len; // 区间里面被覆盖的长度
}tr[N * 8]; // 线段有N * 2个，所以最多有4 * N * 2个区间
vector<double> ys; // 用于离散化

int find(double y){ // 返回第一个 >= y 的下标
    return lower_bound(ys.begin(), ys.end(), y) - ys.begin();
}

void pushup(int u){
    if(tr[u].cnt) tr[u].len = ys[tr[u].r + 1] - ys[tr[u].l]; // 表示整段区间都被覆盖，此时加上线段的长度，使用ys[tr[u].r + 1]因为它存储的是线段，ys[tr[u].r]存储的是线段的左端点，而这里需要的是右端点
    else if(tr[u].l != tr[u].r){ // 如果不是树叶节点
        tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len; // 则长度等于左右区间长度的和
    }else tr[u].len = 0; // 如果是树叶节点，直接将它的长度置为0
}

void build(int u, int l, int r){ // 建树
    tr[u] = {l, r, 0, 0}; // 一开始不管哪段区间，它的被覆盖次数都是0，被覆盖长度也都是0
    if(l != r){
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    }
}

void modify(int u, int l, int r, int k){ // 修改操作
    if(tr[u].l >= l && tr[u].r <= r){ // 如果整段区间都被覆盖
        tr[u].cnt += k; // 被覆盖次数加1,
        pushup(u); // 向上修改
    }else{
        int mid = tr[u].l + tr[u].r >> 1; //
        if(l <= mid) modify(u << 1, l, r, k);
        if(r > mid) modify(u << 1 | 1, l, r, k);
        pushup(u);
    }
}

int main(){
    int T = 1;
    while(scanf("%d", &n), n){
        ys.clear(); // 多组测试数据，清空vector
        for(int i = 0, j = 0; i < n; i++){
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            seg[j++] = {x1, y1, y2, 1}; // 存两条线段
            seg[j++] = {x2, y1, y2, -1};
            ys.push_back(y1), ys.push_back(y2); // 将y轴坐标存进ys中，用于离散化
        }
        
        sort(ys.begin(), ys.end()); // 除去ys中重复的数据
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        
        build(1, 0, ys.size() - 2); // 建树，因为存储的是线段，不是点，所以从0 ~ ys.size() - 2
        sort(seg, seg + n * 2); // 线段按照x轴进行排序
        
        double res = 0; // 结果
        for(int i = 0; i < n * 2; i++){
            if(i > 0) res += tr[1].len * (seg[i].x - seg[i - 1].x); // 加上总区间的被覆盖长度 * x轴的长度
            modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].k); // 将这条线段指定位置的cnt加上k，find(seg[i].y2) - 1是因为存储的是线段，
            // 也就是说y0存储的是y0 - y1的长度，那么如果想要y0 - y3之间的长度，只需要y0-y2即可
        }
        // 按照指定要求输出结果
        printf("Test case #%d\n", T++);
        printf("Total explored area: %.2lf\n\n", res);
    }
    
    return 0;
}