// 给定 n 个正整数 ai，判定每个数是否是质数。

// 输入格式
// 第一行包含整数 n。

// 接下来 n 行，每行包含一个正整数 ai。

// 输出格式
// 共 n 行，其中第 i 行输出第 i 个正整数 ai 是否为质数，是则输出 Yes，否则输出 No。

// 数据范围
// 1≤n≤100,
// 1≤ai≤231−1
// 输入样例：
// 2
// 2
// 6
// 输出样例：
// Yes
// No

// 时间复杂度 O(sqrt(n))
#include<iostream>
using namespace std;

bool is_prim(int x){
    if(x < 2) return false;
    for(int i = 2;  i <= x / i; i++) // 这里不要用 i <= sqrt(x) 因为每次算sqrt需要消耗时间  也不要用 i * i <= x 因为有溢出的风险
        if(x % i == 0) return false;
    return true;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if(is_prim(x)) cout << "Yes" << endl;
        else cout << "No" << endl;
    } 
    return 0;
}