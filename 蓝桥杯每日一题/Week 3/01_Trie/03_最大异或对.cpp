// 在给定的 N
//  个整数 A1，A2……AN
//  中选出两个进行 xor
// （异或）运算，得到的结果最大是多少？

// 输入格式
// 第一行输入一个整数 N
// 。

// 第二行输入 N
//  个整数 A1
// ～AN
// 。

// 输出格式
// 输出一个整数表示答案。

// 数据范围
// 1≤N≤105
// ,
// 0≤Ai<231
// 输入样例：
// 3
// 1 2 3
// 输出样例：
// 3

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 3100010;
int tr[N][2], cnt[N], idx;
int n;

void insert(int x){
    int p = 0;
    for(int i = 30; i >= 0; i--){
        int u = x >> i & 1;
        if(!tr[p][u]) tr[p][u] = ++idx;
        p = tr[p][u];
    }
}

int query(int x){
    int p = 0, res = 0;
    for(int i = 30; i >= 0; i--){
        int u = x >> i & 1;
        if(tr[p][!u]) p = tr[p][!u], res = res * 2 + !u;
        else p = tr[p][u], res = res * 2 + u;
    }
    return res;
}

int main(){
    cin >> n;
    int res = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        res = max(res, query(x) ^ x);
        insert(x);
    }
    
    cout << res << endl;
    
    return 0;
}