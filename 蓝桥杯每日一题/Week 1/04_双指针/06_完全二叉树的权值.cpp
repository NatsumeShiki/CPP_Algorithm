// 给定一棵包含 N
//  个节点的完全二叉树，树上每个节点都有一个权值，按从上到下、从左到右的顺序依次是 A1,A2,⋅⋅⋅AN
// ，如下图所示：

// QQ截图20191205124611.png

// 现在小明要把相同深度的节点的权值加在一起，他想知道哪个深度的节点权值之和最大？

// 如果有多个深度的权值和同为最大，请你输出其中最小的深度。

// 注：根的深度是 1
// 。

// 输入格式
// 第一行包含一个整数 N
// 。

// 第二行包含 N
//  个整数 A1,A2,⋅⋅⋅AN
// 。

// 输出格式
// 输出一个整数代表答案。

// 数据范围
// 1≤N≤105
// ,
// −105≤Ai≤105
// 输入样例：
// 7
// 1 6 5 4 3 2 1
// 输出样例：
// 2

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int a[N];
int n;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int maxv = 0, res = 1;
    for(int i = 0, cnt = 1, k = 1; i < n; cnt *= 2, k++){
        LL sum = 0;
        for(int j = i; j < min(i + cnt, n); j++) sum += a[j];
        if(sum > maxv){
            maxv = sum;
            res = k;
        }
        i += cnt;
    }
    cout << res << endl;
    
    return 0;
}