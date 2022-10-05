// 给定两个非负整数（不含前导 0） A，B，请你计算 A/B 的商和余数。

// 输入格式
// 共两行，第一行包含整数 A，第二行包含整数 B。

// 输出格式
// 共两行，第一行输出所求的商，第二行输出所求余数。

// 数据范围
// 1≤A的长度≤100000,
// 1≤B≤10000,
// B 一定不为 0
// 输入样例：
// 7
// 2
// 输出样例：
// 3
// 1

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> div(vector<int> &A, int b, int &r){
    vector<int> C; // 保存计算的结果
    r = 0; // 将余数重置为0
    for(int i = A.size() - 1; i >= 0; i--){
        r = r * 10 + A[i]; // 计算本次要被除的数
        C.push_back(r / b); // 将本次除法的结果保存
        r %= b; // 获取余数
    }
    reverse(C.begin(), C.end()); // 计算的结果是按照从大到小的顺序保存到C中的，所以需要将它倒序
    while(C.size() > 1 && C.back() == 0){ // 除去多余的0
        C.pop_back();
    }
    return C;
}

int main(){
    string a; // 保存被除的数
    int b; // 保存除数
    cin >> a >> b;
    
    vector<int> A; // 用于存储被除的数
    for(int i = a.size() - 1; i >= 0; i--){
        A.push_back(a[i] - '0'); // 将字符装换成整型
    }
    
    int r; // 用于保存余数
    auto C = div(A, b, r); // 计算结果

    for(int i = C.size() - 1; i >= 0; i--){ // 输出结果
        cout << C[i]; 
    }
    cout << endl << r << endl;

    return 0;
}