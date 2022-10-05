// 给定两个正整数（不含前导 0），计算它们的和。

// 输入格式
// 共两行，每行包含一个整数。

// 输出格式
// 共一行，包含所求的和。

// 数据范围
// 1≤整数长度≤100000
// 输入样例：
// 12
// 23
// 输出样例：
// 35

#include<iostream>
#include<vector>

using namespace std;
const int N = 1e6 + 10;

vector<int> add(vector<int> &A, vector<int> &B){
    vector<int> C;
    
    int t = 0; // 用来保存是否进位
    for(int i = 0; i < A.size() || i < B.size(); i++){
        if(i < A.size()) t += A[i]; // 如果此时i的下标还没有超出A的范围就加
        if(i < B.size()) t += B[i]; // 如果此时i的下标还没有超出B的范围就加
        C.push_back(t % 10); // 余10是因为相加的结果可能会大于10
        t /= 10; // 如果t大于10说明需要进一，所以结果就是下一次加会把这个进一也算上
    }
    
    if(t) C.push_back(1); // 此时如果t为0说明没有进位，如果t为1说明两个数相加后需要位数比二者都大
    return C;
}

int main(){
    string a, b; // 保存从控制台读取的两个数
    vector<int> A, B; // 保存两个数的倒序
    
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0'); // 把字符转换成整型
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    
    auto C = add(A, B);
    
    for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]); // 输出结果
    return 0;
}