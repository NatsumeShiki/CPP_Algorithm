// 对任意正整数 N
// ，计算 XNmod233333
//  的值。

// 输入格式
// 共一行，两个整数 X
//  和 N
// 。

// 输出格式
// 共一行，一个整数，表示 XNmod233333
//  的值。

// 数据范围
// 1≤X,N≤109
// 输入样例：
// 2 5
// 输出样例：
// 32

#include<iostream>
using namespace std;

typedef long long LL;
int p = 233333;

int qmi(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        b >>= 1;
    }
    return res;
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << qmi(a, b) << endl;
    
    return 0;
}