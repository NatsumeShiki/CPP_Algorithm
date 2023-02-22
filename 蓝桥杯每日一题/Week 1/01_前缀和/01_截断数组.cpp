// 给定一个长度为 n
//  的数组 a1,a2,…,an
// 。

// 现在，要将该数组从中间截断，得到三个非空子数组。

// 要求，三个子数组内各元素之和都相等。

// 请问，共有多少种不同的截断方法？

// 输入格式
// 第一行包含整数 n
// 。

// 第二行包含 n
//  个整数 a1,a2,…,an
// 。

// 输出格式
// 输出一个整数，表示截断方法数量。

// 数据范围
// 前六个测试点满足 1≤n≤10
// 。
// 所有测试点满足 1≤n≤105
// ，−10000≤ai≤10000
// 。

// 输入样例1：
// 4
// 1 2 3 3
// 输出样例1：
// 1
// 输入样例2：
// 5
// 1 2 3 4 5
// 输出样例2：
// 0
// 输入样例3：
// 2
// 0 0
// 输出样例3：
// 0

// 我的代码 枚举第二刀
#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;
using namespace std;

const int N = 1e5 + 10;
int s[N];
int n;
int cnt;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }

    int sum = s[n];
    if(n < 3 || sum % 3) cout << 0 << endl;
    else{
        LL res = 0;
        sum /= 3;
        for(int i = 1; i < n; i++) 
            if(s[i] == sum) cnt++;

        for(int i = n - 1; i >= 2; i--){
            if(s[i] == sum) cnt--;
            if(s[n] - s[i] == sum) res += cnt;

        }

        cout << res << endl;
    }

    return 0;
}


// 大佬的代码 同样也是枚举第二刀
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010;
int n;
int s[N];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        s[i] += s[i - 1];
    }

    if(s[n] % 3){
        puts("0");
        return 0;
    }

    LL res = 0;
    for(int i = 3, cnt = 0; i <= n; i++){
        if(s[i - 2] == s[n] / 3) cnt++;
        if(s[n] - s[i - 1] == s[n] / 3) res += cnt;
    }

    cout << res << endl;

    return 0;
}