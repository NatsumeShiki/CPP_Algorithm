// 给定一个整数 n
// ，将数字 1∼n
//  排成一排，将会有很多种排列方法。

// 现在，请你按照字典序将所有的排列方法输出。

// 输入格式
// 共一行，包含一个整数 n
// 。

// 输出格式
// 按字典序输出所有排列方案，每个方案占一行。

// 数据范围
// 1≤n≤7
// 输入样例：
// 3
// 输出样例：
// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1

#include<iostream>
#include<vector>
using namespace std;

const int N = 10;
bool st[N];
int n;
vector<int> res;

void dfs(int u){
    if(u == n){
        for(int i = 0; i <res.size(); i++) cout << res[i] << " ";
        cout << endl;
        return;
    }
    
    for(int i = 1; i <= n; i++){
        if(!st[i]){
            st[i] = true;
            res.push_back(i);
            dfs(u + 1);
            res.pop_back();
            st[i] = false;
        }
    }
}

int main(){
    cin >> n;
    dfs(0);
    
    return 0;
}