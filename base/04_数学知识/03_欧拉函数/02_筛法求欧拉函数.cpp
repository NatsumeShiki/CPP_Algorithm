// 给定一个正整数 n，求 1∼n 中每个数的欧拉函数之和。

// 输入格式
// 共一行，包含一个整数 n。

// 输出格式
// 共一行，包含一个整数，表示 1∼n 中每个数的欧拉函数之和。

// 数据范围
// 1≤n≤106
// 输入样例：
// 6
// 输出样例：
// 12

#include<iostream>
using namespace std;

typedef long long LL;
const int N = 1e6 + 10;
int primes[N], cnt, phi[N]; // primes是保存质数，cnt是质数的个数，phi数组保存每个数的欧拉函数
bool st[N]; // 这个数组保存每个数的欧拉函数是否已经确定了

LL get_eulers(int x){
    for(int i = 2; i <= x; i++){
        if(!st[i]){ // 走到这里说明i是个质数
            primes[cnt++] = i;
            phi[i] = i - 1; // 质数的欧拉函数是 这个质数 - 1
        }
        for(int j = 0; primes[j] <= x / i; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0)
            {  
                phi[primes[j] * i] = phi[i] * primes[j]; 
                // 如果 i % primes[j] == 0，表明primes[j]是i的一个约数，phi[i] = i * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk)
                // 那么可以推出来 phi[primes[j] * i] = primes[j] * i * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk)，这是因为primes[j]是i的一个约数
                // 而欧拉函数是只看底数，不看指数的，primes[j] * i 里面所有的质数，primes[j]是包含在里面的，所以只会改变指数，因此上述公式成立
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
            // 如果 i % primes[j] != 0，表明primes[j]不是i的一个约数，phi[i] = i * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk)
            // 那么可以推出来 phi[primes[j] * i] = primes[j] * i * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk) * (1 - 1/primes[j])
            // 这是因为primes[j]不是i里面的一个质数，但是primes[j]比i小，所以只要是primes[j]里面包含的质数，i是都有的，所以只需有根据欧拉函数
            // 再乘上 (1 - 1/primes[j]) 即可
        }
    }
    LL res = 1; // 因为1的欧拉函数是1，所以这里直接把1算进去，然后求和从第二个数开始
    for(int i = 2; i <= x; i++) res += phi[i];
    return res;
}

int main(){
    int n;
    cin >> n;
    cout << get_eulers(n) << endl;
    
    return 0;
}