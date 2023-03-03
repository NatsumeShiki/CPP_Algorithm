// 维护一个字符串集合，支持两种操作：

// I x 向集合中插入一个字符串 x
// ；
// Q x 询问一个字符串在集合中出现了多少次。
// 共有 N
//  个操作，所有输入的字符串总长度不超过 105
// ，字符串仅包含小写英文字母。

// 输入格式
// 第一行包含整数 N
// ，表示操作数。

// 接下来 N
//  行，每行包含一个操作指令，指令为 I x 或 Q x 中的一种。

// 输出格式
// 对于每个询问指令 Q x，都要输出一个整数作为结果，表示 x
//  在集合中出现的次数。

// 每个结果占一行。

// 数据范围
// 1≤N≤2∗104
// 输入样例：
// 5
// I abc
// Q abc
// Q ab
// I ab
// Q ab
// 输出样例：
// 1
// 0
// 1

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 26 * 2e4 + 10;
int tr[N][30], idx, cnt[N];
int n;

void insert(string s){
    int p = 0;
    for(int i = 0; i < s.size(); i++){
        int u = s[i] - 'a';
        if(!tr[p][u]) tr[p][u] = ++idx;
        p = tr[p][u];
    }
    cnt[p]++;
}

int query(string s){
    int p = 0;
    for(int i = 0; i < s.size(); i++){
        int u = s[i] - 'a';
        if(tr[p][u]) p = tr[p][u];
        else return 0;
    }
    return cnt[p];
}

int main(){
    cin >> n;
    while(n--){
        char op;
        string s;
        cin >> op >> s;
        if(op == 'I') insert(s);
        else cout << query(s) << endl;
    }
    
    return 0;
}