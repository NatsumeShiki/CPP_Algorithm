// 给定 n
//  组询问，每组询问给定两个整数 a，b
// ，请你输出 Cbamod(109+7)
//  的值。

// 输入格式
// 第一行包含整数 n
// 。

// 接下来 n
//  行，每行包含一组 a
//  和 b
// 。

// 输出格式
// 共 n
//  行，每行输出一个询问的解。

// 数据范围
// 1≤n≤10000
// ,
// 1≤b≤a≤2000
// 输入样例：
// 3
// 3 1
// 5 3
// 2 2
// 输出样例：
// 3
// 10
// 1

#include<iostream>
using namespace std;

const int N = 2010, mod = 1e9 + 7;;
int n, a, b;
int c[N][N];

int main(){
    for(int i = 0; i < N; i++)
        for(int j = 0; j <= i; j++)
            if(!j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
            
    cin >> n;
    while(n--){
        int a, b;
        cin >> a >> b;
        cout << c[a][b] << endl;
    }
    
    return 0;
}