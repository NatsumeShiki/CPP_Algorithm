// n
//  个砖块排成一排，从左到右编号依次为 1∼n
// 。

// 每个砖块要么是黑色的，要么是白色的。

// 现在你可以进行以下操作若干次（可以是 0
//  次）：

// 选择两个相邻的砖块，反转它们的颜色。（黑变白，白变黑）

// 你的目标是通过不超过 3n
//  次操作，将所有砖块的颜色变得一致。

// 输入格式
// 第一行包含整数 T
// ，表示共有 T
//  组测试数据。

// 每组数据第一行包含一个整数 n
// 。

// 第二行包含一个长度为 n
//  的字符串 s
// 。其中的每个字符都是 W 或 B，如果第 i
//  个字符是 W，则表示第 i
//  号砖块是白色的，如果第 i
//  个字符是 B，则表示第 i
//  个砖块是黑色的。

// 输出格式
// 每组数据，如果无解则输出一行 −1
// 。

// 否则，首先输出一行 k
// ，表示需要的操作次数。

// 如果 k>0
// ，则还需再输出一行 k
//  个整数，p1,p2,…,pk
// 。其中 pi
//  表示第 i
//  次操作，选中的砖块为 pi
//  和 pi+1
//  号砖块。

// 如果方案不唯一，则输出任意合理方案即可。

// 数据范围
// 1≤T≤10
// ，
// 2≤n≤200
// 。

// 输入样例：
// 4
// 8
// BWWWWWWB
// 4
// BWBB
// 5
// WWWWW
// 3
// BWB
// 输出样例：
// 3
// 6 2 4
// -1
// 0
// 2
// 2 1

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n;
string str;

void update(char& c){
    if(c == 'W') c = 'B';
    else c = 'W';
}

bool check(char c){
    vector<int> res;
    string s = str;
    for(int i = 0; i + 1 < n; i++)
        if(s[i] != c){
            update(s[i]);
            update(s[i + 1]);
            res.push_back(i);
        }
        
    if(s.back() != c) return false;
    
    cout << res.size() << endl;
    for(int x : res) cout << x + 1 << " ";
    if(res.size()) cout << endl;
    
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> str;
        if(!check('B') && !check('W')) puts("-1");
    }
    
    return 0;
}