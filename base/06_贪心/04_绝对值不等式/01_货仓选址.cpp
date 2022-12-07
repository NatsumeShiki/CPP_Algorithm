// 在一条数轴上有 N 家商店，它们的坐标分别为 A1∼AN。

// 现在需要在数轴上建立一家货仓，每天清晨，从货仓到每家商店都要运送一车商品。

// 为了提高效率，求把货仓建在何处，可以使得货仓到每家商店的距离之和最小。

// 输入格式
// 第一行输入整数 N。

// 第二行 N 个整数 A1∼AN。

// 输出格式
// 输出一个整数，表示距离之和的最小值。

// 数据范围
// 1≤N≤100000,
// 0≤Ai≤40000
// 输入样例：
// 4
// 6 2 9 1
// 输出样例：
// 12

// 我的做法
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6 + 10;
int d[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) scanf("%d", &d[i]);
    sort(d, d + n);
    int res = 0;
    for(int l = 0, r = n - 1; l < r; l++, r--) res += d[r] - d[l]; // 使用双指针，因为 xn - x - (x1 - x) = xn - x1，所以我觉得直接用后面的减去前面的
                                                                   // 然后累加即可
    printf("%d\n", res);
    
    return 0;
}

// 大佬的做法
/*
如果点的个数是奇数，那就选中间那个点，如果点的个数是偶数，就选择中间两个点的中间任意一个位置，包括断点
证明：f(x) = |x1 - x| + |x2 - x| + ... + |xn - x|
           = (|x1 - x| + |xn - x|) + (|x2 - x| + |x(n-1) - x|) + ...
           >= xn - x1 + x(n-1) - x2 ...
  采用分组的做法，每次选择两个边界的点，一个点到这两个点距离之和最小，那么这个点必定在这两个点中间，包括端点
  比如说有两个点a, b            __________a_________________b________________
  如果这个点x在a的左边，那么距离就是 d(ax) + d(ab)，如果这个点在b的右边，那么距离就是 d(bx) + d(ab)，而如果在中间，距离就是 d(ab)
  所以选择中间的那个点就是最优解，分成奇数个点和偶数个点两种 
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6 + 10;
int d[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) scanf("%d", &d[i]);
    sort(d, d + n);
    int res = 0;
    for(int i = 0; i < n; i++) res += abs(d[i] - d[n / 2]); // 每次计算该点到中间那个点的距离的绝对值，累加
    printf("%d\n", res);
    
    return 0;
}