// 给定 n 组 ai,bi,pi，对于每组数据，求出 abiimodpi 的值。

// 输入格式
// 第一行包含整数 n。

// 接下来 n 行，每行包含三个整数 ai,bi,pi。

// 输出格式
// 对于每组数据，输出一个结果，表示 abiimodpi 的值。

// 每个结果占一行。

// 数据范围
// 1≤n≤100000,
// 1≤ai,bi,pi≤2×109
// 输入样例：
// 2
// 3 2 5
// 4 3 9
// 输出样例：
// 4
// 1

// 快速幂的方法是这样的：比如说 4 ^ 5 % 10，5的二进制表示为101，那么结果就是 4 ^ 5 % 10 = 4 ^ (101)二进制 % p = (4 ^ (2 ^ 0) + 4 ^ (2 ^ 2) ) % p
#include<iostream>
using namespace std;

typedef long long LL;

int qmi(int a, int b, int p){
    int res = 1;
    while(b){
        if(b & 1) res = (LL)res * a % p;
        b >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int a, b, p;
        cin >> a >> b >> p;
        cout << qmi(a, b, p) << endl;
    }
    
    
    return 0;
}