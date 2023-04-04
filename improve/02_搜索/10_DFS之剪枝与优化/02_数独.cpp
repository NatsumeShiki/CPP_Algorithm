// 数独 是一种传统益智游戏，你需要把一个 9×9
//  的数独补充完整，使得数独中每行、每列、每个 3×3
//  的九宫格内数字 1∼9
//  均恰好出现一次。

// 请编写一个程序填写数独。

// 输入格式
// 输入包含多组测试用例。

// 每个测试用例占一行，包含 81
//  个字符，代表数独的 81
//  个格内数据（顺序总体由上到下，同行由左到右）。

// 每个字符都是一个数字（1−9
// ）或一个 .（表示尚未填充）。

// 您可以假设输入中的每个谜题都只有一个解决方案。

// 文件结尾处为包含单词 end 的单行，表示输入结束。

// 输出格式
// 每个测试用例，输出一行数据，代表填充完全后的数独。

// 输入样例：
// 4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......
// ......52..8.4......3...9...5.1...6..2..7........3.....6...1..........7.4.......3.
// end
// 输出样例：
// 417369825632158947958724316825437169791586432346912758289643571573291684164875293
// 416837529982465371735129468571298643293746185864351297647913852359682714128574936

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 9, M = 1 << N;

int ones[M], map[M]; // ones数组保存一个数的二进制表示中有多少个1，map数组保存一个二进制数，其中只有一个1，这个1的位置，比如说map[1] = 0, map[100] = 2
int row[N], col[N], cell[N][N]; // 保存九宫格的某一行某一列和某一个小井子可以放什么数，1表示可以放，0表示不可以放
char str[100];

void init(){
    for(int i = 0; i < N; i++) row[i] = col[i] = (1 << N) - 1; // 九宫格的每一行每一列和每一个小井子都可以存放1-9所有数
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cell[i][j] = (1 << N) - 1;
}

void draw(int x, int y, int t, bool is_set){ // x、y表示坐标，t表示这个数是几，is_set表示是存放还是删除
    if(is_set) str[x * N + y] = '1' + t; // 如果是存放，把它放进九宫格中
    else str[x * N + y] = '.'; // 否则重置成 .
    
    int v = 1 << t; // 获取它的二进制表示
    if(!is_set) v = -v; // 如果是删除，就取反，因为删除就表示这个位置可以填写t
    
    row[x] -= v; // 如果v是正数，表示不能填写，否则可以填写
    col[y] -= v;
    cell[x / 3][y / 3] -= v;
}

int lowbit(int x){ // 获取最后一个1的二进制数
    return x & -x;
}

int get(int x, int y){ // 获取该位置可以存放什么数
    return row[x] & col[y] & cell[x / 3][y / 3];
}

bool dfs(int cnt){
    if(!cnt) return true; // 如果cnt为0，说明找到了一种方法可以把所有空格全部填写
    
    int minv = 10; // 一个位置最多可以填写的数有9个，用于找出可以填写数最少的位置，这样可以减少分支
    int x, y;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(str[i * N + j] == '.'){ // 如果这个位置是空格
                int state = get(i, j); // 获取它的状态
                if(ones[state] < minv){ // 如果1的数量比minv少
                    minv = ones[state]; // 保存这个状态和他的坐标
                    x = i, y = j;
                }
            }
            
    int state = get(x, y); // 获取到了可以填的数最少的状态
    for(int i = state; i; i -= lowbit(i)){ 
        int t = map[lowbit(i)]; // t是可以填写的数
        draw(x, y, t, true); // 填写t
        if(dfs(cnt - 1)) return true; // dfs，如果返回true，表示这种方案可行，直接返回true
        draw(x, y, t, false); // 否则，继续枚举下一个
    }
    
    return false; // 如果没有答案，返回false
}

int main(){
    for(int i = 0; i < N; i++) map[1 << i] = i; // 保存二进制表示中1的位置
    for(int i = 0; i < 1 << N; i++)
        for(int j = 0; j < N; j++)
            ones[i] += i >> j & 1; // 记录一个数中二进制表示1的个数
            
    while(cin >> str, str[0] != 'e'){
        init(); // 初始化
        
        int cnt = 0; // 保存九宫格中空的位置，最终cnt为0就表示九宫格是空的
        for(int i = 0, k = 0; i < N; i++)
            for(int j = 0; j < N; j++, k++)
                if(str[k] != '.'){ // 如果这个位置是数字
                    int  t = str[k] - '1'; 
                    draw(i, j, t, true); // 存进九宫格中
                }else cnt++; // 否则，空格增加一个
                
        dfs(cnt);
        
        puts(str);
    }
    
    return 0;
}