// 一个商人穿过一个 N×N 的正方形的网格，去参加一个非常重要的商务活动。

// 他要从网格的左上角进，右下角出。

// 每穿越中间 1 个小方格，都要花费 1 个单位时间。

// 商人必须在 (2N−1) 个单位时间穿越出去。

// 而在经过中间的每个小方格时，都需要缴纳一定的费用。

// 这个商人期望在规定时间内用最少费用穿越出去。

// 请问至少需要多少费用？

// 注意：不能对角穿越各个小方格（即，只能向上下左右四个方向移动且不能离开网格）。

// 输入格式
// 第一行是一个整数，表示正方形的宽度 N。

// 后面 N 行，每行 N 个不大于 100 的正整数，为网格上每个小方格的费用。

// 输出格式
// 输出一个整数，表示至少需要的费用。

// 数据范围
// 1≤N≤100
// 输入样例：
// 5
// 1  4  6  8  10
// 2  5  7  15 17
// 6  8  9  18 20
// 10 11 12 19 21
// 20 23 25 29 33
// 输出样例：
// 109
// 样例解释
// 样例中，最小值为 109=1+2+5+7+9+12+19+21+33。

// 自己写出来的代码
// 这道题跟摘花生的差别就是这个是求最小值，所以到考虑边界为0的时候选择哪个，其他就没什么不同了
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;
int w[N][N];
int f[N][N];

int main(){
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            cin >> w[i][j];
            if(i == 1) f[i][j] = f[i][j - 1] + w[i][j];
            else if(j == 1) f[i][j] = f[i - 1][j] + w[i][j];
            else f[i][j] = min(f[i][j - 1], f[i - 1][j]) + w[i][j];
        }
            
    cout << f[n][n] << endl;
    return 0;
}

// 当然也可以先把f都设置成最大值，然后把f[1][0]和f[0][1]设为0，最后遍历一遍就可以了，因为再求f[1][1]的时候必须使用0，但是在f[2][0]和f[0][2]这些的时候
// 只能它的相邻有实际数据的格子
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;
int w[N][N];
int f[N][N];

int main(){
    int n;
    cin >> n;
    memset(f, 0x3f, sizeof f);
    f[1][0] = f[0][1] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            cin >> w[i][j];
            f[i][j] = min(f[i][j - 1], f[i - 1][j]) + w[i][j];
        }
            
    cout << f[n][n] << endl;
    return 0;
}

// 大佬的代码
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, INF = 1e9;

int n;
int w[N][N], f[N][N];

int main(){
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &w[i][j]);
            
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i == 1 && j == 1) f[i][j] = w[i][j];
            else{
                f[i][j] = INF;
                if(i > 1) f[i][j] = min(f[i][j], f[i - 1][j] + w[i][j]);
                if(j > 1) f[i][j] = min(f[i][j], f[i][j - 1] + w[i][j]);
            }
            
    printf("%d\n", f[n][n]);
    
    return 0;
}