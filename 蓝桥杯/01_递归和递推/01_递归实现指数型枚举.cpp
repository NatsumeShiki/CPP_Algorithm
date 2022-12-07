// 从 1∼n 这 n 个整数中随机选取任意多个，输出所有可能的选择方案。

// 输入格式
// 输入一个整数 n。

// 输出格式
// 每行输出一种方案。

// 同一行内的数必须升序排列，相邻两个数用恰好 1 个空格隔开。

// 对于没有选任何数的方案，输出空行。

// 本题有自定义校验器（SPJ），各行（不同方案）之间的顺序任意。

// 数据范围
// 1≤n≤15
// 输入样例：
// 3
// 输出样例：

// 3
// 2
// 2 3
// 1
// 1 3
// 1 2
// 1 2 3


#include<iostream>
using namespace std;

const int N = 15;
bool st[N]; // 记录状态，表示某个数是否选择
int n;

void dfs(int u){
    
    if(u > n){ // 如果u>n，表示到了最后一个数，此时把st为true的输出
        for(int i = 1; i <= n; i++)
            if(st[i]) cout << i << " ";
        cout << endl;
        return;
    }
    
    // 如果u不选，就把st[u]置为false，然后向下递归
    st[u] = false;
    dfs(u + 1);
    // 如果u选择，就把st[u]置为true,然后继续向下递归
    st[u] = true;
    dfs(u + 1);
}

int main(){
    cin >> n;
    dfs(1);
    
    return 0;
}

// 下面这种方法是把所有的方案数保存下来
/*
#include<iostream>
#include<vector>
using namespace std;

const int N = 16;
bool st[N];
int n;
vector<vector<int>> ways; // vector中每个vector都是一个方案

void dfs(int u){
    
    if(u > n){
        vector<int> way;
        for(int i = 1; i <= n; i++)
            if(st[i]) way.push_back(i); // 把所有st为true的都存进way中
        ways.push_back(way); // 把way存进ways中，表示是一种方案
        return;
    }
    
    
    st[u] = false;
    dfs(u + 1);
    
    st[u] = true;
    dfs(u + 1);
}

int main(){
    cin >> n;
    dfs(1);
    
    // 把所有方案输出
    for(int i = 0; i < ways.size(); i++){
        for(int j = 0; j < ways[i].size(); j++)
            cout << ways[i][j] << " ";
        puts("");
    }
    
    return 0;
}
*/