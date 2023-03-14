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
// ，输出 b−a
//  最大的一组。

// 若无解，输出 Goldbach's conjecture is wrong.。

// 数据范围
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

#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e6 + 10;
int primes[N], cnt;
bool st[N];
int n;

void get_primes(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] <= n / i; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main(){
    get_primes(N - 1);
    while(cin >> n, n){
        int l = 0, r = cnt - 1;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(primes[mid] <= n) l = mid;
            else r = mid - 1;
        }
        for(int i = r; i > 0; i--){
            l = 0, r = i;
            while(l < r){
                int mid = l + r >> 1;
                if(primes[mid] + primes[i] >= n) r = mid;
                else l = mid + 1;
            }
            if(primes[l] + primes[i] == n){
                printf("%d = %d + %d\n", n, primes[l], primes[i]);
                break;
            }
        }
    }
    
    return 0;
}

// 大佬的写法
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e6 + 10;
int primes[N], cnt;
bool st[N];
int n;

void get_primes(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] <= n / i; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main(){
    get_primes(N - 1);
    while(cin >> n, n){
        for(int i = 1; ; i++){
            int a = primes[i];
            int b = n - a;
            if(!st[b]){
                printf("%d = %d + %d\n", n, a, b);
                break;
            }
        }
    }
    
    return 0;
}