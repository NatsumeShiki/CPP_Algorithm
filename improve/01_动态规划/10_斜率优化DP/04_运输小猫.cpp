// 小 S
//  是农场主，他养了 M
//  只猫，雇了 P
//  位饲养员。

// 农场中有一条笔直的路，路边有 N
//  座山，从 1
//  到 N
//  编号。

// 第 i
//  座山与第 i−1
//  座山之间的距离为 Di
// 。

// 饲养员都住在 1
//  号山。

// 有一天，猫出去玩。

// 第 i
//  只猫去 Hi
//  号山玩，玩到时刻 Ti
//  停止，然后在原地等饲养员来接。

// 饲养员们必须回收所有的猫。

// 每个饲养员沿着路从 1
//  号山走到 N
//  号山，把各座山上已经在等待的猫全部接走。

// 饲养员在路上行走需要时间，速度为 1
//  米/单位时间。

// 饲养员在每座山上接猫的时间可以忽略，可以携带的猫的数量为无穷大。

// 例如有两座相距为 1
//  的山，一只猫在 2
//  号山玩，玩到时刻 3
//  开始等待。

// 如果饲养员从 1
//  号山在时刻 2
//  或 3
//  出发，那么他可以接到猫，猫的等待时间为 0
//  或 1
// 。

// 而如果他于时刻 1
//  出发，那么他将于时刻 2
//  经过 2
//  号山，不能接到当时仍在玩的猫。

// 你的任务是规划每个饲养员从 1
//  号山出发的时间，使得所有猫等待时间的总和尽量小。

// 饲养员出发的时间可以为负。

// 输入格式
// 第一行包含三个整数 N，M，P
// 。

// 第二行包含 n−1
//  个整数，D2,D3,…,DN
// 。

// 接下来 M
//  行，每行包含两个整数 Hi
//  和 Ti
// 。

// 输出格式
// 输出一个整数，表示所有猫等待时间的总和的最小值。

// 数据范围
// 2≤N≤105
// ,
// 1≤M≤105
// ,
// 1≤P≤100
// ,
// 1≤Di<1000
// ,
// 1≤Hi≤N
// ,
// 0≤Ti≤109
// 输入样例：
// 4 6 2
// 1 3 5
// 1 0
// 2 1
// 4 9
// 1 10
// 2 10
// 3 12
// 输出样例：
// 3

/*
f[j, i]:j个饲养员，取前i只小猫的最小消费
f[j, i] = min{ f[j - 1, k] + a[i] * (i - k) - (s[i] - s[k]) }
f[j, i] = f[j - 1, k] - a[i] * k + s[k] + a[i] * i - s[i]
s[k] + f[j - 1, k] = a[i] * k + f[j, i] - a[i] * i + s[i]
斜率是a[i]，是递增的，a[i] = t[i] - d[i]，然后排序使他变成递增
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10, M = 1e5 + 10, P = 110;
int n, m, p;
LL d[N], t[N], a[N], s[N];
LL f[P][M];
int q[M];

LL get_y(int k, int j){
    return f[j - 1][k] + s[k];
}

int main(){
    cin >> n >> m >> p;
    for(int i = 2; i <= n; i++){
        cin >> d[i];
        d[i] += d[i - 1];
    }
    
    for(int i = 1; i <= m; i++){
        int h;
        cin >> h >> t[i];
        a[i] = t[i] - d[h];
    }
    sort(a + 1, a + m + 1);
    
    for(int i = 1; i <= m; i++) s[i] = s[i - 1] + a[i];
    
    memset(f, 0x3f, sizeof f);
    for(int i = 0; i <= p; i++) f[i][0] = 0; // i个饲养员，0只小猫花费是0
    
    for(int j = 1; j <= p; j++){
        int hh = 0, tt = 0;
        q[0] = 0;
        
        for(int i = 1; i <= m; i++){
            while(hh < tt && (get_y(q[hh + 1], j) - get_y(q[hh], j)) <= a[i] * (q[hh + 1] - q[hh])) hh++;
            int k = q[hh];
            f[j][i] = f[j - 1][k] - a[i] * k + s[k] + a[i] * i - s[i];
            while(hh < tt && (get_y(q[tt], j) - get_y(q[tt - 1], j)) * (i - q[tt]) >= 
                (get_y(i, j) - get_y(q[tt], j)) * (q[tt] - q[tt - 1])) tt--;
            q[++tt] = i;
        }
    }
    
    cout << f[p][m] << endl;
    
    return 0;
}