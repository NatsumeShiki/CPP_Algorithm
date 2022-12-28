// 糖果店的老板一共有 M 种口味的糖果出售。

// 为了方便描述，我们将 M 种口味编号 1∼M。

// 小明希望能品尝到所有口味的糖果。

// 遗憾的是老板并不单独出售糖果，而是 K 颗一包整包出售。

// 幸好糖果包装上注明了其中 K 颗糖果的口味，所以小明可以在买之前就知道每包内的糖果口味。

// 给定 N 包糖果，请你计算小明最少买几包，就可以品尝到所有口味的糖果。

// 输入格式
// 第一行包含三个整数 N,M,K。

// 接下来 N 行每行 K 个整数 T1,T2,⋅⋅⋅,TK，代表一包糖果的口味。

// 输出格式
// 一个整数表示答案。

// 如果小明无法品尝所有口味，输出 −1。

// 数据范围
// 1≤N≤100,
// 1≤M,K≤20,
// 1≤Ti≤M
// 输入样例：
// 6 5 3
// 1 1 2
// 1 2 3
// 1 1 3
// 2 3 5
// 5 4 2
// 5 1 2
// 输出样例：
// 2

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 110, M = 1 << 20;

int n, m, k;
vector<int> col[N];
int log2[M];

int lowbit(int x){
    return x & -x;
}

int h(int state){
    int res = 0;
    for(int i = (1 << m) - 1 - state; i; i -= lowbit(i)){
        int c = log2[lowbit(i)];
        res++;
        for(auto row : col[c]) i &= ~row;
    }
    return res;
}

bool dfs(int depth, int state){
    if(!depth || h(state) > depth) return state == (1 << m) - 1;
    
    int t = -1;
    for(int i = (1 << m) - 1 - state; i; i -= lowbit(i)){
        int c = log2[lowbit(i)];
        if(t == -1 || col[t].size() > col[c].size())
            t = c;
    }
    
    for(auto row : col[t])
        if(dfs(depth - 1, state | row))
            return true;
            
    return false;
}

int main(){
    cin >> n >> m >> k;
    
    for(int i = 0; i < m; i++) log2[1 << i] = i;
    for(int i = 0; i < n; i++){
        int state = 0;
        for(int j = 0; j < k; j++){
            int c;
            cin >> c;
            state |= 1 << c - 1;
        }
        
        for(int j = 0; j < m; j++)
            if(state >> j & 1)
                col[j].push_back(state);
    }
    
    for (int i = 0; i < m; i ++ ){
        sort(col[i].begin(), col[i].end());
        col[i].erase(unique(col[i].begin(), col[i].end()), col[i].end());
    }

    
    int depth = 0;
    while(depth <= m && !dfs(depth, 0)) depth++;
    
    if(depth > m) depth = -1;
    cout << depth << endl;
    
    return 0;
}