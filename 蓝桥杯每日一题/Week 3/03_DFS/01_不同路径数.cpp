// 给定一个 n×m
//  的二维矩阵，其中的每个元素都是一个 [1,9]
//  之间的正整数。

// 从矩阵中的任意位置出发，每次可以沿上下左右四个方向前进一步，走过的位置可以重复走。

// 走了 k
//  次后，经过的元素会构成一个 (k+1)
//  位数。

// 请求出一共可以走出多少个不同的 (k+1)
//  位数。

// 输入格式
// 第一行包含三个整数 n,m,k
// 。

// 接下来 n
//  行，每行包含 m
//  个空格隔开的整数，表示给定矩阵。

// 输出格式
// 输出一个整数，表示可以走出的不同 (k+1)
//  位数的个数。

// 数据范围
// 对于 30%
//  的数据, 1≤n,m≤2,0≤k≤2

// 对于 100%
//  的数据，1≤n,m≤5,0≤k≤5,m×n>1
// 输入样例：
// 3 3 2
// 1 1 1
// 1 1 1
// 2 1 1
// 输出样例：
// 5
// 样例解释
// 一共有 5
//  种可能的 3
//  位数：

// 111
// 112
// 121
// 211
// 212

#include<iostream>
#include<iostream>
#include<unordered_map>
using namespace std;

const int N = 7;
int g[N][N];
bool st[N][N];
int n, m, k;
unordered_map<int, int> d;
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

void dfs(int x, int y, int res, int cnt){
    if(cnt == k){
        if(!d.count(res)) d[res]++;
        return;
    }
    
    for(int i = 0; i < 4; i++){
        int a = x + dx[i], b = y + dy[i];
        if(a < 1 || a > n || b < 1 || b > m) continue;
        dfs(a, b, res * 10 + g[a][b], cnt + 1);
    }
}

int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> g[i][j];
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dfs(i, j, g[i][j], 0);
    cout << d.size();
    
    return 0;
}

#include<iostream>
#include<unordered_set>
using namespace std;

const int N = 10;
int g[N][N];
unordered_set<int> S;
int n, m, k;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

void dfs(int x, int y, int u, int num){
    if(u == k) {
        S.insert(num);
        return;
    }
    
    for(int i = 0; i < 4; i++){
        int a = x + dx[i], b = y + dy[i];
        if(a < 0 || a >= n || b < 0 || b >= m) continue;
        dfs(a, b, u + 1, num * 10 + g[a][b]);
    }
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];
            
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dfs(i, j, 0, g[i][j]);
            
    cout << S.size() << endl;
    
    return 0;
}