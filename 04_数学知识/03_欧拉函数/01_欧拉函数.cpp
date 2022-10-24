
// 给定 n 个正整数 ai，请你求出每个数的欧拉函数。

// 欧拉函数的定义
// 1∼N 中与 N 互质的数的个数被称为欧拉函数，记为 ϕ(N)。  互质是公约数只有1的两个整数，叫做互质整数。公约数只有1的两个自然数，叫做互质自然数
// 若在算数基本定理中，N=p1^a1 * p2^a2 * … * pm ^ am，则： p是底数
// ϕ(N) = N × (p1−1)/p1 × (p2−1)p2 × …× (pm−1)pm  
// 输入格式
// 第一行包含整数 n。

// 接下来 n 行，每行包含一个正整数 ai。

// 输出格式
// 输出共 n 行，每行输出一个正整数 ai 的欧拉函数。

// 数据范围
// 1≤n≤100,
// 1≤ai≤2×109
// 输入样例：
// 3
// 3
// 6
// 8
// 输出样例：
// 2
// 2
// 4

// 这道题就按照公式来做
#include<iostream>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        int res = x;
        for(int i = 2; i <= x / i; i++){
            if(x % i == 0){
                while(x % i == 0) x /= i;
                res = res / i * (i - 1); // 也可以写成 res = res - res * i
            }
        }
        if(x > 1) res = res / x * (x - 1); // 也可以写成 res = res - res * x
        cout << res << endl;
    }
    
    return 0;
}