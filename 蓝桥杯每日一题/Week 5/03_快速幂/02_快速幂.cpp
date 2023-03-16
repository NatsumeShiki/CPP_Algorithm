// 给定 n
//  组 ai,bi,pi
// ，对于每组数据，求出 abiimodpi
//  的值。

// 输入格式
// 第一行包含整数 n
// 。

// 接下来 n
//  行，每行包含三个整数 ai,bi,pi
// 。

// 输出格式
// 对于每组数据，输出一个结果，表示 abiimodpi
//  的值。

// 每个结果占一行。

// 数据范围
// 1≤n≤100000
// ,
// 1≤ai,bi,pi≤2×109
// 输入样例：
// 2
// 3 2 5
// 4 3 9
// 输出样例：
// 4
// 1

#include<iostream>
using namespace std;

typedef long long LL;
int n, a, b, p;

int qmi(){
    LL res = 1;
    while(b){
        if(b & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        b >>= 1;
    }
    return res;
}

int main(){
    cin >> n;
    while(n--){
        cin >> a >> b >> p;
        cout << qmi() << endl;
    }
    
    
    return 0;
}