// 奶牛贝茜正在学习如何在不同进制之间转换数字。

// 但是她总是犯错误，因为她无法轻易的用两个前蹄握住笔。

// 每当贝茜将数字转换为一个新的进制并写下结果时，她总是将其中的某一位数字写错。

// 例如，如果她将数字 14
//  转换为二进制数，那么正确的结果应为 1110
// ，但她可能会写下 0110
//  或 1111
// 。

// 贝茜不会额外添加或删除数字，但是可能会由于写错数字的原因，写下包含前导 0
//  的数字。

// 给定贝茜将数字 N
//  转换为二进制数字以及三进制数字的结果，请确定 N
//  的正确初始值（十进制表示）。

// 输入格式
// 第一行包含 N
//  的二进制表示，其中一位是错误的。

// 第二行包含 N
//  的三进制表示，其中一位是错误的。

// 输出格式
// 输出正确的 N
//  的值。

// 数据范围
// 0≤N≤109
// ，且存在唯一解。

// 输入样例：
// 1010
// 212
// 输出样例：
// 14
// 样例解释
// 14
//  在二进制下的正确表示为 1110
// ，在三进制下的正确表示为 112
// 。

#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
using namespace std;

const int N = 40;

int get(string s, int b){
    int res = 0;
    for(char c : s)
        res = res * b + c - '0';
    return res;
}

int main(){
    string a, b;
    cin >> a >> b;
    unordered_set<int> hash;
    
    for(int i = 0; i < a.size(); i++){
        a[i] ^= 1;
        if(a.size() > 1 && a[0] == '0'){
            a[i] ^= 1;
            continue;
        }
        hash.insert(get(a, 2));
        a[i] ^= 1;
    }
    
    for(int i = 0; i < b.size(); i++){
        char t = b[i];
        for(int j = 0; j < 3; j++){
            if(j + '0' == t) continue;
            b[i] = j + '0';
            int x = get(b, 3);
            if(hash.count(x)) {
                cout << x << endl;
                return 0;
            }
        }
        b[i] = t;
    }
    
    return 0;
}