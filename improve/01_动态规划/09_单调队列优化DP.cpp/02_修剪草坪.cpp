// 在一年前赢得了小镇的最佳草坪比赛后，FJ 变得很懒，再也没有修剪过草坪。

// 现在，新一轮的最佳草坪比赛又开始了，FJ 希望能够再次夺冠。

// 然而，FJ 的草坪非常脏乱，因此，FJ 只能够让他的奶牛来完成这项工作。

// FJ 有 N
//  只排成一排的奶牛，编号为 1
//  到 N
// 。

// 每只奶牛的效率是不同的，奶牛 i
//  的效率为 Ei
// 。

// 编号相邻的奶牛们很熟悉，如果 FJ 安排超过 K
//  只编号连续的奶牛，那么这些奶牛就会罢工去开派对。

// 因此，现在 FJ 需要你的帮助，找到最合理的安排方案并计算 FJ 可以得到的最大效率。

// 注意，方案需满足不能包含超过 K
//  只编号连续的奶牛。

// 输入格式
// 第一行：空格隔开的两个整数 N
//  和 K
// ；

// 第二到 N+1
//  行：第 i+1
//  行有一个整数 Ei
// 。

// 输出格式
// 共一行，包含一个数值，表示 FJ 可以得到的最大的效率值。

// 数据范围
// 1≤N≤105
// ,
// 0≤Ei≤109
// 输入样例：
// 5 2
// 1
// 2
// 3
// 4
// 5
// 输出样例：
// 12
// 样例解释
// FJ 有 5 只奶牛，效率分别为 1、2、3、4、5。

// FJ 希望选取的奶牛效率总和最大，但是他不能选取超过 2 只连续的奶牛。

// 因此可以选择第三只以外的其他奶牛，总的效率为 1 + 2 + 4 + 5 = 12。

// 方法一
/*
状态表示f[i]
  集合：从前i头牛中选，且合法的所有方案
  属性：Max
状态计算
  1.不选i  f[i - 1]
  2.选i  根据长度来划分 1 <= j <= k
  f[i] = max(f[i - j - 1] + s[i] - s[i - j]) = max(f[i - j - 1] - s[i - j]) + s[i] = g[i - j] + s[i]，将f[i - j - 1] - s[i - j] 替换成 g[i - j]
  用一个单调队列来维护g(i - j)
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int n, m;
LL s[N];
LL f[N];
int q[N]; 

LL g(int i){
    return f[i - 1] - s[i];
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        s[i] += s[i - 1]; // 前缀和
    }
    
    int hh = 0, tt = 0; // 选择第0头牛
    for(int i = 1; i <= n; i++){
        if(q[hh] < i - m) hh++; // 如果最小值单调下标小于了i - m，此时牛会罢工，所以hh向后走一步
        f[i] = max(f[i - 1], g(q[hh]) + s[i]); // 通过g函数获取f[i - j - 1] - s[i - j]
        while(hh <= tt && g(q[tt]) <= g(i)) tt--; // 按照g(i)从大到小排列
        q[++tt] = i;
    }
    
    cout << f[n] << endl;
    
    return 0;
}

// 方法二：
// 仿照烽火传递这道题，在k+1中必须有一只牛不工作，然后获取不工作牛的效率最小值，再用总和减去它即可
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int n, m;
LL w[N];
LL f[N];
int q[N];

int main(){
    cin >> n >> m;
    LL sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
        sum += w[i];
    }
    
    int hh = 0, tt = 0;
    for(int i = 1; i <= n; i++){
        if(q[hh] < i - m - 1) hh++;
        f[i] = f[q[hh]] + w[i];
        while(hh <= tt && f[q[tt]] >= f[i]) tt--;
        q[++tt] = i;
    }
    
    LL res = 1e18;
    for(int i = n; i >= n - m; i--) res = min(res, f[i]);
    
    cout << sum - res << endl;
    
    
    return 0;
}