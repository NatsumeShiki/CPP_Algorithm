// 你玩过“拉灯”游戏吗？

// 25
//  盏灯排成一个 5×5
//  的方形。

// 每一个灯都有一个开关，游戏者可以改变它的状态。

// 每一步，游戏者可以改变某一个灯的状态。

// 游戏者改变一个灯的状态会产生连锁反应：和这个灯上下左右相邻的灯也要相应地改变其状态。

// 我们用数字 1
//  表示一盏开着的灯，用数字 0
//  表示关着的灯。

// 下面这种状态

// 10111
// 01101
// 10111
// 10000
// 11011
// 在改变了最左上角的灯的状态后将变成：

// 01111
// 11101
// 10111
// 10000
// 11011
// 再改变它正中间的灯后状态将变成：

// 01111
// 11001
// 11001
// 10100
// 11011
// 给定一些游戏的初始状态，编写程序判断游戏者是否可能在 6
//  步以内使所有的灯都变亮。

// 输入格式
// 第一行输入正整数 n
// ，代表数据中共有 n
//  个待解决的游戏初始状态。

// 以下若干行数据分为 n
//  组，每组数据有 5
//  行，每行 5
//  个字符。

// 每组数据描述了一个游戏的初始状态。

// 各组数据间用一个空行分隔。

// 输出格式
// 一共输出 n
//  行数据，每行有一个小于等于 6
//  的整数，它表示对于输入数据中对应的游戏状态最少需要几步才能使所有灯变亮。

// 对于某一个游戏初始状态，若 6
//  步以内无法使所有灯变亮，则输出 −1
// 。

// 数据范围
// 0<n≤500
// 输入样例：
// 3
// 00111
// 01011
// 10001
// 11010
// 11100

// 11101
// 11101
// 11110
// 11111
// 11111

// 01111
// 11111
// 11111
// 11111
// 11111
// 输出样例：

// 3
// 2
// -1

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5;
char g[N][N], backup[N][N];
int n;

int dx[5] = {0, -1, 0, 1, 0}, dy[5] = {-1, 0, 1, 0, 0};

void turn(int x, int y){
    for(int i = 0; i < 5; i++){
        int a = x + dx[i], b = y + dy[i];
        if(a < 0 || a >= 5 || b < 0 || b >= 5) continue;
        backup[a][b] ^= 1;
    }
}

int main(){
    cin >> n;
    while(n--){
        for(int i = 0; i < 5; i++) cin >> g[i];
        
        int res = 10;
        for(int op = 0; op < 32; op++){
            int step = 0;
            memcpy(backup, g, sizeof g);
            for(int j = 0; j < 5; j++)
                if(op >> j & 1)
                    turn(0, j), step++;
            
            for(int i = 0; i < 4; i++)
                for(int j = 0; j < 5; j++)
                    if(backup[i][j] == '0')
                        turn(i + 1, j), step++;
                    
            bool dark = false;    
            for(int i = 0; i < 5; i++)
                if(backup[4][i] == '0'){
                    dark = true;
                    break;
                }
            if(!dark) res = min(res, step);
        }
        if(res <= 6) cout << res << endl;
        else cout << -1 << endl;
    }
    
    return 0;
}