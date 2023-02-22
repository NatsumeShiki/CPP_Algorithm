// 农夫约翰出门沿着马路散步，但是他现在发现自己可能迷路了！

// 沿路有一排共 N
//  个农场。

// 不幸的是农场并没有编号，这使得约翰难以分辨他在这条路上所处的位置。

// 然而，每个农场都沿路设有一个彩色的邮箱，所以约翰希望能够通过查看最近的几个邮箱的颜色来唯一确定他所在的位置。

// 每个邮箱的颜色用 A..Z
//  之间的一个字母来指定，所以沿着道路的 N
//  个邮箱的序列可以用一个长为 N
//  的由字母 A..Z
//  组成的字符串来表示。

// 某些邮箱可能会有相同的颜色。

// 约翰想要知道最小的 K
//  的值，使得他查看任意连续 K
//  个邮箱序列，他都可以唯一确定这一序列在道路上的位置。

// 例如，假设沿路的邮箱序列为 ABCDABC 。

// 约翰不能令 K=3
// ，因为如果他看到了 ABC，则沿路有两个这一连续颜色序列可能所在的位置。

// 最小可行的 K
//  的值为 K=4
// ，因为如果他查看任意连续 4
//  个邮箱，那么可得到的连续颜色序列可以唯一确定他在道路上的位置。

// 输入格式
// 输入的第一行包含 N
// ，第二行包含一个由 N
//  个字符组成的字符串，每个字符均在 A..Z
//  之内。

// 输出格式
// 输出一行，包含一个整数，为可以解决农夫约翰的问题的最小 K
//  值。

// 数据范围
// 1≤N≤100
// 输入样例：
// 7
// ABCDABC
// 输出样例：
// 4

// 自己的代码
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;
char str[N];
int n;

bool check(int len){
    for(int i = 1; i + len <= n; i++)
        for(int j = i + 1; j + len - 1 <= n; j++){
            int a = i, b = j;
            while(a <= i + len - 1 && str[a] == str[b]) a++, b++;
            if(a == i + len) return false;
        }
    return true;
}

int main(){
    cin >> n >> str + 1;
    int l = 1, r = n;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    
    return 0;
}

// 大佬的代码
// 用unordered_set来存储字符串
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;

int n;
string str;

bool check(int mid){
    unordered_set<string> hash;
    for(int i = 0; i + mid - 1 < str.size(); i++){
        auto s = str.substr(i, mid);
        if(hash.count(s)) return false;
        hash.insert(s);
    }
    return true;
}

int main(){
    cin >> n;
    cin >> str;
    
    int l = 1, r = n;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    
    cout << l << endl;
    
    return 0;
}