// 数学老师给小明出了一道等差数列求和的题目。

// 但是粗心的小明忘记了一部分的数列，只记得其中 N 个整数。

// 现在给出这 N 个整数，小明想知道包含这 N 个整数的最短的等差数列有几项？

// 输入格式
// 输入的第一行包含一个整数 N。

// 第二行包含 N 个整数 A1,A2,⋅⋅⋅,AN。(注意 A1∼AN 并不一定是按等差数
// 列中的顺序给出)

// 输出格式
// 输出一个整数表示答案。

// 数据范围
// 2≤N≤100000,
// 0≤Ai≤109
// 输入样例：
// 5
// 2 6 4 10 20
// 输出样例：
// 10
// 样例解释
// 包含 2、6、4、10、20 的最短的等差数列是 2、4、6、8、10、12、14、16、18、20。

/*
1. 获取数列后先排序
2. 然后设置公差d为0，然后用后面每个数与第一个数的差就最大公约数
3. 最终如果这个d为0，表明这个数列所有数都相同，输出n，否则，输出 (a[n - 1] - a[0]) / d + 1
一个数列的数的个数是 (a末 - a前) / d + 1，要让这个数最小化，则必须让(a末 - a前) / d，也就是让a末取尽可能小，a前尽可能大，d尽可能大
要实现这一点，就排序后让a末是a[n - 1]，a前是a[0]，然后这个d就是所有数与第一个数的差的最大公约数，0与任何数的最大公约数都是0
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;
int a[N];

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
} 

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    sort(a, a + n);
    
    int d = 0;
    for(int i = 1; i < n; i++) d = gcd(d, a[i] - a[0]);
    
    if(d){
        cout << (a[n - 1] - a[0]) / d + 1 << endl;
    }else{
        cout << n << endl;
    }
    return 0;
}