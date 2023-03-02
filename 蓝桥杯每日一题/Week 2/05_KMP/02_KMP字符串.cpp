// 给定一个字符串 S
// ，以及一个模式串 P
// ，所有字符串中只包含大小写英文字母以及阿拉伯数字。

// 模式串 P
//  在字符串 S
//  中多次作为子串出现。

// 求出模式串 P
//  在字符串 S
//  中所有出现的位置的起始下标。

// 输入格式
// 第一行输入整数 N
// ，表示字符串 P
//  的长度。

// 第二行输入字符串 P
// 。

// 第三行输入整数 M
// ，表示字符串 S
//  的长度。

// 第四行输入字符串 S
// 。

// 输出格式
// 共一行，输出所有出现位置的起始下标（下标从 0
//  开始计数），整数之间用空格隔开。

// 数据范围
// 1≤N≤105

// 1≤M≤106
// 输入样例：
// 3
// aba
// 5
// ababa
// 输出样例：
// 0 2

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;
char p[N], s[N];
int n, m;
int ne[N];

int main(){
    cin >> n >> p + 1 >> m >> s + 1;
    for(int i = 2, j = 0; i <= n; i++){
        while(j && p[j + 1] != p[i]) j = ne[j];
        if(p[j + 1] == p[i]) j++;
        ne[i] = j;
    }
    
    for(int i = 1, j = 0; i <= m; i++){
        while(j && p[j + 1] != s[i]) j = ne[j];
        if(p[j + 1] == s[i]) j++;
        if(j == n){
            cout << i - j << " ";
            j = ne[j];
        }
    }
    
    return 0;
}