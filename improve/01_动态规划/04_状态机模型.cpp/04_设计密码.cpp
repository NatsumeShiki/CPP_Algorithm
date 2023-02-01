// 你现在需要设计一个密码 S
// ，S
//  需要满足：

// S
//  的长度是 N
// ；
// S
//  只包含小写英文字母；
// S
//  不包含子串 T
// ；
// 例如：abc
//  和 abcde
//  是 abcde
//  的子串，abd
//  不是 abcde
//  的子串。

// 请问共有多少种不同的密码满足要求？

// 由于答案会非常大，请输出答案模 109+7
//  的余数。

// 输入格式
// 第一行输入整数N，表示密码的长度。

// 第二行输入字符串T，T中只包含小写字母。

// 输出格式
// 输出一个正整数，表示总方案数模 109+7
//  后的结果。

// 数据范围
// 1≤N≤50
// ,
// 1≤|T|≤N
// ，|T|
// 是T
// 的长度。

// 输入样例1：
// 2
// a
// 输出样例1：
// 625
// 输入样例2：
// 4
// cbc
// 输出样例2：
// 456924

/*
动态规划
    状态表示f[i, j]
        集合：密码已经生成了i位，并且第i位匹配到子串中的位置为j时的方案
        属性：Count
    状态计算：
        枚举第i+1位的字母，从'a' - 'z'
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
    
const int N = 55, mod = 1e9 + 7;
int n, m;
char str[N];
int f[N][N];
    
int main(){
    cin >> n >> str + 1;
    m = strlen(str + 1);
    
    int next[N] = {0};
    for(int i = 2, j = 0; i <= m; i++){ // kmp求next数组
        while(j && str[i] != str[j + 1]) j = next[j];
        if(str[i] == str[j + 1]) j++;
        next[i] = j;
    }
    
    f[0][0] = 1; // 密码生成了0位，并且第0位匹配到子串中的位置为0的方案为1
    for(int i = 0; i < n; i++) // 枚举密码串的每一位
        for(int j = 0; j < m; j++) // 枚举匹配子串的位置，因为不能与m位匹配，所以小于m
            for(char k = 'a'; k <= 'z'; k++){ // 枚举小写字母
                int u = j;
                while(u && k != str[u + 1]) u = next[u]; // 查找u可以跳到哪个位置
                if(k == str[u + 1]) u++; // 如果与str[u + 1]匹配，u向后走一位
                if(u < m) f[i + 1][u] = (f[i + 1][u] + f[i][j]) % mod; // 把f[i, j]位置的数量累加到f[i + 1, u]位置上，因为可以跳到这个位置
            }
            
    int res = 0; // 最终，要把0 ~ m-1累加一遍
    for(int i = 0; i < m; i++) res = (res + f[n][i]) % mod;
    cout << res << endl;
    
    return 0;
}