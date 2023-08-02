// 给定整数 N
// ，试把阶乘 N!
//  分解质因数，按照算术基本定理的形式输出分解结果中的 pi
//  和 ci
//  即可。

// 输入格式
// 一个整数 N
// 。

// 输出格式
// N!
//  分解质因数后的结果，共若干行，每行一对 pi,ci
// ，表示含有 pcii
//  项。按照 pi
//  从小到大的顺序输出。

// 数据范围
// 3≤N≤106
// 输入样例：
// 5
// 输出样例：
// 2 3
// 3 1
// 5 1
// 样例解释
// 5!=120=23?3?5

/*有馬（ありま）かな
拿6!来打比方
小于等于6的质数有2、3、5
枚举每个质数，然后一个循环从n开始，每次除以这个质数，直到0，6 / 2 等于3，表示从1-6中有3个数有质因子2，6 /= 2 = 3，然后3 / 2 等于1，表示有一个数有因子4，
它是质因子2的倍数，也累加上
依次做法枚举每个质数
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int primes[N], cnt;
bool st[N];

void init(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= n; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main(){
    int n;
    cin >> n;
    init(n);

    for(int i = 0; i < cnt; i++){
        int p = primes[i];
        int s = 0;
        for(int j = n; j; j /= p) s += j / p;
        cout << p << " " << s << endl;
    }
    
    return 0;
}