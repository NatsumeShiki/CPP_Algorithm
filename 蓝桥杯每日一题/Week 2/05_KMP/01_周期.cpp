// 一个字符串的前缀是从第一个字符开始的连续若干个字符，例如 abaab 共有 5
//  个前缀，分别是 a，ab，aba，abaa，abaab。

// 我们希望知道一个 N
//  位字符串 S
//  的前缀是否具有循环节。

// 换言之，对于每一个从头开始的长度为 i
// （i>1
// ）的前缀，是否由重复出现的子串 A
//  组成，即 AAA…A
//  （A
//  重复出现 K
//  次,K>1
// ）。

// 如果存在，请找出最短的循环节对应的 K
//  值（也就是这个前缀串的所有可能重复节中，最大的 K
//  值）。

// 输入格式
// 输入包括多组测试数据，每组测试数据包括两行。

// 第一行输入字符串 S
//  的长度 N
// 。

// 第二行输入字符串 S
// 。

// 输入数据以只包括一个 0
//  的行作为结尾。

// 输出格式
// 对于每组测试数据，第一行输出 Test case # 和测试数据的编号。

// 接下来的每一行，输出具有循环节的前缀的长度 i
//  和其对应 K
// ，中间用一个空格隔开。

// 前缀长度需要升序排列。

// 在每组测试数据的最后输出一个空行。

// 数据范围
// 2≤N≤1000000
// 输入样例：
// 3
// aaa
// 4
// abcd
// 12
// aabaabaabaab
// 0
// 输出样例：
// Test case #1
// 2 2
// 3 3

// Test case #2

// Test case #3
// 2 2
// 6 2
// 9 3
// 12 4


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;
int n;
char str[N];
int ne[N];

int main(){
    int cnt = 1;
    while(cin >> n, n){
        cin >> str + 1;
        for(int i = 2, j = 0; i <= n; i++){
            while(j && str[j + 1] != str[i]) j = ne[j];
            if(str[j + 1] == str[i]) j++;
            ne[i] = j;
        }
        
        printf("Test case #%d\n", cnt++);
        for(int i = 2; i <= n; i++){
            int T = i - ne[i];
            if(i % T == 0 && i / T > 1) cout << i << " " << i / T << endl;
        }
        cout << endl;
    }
    
    return 0;
}