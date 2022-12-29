// X星球的考古学家发现了一批古代留下来的密码。

// 这些密码是由A、B、C、D 四种植物的种子串成的序列。

// 仔细分析发现，这些密码串当初应该是前后对称的（也就是我们说的镜像串）。

// 由于年代久远，其中许多种子脱落了，因而可能会失去镜像的特征。

// 你的任务是：

// 给定一个现在看到的密码串，计算一下从当初的状态，它要至少脱落多少个种子，才可能会变成现在的样子。

// 输入格式
// 共一行，包含一个由大写字母ABCD构成的字符串，表示现在看到的密码串。

// 输出格式
// 输出一个整数，表示至少脱落了多少个种子。

// 数据范围
// 输入字符串长度不超过1000

// 输入样例1：
// ABCBA
// 输出样例1：
// 0
// 输入样例2：
// ABDCDCBABC
// 输出样例2：
// 3

/*
听了大佬的讲解自己写出来的代码
题目求得可以转换成 在现在的字符串中查找最长的回文子串，然后用字符串总长度减去它即可
状态表示f[l][r]
  集合：所有 s[l~r]之间的回文子序列的集合
  属性：长度的最大值
状态计算：
  可以分成四部分 
    1.包含l和r，此时必须str[l] == str[r]，所以是f[l + 1][r - 1] + 2
    2.包含l，不包含r，注意，是必须包含l，所以需要在l+1到r-1中查找一个字符等于str[l]，但是不需要那么做，因为要求的是最大值，所以可以找一个涵盖它的即可，也就是f[l][r-1]
    3.不包含l，包含r，与上面一样，可以表示成 f[l + 1][r]
    4.不包含l和r，即f[l + 1][r - 1]，这个是包含在2、3这两种方案中的，所以可以直接忽略这个方案，即在前三种中选择较大值
*/
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1010;
char str[N];
int f[N][N];

int main(){
    cin >> str + 1;
    int n = strlen(str + 1);
    for(int len = 1; len <= n; len++){ // 枚举字符串长度
        for(int l = 1; l <= n - len + 1; l++){ // 枚举左边界
            int r = l + len - 1; // 计算右边界
            f[l][r] = max(f[l][r - 1], f[l + 1][r]);
            if(str[l] == str[r]){
                if(l == r) f[l][r] = 1;
                else  f[l][r] = max(f[l][r], f[l + 1][r - 1] + 2);
            }
        }
    }
    
    cout << n - f[1][n] << endl; // f[1][n]表示在字符串1~n中回文子串的最大长度，用总长度减去它
    return 0;
}

// 大佬的代码
#include<iostream>
#include<string.h>
using namespace std;

const int N = 1010;
char s[N];
int f[N][N];

int main(){
    scanf("%s", s);
    int n = strlen(s);
    
    for(int len = 1; len <= n; len++)
        for(int l = 0; l + len - 1 < n; l++){
            int r = l + len - 1;
            if(len == 1) f[l][r] = 1;
            else{
                if(s[l] == s[r]) f[l][r] = f[l + 1][r - 1] + 2;
                if(f[l][r - 1] > f[l][r]) f[l][r] = f[l][r - 1];
                if(f[l + 1][r] > f[l][r]) f[l][r] = f[l + 1][r];
            }
        }

    printf("%d\n", n - f[0][n - 1]);
    
    return 0;
}