// 给定 n 个正整数 ai，将每个数分解质因数，并按照质因数从小到大的顺序输出每个质因数的底数和指数。

// 输入格式
// 第一行包含整数 n。

// 接下来 n 行，每行包含一个正整数 ai。

// 输出格式
// 对于每个正整数 ai，按照从小到大的顺序输出其分解质因数后，每个质因数的底数和指数，每个底数和指数占一行。

// 每个正整数的质因数全部输出完毕后，输出一个空行。

// 数据范围
// 1≤n≤100,
// 2≤ai≤2×109
// 输入样例：
// 2
// 6
// 8
// 输出样例：
// 2 1
// 3 1

// 2 3

// 时间复杂度 O(sqrt(n))  最坏情况是O(sqrt(n)),最好情况O(logn)
#include<iostream>
using namespace std;

void divide(int n){
    for(int i = 2; i <= n / i; i++){
        if(n % i == 0){ // 这个i一定是质数
            int s = 0;
            while(n % i == 0){
                n /= i;
                s++;
            }
            cout << i << " " << s << endl;;
        }
    }
    if(n > 1) cout << n << " " << "1" << endl; // n中最多只包含一个大于sqrt(n)的质因子，在这种情况下就是大于sqrt(n)的质因子
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        divide(x);
    }
    
    return 0;
}