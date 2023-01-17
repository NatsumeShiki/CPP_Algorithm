// 熊大妈的奶牛在小沐沐的熏陶下开始研究信息题目。

// 小沐沐先让奶牛研究了最长上升子序列，再让他们研究了最长公共子序列，现在又让他们研究最长公共上升子序列了。

// 小沐沐说，对于两个数列 A 和 B，如果它们都包含一段位置不一定连续的数，且数值是严格递增的，那么称这一段数是两个数列的公共上升子序列，而所有的公共上升子序列中最长的就是最长公共上升子序列了。

// 奶牛半懂不懂，小沐沐要你来告诉奶牛什么是最长公共上升子序列。

// 不过，只要告诉奶牛它的长度就可以了。

// 数列 A 和 B 的长度均不超过 3000。

// 输入格式
// 第一行包含一个整数 N，表示数列 A，B 的长度。

// 第二行包含 N 个整数，表示数列 A。

// 第三行包含 N 个整数，表示数列 B。

// 输出格式
// 输出一个整数，表示最长公共上升子序列的长度。

// 数据范围
// 1≤N≤3000,序列中的数字均不超过 231−1。

// 输入样例：
// 4
// 2 2 1 3
// 2 1 2 3
// 输出样例：
// 2

/*
动态规划：
  状态表示f[i, j]
    集合：所有由第一个序列的前i个字母，和第二个序列的前j个字母构成的，且以b[j]结尾的公共上升子序列
    属性：Max
  状态计算：
    所有不包含a[i]的公共上升子序列 f[i - 1, j]
    所有包含a[i]的公共上升子序列，从b序列的 1 ~ j - 1 查找比b[j]小的数，然后更新f[i][j]
*/
// 这个是按照上面的思路写得代码，照理说如果相同的数字多的话，它的三种循环是会取满的，所以会TLE
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 3010;
int a[N], b[N];
int f[N][N];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            f[i][j] = f[i - 1][j]; // 不包含 a[i]
            if(a[i] == b[j]){ // 如果两个结尾相同
                f[i][j] = max(f[i][j], 1); // 如果在前i - 1和前j - 1没有公共上升子序列，则f[i][j]就是1，所以先初始化
                for(int k = 1; k < j; k++) // 然后从1 ~ j - 1 查找比b[j]小的，然后在 f[i][j] 和 f[i][k] + 1 二者中取较大值
                    if(b[k] < b[j])
                        f[i][j] = max(f[i][j], f[i][k] + 1);
            }
        }
        
    int res = 0;
    for(int i = 1; i <= n; i++) res = max(res, f[n][i]); // 遍历取最大值
    cout << res << endl;
    
    return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 3010;
int a[N], b[N];
int f[N][N];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    
    // for(int i = 1; i <= n; i++)
    //     for(int j = 1; j <= n; j++){
    //         f[i][j] = f[i - 1][j]; // 不包含 a[i]
    //         if(a[i] == b[j]){
    //             f[i][j] = max(f[i][j], 1);
    //             for(int k = 1; k < j; k++)
    //                 if(b[k] < b[j])
    //                     f[i][j] = max(f[i][j], f[i][k] + 1);
    //         }
    //     }
    /*
    如果a[i] == b[j]，则b[k] < b[j] 可以转换成 b[k] < a[i]，也就是说这个if判断语句与第二层循环是无关的，所以可以把它提取出来，然后就可以把它看成是
    从1 ~ j - 1中寻找比a[i]小的 f[i][j] + 1 的最大值，用一个变量保存它就可以减少一层循环
    */
    for(int i = 1; i <= n; i++){
        int maxv = 1;
        for(int j = 1; j <= n; j++){
            f[i][j] = f[i - 1][j];
            if(a[i] == b[j]) f[i][j] = max(f[i][j], maxv);
            if(b[j] < a[i]) maxv = max(maxv, f[i][j] + 1);
        }
    }
        
    int res = 0;
    for(int i = 1; i <= n; i++) res = max(res, f[n][i]);
    cout << res << endl;
    
    return 0;
}