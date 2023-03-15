// 给定 n
//  对正整数 ai,bi
// ，请你求出每对数的最大公约数。

// 输入格式
// 第一行包含整数 n
// 。

// 接下来 n
//  行，每行包含一个整数对 ai,bi
// 。

// 输出格式
// 输出共 n
//  行，每行输出一个整数对的最大公约数。

// 数据范围
// 1≤n≤105
// ,
// 1≤ai,bi≤2×109
// 输入样例：
// 2
// 3 6
// 4 6
// 输出样例：
// 3
// 2

#include<iostream>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
    
    
    return 0;
}