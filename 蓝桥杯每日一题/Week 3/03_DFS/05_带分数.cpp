// 100
//   可以表示为带分数的形式：100=3+69258714
// 还可以表示为：100=82+3546197
// 注意特征：带分数中，数字 1∼9
//  分别出现且只出现一次（不包含 0
// ）。

// 类似这样的带分数，100
//  有 11
//  种表示法。

// 输入格式
// 一个正整数。

// 输出格式
// 输出输入数字用数码 1∼9
//  不重复不遗漏地组成带分数表示的全部种数。

// 数据范围
// 1≤N<106
// 输入样例1：
// 100
// 输出样例1：
// 11
// 输入样例2：
// 105
// 输出样例2：
// 6

#include<iostream>
#include<vector>
using namespace std;

const int N = 10;
vector<int> d;
int n;
int ans;
bool st[N];

int get(int l, int r){
    int res = 0;
    for(int i = l; i <= r; i++)
        res = res * 10 + d[i];
    return res;
}

void dfs(int u){
    if(u == 9){
        for(int i = 0; i <= 6; i++)
            for(int j = i + 1; j <= 7; j++){
                int a = get(0, i);
                int b = get(i + 1, j);
                int c = get(j + 1, 8);
                if(a > n || b % c) continue;
                if(a + b / c == n) ans++;
            }
    }
    
    for(int i = 1; i <= 9; i++){
        if(!st[i]){
            st[i] = true;
            d.push_back(i);
            dfs(u + 1);
            d.pop_back();
            st[i] = false;
        }
    }
}

int main(){
    cin >> n;
    
    dfs(0);
    
    cout << ans << endl;
    
    
    return 0;
}