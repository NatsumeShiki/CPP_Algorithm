// 如下图所示，有一个 # 形的棋盘，上面有 1,2,3
//  三种数字各 8
//  个。

// 给定 8
//  种操作，分别为图中的 A∼H
// 。

// 这些操作会按照图中字母和箭头所指明的方向，把一条长为 7
//  的序列循环移动 1
//  个单位。

// 例如下图最左边的 # 形棋盘执行操作 A
//  后，会变为下图中间的 # 形棋盘，再执行操作 C
//  后会变成下图最右边的 # 形棋盘。

// 给定一个初始状态，请使用最少的操作次数，使 # 形棋盘最中间的 8
//  个格子里的数字相同。

// 2286_1.jpg

// 输入格式
// 输入包含多组测试用例。

// 每个测试用例占一行，包含 24
//  个数字，表示将初始棋盘中的每一个位置的数字，按整体从上到下，同行从左到右的顺序依次列出。

// 输入样例中的第一个测试用例，对应上图最左边棋盘的初始状态。

// 当输入只包含一个 0
//  的行时，表示输入终止。

// 输出格式
// 每个测试用例输出占两行。

// 第一行包含所有移动步骤，每步移动用大写字母 A∼H
//  中的一个表示，字母之间没有空格，如果不需要移动则输出 No moves needed。

// 第二行包含一个整数，表示移动完成后，中间 8
//  个格子里的数字。

// 如果有多种方案，则输出字典序最小的解决方案。

// 输入样例：
// 1 1 1 1 3 2 3 2 3 1 3 2 2 3 1 2 2 2 3 1 2 1 3 3
// 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3
// 0
// 输出样例：
// AC
// 2
// DDHH
// 2

/*
           0     1
           A     B
           0     1
           2     3
7 H  4  5  6  7  8  9 10  C 2
          11    12
6 G 13 14 15 16 17 18 19 10 3
          20    21
          22    23
           F     E
           5     4
  打个表
*/

#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 24;
int op[8][7] = { // 记录这八种操作方式的下标
    {0, 2, 6, 11, 15, 20, 22},
    {1, 3, 8, 12, 17, 21, 23},
    {10, 9, 8, 7, 6, 5, 4},
    {19, 18, 17, 16, 15, 14, 13},
    {23, 21, 17, 12, 8, 3, 1},
    {22, 20, 15, 11, 6, 2, 0},
    {13, 14, 15, 16, 17, 18, 19},
    {4, 5, 6, 7, 8, 9, 10}
};

int opposite[8] = {5, 4, 7, 6, 1, 0, 3, 2}; // 记录第i种操作它的逆操作
int center[8] = {6, 7, 8, 11, 12, 15, 16, 17}; // 记录中间八个点的坐标

int q[N];
int path[100];

int f(){ // 估价数组
    static int sum[4];
    memset(sum, 0, sizeof sum);
    
    for(int i = 0; i < 8; i++) sum[q[center[i]]]++; // 将对应的八个点在对应位置累加
    
    int s = 0;
    for(int i = 1; i <= 3; i++) s = max(s, sum[i]); // 获取最大值
    
    return 8 - s; // 返回需要操作次数，因为一步操作最多可以改变一个位置
}

void operate(int x){
    int t = q[op[x][0]]; // 先保存第一个数
    for(int i = 0; i < 6; i++) q[op[x][i]] = q[op[x][i + 1]]; // 后面六个数往前走
    q[op[x][6]] = t; // 最后一个位置填t
}

bool dfs(int depth, int max_depth, int last){
    if(depth + f() > max_depth) return false; // 如果当前层数加上至少需要的次数大于max_depth，返回false
    if(f() == 0) return true; // 如果估价函数为0，表明找到的第一个解
    
    for(int i = 0; i < 8; i++) // 枚举八种操作
        if(opposite[i] != last){ // 如果它不为上一步操作的逆步骤
            operate(i); // 进行i操作
            path[depth] = i; // 记录
            if(dfs(depth + 1, max_depth, i)) return true; // 向下查询
            operate(opposite[i]); // 没有查到，返回原状态
        }
        
    return false;
}

int main(){
    while(cin >> q[0], q[0]){
        for(int i = 1; i < N; i++) cin >> q[i];
        
        int depth = 0; // 迭代加深
        while(!dfs(0, depth, -1)) depth++;
        
        if(!depth) printf("No moves needed");
        else for(int i = 0; i < depth; i++) printf("%c", path[i] + 'A');
        
        printf("\n%d\n", q[6]);
    }
    
    return 0;
}