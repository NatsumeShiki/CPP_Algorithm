// 给定 n 组 ai,pi，其中 pi 是质数，求 ai 模 pi 的乘法逆元，若逆元不存在则输出 impossible。

// 注意：请返回在 0∼p−1 之间的逆元。

// 乘法逆元的定义
// 若整数 b，m 互质，并且对于任意的整数 a，如果满足 b|a，则存在一个整数 x，使得 a/b≡a×x(modm)，则称 x 为 b 的模 m 乘法逆元，记为 b−1(modm)。
// b 存在乘法逆元的充要条件是 b 与模数 m 互质。当模数 m 为质数时，bm−2 即为 b 的乘法逆元。

// 输入格式
// 第一行包含整数 n。

// 接下来 n 行，每行包含一个数组 ai,pi，数据保证 pi 是质数。

// 输出格式
// 输出共 n 行，每组数据输出一个结果，每个结果占一行。

// 若 ai 模 pi 的乘法逆元存在，则输出一个整数，表示逆元，否则输出 impossible。

// 数据范围
// 1≤n≤105,
// 1≤ai,pi≤2∗109
// 输入样例：
// 3
// 4 3
// 8 5
// 6 3
// 输出样例：
// 1
// 2
// impossible

// 逆元的含义：如果a可以整除b，那么一定存在一个x，使得 a/b 等用于 a*x (mod m)，充分必要条件是 b和m互质
// 这道题本质上就是让求一个数x，使得 a * x 等同于 1 (mod p)
// 使用费马定理 a ^ (p - 1) 等同于 1 (mod p)
// 所以可以得到 a * a ^ (p - 2) 等同于 1 (mod p)
// 与最上面式子对比可以发现，只要通过快速幂就可以得到答案，也就是求 a ^ (p - 2) % p
// 注意，使用费马定理要求p一定要是质数，题目给出p是质数才可以这么做，否则不行
#include<iostream>
using namespace std;

typedef long long LL;

int qmi(int a, int k, int p){
    int res = 1;
    while(k){
        if(k & 1) res = (LL)res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int a, p;
        cin >> a >> p;
        if(a % p == 0) cout << "impossible" << endl; // 当a%p等于0的时候，a乘以任何数模p都是0
        else cout << qmi(a, p-2, p) << endl;
    }
    return 0;
}