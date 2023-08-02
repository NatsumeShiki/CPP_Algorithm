// 给定两个整数 L
//  和 U
// ，你需要在闭区间 [L,U]
//  内找到距离最接近的两个相邻质数 C1
//  和 C2
// （即 C2?C1
//  是最小的），如果存在相同距离的其他相邻质数对，则输出第一对。

// 同时，你还需要找到距离最远的两个相邻质数 D1
//  和 D2
// （即 D1?D2
//  是最大的），如果存在相同距离的其他相邻质数对，则输出第一对。

// 输入格式
// 每行输入两个整数 L
//  和 U
// ，其中 L
//  和 U
//  的差值不会超过 106
// 。

// 输出格式
// 对于每个 L
//  和 U
// ，输出一个结果，结果占一行。

// 结果包括距离最近的相邻质数对和距离最远的相邻质数对。（具体格式参照样例）

// 如果 L
//  和 U
//  之间不存在质数对，则输出 There are no adjacent primes.。

// 数据范围
// 1≤L<U≤231?1
// 输入样例：
// 2 17
// 14 17
// 输出样例：
// 2,3 are closest, 7,11 are most distant.
// There are no adjacent primes.

/*
这道题要使用一条性质：x是合数，那么存在p <= 50000，使得x可以被p整除，并且需要p小于x
1.找出1~50000中的所有质因子
2.对于1~50000中的每个质数p，将[L, R]中所有p的倍数筛掉（至少两倍）
虽然l和r很大，但是偏移量不大，筛的时候要从(l / p)向上取整在乘以p开始筛，可以转化成(l + p - 1) / p * p，最后还要在它和2p之间取最大值，免得把自身给筛掉了
在埃氏筛法中也是从两倍开始的
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1e6 + 10;
int primes[N], cnt;
bool st[N];

void init(int n){
    memset(st, 0, sizeof st);
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= n; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main(){
    int l, r;
    init(50000);
    while(cin >> l >> r){
        memset(st, 0, sizeof st);
        for(int i = 0; i < cnt; i++){
            LL p = primes[i];
            for(LL j = max(p * 2, (l + p - 1) / p * p); j <= r; j += p){
                st[j - l] = true;
                // cout << j - l << " ";
            }
            // cout << endl;
        }
        vector<int> alls;
        for(int i = 0; i <= r - l; i++){
            if(!st[i] && i + l != 1)
                alls.push_back(i + l);
        }
                
        if(alls.size() == 1) puts("There are no adjacent primes.");
        else{
            int a = 1, b = 1;
            for(int i = 1; i < (int)alls.size(); i++){
                int len = alls[i] - alls[i - 1];
                if(len < alls[a] - alls[a - 1]) a = i;
                if(len > alls[b] - alls[b - 1]) b = i;
            }
            printf("%d,%d are closest, %d,%d are most distant.\n", alls[a - 1], alls[a], alls[b - 1], alls[b]);
        }
    }
    
    return 0;
}