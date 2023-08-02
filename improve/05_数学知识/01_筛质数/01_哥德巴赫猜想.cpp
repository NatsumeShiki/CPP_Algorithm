// 哥德巴赫猜想的内容如下：

// 任意一个大于 4
//  的偶数都可以拆成两个奇素数之和。

// 例如：

// 8=3+5

// 20=3+17=7+13

// 42=5+37=11+31=13+29=19+23
// 现在，你的任务是验证所有小于一百万的偶数能否满足哥德巴赫猜想。

// 输入格式
// 输入包含多组数据。

// 每组数据占一行，包含一个偶数 n
// 。

// 读入以 0
//  结束。

// 输出格式
// 对于每组数据，输出形如 n = a + b，其中 a,b
//  是奇素数。

// 若有多组满足条件的 a,b
// ，输出 b?a
//  最大的一组。

// 若无解，输出 Goldbach's conjecture is wrong.。

// 数据范围
// 输入最多包含 50006
//  组数据。
// 6≤n<106
// 输入样例：
// 8
// 20
// 42
// 0
// 输出样例：
// 8 = 3 + 5
// 20 = 3 + 17
// 42 = 5 + 37

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
bool st[N];
int primes[N], cnt;

void init(){
    for(int i = 2; i <= N; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] <= N / i; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main(){
    init();    
    int x;
    while(cin >> x, x){
        for(int i = 0; i < cnt; i++){
            int a = primes[i], b = x - primes[i];
            if(!st[b]){
                printf("%d = %d + %d\n", x, a, b);
                break;
            }
        }
    }
    
    return 0;
}