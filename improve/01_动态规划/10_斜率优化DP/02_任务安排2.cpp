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
// 1≤N≤3×105
// ,
// 1≤Ti,Ci≤512
// ,
// 0≤S≤512
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
只是做了数据方面的强化，目的是为了找出时间复杂度低的方法
f[i] = min{ f[j] + sumTi * (sumCi - sumCj) + s * (sumCn - sumCj) }
在这里面涉及到j的只有两个，分别是，f[j] 和 sumCj，把原来的式子变形一下是
f[i] = min{ f[j] - (sumTi + s) * sumCj + sumTi * sumCi + s * sumCn }
把f[j]想象成y，sumCj想象成x，把它变成y = kx * b的形式是
f[j] = (sumTi + s) * sumCj + f[i] - sumTi * sumCi - s * sumCn
有了这个式子，题目是要求f[i]的最小值，所以，要让它是最小值，只需要让斜率最小化即可
因此可以用单调队列来维护凸包

怎么在维护的凸包中找到截距最小的点？
相当于在一个单调队列中，找到第一个大于某一个数的点

斜率单调递增，新加的点的横坐标也单调递增
    在查询的时候，可以将队头小于当前斜率的点全部删掉  (f2 - f1) / (c2 - c1) <= sumTi + s 通过它来查找队头斜率大于当前斜率的点
    在插入的时候，将队尾所有不在凸包上的点全部删掉    (ftt - f(tt-1)) / (ctt - c(tt-1)) >= (fi - f(ff-1)) / (ci - c(tt-1)) 通过它来查找队尾不在凸包上的点
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 300010;
int n, s;
LL c[N], t[N];
LL f[N];
int q[N];

int main(){
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        cin >> t[i] >> c[i];
        t[i] += t[i - 1];
        c[i] += c[i - 1];
    }
    
    int hh = 0, tt = 0;
    q[0] = 0; // 将(0, 0)点放进队列中
    
    for(int i = 1; i <= n; i++){
        while(hh < tt && (f[q[hh + 1]] - f[q[hh]]) <= (t[i] + s) * (c[q[hh + 1]] - c[q[hh]])) hh++; // 找到队头斜率大于当前斜率的点 
        int j = q[hh]; // 保存该点
        f[i] = f[j] - (t[i] + s) * c[j] + t[i] * c[i] + s * c[n]; // 用上面的式子直接计算f[i]的最小值
        // 查找队尾所有不在凸包上的点，也就找斜率比该点到q[tt-1]斜率大的点，tt--来删掉他们
        while(hh < tt && (f[q[tt]] - f[q[tt - 1]]) * (c[i] - c[q[tt - 1]]) >= (f[i] - f[q[tt - 1]]) * (c[q[tt]] - c[q[tt - 1]])) tt--; 
        q[++tt] = i; // 把i存进队列中
    }
    
    cout << f[n] << endl;
    
    return 0;
}