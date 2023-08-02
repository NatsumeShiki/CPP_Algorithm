// 在一个平面直角坐标系的第一象限内，如果一个点 (x,y)
//  与原点 (0,0)
//  的连线中没有通过其他任何点，则称该点在原点处是可见的。

// 例如，点 (4,2)
//  就是不可见的，因为它与原点的连线会通过点 (2,1)
// 。

// 部分可见点与原点的连线如下图所示：

// 3090_1.png

// 编写一个程序，计算给定整数 N
//  的情况下，满足 0≤x，y≤N
//  的可见点 (x，y)
//  的数量（可见点不包括原点）。

// 输入格式
// 第一行包含整数 C
// ，表示共有 C
//  组测试数据。

// 每组测试数据占一行，包含一个整数 N
// 。

// 输出格式
// 每组测试数据的输出占据一行。

// 应包括：测试数据的编号（从 1
//  开始），该组测试数据对应的 N
//  以及可见点的数量。

// 同行数据之间用空格隔开。

// 数据范围
// 1≤N,C≤1000
// 输入样例：
// 4
// 2
// 4
// 5
// 231
// 输出样例：
// 1 2 5
// 2 4 13
// 3 5 21
// 4 231 32549

/*
左下角下标从0开始，两个互质的数可以看到它，因此使用欧拉函数算出每个数的互质的数的个数
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int ans[N];
int n;
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

void get(int n){
    int t = n;
    int sum = n;
    for(int i = 0; i < cnt && primes[i] <= t; i++){
        int p = primes[i];
        if(t % p == 0){
            int s = 0;
            while(t % p == 0) t /= p, s++;
            sum = sum * (p - 1) / p;
        }
    }
    if(t > 1) sum = sum * (t - 1) / t;
    ans[n] = sum;
}

int main(){
    init(N - 1);
    for(int i = 1; i < N; i++){
        get(i);
    }
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cin >> n;
        int res = 0;
        for(int i = 1; i <= n; i++) res += ans[i];
        printf("%d %d %d\n", i, n, res * 2 + 1);
    }
    
    return 0;
}

// 使用线性筛欧拉函数
#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int n;
int primes[N], cnt;
bool st[N];
int phi[N];

void init(int n){
    phi[1] = 1;
    for(int i = 2; i <= n; i++){
        if(!st[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; primes[j] * i <= n; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) {
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }
}


int main(){
    init(N - 1);
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cin >> n;
        int res = 0;
        for(int i = 1; i <= n; i++) res += phi[i];
        printf("%d %d %d\n", i, n, res * 2 + 1);
    }
    
    return 0;
}