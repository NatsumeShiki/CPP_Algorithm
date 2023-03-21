// 一个整数总可以拆分为 2
//  的幂的和。

// 例如：7
//  可以拆分成

// 7=1+2+4,7=1+2+2+2,7=1+1+1+4,7=1+1+1+2+2,

// 7=1+1+1+1+1+2,7=1+1+1+1+1+1+1

// 共计 6
//  种不同拆分方式。

// 再比如：4
//  可以拆分成：4=4,4=1+1+1+1,4=2+2,4=1+1+2
// 。

// 用 f(n)
//  表示 n
//  的不同拆分的种数，例如 f(7)=6
// 。

// 要求编写程序，读入 n
// ，输出 f(n)mod109
// 。

// 输入格式
// 一个整数 n
// 。

// 输出格式
// 一个整数，表示 f(n)mod109
// 。

// 数据范围
// 1≤N≤106
// 输入样例：
// 7
// 输出样例：
// 6

// 二维数组空间过大
#include<iostream>
using namespace std;

const int N = 25, M = 1e6 + 10, mod = 1e9;
int f[N][M];
int n;
int a[N];

int main(){
    a[1] = 1;
    for(int i = 2; i <= 21; i++) a[i] = a[i - 1] * 2;
    cin >> n;
    f[0][0] = 1;
    for(int i = 1; i <= 21; i++)
        for(int j = 0; j <= n; j++){
            f[i][j] = f[i - 1][j];
            if(j >= a[i]) f[i][j] = (f[i][j] + f[i][j - a[i]]) % mod;
        }
    
    cout << f[21][n] << endl;
    
    return 0;
}


// 使用一维可以过
#include<iostream>
using namespace std;

const int N = 25, M = 1e6 + 10, mod = 1e9;
int f[M];
int n;
int a[N];

int main(){
    a[1] = 1;
    for(int i = 2; i <= 21; i++) a[i] = a[i - 1] * 2;
    cin >> n;
    f[0] = 1;
    for(int i = 1; i <= 21; i++)
        for(int j = a[i]; j <= n; j++)
            f[j] = (f[j] + f[j - a[i]]) % mod;
    
    cout << f[n] << endl;
    
    return 0;
}