// 岩石怪物杜达生活在魔法森林中，他在午餐时收集了 N
//  块能量石准备开吃。

// 由于他的嘴很小，所以一次只能吃一块能量石。

// 能量石很硬，吃完需要花不少时间。

// 吃完第 i
//  块能量石需要花费的时间为 Si
//  秒。

// 杜达靠吃能量石来获取能量。

// 不同的能量石包含的能量可能不同。

// 此外，能量石会随着时间流逝逐渐失去能量。

// 第 i
//  块能量石最初包含 Ei
//  单位的能量，并且每秒将失去 Li
//  单位的能量。

// 当杜达开始吃一块能量石时，他就会立即获得该能量石所含的全部能量（无论实际吃完该石头需要多少时间）。

// 能量石中包含的能量最多降低至 0
// 。

// 请问杜达通过吃能量石可以获得的最大能量是多少？

// 输入格式
// 第一行包含整数 T
// ，表示共有 T
//  组测试数据。

// 每组数据第一行包含整数 N
// ，表示能量石的数量。

// 接下来 N
//  行，每行包含三个整数 Si,Ei,Li
// 。

// 输出格式
// 每组数据输出一个结果，每个结果占一行。

// 结果表示为 Case #x: y，其中 x
//  是组别编号（从 1
//  开始），y
//  是可以获得的最大能量值。

// 数据范围
// 1≤T≤10
// ,
// 1≤N≤100
// ,
// 1≤Si≤100
// ,
// 1≤Ei≤105
// ,
// 0≤Li≤105
// 输入样例：
// 3
// 4
// 20 10 1
// 5 30 5
// 100 30 1
// 5 80 60
// 3
// 10 4 1000
// 10 3 1000
// 10 8 1000
// 2
// 12 300 50
// 5 200 0
// 输出样例：
// Case #1: 105
// Case #2: 8
// Case #3: 500
// 样例解释
// 在样例＃1中，有 N=4
//  个宝石。杜达可以选择的一个吃石头顺序是：

// 吃第四块石头。这需要 5
//  秒，并给他 80
//  单位的能量。
// 吃第二块石头。这需要 5
//  秒，并给他 5
//  单位的能量（第二块石头开始时具有 30
//  单位能量，5
//  秒后失去了 25
//  单位的能量）。
// 吃第三块石头。这需要 100
//  秒，并给他 20
//  单位的能量（第三块石头开始时具有 30
//  单位能量，10
//  秒后失去了 10
//  单位的能量）。
// 吃第一块石头。这需要 20
//  秒，并给他 0
//  单位的能量（第一块石头以 10
//  单位能量开始，110
//  秒后已经失去了所有的能量）。
// 他一共获得了 105
//  单位的能量，这是能获得的最大值，所以答案是 105
// 。

// 在样本案例＃2中，有 N=3
//  个宝石。

// 无论杜达选择吃哪块石头，剩下的两个石头的能量都会耗光。

// 所以他应该吃第三块石头，给他提供 8
//  单位的能量。

// 在样本案例＃3中，有 N=2
//  个宝石。杜达可以：

// 吃第一块石头。这需要 12
//  秒，并给他 300
//  单位的能量。
// 吃第二块石头。这需要 5
//  秒，并给他 200
//  单位的能量（第二块石头随着时间的推移不会失去任何能量！）。
// 所以答案是 500
// 。

/*
有两块能量石，分别是i和j，
方案1：先吃i，再吃j 能量：ei + ej - si * lj
方案2：先吃j，再吃i 能量：ej + ei - sj * li
如果 si * lj < sj * li，则方案1为更优解，反之方案2为更优解
所以可以得出一个结论，将 s / l 从小到大吃获得的能量最多

动态规划：
  状态表示f[i, j]
    集合 所有只从前i块能量石中选，且花费时间刚好等于j的方案
    属性：Max
  状态计算： f[i, j] = max(f[i - 1, j], f[i - 1, j - s] + e - (j - s) * l)
*/
// 二维
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, M = 10010;
int f[N][M];
struct stone{ // 能量石的结构体
    int s, e, l;
    bool operator<(const stone &t)const { // 定义<的比较方式
        return s * t.l < t.s * l;
    }
}stones[N];

int main(){
    int t;
    cin >> t;
    for(int c = 1; c <= t; c++) {
        int n, m = 0;
        cin >> n;
        m = 100 * n;
        for(int i = 1; i <= n; i++) {
            int s, e, l;
            cin >> s >> e >> l;
            stones[i] = {s, e, l};
        }
        
        sort(stones + 1, stones + n + 1);
        
        memset(f, -0x3f, sizeof f); // 先全部都定义成负无穷大
        f[0][0] = 0; // 从前0个选，花费时间恰好是0的方案获得能量最大值为0
        for(int i = 1; i <= n; i++){
            int s = stones[i].s, e = stones[i].e, l = stones[i].l;
            for(int j = 0; j <= m; j++){
                f[i][j] = f[i - 1][j];
                if(j >= s) f[i][j] = max(f[i][j], f[i - 1][j - s] + e - (j - s) * l);
            }
        }
        
        int res = 0;
        for(int i = 0; i <= m; i++) res = max(res, f[n][i]); // 查找一遍最大值
        printf("Case #%d: %d\n", c, res);
    }
    
    return 0;
}

// 一维
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, M = 10010;
int f[M];
int n;
struct stone{
    int s, e, l;
    bool operator <(const stone& t) const{
        return s * t.l < l * t.s;
    }
}stones[N];

int main(){
    int t;
    cin >> t;
    for(int c = 1; c <= t; c++){
        cin >> n;
        int m = 0;
        for(int i = 0; i < n; i++){
            int s, e, l;
            cin >> s >> e >> l;
            stones[i] = {s, e, l};
            m += s;
        }
        sort(stones, stones + n);
        memset(f, -0x3f, sizeof f);
        f[0] = 0;
        for(int i = 0; i < n; i++){
            int s = stones[i].s, e = stones[i].e, l = stones[i].l;
            for(int j = m; j >= s; j--)
                f[j] = max(f[j], f[j - s] + e - (j - s) * l);
        }
        
        int res = 0;
        for(int i = 0; i <= m; i++) res = max(res, f[i]);
        printf("Case #%d: %d\n", c, res);
    }
    
    return 0;
}