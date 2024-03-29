// Vani 和 cl2 在一片树林里捉迷藏。

// 这片树林里有 N
//  座房子，M
//  条有向道路，组成了一张有向无环图。

// 树林里的树非常茂密，足以遮挡视线，但是沿着道路望去，却是视野开阔。

// 如果从房子 A
//  沿着路走下去能够到达 B
// ，那么在 A
//  和 B
//  里的人是能够相互望见的。

// 现在 cl2 要在这 N
//  座房子里选择 K
//  座作为藏身点，同时 Vani 也专挑 cl2 作为藏身点的房子进去寻找，为了避免被 Vani 看见，cl2 要求这 K
//  个藏身点的任意两个之间都没有路径相连。

// 为了让 Vani 更难找到自己，cl2 想知道最多能选出多少个藏身点。

// 输入格式
// 输入数据的第一行是两个整数 N
//  和 M
// 。

// 接下来 M
//  行，每行两个整数 x,y
// ，表示一条从 x
//  到 y
//  的有向道路。

// 输出格式
// 输出一个整数，表示最多能选取的藏身点个数。

// 数据范围
// N≤200,M≤30000
// ,
// 1≤x,y≤N
// 。

// 输入样例：
// 7 5
// 1 2
// 3 2
// 2 4
// 4 5
// 4 6
// 输出样例：
// 3

// 这道题的方法就是先求传递闭包，然后求最小路径覆盖，结果就是n - 最小路径覆盖
#include<iostream>
#include<cstring>
using namespace std;

const int N = 210;
bool g[N][N], st[N];
int match[N];
int n, m;

int find(int x){
    for(int i = 1; i <= n; i++)
        if(!st[i] && g[x][i]){
            st[i] = true;
            int t = match[i];
            if(t == 0 || find(t)){
                match[i] = x;
                return true;
            }
        }
    return false;
}

int main(){
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        g[a][b] = true;
    }
    
    // 传递闭包
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= n; j++)
                g[i][j] |= g[i][k] & g[k][j];
                
    int res = 0;
    for(int i = 1; i <= n; i++){
        memset(st, 0, sizeof st);
        if(find(i)) res++;
    }
    cout << n - res << endl;
    
    return 0;
}