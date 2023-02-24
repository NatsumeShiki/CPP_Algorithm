// 地图上有 N
//  个目标，用整数 Xi,Yi
//  表示目标在地图上的位置，每个目标都有一个价值 Wi
// 。

// 注意：不同目标可能在同一位置。

// 现在有一种新型的激光炸弹，可以摧毁一个包含 R×R
//  个位置的正方形内的所有目标。

// 激光炸弹的投放是通过卫星定位的，但其有一个缺点，就是其爆炸范围，即那个正方形的边必须和 x，y
//  轴平行。

// 求一颗炸弹最多能炸掉地图上总价值为多少的目标。

// 输入格式
// 第一行输入正整数 N
//  和 R
// ，分别代表地图上的目标数目和正方形包含的横纵位置数量，数据用空格隔开。

// 接下来 N
//  行，每行输入一组数据，每组数据包括三个整数 Xi,Yi,Wi
// ，分别代表目标的 x
//  坐标，y
//  坐标和价值，数据用空格隔开。

// 输出格式
// 输出一个正整数，代表一颗炸弹最多能炸掉地图上目标的总价值数目。

// 数据范围
// 0≤R≤109

// 0<N≤10000
// ,
// 0≤Xi,Yi≤5000

// 0≤Wi≤1000
// 输入样例：
// 2 1
// 0 0 1
// 1 1 1
// 输出样例：
// 1

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 5010;
int s[N][N];
int cnt, r;
int n, m;

int main(){
    cin >> cnt >> r;
    r = min(r, 5001);
    n = m = r;
    while(cnt--){
        int x, y, w;
        cin >> x >> y >> w;
        x++, y++;
        n = max(n, x);
        m = max(m, y);
        s[x][y] += w;
    }
    
    int res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            res = max(res, s[i][j] - s[max(i - r, 0)][j] - s[i][max(j - r, 0)] + s[max(i - r, 0)][max(j - r, 0)]);
    }
        
    cout << res << endl;
    
    return 0;
}