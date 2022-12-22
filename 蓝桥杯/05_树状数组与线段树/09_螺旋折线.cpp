// 如下图所示的螺旋折线经过平面上所有整点恰好一次。

// p1.png

// 对于整点 (X,Y)，我们定义它到原点的距离 dis(X,Y) 是从原点到 (X,Y) 的螺旋折线段的长度。

// 例如 dis(0,1)=3,dis(−2,−1)=9

// 给出整点坐标 (X,Y)，你能计算出 dis(X,Y) 吗？

// 输入格式
// 包含两个整数 X,Y。

// 输出格式
// 输出一个整数，表示 dis(X,Y)。

// 数据范围
// −109≤X,Y≤109
// 输入样例：
// 0 1
// 输出样例：
// 3

// 题目给出的x和y很大，使用模拟或者每次走一条边会TLE，所以本道题需要找规律
/*
左上角是(2n - 1)    右上角是(2n)^2
   30 31 32 33 34 35 36   上边 abs(x) <= y
   29 12 13 14 15 16 37   右边 abs(y) <= x
   28 11  2  3  4 17 38   下边 abs(x) <= abs(y) + 1 && y < 0
   27 10  1  0  5 18 39   左边 abs(y) <= abs(x)
   26  9  8  7  6 19 40
   25 24 23 22 21 20 41
49 48 47 46 45 44 43 42
左下角是(2n - 1)^2   右下角是2n*(2n - 1)
*/
#include<iostream>
using namespace std;

typedef long long LL;

int main(){
    int x, y;
    cin >> x >> y;
    
    LL res = 0;
    if(abs(x) <= y){ // 在上方
        int n = y;
        res = (LL)2 * n * (2 * n - 1) + x - (-n);
    }else if(abs(y) <= x){  // 在右方
        int n = x;
        res = (LL)2 * n * 2 * n + n - y;
    }else if(abs(x) <= abs(y) + 1 && y < 0){  // 在下方
        int n = abs(y);
        res = (LL)2 * n * (2 * n + 1) + n - x;
    }else{  // 在左方
        int n = abs(x);
        res = (LL)(2 * n - 1) * (2 * n - 1) + y - (-n + 1);
    }
    cout << res << endl;
    return 0;
}