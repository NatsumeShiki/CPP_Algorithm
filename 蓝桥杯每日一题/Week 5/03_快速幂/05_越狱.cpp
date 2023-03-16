// 监狱有连续编号为 1
//  到 n
//  的 n
//  个房间，每个房间关押一个犯人。

// 有 m
//  种宗教，每个犯人可能信仰其中一种。

// 如果相邻房间的犯人信仰的宗教相同，就可能发生越狱。

// 求有多少种状态可能发生越狱。

// 输入格式
// 共一行，包含两个整数 m
//  和 n
// 。

// 输出格式
// 可能越狱的状态数，对 100003
//  取余。

// 数据范围
// 1≤m≤108
// ,
// 1≤n≤1012
// 输入样例：
// 2 3
// 输出样例：
// 6
// 样例解释
// 所有可能的 6
//  种状态为：(000)(001)(011)(100)(110)(111)
// 。

#include<iostream>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
int p = 100003;

ULL qmi(ULL a, ULL b){
    ULL res = 1;
    while(b){
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main(){
    ULL a, b;
    cin >> a >> b;
    ULL x = qmi(a, b);
    ULL y = a * qmi(a - 1, b - 1) % p;
    LL res = x - y;
    cout << (res % p + p) % p << endl;
    
    
    return 0;
}