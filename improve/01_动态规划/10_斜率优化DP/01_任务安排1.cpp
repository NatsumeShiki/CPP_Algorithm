// 有 N
//  个任务排成一个序列在一台机器上等待执行，它们的顺序不得改变。

// 机器会把这 N
//  个任务分成若干批，每一批包含连续的若干个任务。

// 从时刻 0
//  开始，任务被分批加工，执行第 i
//  个任务所需的时间是 Ti
// 。

// 另外，在每批任务开始前，机器需要 S
//  的启动时间，故执行一批任务所需的时间是启动时间 S
//  加上每个任务所需时间之和。

// 一个任务执行后，将在机器中稍作等待，直至该批任务全部执行完毕。

// 也就是说，同一批任务将在同一时刻完成。

// 每个任务的费用是它的完成时刻乘以一个费用系数 Ci
// 。

// 请为机器规划一个分组方案，使得总费用最小。

// 输入格式
// 第一行包含整数 N
// 。

// 第二行包含整数 S
// 。

// 接下来 N
//  行每行有一对整数，分别为 Ti
//  和 Ci
// ，表示第 i
//  个任务单独完成所需的时间 Ti
//  及其费用系数 Ci
// 。

// 输出格式
// 输出一个整数，表示最小总费用。

// 数据范围
// 1≤N≤5000
// ,
// 0≤S≤50
// ,
// 1≤Ti,Ci≤100
// 输入样例：
// 5
// 1
// 1 3
// 3 2
// 4 3
// 2 3
// 1 4
// 输出样例：
// 153

/*
动态规划
  状态表示f[i]
    集合：将前i个任务处理完的所有方案的集合
    属性：Min
  状态计算
    枚举j从0到i-1，f[i] = min( f[j] + sumTi * (sumCi - sumCj) + s * (sumCn - sumCj) )，j = 0 ~ i-1
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 5050;
int n, s;
int sumt[N], sumc[N];
LL f[N];

int main(){
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        cin >> sumt[i] >> sumc[i];
        sumt[i] += sumt[i - 1];
        sumc[i] += sumc[i - 1];
    }
    
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < i; j++)
            f[i] = min(f[i], f[j] + (LL)sumt[i] * (sumc[i] - sumc[j]) + (LL)s * (sumc[n] - sumc[j]));
    
    cout << f[n] << endl;
    
    return 0;
}