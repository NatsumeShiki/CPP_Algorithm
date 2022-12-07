// 从 1∼n 这 n 个整数中随机选出 m 个，输出所有可能的选择方案。

// 输入格式
// 两个整数 n,m ,在同一行用空格隔开。

// 输出格式
// 按照从小到大的顺序输出所有方案，每行 1 个。

// 首先，同一行内的数升序排列，相邻两个数用一个空格隔开。

// 其次，对于两个不同的行，对应下标的数一一比较，字典序较小的排在前面（例如 1 3 5 7 排在 1 3 6 8 前面）。

// 数据范围
// n>0 ,
// 0≤m≤n ,
// n+(n−m)≤25
// 输入样例：
// 5 3
// 输出样例：
// 1 2 3 
// 1 2 4 
// 1 2 5 
// 1 3 4 
// 1 3 5 
// 1 4 5 
// 2 3 4 
// 2 3 5 
// 2 4 5 
// 3 4 5 

// 方法一
#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<int> num;

void dfs(int u){
    if(num.size() + n - u + 1 < m) return; // 如果即使把后面所有数都用上也不足以有m个数，就直接return，否定这一种可能，也就是剪枝
    
    if(num.size() == m){ // 输出当前这种方案
        for(int i = 0; i < num.size(); i++) cout << num[i] << " ";
        puts("");
        return;
    }
    
    // 第一种是使用这个数，把它push进去，然后进入下一层递归
    num.push_back(u);
    dfs(u + 1);
    // 第二种是不选择这个数，所以要先还原状态，把push进去的那个数pop掉，然后进入下一层递归
    num.pop_back();
    dfs(u + 1);
}

int main(){
    cin >> n >> m;
    dfs(1);
    return 0;
}

// 方法二
// 只是不适用vector，思路都是一样的
#include<iostream>
using namespace std;

const int N = 30;
int way[N];
int n, m;

// dfs的第一个参数是当前要填入第几个数，start表示这一个函数的循环要从多少开始，因为是字符集从小到大的
void dfs(int u, int start){
    if(u == m + 1){ // 当u等于m+1的时候，相当于已经决定了u-1个数，也就是m个数已经存进去了，输出这种方案
        for(int i = 1; i <= m; i++) cout << way[i] << " ";
        puts("");
        return;
    }
    
    for(int i = start; i <= n; i++){
        // 第一种是使用这个数，然后进入下一层递归
        way[u] = i; 
        dfs(u + 1, i + 1);

        // way[u] = 0; 可以省略，因为会被覆盖掉
    }
}

int main(){
    cin >> n >> m;
    dfs(1, 1);
    
    return 0;
}

// 方法三：方法二优化剪枝
#include<iostream>
using namespace std;

const int N = 30;
int way[N];
int n, m;

void dfs(int u, int start){
    
    if(u - 1 + n - start + 1 < m) return; // 剪枝
    
    if(u == m + 1){
        for(int i = 1; i <= m; i++) cout << way[i] << " ";
        puts("");
        return;
    }
    
    for(int i = start; i <= n; i++){
        way[u] = i;
        dfs(u + 1, i + 1);
    }
}

int main(){
    cin >> n >> m;
    dfs(1, 1);
    
    return 0;
}