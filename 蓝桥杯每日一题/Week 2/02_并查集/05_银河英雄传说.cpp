// 有一个划分为 N
//  列的星际战场，各列依次编号为 1,2,…,N
// 。

// 有 N
//  艘战舰，也依次编号为 1,2,…,N
// ，其中第 i
//  号战舰处于第 i
//  列。

// 有 T
//  条指令，每条指令格式为以下两种之一：

// M i j，表示让第 i
//  号战舰所在列的全部战舰保持原有顺序，接在第 j
//  号战舰所在列的尾部。
// C i j，表示询问第 i
//  号战舰与第 j
//  号战舰当前是否处于同一列中，如果在同一列中，它们之间间隔了多少艘战舰。
// 现在需要你编写一个程序，处理一系列的指令。

// 输入格式
// 第一行包含整数 T
// ，表示共有 T
//  条指令。

// 接下来 T
//  行，每行一个指令，指令有两种形式：M i j 或 C i j。

// 其中 M
//  和 C
//  为大写字母表示指令类型，i
//  和 j
//  为整数，表示指令涉及的战舰编号。

// 输出格式
// 你的程序应当依次对输入的每一条指令进行分析和处理：

// 如果是 M i j 形式，则表示舰队排列发生了变化，你的程序要注意到这一点，但是不要输出任何信息；

// 如果是 C i j 形式，你的程序要输出一行，仅包含一个整数，表示在同一列上，第 i
//  号战舰与第 j
//  号战舰之间布置的战舰数目，如果第 i
//  号战舰与第 j
//  号战舰当前不在同一列上，则输出 −1
// 。

// 数据范围
// N≤30000,T≤500000
// 输入样例：
// 4
// M 2 3
// C 1 2
// M 2 4
// C 4 2
// 输出样例：
// -1
// 1

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 30010;
int p[N], d[N], sz[N];

int find(int x){
    if(x != p[x]){
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main(){
    for(int i = 1; i < N; i++) p[i] = i, sz[i] = 1;
    int t;
    cin >> t;
    while(t--){
        char op;
        int a, b;
        cin >> op >> a >> b;
        int pa = find(a), pb = find(b);
        if(op == 'M') {
            if(pa == pb) continue;
            d[pa] = sz[pb];
            sz[pb] += sz[pa];
            p[pa] = pb;
        }
        else {
            if(pa != pb) puts("-1");
            else cout << max(0, abs(d[a] - d[b]) - 1) << endl;
        }
    }
    
    return 0;
}