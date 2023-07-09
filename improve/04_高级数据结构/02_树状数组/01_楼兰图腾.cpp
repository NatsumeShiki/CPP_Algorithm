// 在完成了分配任务之后，西部 314
//  来到了楼兰古城的西部。

// 相传很久以前这片土地上(比楼兰古城还早)生活着两个部落，一个部落崇拜尖刀(V)，一个部落崇拜铁锹(∧)，他们分别用 V 和 ∧ 的形状来代表各自部落的图腾。

// 西部 314
//  在楼兰古城的下面发现了一幅巨大的壁画，壁画上被标记出了 n
//  个点，经测量发现这 n
//  个点的水平位置和竖直位置是两两不同的。

// 西部 314
//  认为这幅壁画所包含的信息与这 n
//  个点的相对位置有关，因此不妨设坐标分别为 (1,y1),(2,y2),…,(n,yn)
// ，其中 y1?yn
//  是 1
//  到 n
//  的一个排列。

// 西部 314
//  打算研究这幅壁画中包含着多少个图腾。

// 如果三个点 (i,yi),(j,yj),(k,yk)
//  满足 1≤i<j<k≤n
//  且 yi>yj,yj<yk
// ，则称这三个点构成 V 图腾;

// 如果三个点 (i,yi),(j,yj),(k,yk)
//  满足 1≤i<j<k≤n
//  且 yi<yj,yj>yk
// ，则称这三个点构成 ∧ 图腾;

// 西部 314
//  想知道，这 n
//  个点中两个部落图腾的数目。

// 因此，你需要编写一个程序来求出 V 的个数和 ∧ 的个数。

// 输入格式
// 第一行一个数 n
// 。

// 第二行是 n
//  个数，分别代表 y1，y2,…,yn
// 。

// 输出格式
// 两个数，中间用空格隔开，依次为 V 的个数和 ∧ 的个数。

// 数据范围
// 对于所有数据，n≤200000
// ，且输出答案不会超过 int64
// 。
// y1?yn
//  是 1
//  到 n
//  的一个排列。

// 输入样例：
// 5
// 1 5 3 2 4
// 输出样例：
// 3 4

#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 200010;

int n;
int a[N]; // 原数组
int tr[N]; // 
int bigger[N], lower[N]; // 保存比x大的数的个数，保存比x小的数的个数

int lowbit(int x){ 
    return x & -x;
}

void add(int x, int c){ // 将x添加到树状数组
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

int sum(int x){ // 求x的前缀和
    int res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++){
        int y = a[i];
        bigger[i] = sum(n) - sum(y); // 获取在i左边比y大的数的个数
        lower[i] = sum(y - 1); // 获取在i左边比y小的数的个数
        add(y, 1); // 将y添加进树状数组中
    }
    
    memset(tr, 0, sizeof tr); // 将tr数组清空
    LL res1 = 0, res2 = 0; // 分别保存两个结果
    for(int i = n; i; i--){ // 从大往小，意味着获取i右边比y大的和小的数的个数
        int y = a[i];
        res1 += bigger[i] * (LL)(sum(n) - sum(y)); // 获取i右边比y大的个数，与i左边的数的个数相乘
        res2 += lower[i] * (LL)(sum(y - 1)); // 获取i右边比i小的数的个数，与i左边的数的个数相乘
        add(y, 1); // 将y添加进树状数组中
    }
    
    printf("%lld %lld\n", res1, res2);
    
    return 0;
} 