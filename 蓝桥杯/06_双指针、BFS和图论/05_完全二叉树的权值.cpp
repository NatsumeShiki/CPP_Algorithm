// 给定一棵包含 N 个节点的完全二叉树，树上每个节点都有一个权值，按从上到下、从左到右的顺序依次是 A1,A2,⋅⋅⋅AN，如下图所示：

// QQ截图20191205124611.png

// 现在小明要把相同深度的节点的权值加在一起，他想知道哪个深度的节点权值之和最大？

// 如果有多个深度的权值和同为最大，请你输出其中最小的深度。

// 注：根的深度是 1。

// 输入格式
// 第一行包含一个整数 N。

// 第二行包含 N 个整数 A1,A2,⋅⋅⋅AN。

// 输出格式
// 输出一个整数代表答案。

// 数据范围
// 1≤N≤105,
// −105≤Ai≤105
// 输入样例：
// 7
// 1 6 5 4 3 2 1
// 输出样例：
// 2

// 自己写的代码
// 这道题就像题目说的那样做就可以
/*
第一层有一个数，第二层有二个数，第n层有2^(n-1)个数
每次把这一层数加起来跟最大值比较，如果大于最大值，就把这个和设置为最大值，然后保存这是第几层，直到所有数都被遍历一遍
*/
#include<iostream>
#include<climits>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int a[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int res = 0; // 保存结果是第几层
    LL max = INT_MIN; // 保存最大值
    for(int i = 0, j = 1, w = 1; i < n; j *= 2, w++){ // i是记录当前的下标，j是记录这一层有几个数，w是保存这是第几层
        LL t = 0; // t来保存这一层数的累加
        int x = j; // x是这一层有多少个数
        while(x-- && i < n){ // 直到x为0或者i到了最后
            t += a[i++]; // 让t累加
        }
        if(t > max){ // 如果这一层数权值之和大于max
            max = t; // 就把它赋值给max
            res = w; // 然后记录这是第几层
        }
    }
    cout << res << endl; // 最后输出即可
    return 0;
}

// 大佬的代码
#include<iostream>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int a[N];
int n;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    LL maxs = -1e18;
    int depth = 0;
    
    for(int d = 1, i = 1; i <= n; i *= 2, d++){
        LL s = 0;
        for(int j = i; j < i + (1 << d - 1) && j <= n; j++)
            s += a[j];
            
        if(s > maxs){
            maxs = s;
            depth = d;
        }
    }
    
    cout << depth << endl;
    return 0;
}