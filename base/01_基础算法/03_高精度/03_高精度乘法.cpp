// 给定两个非负整数（不含前导 0） A 和 B，请你计算 A×B 的值。

// 输入格式
// 共两行，第一行包含整数 A，第二行包含整数 B。

// 输出格式
// 共一行，包含 A×B 的值。

// 数据范围
// 1≤A的长度≤100000,
// 0≤B≤10000
// 输入样例：
// 2
// 3
// 输出样例：
// 6

#include<iostream>
#include<vector>
using namespace std;

vector<int> mul(vector<int> &A, int b){
    int t = 0; // 用来保存进行乘法的结果
    vector<int> C; // 用来保存最终的输出
    for(int i = 0; i < A.size() || t; i++){ // 如果A中的所有数还没有都用到或者t不为0，就继续循环
        if(i < A.size()) t += A[i] * b; // 如果此时还没有用A的最高位乘以b，就把乘法的结果加到t上
        C.push_back(t % 10); // 把t%10的结果保存到C中
        t /= 10; // 除去t的最后一位
    }
    // 把多余的0除去
    while(C.size() > 1 && C.back() == 0){
        C.pop_back();
    }
    return C;
}

int main(){
    
    string a; // 用来存储大的数
    int b; // 存储较小的那个数
    cin >> a >> b;
    
    vector<int> A; // 用来保存a中的数据
    for(int i = a.size() - 1; i >= 0; i--){
        A.push_back(a[i] - '0'); // 使a倒序并把字符转换成整型
    }
    
    vector<int> C = mul(A, b); // 获取结果
    for(int i = C.size() - 1; i >= 0; i--){
        cout << C[i]; // 输出结果
    }
    
    return 0;
}