// 输入 a,b，求 Cba 的值。

// 注意结果可能很大，需要使用高精度计算。

// 输入格式
// 共一行，包含两个整数 a 和 b。

// 输出格式
// 共一行，输出 Cba 的值。

// 数据范围
// 1≤b≤a≤5000
// 输入样例：
// 5 3
// 输出样例：
// 10


/*
  C(a, b)等于 (a * (a - 1) * ... * (a - b + 1))/(b * (b - 1) * ... * 1)
  可以变换成 C(a, b) = a! / (b! * (a - b)!) = p1^a1 + p2^a2 + ... + pn^an
  先求出a的所有质数保存在数组primes中，再通过这个质数来获取每个质数对应的指数，保存在sum数组中
  具体实现方法是：当底数是p是，a! = [a/p](向下取整) + [a/p^2](向下取整) + ... + [a/p^n(直到p^n不会大于a)](向下取整)
  通过get函数来实现上面的想法，所以对于 C(a, b) = a! / (b! * (a - b)!) = p1^a1 + p2^a2 + ... + pn^an，
  底数是p1时，指数是get(a, p) - get(b, p) - get(a - b, p)，将这些保存到sum数组中
  最后通过高精度乘法乘起来就可以了
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 5010;
int primes[N], cnt;
int sum[N];
bool st[N];

// 获取质数
void get_primes(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] <= n / i; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

// 获取某个质数的指数
int get(int n, int p){
    int res = 0;
    while(n){
        res += n / p;
        n /= p;
    }
    return res;
}

// 高精度乘法
vector<int> mul(vector<int> a, int b){
    vector<int> c;
    int t = 0;
    for(int i = 0; i < a.size(); i++){
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while(t){
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}

int main(){
    int a, b;
    cin >> a >> b;
    get_primes(a); // 获取a中所有的质数
    for(int i = 0; i < cnt; i++){
        int p = primes[i];
        sum[i] = get(a, p) - get(b, p) - get(a - b, p); // 将a的每个质数的指数都保存在sum数组中
    }
    vector<int> res; // 高精度乘法的结果保存到这里面
    res.push_back(1);
    for(int i = 0; i < cnt; i++)
        for(int j = 0; j < sum[i]; j++)
            res = mul(res, primes[i]); // 一共有cnt个质数，每个质数的次数是sum[i]，所以通过双重循环来实现乘积
    for(int i = res.size() - 1; i >= 0; i--) cout << res[i]; // 最后，将res从后往前输出
    return 0;
}